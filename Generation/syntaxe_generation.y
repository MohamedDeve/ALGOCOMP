%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "generation.h"

char *nomProgramme;
int estNomProgramme; /* variable pour verifier si l'identifiant est pour nomer le programme ou c'est une variable*/
int finDeclaration; /* 0 si la declaration n'est pas terminee 1 si la declaration est terminee */
int estConstante; /* 1 on est encors dans la declaration des constantes 0 sinon*/
int estVariable; /* 1 on est encors dans la declaration des variables  0 sinon */
int nbrVarDecEnC; /* le nombre des variables dejas declares dans le fichier .c */
int nbrConstDecEnC; /* le nombre des constantes dejas declares dans le fichier .c */
int numeroType; /* la variable qui va contenire a chaque fois le numero d'un type qu'on va utiliser pour associer le type a une variable ou une constante*/
int typeAffG; /* la variable qui va contenir le numero du type de la partie gauche de l'affectation */
int typeAffD; /* la variable qui va contenir le numero du type de la partie droite de l'affectation */
int typeAffDO;/* la variable qui va contenir le numero du type de chaque operande de l'affectation */
int symboleOperation; /* 1- pour la somme 2- pour la soustraction  3- pour le produit 4- pour la division */
int nature;/* identifiant ou valeur */
int typeVarSwitch;/* la variable qui stock le type de la variable de switch */
int estInstrEcrireOuLire;/* varaible utiliser pour autoriser l'affichage des chaine (en val) dans les instruction d'affichage (sa valeur est 1) */
int debutInstrAff; /* variable qui indique le debut d'une instruction de l'affectation si sa valeur est 1 et  o sinon */
int estFormateur;
int boucleTQueFinie; /* la variable qui indique qu'une boucle tantque est finie ( si sa valeur est 1 ) ou non ()*/
int boucleFTQueFinie; /* la variable qui indique qu'une boucle faire tantque est finie ( si sa valeur est 1 ) ou non ()*/
int eatBoucle;
int estFonction; /* variable qui va nous dir que nous somme entrain de declarer une fonction si sa valeur est 1 et sinon si sa valeur est 0 */
int niveauFonct;
int fonctPossedeArgs;/* la variable qui permet de dire qu'une fonction possede des arguments ou non */
int fonctEstTrouve; /* la variable qui permet de dire qu'une fonction existe ou non (pour ne pas afficher les autre erreur si une fonction n'existe pas)*/
int numArgum; /* la variable qui stock le numero de l'argument d'une fonction */
int estAppelFonct; /* la variable qui indique qu'une unstruction est une appelle d'une fonction */
int typeAffG_appelFonct; /* la variable qui va contenir le type de la partie gauche lors de l'appele d'une fonction*/
int nomFonctEstPasse;/* cette variable va nous indique qu'on a verifie l'existance d'une fonction l'hors de son appelle  */
int erreur;
int estRetourne;/* si sa valeur est 1 on est dans une instruction de return d'une fonction 0 sinon utilisee pour empecher l'affichage de l'erreur lier au changement de la valeur stockee dans une constante */
int estBoucle;/* si sa valeur est 1 on est dans une expresion conditionnele d'une boucle 0 sinon utilisee pour empecher l'affichage de l'erreur lier au changement de la valeur stockee dans une constante */
int varEstGlobale; /* la variable qui indique si une variable est globale pour une fonction ou non */
char c;
char *affAppeleFonct;
char *nomF;
char *identPour; /* la variable qui va stocker le nom de la variable utilise dans la boucle pour */
char *chaineSource;
char *chainePrincipale;
char *chaineSecondere;
char *chaineParametres;
char *nomConstante; /* variable qui va stocker le nom de la constante a chaque fois qu'on veut declarer une constante */
char *valConstante; /* variable qui va stocker la valeur de la constante a chaque fois qu'on veut convertire la declaration d'une constante dans le fichier .c*/
FILE *fichierProgEnC;
FILE *fichierHeader;
FILE *fichierFonction;
FILE *fichierVarGlobale;
extern FILE* yyin; 
int 	yylex(void); 
extern char *yytext;
void	yyerror(const char * msg); 
int 	lineNumber; 
pileIdentifs pileIdentifiants;
pileValConst pileConstantes;
fonction ExFonction;
pileFonctions pileFoncs;
%}

%token ALGO VARS CSTS DEBUT FIN IDENT
%token AFF DXPT PTVIRG VIRG
%token ENTIER REEL CHAINE CARACTERE
%token ENTIER_D REEL_D CHAINE_D CARACTERE_D
%token SOMM SOUSTR PROD DIV PAR_OUV PAR_FERM
%token INF SUP EG INF_EG SUP_EG DIFF CONJ DISJ NEG
%token SI ALORS SINON  SELON CAS 
%token POUR DE JUSQUA PAS FAIRE TANTQUE RETOURNE FONCTION
%token ECRIRE LIRE

%start programme 

%%
programme 	: entete{niveauFonct = 0;varEstGlobale = 0;} declaration corps;
entete 		: | ALGO IDENT;

declaration : | VARS ls_vars | VARS ls_vars CSTS l_csts | CSTS l_csts VARS ls_vars;
ls_vars 	:  ls_vars l_vars | l_vars;
l_vars      :  l_ident DXPT type{ prendreTypeDec(yytext); associerType(); declarationEnReChCa(yytext);} PTVIRG;	  
l_ident 	:  l_ident VIRG IDENT | IDENT;
l_csts		:  l_csts d_cst | d_cst;
d_cst 		:  IDENT{prendreNomConst(yytext);} AFF val{ prendreValConst(yytext);typeAffDO = 3;} DXPT type{  prendreTypeDec(yytext); associerType(); empilerValConst(&pileConstantes,&pileIdentifiants,yytext); declarationEnReChCa(yytext); } PTVIRG;
val 		:  ENTIER {typeAffDO = 1} | REEL {typeAffDO = 2}| CHAINE {typeAffDO = 3}| CARACTERE {typeAffDO = 4};
type      	:  ENTIER_D | REEL_D | CHAINE_D | CARACTERE_D ;

corps    	: DEBUT{if(niveauFonct == 0) fputs("int main(){\n",fichierProgEnC);} ls_instruction FIN {fermeturFichierC();} ;
ls_instruction  : ls_instruction instruction | instruction ;
instruction 	: IDENT AFF{if(typeAffG != 3){ if(niveauFonct == 0) fputs(" = ",fichierProgEnC); else fputs(" = ",fichierFonction);}} expr_ar PTVIRG{if(typeAffG != 3){ if(niveauFonct == 0) fputs(";\n",fichierProgEnC); else fputs(";\n",fichierFonction);} else executerAffCh();} | condition | switch | boucle | routine | appel_fonct | es_std ;
expr_ar		: expr_ar op_sym oper | PAR_OUV{ if(niveauFonct == 0) fputs(yytext,fichierProgEnC); else fputs(yytext,fichierFonction);} expr_ar PAR_FERM{if(niveauFonct == 0) fputs(yytext,fichierProgEnC); else fputs(yytext,fichierFonction);} | expr_ar op_sym{if(niveauFonct == 0) fputs(yytext,fichierProgEnC); else fputs(yytext,fichierFonction);} PAR_OUV{if(niveauFonct == 0) fputs(yytext,fichierProgEnC); else fputs(yytext,fichierFonction);} expr_ar PAR_FERM{if(niveauFonct == 0) fputs(yytext,fichierProgEnC); else fputs(yytext,fichierFonction);} | appel_fonct | oper;
oper 		: val {if(estInstrEcrireOuLire == 1){ stockerMessageCh(yytext);} else {nature = 2; if(estAppelFonct == 0){typeAffDestValide(yytext,2);} if(typeAffDO != 3 && typeAffG !=3 && estAppelFonct == 0){if(typeAffDO == 4){if(niveauFonct == 0){ fputs("'",fichierProgEnC); fputs(corrigerChaine(yytext),fichierProgEnC); fputs("'",fichierProgEnC);} else{ fputs("'",fichierFonction); fputs(corrigerChaine(yytext),fichierFonction); fputs("'",fichierFonction);}}else{ if(niveauFonct == 0) fputs(yytext,fichierProgEnC); else fputs(yytext,fichierFonction);}}}}| IDENT {prendreTypeAff(yytext,2); if(estInstrEcrireOuLire == 1){ stockerMessageIdent(yytext); } else { nature = 1; if(estAppelFonct == 0){typeAffDestValide(yytext,1);}}};
op_sym 		: SOMM {prendreSymOp(yytext); if(typeAffD != 3){ if(niveauFonct == 0) fputs(yytext,fichierProgEnC); else fputs(yytext,fichierFonction);}}| SOUSTR {prendreSymOp(yytext); if(typeAffD != 3){ if(niveauFonct == 0) fputs(yytext,fichierProgEnC); else fputs(yytext,fichierFonction);}}| PROD {prendreSymOp(yytext); if(typeAffD != 3){  if(niveauFonct == 0) fputs(yytext,fichierProgEnC); else fputs(yytext,fichierFonction);}}| DIV {prendreSymOp(yytext); if(typeAffD != 3){ if(niveauFonct == 0) fputs(yytext,fichierProgEnC); else fputs(yytext,fichierFonction);}} ;

expr_cond	: expr_log | NEG expr_log ;
expr_log 	: expr_log op_log expr_cmpr | PAR_OUV expr_log PAR_FERM | expr_cmpr ;
expr_cmpr	: expr_ar { exprComprEstValide(typeAffD); typeAffD = 0;} op_cmpr expr_ar { exprComprEstValide(typeAffD);} ;
op_cmpr		: INF | SUP | EG | INF_EG | SUP_EG | DIFF; 
op_log  	: CONJ | DISJ ;


condition	: SI expr_cond ALORS ls_instruction FIN {if(niveauFonct == 0) fputs("}\n",fichierProgEnC); else fputs("}\n",fichierFonction);} | SI expr_cond ALORS ls_instruction SINON ls_instruction FIN {if(niveauFonct == 0)  fputs("}\n",fichierProgEnC); else fputs("}\n",fichierFonction);};
switch 		: SELON IDENT{typeVarSwitchEstValide(typeAffDO); if(niveauFonct == 0) fputs(" ){\n",fichierProgEnC); else fputs(" ){\n",fichierFonction);} les_cas FIN {if(niveauFonct == 0) fputs("}\n",fichierProgEnC); else fputs("}\n",fichierFonction);};
les_cas 	: les_cas un_cas | un_cas;
un_cas		: CAS expr_ar{typeCasEstValide(typeAffD);} FAIRE{if(niveauFonct == 0) fputs(":\n{\n",fichierProgEnC); else fputs(":\n{\n",fichierFonction);} ls_instruction FIN {if(niveauFonct == 0) fputs("break;\n}\n",fichierProgEnC); else fputs("break;\n}\n",fichierFonction);}; 

boucle 		: b_pour | b_tque | b_ftque;
b_pour      : DXPT POUR{if(niveauFonct == 0) fputs("for(",fichierProgEnC); else fputs("for(",fichierFonction);} IDENT{typeVarPourEstValide();prendreIdentPour(yytext);} DE{if(niveauFonct == 0) fputs("=",fichierProgEnC); else fputs("=",fichierFonction);} expr_ar{if(niveauFonct == 0) fputs("; ",fichierProgEnC); else fputs("; ",fichierFonction);} JUSQUA expr_cond {if(niveauFonct == 0) fputs("; ",fichierProgEnC); else fputs("; ",fichierFonction);} le_pas FAIRE{if(niveauFonct == 0) fputs("){\n",fichierProgEnC); else fputs("){\n",fichierFonction);} ls_instruction FIN{if(niveauFonct == 0) fputs("}\n",fichierProgEnC); else fputs("}\n",fichierFonction);};
le_pas		: PAS{if(niveauFonct == 0) {fputs(identPour,fichierProgEnC);fputs("+=",fichierProgEnC);} else {fputs(identPour,fichierFonction);fputs("+=",fichierFonction);}} oper{typePasEstValide();} |{if(niveauFonct == 0) fputs("1",fichierProgEnC); else fputs("1",fichierFonction);};
b_tque 		: DXPT TANTQUE {if(niveauFonct == 0) {fputs("while( ",fichierProgEnC);} else {fputs("while( ",fichierFonction);} estBoucle = 1;} expr_cond FAIRE{if(niveauFonct == 0) fputs(" ){\n",fichierProgEnC); else fputs(" ){\n",fichierFonction); estBoucle = 0;} ls_instruction FIN{if(niveauFonct == 0) fputs("}\n",fichierProgEnC); else fputs("}\n",fichierFonction); boucleTQueFinie = 1;};
b_ftque 	: DXPT FAIRE{if(niveauFonct == 0) fputs("do{\n",fichierProgEnC); else fputs("do{\n",fichierFonction);} ls_instruction TANTQUE {if(niveauFonct == 0) {fputs("}while( ",fichierProgEnC);} else {fputs("}while( ",fichierFonction);} estBoucle = 1;}  expr_cond FIN{if(niveauFonct == 0) fputs(");\n",fichierProgEnC); else fputs(");\n",fichierFonction);  boucleFTQueFinie = 1; estBoucle = 0;};

routine 	: FONCTION {estFonction = 1;} IDENT{prendreNomFonction(yytext); fonctionEstValide(yytext);} PAR_OUV ls_param PAR_FERM rout_spec{ecrireEnteteFonct(); empilerFonction(&pileFoncs); niveauFonct++; finDeclaration = 0; estFonction = 0;} declaration DEBUT ls_instruction ret FIN{niveauFonct--;};
ls_param	: ls_param VIRG param | param |;
param 		: IDENT{if(estInstrEcrireOuLire == 1){ prendreTypeAff(yytext,2); prendreNomIdent(yytext);} if(estFonction == 1){prendreNomParametre(yytext);}} DXPT type{if(estInstrEcrireOuLire == 1){prendreTypeLire(yytext);} if(estFonction == 1){prendreTypeDec(yytext); associerType();}};
rout_spec 	: DXPT type{prendreTypeRetoure(yytext);} |{ExFonction.typeRetoure = 0};
ret			: RETOURNE{fputs("return ",fichierFonction);typeAffG = 0; typeAffD = 0; estRetourne = 1;} expr_ar{verifierTypeRetoure();} PTVIRG{fputs(";\n}\n",fichierFonction); estRetourne = 0;} |{if(ExFonction.typeRetoure != 0) printf("( la ligne %d ) ERREUR : la fonction \" %s \" doit retourner une donne.\n",lineNumber,ExFonction.nomFonction); fputs("}\n",fichierFonction);};

appel_fonct : DXPT{estAppelFonct = 1; typeAffG_appelFonct = typeAffG; typeAffG = 0; nomFonctEstPasse = 0;} IDENT{nomFonctEstPasse = 1; fonctionExiste(yytext); if(typeAffG_appelFonct == 3 && erreur == 0){ strcat(affAppeleFonct,yytext); } chaineParametres = NULL;} PAR_OUV{if(niveauFonct == 0) fputs("(",fichierProgEnC); else fputs("(",fichierFonction); if(typeAffG_appelFonct == 3 && erreur == 0) strcat(affAppeleFonct,"("); numArgum = 1; debutInstrAff = 0; } ls_argument PAR_FERM {  ecrireLsParametres(); fonctAParams(nomF); verefierNbrArgums(); if(niveauFonct == 0) fputs(")",fichierProgEnC); else fputs(")",fichierFonction); nomFonctEstPasse = 0; if(typeAffG_appelFonct == 3 && erreur == 0){ comleterAffAppeleFonct();} estAppelFonct = 0;} 
ls_argument : ls_argument VIRG oper{argumentEstValide(yytext); numArgum++;} | oper{argumentEstValide(yytext); numArgum++;} | {fonctNAPasParams(nomF);};

es_std		: e_std | s_std ;
e_std		: LIRE{viderChaines(); if(niveauFonct == 0) fputs("scanf",fichierProgEnC); else fputs("scanf",fichierFonction);} PAR_OUV{if(niveauFonct == 0) fputs("(",fichierProgEnC); else fputs("(",fichierFonction);} ls_param{formerMeg();} PAR_FERM{if(niveauFonct == 0) fputs(")",fichierProgEnC); else fputs(")",fichierFonction);} PTVIRG{if(niveauFonct == 0) fputs(";\n",fichierProgEnC); else fputs(";\n",fichierFonction); estInstrEcrireOuLire = 0};
s_std		: ECRIRE{viderChaines(); if(niveauFonct == 0) fputs("printf",fichierProgEnC); else fputs("printf",fichierFonction);} PAR_OUV{if(niveauFonct == 0) fputs("(",fichierProgEnC); else fputs("(",fichierFonction);} msg{formerMeg();} PAR_FERM{if(niveauFonct == 0) fputs(")",fichierProgEnC); else fputs(")",fichierFonction);} PTVIRG{if(niveauFonct == 0) fputs(";\n",fichierProgEnC); else fputs(";\n",fichierFonction); estInstrEcrireOuLire = 0};
msg		: msg VIRG oper | oper ;
%%


void yyerror( const char * msg){
	printf("line %d : %s \n", lineNumber, msg);

}
int main(int argc,char ** argv){
	if(argc>1) yyin=fopen(argv[1],"r"); 
	/* declaration et creation de la pile des identifiant */
	pileIdentifiants = creerPileIdentifes();
	/* declaration et creation de la pile des valeurs des constantes */
	pileConstantes = creerPileConsts();
	/* initialiser estNomProgramme qui va etre utiliser apre pour stocker le nom du programme */
	estNomProgramme = 0;
	/* initialiser finDeclaration qui va etre utiliser apres pour marker la fin de la declaration */
	finDeclaration = 0;
	/* aucune variable n'est encore declare dans le fichier .c */
	nbrVarDecEnC = 0;
	/* aucune constante  n'est encore declare dans le fichier .c */
	nbrConstDecEnC = 0;
	/* initialiser la variable qui va s'occuper de l'affechage des instruction d'ecreture */
	estInstrEcrireOuLire = 0;
	estFormateur = 0;
	estFonction = 0;
	estAppelFonct = 0;
	nomFonctEstPasse = 0;
	typeAffG_appelFonct = 0;
	erreur = 0;
	estRetourne = 0;
	estBoucle = 0;
	/* declaration et creation de des piles utilisees */
	pileFoncs = creerPileFoncts();
	overtureFichierFonction();
	overtureFichierHeader();
	overtureFichierVarGlobale();
	printf("DEBUT compilation : \n");
	lineNumber=1;
	if(!yyparse()) printf("FIN compilation : \n");
	return 0;
}

/*####################################### LES FONCTIONS DE L'ANALYSE SYMENTIQUE #########################*/

void saisirNomProgramme(char * identif){
	nomProgramme = malloc((strlen(identif)+1)*sizeof(char));
	if(nomProgramme == NULL){
		printf("ERREUR : problemme dans l'allocation dynamique de la memoire en ( dans saisirNomProgramme ).\n");
		exit(1);
	}
	strcpy(nomProgramme,identif);
	estNomProgramme = 1; // 0 pour dir a la fonction identEstValide que cet identifiant est le nom du programme il  ne faut pas le stocker dans la pile des identifiants.
}

void identEstValide(char *identifiant){
	FILE* fichierMotsCles = NULL;
	int i = 0, trouve = 0;
	char mot[tailleMaxChaine] = "";
	
	// overture de fichier des mots cles 
	fichierMotsCles = fopen("motsCles.txt","r");
	if(fichierMotsCles == NULL){
		printf("ERREUR : probleme d'overture du fichier des mots cles.\n");
		exit(1);
	}

	// verifier si l'identifiant n'est pas un mot cle du langege
	do{
		fgets(mot,tailleMaxChaine,fichierMotsCles);
		if(strcmp(mot,identifiant) == 0){
			printf("( la ligne %d ) ERREUR : le mot \" %s \" est reserve (c'est un mot cle)\n.",lineNumber,identifiant);
			trouve = 1;
			return;
		}
	}while(!feof(fichierMotsCles));
	fclose(fichierMotsCles); 

	 // si l'identifiant n'est pas un mot cle 
	if(trouve == 0){
		//printf("( la ligne %d ) la variable qui a l'identifiant \" %s \" est declaree avec succe (etape 1).\n",lineNumber,identifiant);
		// verifier si l'identifiant n'est pas dejas declare
		if(estFonction == 1){ // la declaration des parametres d'une fonction
			if(ExFonction.listeParametres.nombreElement == 0){ 
				// si aucun identifiant n'est encors declare
				empilerIdentif(&(ExFonction.listeParametres),identifiant);
				//printf("( la ligne %d ) la variable qui a l'identifiant \" %s \" est declaree avec succe (etape 2-a).\n",lineNumber,identifiant);
			}
			else{ 
				// si on a dejas declare d'autre identifiant
				if(identifEstDeclarer(ExFonction.listeParametres,identifiant) == 1){
					// si il existe une autre variable dejas declaree dans la meme fonction qui prent le meme nom de la variable actuielle
					printf("( la ligne %d ) ERREUR : une variable nomee \" %s \" est deja declare.\n",lineNumber,identifiant);
					return;
				}
				else{
					// si aucune variable dejas decleree n'a le meme nom de la variable actuelle 
					empilerIdentif(&(ExFonction.listeParametres),identifiant);
					//printf("( la ligne %d ) la variable qui a l'identifiant \" %s \" est declaree avec succe (etape 2-b).\n",lineNumber,identifiant);
				}
			}
		}
		else{ // la declaration normale des variables
			if(pileIdentifiants.nombreElement == 0){ 
				// si aucun identifiant n'est encors declare
				empilerIdentif(&pileIdentifiants,identifiant);
				//printf("( la ligne %d ) la variable qui a l'identifiant \" %s \" est declaree avec succe (etape 2-a).\n",lineNumber,identifiant);
			}
			else{ 
				// si on a dejas declare d'autre identifiant
				if(identifEstDeclarer(pileIdentifiants,identifiant) == 1){
					// si il existe une autre variable dejas declaree dans la meme fonction qui prent le meme nom de la variable actuielle
					printf("( la ligne %d ) ERREUR : une variable nomee \" %s \" est deja declare.\n",lineNumber,identifiant);
					return;
				}
				else{
					// si aucune variable dejas decleree n'a le meme nom de la variable actuelle 
					empilerIdentif(&pileIdentifiants,identifiant);
					//printf("( la ligne %d ) la variable qui a l'identifiant \" %s \" est declaree avec succe (etape 2-b).\n",lineNumber,identifiant);
				}
			}
		}
	}
}

pileIdentifs creerPileIdentifes(){
	pileIdentifs pile;
	pile.nombreElement = 0;
	pile.premier = NULL;
	return pile;
}

void empilerIdentif(pileIdentifs *p,char *identif){
	p->nombreElement++;
	identifiant *elem = NULL;
	elem = malloc(sizeof(identifiant));
	if(elem == NULL){
		printf("ERREUR : probleme d'allocation dynamique de la memoire (dans empiler).\n");
		exit(1);
	}
	elem->mot = malloc((strlen(identif)+1)*sizeof(char));
	if(elem->mot == NULL){
		printf("ERREUR : probleme d'allocation dynamique de la memoire (dans empiler).\n");
		exit(1);
	}
	strcpy(elem->mot,identif);
	elem->numType = 0; // initialiser le numero du type de cet element pour qu'on puissent le detecter lorsqu'on veut lui associer son type apres 
	if(estVariable == 1) {
		elem->valVarChaine = NULL; // on a suposer que l'initialisation est interdit lors de la declaration
		elem->estInitialise = 0; // la variable n'est pas initialise il ne contient aucune valeur
		elem->estConst = 0; // c'est une variable
	}
	if(estConstante == 1){
		elem->estInitialise = 1; // la constante est toujour initialise a la declaration
		elem->estConst = 1; // c'est une constante
	}
	elem->niveauFonction = niveauFonct; // entrer le niveau de la fonction
	elem->suivant = malloc(sizeof(identifiant));
	if(elem->suivant == NULL){
		printf("ERREUR : probleme d'allocation dynamique de la memoire (dans empiler).\n");
		exit(1);
	}

	elem->suivant = p->premier;
	p->premier = elem;
}

int identifEstDeclarer(pileIdentifs p,char *identif){
	int i = 1;
	identifiant *elementCourant = malloc(sizeof(identifiant));
	if(elementCourant == NULL){
		printf("ERREUR : probleme d'allocation dynamique de la memoire (dans identifEstDeclarer).\n");
		exit(1);
	}
	elementCourant = p.premier;
	do{
		if(strcmp(elementCourant->mot,identif) == 0){
			if(elementCourant->niveauFonction == niveauFonct) return 1;// si la variable est declare dans la meme fonction
			else{
				if(finDeclaration == 1 && elementCourant->estConst == 0){
					varEstGlobale = 1;// on presise que la variable est globale donc on doit l'ecrire dans fichierVarGlobale
					fputs("\nextern ",fichierVarGlobale);
					if(elementCourant->numType == 1) fputs("int ",fichierVarGlobale);
					if(elementCourant->numType == 2) fputs("double ",fichierVarGlobale);
					if(elementCourant->numType == 3) fputs("char *",fichierVarGlobale);
					if(elementCourant->numType == 4) fputs("char ",fichierVarGlobale);
				}
				return 2;// si la variable est declare dans une fonction pere de la fonction actuielle
			}
		}
		elementCourant = elementCourant->suivant;
		i++;
	}while(elementCourant != NULL);
	free(elementCourant);
	return 0; // si l'identifiant n'est pas trouve
}

void variableEstDeclaree(pileIdentifs p,char *identif){
	int identifEstTrouve = identifEstDeclarer(p,identif);
	if(identifEstTrouve == 1 || identifEstTrouve == 2){ 
		//printf("( la ligne %d ) la variable\" %s \" est dejas declaree tu peut l'utiliser.\n",lineNumber,identif);
	}
	else{
		printf("( la ligne %d ) ERREUR : la variable \" %s \" n'est pas encors declaree tu doit la declare dabord.\n",lineNumber,identif);
		erreur = 1;
	}
}

/*####################################### LES FONCTIONS DE LA GENERATION DE CODE #########################*/

void overtureFichierC(char *nomAlgo){
	fichierProgEnC = NULL;
	char *nomFichierProgEnC = NULL;

	// stocker le nom du programme suivie d'un .c dans la variable nomFichierProgEnC
	nomFichierProgEnC = malloc((strlen(nomAlgo)+3)*sizeof(char));
	if(nomFichierProgEnC == NULL){
		printf("ERREUR : probleme d'allocation dynamique de la memoire ( dans overtureFichierC ).\n");
		exit(1);
	}
	strcpy(nomFichierProgEnC,nomAlgo);
	strcat(nomFichierProgEnC,".c");
	// overture du fichier .c qui va contenire la convertion du programme source en c
	fichierProgEnC = fopen(nomFichierProgEnC,"w");
	if(fichierProgEnC == NULL){
		printf("ERREUR : probleme d'allocation dynamique de la memoire ( dans overtureFichierC ).\n");
		exit(1);
	}
	fputs("#include <stdio.h>\n",fichierProgEnC);
	fputs("#include <string.h>\n",fichierProgEnC);
	fputs("#include <stdlib.h>\n",fichierProgEnC);
	fputs("#include \"header.h\"\n",fichierProgEnC);
}

void declarationEnReChCa(char *typeVouC){
	int i;
	int nbrVarADeclarer; // le nombre de variable que cette fonction va declares dans le fichier .c
	int nbrConstADeclarer; // le nombre de constantes que cette fonction va declares dans le fichier .c
	char *leType = NULL;
	identifiant *varOuConst = NULL;
	constante *cst = NULL;

	// determination du type de la variable ou la constante
	if(strcmp(typeVouC,"entier") == 0){ // le type entier
		leType = malloc(5*sizeof(char));
		if(leType == NULL){
			printf("ERREUR : probleme d'allocation dynamique de la memoire (dans declarationEnReChCa).\n ");
			exit(1);
		}
		strcpy(leType,"int ");
	}
	if(strcmp(typeVouC,"reel") == 0){ // le type reel
		leType = malloc(8*sizeof(char));
		if(leType == NULL){
			printf("ERREUR : probleme d'allocation dynamique de la memoire (dans declarationEnReChCa).\n ");
			exit(1);
		}
		strcpy(leType,"double ");
	}
	if(strcmp(typeVouC,"chaine") == 0){ // le type chaine
		leType = malloc(5*sizeof(char));
		if(leType == NULL){
			printf("ERREUR : probleme d'allocation dynamique de la memoire (dans declarationEnReChCa).\n ");
			exit(1);
		}
		strcpy(leType,"char");
	}
	if(strcmp(typeVouC,"caractere") == 0){ // le type caractere
		leType = malloc(6*sizeof(char));
		if(leType == NULL){
			printf("ERREUR : probleme d'allocation dynamique de la memoire (dans declarationEnReChCa).\n ");
			exit(1);
		}
		strcpy(leType,"char ");
	}

	// la declaration des variables dans le fichier .c 
	if(estVariable == 1){
		nbrVarADeclarer = pileIdentifiants.nombreElement - nbrConstDecEnC - nbrVarDecEnC; 
		varOuConst = malloc(sizeof(identifiant));
		if(varOuConst == NULL){
			printf("ERREUR : probleme d'allocation dynamique de la memoire (dans declarationEnReChCa).\n");
			exit(1);
		}
		varOuConst = pileIdentifiants.premier;
		if(strcmp(leType,"char") == 0 && strcmp(typeVouC,"chaine") == 0){ // si la variable est de type chaine de caractere
			for(i=1; i<=nbrVarADeclarer; i++){
				if(i == 1){
					if(niveauFonct == 0) fputs(leType,fichierProgEnC);
					else{
						fputs(leType,fichierFonction);
					}
				}
				if(i != nbrVarADeclarer){
					if(niveauFonct == 0) fprintf(fichierProgEnC,"*%s ,",varOuConst->mot);
					else fprintf(fichierFonction,"*%s ,",varOuConst->mot);
					varOuConst = varOuConst->suivant;
				}
				else{
					if(niveauFonct == 0) fprintf(fichierProgEnC," *%s;\n",varOuConst->mot);
					else fprintf(fichierFonction," *%s;\n",varOuConst->mot);
				}
			}
		}
		else{ // si la variable est de type autre que chaine
			for(i=1; i<=nbrVarADeclarer; i++){
				if(i == 1){
					if(niveauFonct == 0) fputs(leType,fichierProgEnC);
					else fputs(leType,fichierFonction);
				}
				if(i != nbrVarADeclarer){
					if(niveauFonct == 0) fprintf(fichierProgEnC,"%s ,",varOuConst->mot);
					else fprintf(fichierFonction,"%s ,",varOuConst->mot);
					varOuConst = varOuConst->suivant;
				}
				else{
					if(niveauFonct == 0) fprintf(fichierProgEnC,"%s;\n",varOuConst->mot);
					else fprintf(fichierFonction,"%s;\n",varOuConst->mot);
				}
			}
		}
		nbrVarDecEnC = nbrVarDecEnC + nbrVarADeclarer;/* ajouter le nombre de variables declares dans cette fonction
		au nombre des variables qu'on a dejas declares */ 
	}

	// la declaration des constantes dans le fichier .c
	if(estConstante == 1){
		nbrConstADeclarer = pileIdentifiants.nombreElement - nbrVarDecEnC - nbrConstDecEnC;
		varOuConst = malloc(sizeof(identifiant));
		if(varOuConst == NULL){
			printf("ERREUR : probleme d'allocation dynamique de la memoire (dans declarationEnReChCa).\n");
			exit(1);
		}
		varOuConst = pileIdentifiants.premier;
		
		cst = malloc(sizeof(constante));
		if(cst == NULL){
			printf("ERREUR : probleme d'allocation dynamique de la memoire (dans declarationEnReChCa).\n");
			exit(1);
		}
		cst = pileConstantes.premier;
		
		for(i=0; i<nbrConstADeclarer; i++){
			if(niveauFonct == 0){
				fputs("const ",fichierProgEnC);
				fputs(leType,fichierProgEnC);
			}
			else{
				fputs("const ",fichierFonction);
				fputs(leType,fichierFonction);
			}
			
			if(strcmp(leType,"char") == 0 && strcmp(typeVouC,"chaine") == 0){ // si la constante est du type chaine
				if(niveauFonct == 0) fprintf(fichierProgEnC," %s[] = %s;\n",varOuConst->mot,cst->valConstanteS);
				else fprintf(fichierFonction," %s[] = %s;\n",varOuConst->mot,cst->valConstanteS);
				varOuConst = varOuConst->suivant;
				cst = cst->suivant;
			}
			if(strcmp(leType,"double ") == 0){ // si la constante est de type reel
				if(niveauFonct == 0) fprintf(fichierProgEnC,"%s = %lf;\n",varOuConst->mot,cst->valConstanteD);
				else fprintf(fichierFonction,"%s = %lf;\n",varOuConst->mot,cst->valConstanteD);
				varOuConst = varOuConst->suivant;
				cst = cst->suivant;
			}
			if(strcmp(leType,"int ") == 0){ // si la constante est du type entier
				if(niveauFonct == 0) fprintf(fichierProgEnC,"%s = %d;\n",varOuConst->mot,cst->valConstanteE);
				else fprintf(fichierFonction,"%s = %d;\n",varOuConst->mot,cst->valConstanteE);
				varOuConst = varOuConst->suivant;
				cst = cst->suivant;
			}
			if(strcmp(leType,"char ") == 0 && strcmp(typeVouC,"caractere") == 0){ // si la constante est du type caractere
				if(niveauFonct == 0) fprintf(fichierProgEnC,"%s = \'%c\';\n",varOuConst->mot,cst->valConstanteC);
				else fprintf(fichierFonction,"%s = \'%c\';\n",varOuConst->mot,cst->valConstanteC);
				varOuConst = varOuConst->suivant;
				cst = cst->suivant;
			}
		}
		nbrConstDecEnC = nbrConstDecEnC + nbrConstADeclarer;/* ajouter le nombre de constantes declares dans cette fonction
		au nombre des constantes qu'on a dejas declares */ 
	}
	
}

pileValConst creerPileConsts(){
	pileValConst pile;
	pile.nombreConstantes = 0;
	pile.premier = NULL;
	return pile;
}

void prendreValConst(char * valeurC){
	valConstante = malloc((strlen(valeurC)+1)*sizeof(char));
	if(valConstante == NULL){
		printf("ERREUR : probleme d'allocation dynamique de la memoire (dans prendreValConst).\n");
		exit(1);
	}
	strcpy(valConstante,valeurC);
}

void prendreNomConst(char *nom){
	nomConstante = malloc((strlen(nom)+1)*sizeof(char));
	if(nomConstante == NULL){
		printf("ERREUR : probleme d'allocation dynamique de la memoire (dans prendreNomConst).\n");
		exit(1);
	}
	strcpy(nomConstante,nom);
}

void empilerValConst(pileValConst *p,pileIdentifs *pE, char *typeC){
	constante *elementCourant = NULL;
	identifiant *elem = NULL;
	elementCourant = malloc(sizeof(constante));
	if(elementCourant == NULL){
		printf("ERREUR : probleme d'allocation de la memoire dans (empilerValConst).\n");
		exit(1);
	}
	p->nombreConstantes++;
	if(strcmp(typeC,"entier") == 0){ // si la constante est de type entier 
		elementCourant->valConstanteE = atoi(valConstante);
	}
	if(strcmp(typeC,"reel") == 0){ // si la constante est de type reel
		elementCourant->valConstanteD = atof(valConstante);
	}
	if(strcmp(typeC,"caractere") == 0){ // si la constante est de type caractere
		elementCourant->valConstanteC = valConstante[1];

		// stocker la valeur de la constante dans la pile des identifiants
		elem = malloc(sizeof(identifiant));
		if(elem == NULL){
			printf("ERREUR : probleme d'allocation dynamique de la memoire (dans empiler).\n");
			exit(1);
		}
		elem = pE->premier;
		while(elem != NULL){
			if(strcmp(elem->mot,nomConstante) == 0){
				elem->valVarChaine = malloc((strlen(valConstante)+1)*sizeof(char));
				if(elem->valVarChaine == NULL){
					printf("ERREUR : probleme d'allocation dynamique de la memoire dans (dans empilerValConst).\n");
					exit(1);
				}
				strcpy(elem->valVarChaine,valConstante);
				break;
			}
			elem = elem->suivant;
		}
	}
	if(strcmp(typeC,"chaine") == 0){ // si la constante est de type chaine  
		// stocker la valeur de la constante dans la pile des valeur des constantes
		elementCourant->valConstanteS = malloc((strlen(valConstante)+1)*sizeof(char));
		if(elementCourant->valConstanteS == NULL){
			printf("ERREUR : problemme d'allocation dynamique de la memoire (dans empilerValConst).\n");
			exit(1);
		}
		strcpy(elementCourant->valConstanteS,valConstante);

		// stocker la valeur de la constante dans la pile des identifiants
		elem = malloc(sizeof(identifiant));
		if(elem == NULL){
			printf("ERREUR : probleme d'allocation dynamique de la memoire (dans empiler).\n");
			exit(1);
		}
		elem = pE->premier;
		while(elem != NULL){
			if(strcmp(elem->mot,nomConstante) == 0){
				elem->valVarChaine = malloc((strlen(valConstante)+1)*sizeof(char));
				if(elem->valVarChaine == NULL){
					printf("ERREUR : probleme d'allocation dynamique de la memoire dans (dans empilerValConst).\n");
					exit(1);
				}
				strcpy(elem->valVarChaine,valConstante);
				break;
			}
			elem = elem->suivant;
		}
	}
	elementCourant->suivant = p->premier;
	p->premier = elementCourant;
}

void prendreTypeDec(char *typeVC){
	if(strcmp(typeVC,"entier") == 0){ // le type entier
		numeroType = 1;
	}
	if(strcmp(typeVC,"reel") == 0){ // le type reel
		numeroType = 2;
	}
	if(strcmp(typeVC,"chaine") == 0){ // le type chaine
		numeroType = 3;
	}
	if(strcmp(typeVC,"caractere") == 0){ // le type caractere
		numeroType = 4;
	}
}

void associerType(){
	identifiant *elem = NULL;
	elem = malloc(sizeof(identifiant));
	if(elem == NULL){
		printf("ERREUR : probleme d'allocation dynamique de la memoire dans (dans associerType).\n");
		exit(1);
	}
	if(estFonction == 1) elem = ExFonction.listeParametres.premier;
	else elem = pileIdentifiants.premier;
	while(elem != NULL && elem->numType == 0){
		elem->numType = numeroType;
		elem = elem->suivant;
	}
}

void prendreTypeAff(char *ident,int direction){ // direction : 1- pour gauche et 2- pour droite
	int i=0;
	int limiteEntreVarConst; // la limite entre les variables est les constantes
	identifiant *elem = NULL;
	elem = malloc(sizeof(identifiant));
	if(elem == NULL){
		printf("ERREUR : probleme d'allocation dynamique de la memoire dans (dans associerType).\n");
		exit(1);
	}
	elem = pileIdentifiants.premier;
	while(elem != NULL){
		i++;
		if(strcmp(ident,elem->mot) == 0){
			if(direction == 1 && debutInstrAff == 1){// si on est au debut de l'instruction de l'affectation
				typeAffD = 0; // initialiser typeAffD pour une nouvelle affectation
				typeAffG = elem->numType;
				elem->estInitialise = 1; // pour s'assurer la prochaine fois qu'on utilise cette variable qu'elle est dejas initialise 

				if(elem->estConst == 1 && estRetourne == 0 && estBoucle == 0){ // si l'affectation essaye de modifier une constante
					printf("( la ligne %d ) ERREUR : \" %s \" est une constante tu ne peut pas changer sa valeur.\n",lineNumber,ident);
				}
			} 
			if(direction == 2 && debutInstrAff == 0){ 
				typeAffDO = elem->numType;
				if(estInstrEcrireOuLire != 1) identifEstInitialise(ident); // pour savoire que la variable est initialise ou non si on est dans une affectation
			}
			return;
		}
		elem = elem->suivant;
	}
}

void identifEstInitialise(char *ident){
	identifiant *elem = NULL;
	elem = malloc(sizeof(identifiant));
	if(elem == NULL){
		printf("ERREUR : probleme d'allocation dynamique de la memoire dans (dans associerType).\n");
		exit(1);
	}
	elem = pileIdentifiants.premier;

	while(elem != NULL){
		if(strcmp(ident,elem->mot) == 0){
			if(elem->estInitialise == 0){
				printf("( la ligne %d ) ERREUR : \" %s \" n'est pas initialise.\n",lineNumber,ident);
				break;
			}
		}
		elem = elem->suivant;
	}
}

void prendreSymOp(char *symbole){
	if(strcmp(symbole,"+") == 0) symboleOperation = 1;
	if(strcmp(symbole,"-") == 0) symboleOperation = 2;
	if(strcmp(symbole,"*") == 0) symboleOperation = 3;
	if(strcmp(symbole,"/") == 0) symboleOperation = 4;   
}

void prendreChaine(char *chainePr,int nature){
	identifiant *elem = NULL;
	if(nature == 1){ // si on traite une variable de type chaine
		if(vallCouVexiste(chainePr) == 0){ // si on a pas initialiser une variable de type chaine
			printf("( la ligne %d ) ERREUR : la variable %s n'est pas initialisee.\n",lineNumber,chainePr);
			return;
		}
		else{ // si on a dejas initialiser la variable de type chaine
			elem = malloc(sizeof(identifiant));
			if(elem == NULL){
				printf("ERREUR : probleme d'allocation dynamique de la memoire dans (dans associerType).\n");
				exit(1);
			}
			elem = pileIdentifiants.premier;
			while(elem != NULL){
				if(strcmp(chainePr,elem->mot) == 0){
					strcpy(elem->valVarChaine,corrigerChaine(elem->valVarChaine));
					chainePrincipale = malloc((strlen(elem->valVarChaine)+1)*sizeof(char));
					if(chainePrincipale == NULL){
						printf("ERREUR : probleme d'allocation dynamique de la memoire dans (prendreChaine).\n");
						exit(1);
					}
					
					if(elem->valVarChaine != NULL) strcpy(chainePrincipale,elem->valVarChaine);  
					break;
				}
				elem = elem->suivant;
			}
		}
	}
	else{ // si on traite une valeur de type chaine
		strcpy(chainePr,corrigerChaine(chainePr));
		chainePrincipale = malloc((strlen(chainePr)+1)*sizeof(char));
		if(chainePrincipale == NULL){
			printf("ERREUR : probleme d'allocation dynamique de la memoire dans (prendreChaine).\n");
			exit(1);
		}
		strcpy(chainePrincipale,chainePr);
	}	
}

void typeAffDestValide(char *identOuVal,int nature){
	identifiant *elem = NULL;
	if(typeAffD == 0){ // si on a tombe dans le premeir operande 
		typeAffD = typeAffDO; 
		if(typeAffDO == 4 && typeAffG == 3) typeAffD = 3;  // si le premier operande est un caractere et typeAffG = 3 on va le considerer comme une chaine 
		// comparaison du type de la partie gauche et le type de la partie droite de l'affectation
		if((typeAffG == 1 || typeAffG == 2 || typeAffG == 4) && typeAffD == 3){
			printf("( la ligne %d ) ERREUR : le type de \" %s \" est incompatible.\n",lineNumber,identOuVal);
			return;
		}
		if(typeAffG == 3 && (typeAffD == 1 || typeAffD == 2 || typeAffD == 4)){
			printf("( la ligne %d ) ERREUR : le type de \" %s \" est incompatible.\n",lineNumber,identOuVal);
			return;
		}
		if(typeAffD == 3) prendreChaine(identOuVal,nature); // si cet operande est de type chaine
	}
	else{ // si on a dejas passe par d'autre operande 
		// comparaison du type de la partie gauche et le type de la partie droite de l'affectation
		if((typeAffG == 1 || typeAffG == 2 || typeAffG == 4) && typeAffD == 3){
			printf("( la ligne %d ) ERREUR : le type de \" %s \" est incompatible.\n ",lineNumber,identOuVal);
			return;
		}
		if(typeAffG == 3 && (typeAffD == 1 || typeAffD == 2 || typeAffD == 4)){
			printf("( la ligne %d ) ERREUR : le type de \" %s \" est incompatible.\n ",lineNumber,identOuVal);
			return;
		}
		// comparaison du type de l'operande actuile et le type de l'expretion arethmetique precedent
		// les cas ou les types son incompatible
		if(typeAffD == 1 || typeAffD == 2 || typeAffD == 4 ){
			if(typeAffDO == 3){
				printf("( la ligne %d ) ERREUR : operation impossible le type de \" %s \" est incompatible.\n",lineNumber,identOuVal);
				return;
			}
			else{
				typeAffD = 2; // quel que soit le type de l'expresion precedent on va toujour garder le resultat comme etant une valeur reel 
			}
		}
		if(typeAffD == 3){ // les operation entre les chaines
			
			if(typeAffDO == 1 || typeAffDO == 2){
				printf("( la ligne %d ) ERREUR : operation impossible le type de \" %s \" est incompatible.\n",lineNumber,identOuVal);
				return;
			}
			else{
				if(symboleOperation == 2 || symboleOperation == 3 || symboleOperation == 4){
					if(symboleOperation == 2) printf("( la ligne %d ) ERREUR : l'operation \" - \" est imposible dans le type chaine.\n",lineNumber);
					if(symboleOperation == 3) printf("( la ligne %d ) ERREUR : l'operation \" * \" est imposible dans le type chaine.\n",lineNumber);
					if(symboleOperation == 4) printf("( la ligne %d ) ERREUR : l'operation \" / \" est imposible dans le type chaine.\n",lineNumber);
					return;
				}
				if(symboleOperation == 1){ // la concatenation
					
					if(nature == 1){ // si on traite une variable de type chaine 
						if(vallCouVexiste(identOuVal) == 0){ // si la variable n'est pas initialise
							printf("( la ligne %d ) ERREUR : la variable %s n'est pas initialisee.\n",lineNumber,identOuVal);
							return;
						}
						else{ // si on a dejas initialiser la variable de type chaine
							elem = malloc(sizeof(identifiant));
							if(elem == NULL){
								printf("ERREUR : probleme d'allocation dynamique de la memoire dans (dans associerType).\n");
								exit(1);
							}
							elem = pileIdentifiants.premier;
							// on garde la valeur qui est stocker dans chainePrincipale 
							chaineSecondere = malloc((strlen(chainePrincipale)+1)*sizeof(char));
							if(chaineSecondere == NULL){
								printf("ERREUR : probleme d'allocation dynamique de la memoire dans (typeAffDestValide).\n");
								exit(1);
							}
							strcpy(chaineSecondere,chainePrincipale);
							free(chainePrincipale);
							chainePrincipale = NULL;

							while(elem != NULL){
								if(strcmp(identOuVal,elem->mot) == 0){
									strcpy(elem->valVarChaine,corrigerChaine(elem->valVarChaine));
									chainePrincipale = malloc((strlen(chaineSecondere)+strlen(elem->valVarChaine)+1)*sizeof(char));
									if(chainePrincipale == NULL){
										printf("ERREUR : probleme d'allocation dynamique de la memoire dans (prendreChaine).\n");
										exit(1);
									}
									strcpy(chainePrincipale,chaineSecondere);
									strcat(chainePrincipale,elem->valVarChaine);
									return;
								}
								elem = elem->suivant;
							}
							
						}
					}
					else{
						
						chaineSecondere = malloc((strlen(chainePrincipale)+1)*sizeof(char));
						if(chaineSecondere == NULL){
							printf("ERREUR : probleme d'allocation dynamique de la memoire dans (typeAffDestValide).\n");
							exit(1);
						}
						strcpy(chaineSecondere,chainePrincipale);
						free(chainePrincipale);
						chainePrincipale = NULL;
						strcpy(identOuVal,corrigerChaine(identOuVal));
						chainePrincipale =  malloc((strlen(identOuVal)+strlen(chaineSecondere)+1)*sizeof(char));
						if(chainePrincipale == NULL){
							printf("ERREUR : probleme d'allocation dynamique de la memoire dans (typeAffDestValide).\n");
							exit(1); 
						}
						strcpy(chainePrincipale,chaineSecondere);
						strcat(chainePrincipale,identOuVal);
					}
					free(chaineSecondere);
					chaineSecondere = NULL;
				}
				
			}
		}
		
	}
}

int vallCouVexiste(char *ident){
	identifiant *elem = NULL;
	elem = malloc(sizeof(identifiant));
	if(elem == NULL){
		printf("ERREUR : probleme d'allocation dynamique de la memoire dans (dans associerType).\n");
		exit(1);
	}
	elem = pileIdentifiants.premier;
	while(elem != NULL){
		if(strcmp(ident,elem->mot) == 0){ 
			if(elem->valVarChaine == NULL && elem->estConst == 0) return 0;
			else return 1;
		}
		elem = elem->suivant;
	}
}

void prendreChSource(char *chaineS){
	chaineSource = malloc((strlen(chaineS)+1)*sizeof(char));
	if(chaineSource == NULL){
		printf("ERREUR : probleme d'allocation dynamique de la memoire dans (prendreChSource).\n");
		exit(1);
	}
	strcpy(chaineSource,chaineS);
}

void executerAffCh(){
	identifiant *elem = NULL;
	elem = malloc(sizeof(identifiant));
	if(elem == NULL){
		printf("ERREUR : probleme d'allocation dynamique de la memoire dans (dans associerType).\n");
		exit(1);
	}
	elem = pileIdentifiants.premier;
	while(elem != NULL){
		if(strcmp(chaineSource,elem->mot) == 0){
			elem->valVarChaine = malloc((strlen(chainePrincipale)+1)*sizeof(char));
			if(elem->valVarChaine == NULL){
				printf("ERREUR : probleme d'allocation dynamique de la memoire dans (executerAffCh).\n");
				exit(1);
			}
			strcpy(elem->valVarChaine,chainePrincipale);
			// ecreture dans le fichier
			if(niveauFonct == 0){
				fputs(chaineSource,fichierProgEnC);
				fputs(" = ",fichierProgEnC);
				fputs("malloc((strlen(\"",fichierProgEnC);
				fputs(chainePrincipale,fichierProgEnC);
				fputs("\")+1)*sizeof(char));\n",fichierProgEnC);
				fputs("if(",fichierProgEnC);
				fputs(chaineSource,fichierProgEnC);
				fputs(" == NULL){\nprintf(\"ERREUR : probleme d'allocation dynamique de la memoire.\");\nexit(1);\n}\n",fichierProgEnC);
				fputs("strcpy(",fichierProgEnC);
				fputs(chaineSource,fichierProgEnC);
				fputs(",\"",fichierProgEnC);
				fputs(chainePrincipale,fichierProgEnC);
				fputs("\");\n",fichierProgEnC);
			}
			else{
				fputs(chaineSource,fichierFonction);
				fputs(" = ",fichierFonction);
				fputs("malloc((strlen(\"",fichierFonction);
				fputs(chainePrincipale,fichierFonction);
				fputs("\")+1)*sizeof(char));\n",fichierFonction);
				fputs("if(",fichierFonction);
				fputs(chaineSource,fichierFonction);
				fputs(" == NULL){\nprintf(\"ERREUR : probleme d'allocation dynamique de la memoire.\");\nexit(1);\n}\n",fichierFonction);
				fputs("strcpy(",fichierFonction);
				fputs(chaineSource,fichierFonction);
				fputs(",\"",fichierFonction);
				fputs(chainePrincipale,fichierFonction);
				fputs("\");\n",fichierFonction);
			}

			free(chainePrincipale);
			chainePrincipale = NULL;
			free(chaineSource);
			chaineSource = NULL;
			return;
		}
		elem = elem->suivant;
	}
}

char *corrigerChaine(char *chaineNC){
	int i = 1,j;
	if(chaineNC[0] == '"'){
		chaineNC[0] = chaineNC[1];
		j = i;
		for(i=1;i<strlen(chaineNC)-1;i++){
			j++;
			chaineNC[i] = chaineNC[j];
		}
		chaineNC[i-1] = '\0';
	}
	return chaineNC;
}

void exprComprEstValide(int typeExpr){
	if(typeExpr == 3){
		printf("( la ligne %d ) ERREUR : la comparison est impossible dans le type chaine.\n",lineNumber);
	}
}

void typeVarSwitchEstValide(int typeVar){
	typeVarSwitch = typeVar;
	if(typeVar == 3){
		printf("( la ligne %d ) ERREUR : le type de la variable utilisee dans le switch doit etre different du type chaine.\n");
	}
}

void typeCasEstValide(int typeCas){// le cas ou la variable de switch est de type int et le type du cas est de type char ou le contraire est a voir apre
	if(typeVarSwitch != typeAffD){
		printf("( la ligne %d ) ERREUR : le type de la variable de switch est different du type de ce cas.\n",lineNumber);
	}
}

void stockerMessageCh(char *message){
	char *msg = NULL;
	if(chainePrincipale == NULL){
		chainePrincipale = malloc((strlen(message)+1)*sizeof(char));
		if(chainePrincipale == NULL){
			printf("ERREUR : probleme d'allocation dynamique de la memoire (dans stockerMessageCh).\n");
			exit(1);
		}
		strcpy(chainePrincipale,corrigerChaine(message));
	}
	else{
		msg = malloc((strlen(chainePrincipale)+1)*sizeof(char));
		if(msg == NULL){
			printf("ERREUR : probleme d'allocation dynamique de la memoire (dans stockerMessageCh).\n");
			exit(1);
		}
		strcpy(msg,chainePrincipale);
		free(chainePrincipale);
		chainePrincipale = NULL;
		chainePrincipale = malloc((strlen(msg)+strlen(message)+1)*sizeof(char));
		if(chainePrincipale == NULL){
			printf("ERREUR : probleme d'allocation dynamique de la memoire (dans stockerMessageCh).\n");
			exit(1);
		}
		strcpy(chainePrincipale,msg);
		if(estFormateur == 0) strcat(chainePrincipale,corrigerChaine(message));
		else strcat(chainePrincipale,message);
		free(msg);
		msg = NULL;
	}
}

void stockerMessageIdent(char *nomIdent){
	char *msg = NULL;
	// determination du formateur et l'ajoutter dans la chainePrincipale
	estFormateur = 1;
	if(typeAffDO == 1) stockerMessageCh("%d");
	if(typeAffDO == 2) stockerMessageCh("%lf");
	if(typeAffDO == 3) stockerMessageCh("%s");
	if(typeAffDO == 4) stockerMessageCh("%c");
	// stocker le nom de la variable 
	if(chaineSecondere == NULL){
		chaineSecondere = malloc((strlen(nomIdent)+2)*sizeof(char));
		if(chainePrincipale == NULL){
			printf("ERREUR : probleme d'allocation dynamique de la memoire (dans stockerMessageTdent).\n");
			exit(1);
		}
		strcpy(chaineSecondere,",");
		strcat(chaineSecondere,nomIdent);
	}
	else{
		msg = malloc((strlen(chaineSecondere)+1)*sizeof(char));
		if(msg == NULL){
			printf("ERREUR : probleme d'allocation dynamique de la memoire (dans stockerMessageCh).\n");
			exit(1);
		}
		strcpy(msg,chaineSecondere);
		free(chaineSecondere);
		chaineSecondere = NULL;
		chaineSecondere = malloc((strlen(msg)+strlen(nomIdent)+2)*sizeof(char));
		if(chaineSecondere == NULL){
			printf("ERREUR : probleme d'allocation dynamique de la memoire (dans stockerMessageCh).\n");
			exit(1);
		}
		strcpy(chaineSecondere,msg);
		strcat(chaineSecondere,",");
		strcat(chaineSecondere,nomIdent);
		free(msg);
		msg = NULL;
	}
	estFormateur = 0;
}

void formerMeg(){
	if(niveauFonct == 0){
		fputs("\"",fichierProgEnC);
		fputs(chainePrincipale,fichierProgEnC);
		fputs("\"",fichierProgEnC);
		fputs(chaineSecondere,fichierProgEnC);
	}
	else{
		fputs("\"",fichierFonction);
		fputs(chainePrincipale,fichierFonction);
		fputs("\"",fichierFonction);
		fputs(chaineSecondere,fichierFonction);
	}
}

void viderChaines(){
	free(chainePrincipale);
	chainePrincipale = NULL;
	free(chaineSecondere);
	chaineSecondere = NULL;
}

void prendreNomIdent(char *nomIdent){
	char *msg = NULL;
	// stocker le nom de la variable 
	if(chaineSecondere == NULL){
		chaineSecondere = malloc((strlen(nomIdent)+3)*sizeof(char));
		if(chaineSecondere == NULL){
			printf("ERREUR : probleme d'allocation dynamique de la memoire (dans prendreNomIdent).\n");
			exit(1);
		}
		strcpy(chaineSecondere,",&");
		strcat(chaineSecondere,nomIdent);
	}
	else{
		msg = malloc((strlen(chaineSecondere)+1)*sizeof(char));
		if(msg == NULL){
			printf("ERREUR : probleme d'allocation dynamique de la memoire (dans prendreNomIdent).\n");
			exit(1);
		}
		strcpy(msg,chaineSecondere);
		free(chaineSecondere);
		chaineSecondere = NULL;
		chaineSecondere = malloc((strlen(msg)+strlen(nomIdent)+3)*sizeof(char));
		if(chaineSecondere == NULL){
			printf("ERREUR : probleme d'allocation dynamique de la memoire (dans prendreNomIdent).\n");
			exit(1);
		}
		strcpy(chaineSecondere,msg);
		strcat(chaineSecondere,",&");
		strcat(chaineSecondere,nomIdent);
		free(msg);
		msg = NULL;
	}
}

void prendreTypeLire(char *type){
	char *msg = NULL;
	if(strcmp(type,"entier") == 0) typeAffD = 1;
	if(strcmp(type,"reel") == 0) typeAffD = 2;
	if(strcmp(type,"chaine") == 0) typeAffD = 3;
	if(strcmp(type,"caractere") == 0) typeAffD = 4;
	if(typeAffD != typeAffDO){
		if(erreur != 1) printf("( la ligne %d ) ERREUR : le type de la donne a stocke est different du type de la variable distinataire.\n",lineNumber);
		erreur = 0;
		return;
	}
	if(chainePrincipale == NULL){
		chainePrincipale = malloc(4*sizeof(char));
		if(chainePrincipale == NULL){
			printf("ERREUR : probleme d'allocation dynamique de la memoire (dans prendreTypeLire).\n");
			exit(1);
		}
		if(typeAffD == 1) strcpy(chainePrincipale,"%d");
		if(typeAffD == 2) strcpy(chainePrincipale,"%lf");
		if(typeAffD == 3) strcpy(chainePrincipale,"%s");
		if(typeAffD == 4) strcpy(chainePrincipale,"%c");
	}
	else{
		msg = malloc((strlen(chainePrincipale)+1)*sizeof(char));
		if(msg == NULL){
			printf("ERREUR : probleme d'allocation dynamique de la memoire (dans prendreTypeLire).\n");
			exit(1);
		}
		strcpy(msg,chainePrincipale);
		free(chainePrincipale);
		chainePrincipale = NULL;
		chainePrincipale = malloc((strlen(msg)+5)*sizeof(char));
		if(chainePrincipale == NULL){
			printf("ERREUR : probleme d'allocation dynamique de la memoire (dans prendreTypeLire).\n");
			exit(1);
		}
		strcpy(chainePrincipale,msg);
		if(typeAffD == 1) strcat(chainePrincipale," %d");
		if(typeAffD == 2) strcat(chainePrincipale," %lf");
		if(typeAffD == 3) strcat(chainePrincipale," %s");
		if(typeAffD == 4) strcat(chainePrincipale," %c");
		free(msg);
		msg = NULL;
	}
}

void prendreIdentPour(char *ident){
	identPour = malloc((strlen(ident)+1)*sizeof(char));
	if(identPour == NULL){
		printf("ERREUR : probleme d'allocation dynamique de la memoire (dans prendreIdentPour).\n");
		exit(1);
	}
	strcpy(identPour,ident);
}

void typeVarPourEstValide(){
	if(typeAffG == 3){
		printf("( la ligne %d ) ERREUR : Impossible d'utiliser une variable de type chaine comme compteur de la boucle Pour.\n",lineNumber);
	}
}

void typePasEstValide(){
	if(typeAffDO == 3){
		printf("( la ligne %d ) ERREUR : le type du Pas doit etre different du type chaine.\n",lineNumber);
		return;
	}
	if(typeAffDO != typeAffG){
		printf("( la ligne %d ) ERREUR : le type du Pas est different du type de la variable utilisee comme compteur de la boucle Pour.\n",lineNumber);
	}
}

void prendreNomFonction(char *nomf){
	ExFonction.nomFonction = malloc((strlen(nomf)+1)*sizeof(char));
	if(ExFonction.nomFonction == NULL){
		printf("ERREUR : probleme d'allocation dynamique de la memoire (dans prendreNomFonction).\n");
		exit(1);
	}
	strcpy(ExFonction.nomFonction,nomf);
	ExFonction.listeParametres = creerPileIdentifes();
}

void prendreNomParametre(char *nomp){
	identEstValide(nomp);
}

void overtureFichierHeader(){
	fichierHeader = fopen("header.h","w");
	if(fichierHeader == NULL){
		printf("ERREUR : probleme d'overture du fichier header.h\n");
		exit(1);
	}
	fputs("#ifndef __header\n",fichierHeader);
	fputs("#define __header\n\n",fichierHeader);
}

void overtureFichierVarGlobale(){
	fichierVarGlobale = fopen("varGlobale.h","w");
	if(fichierVarGlobale == NULL){
		printf("ERREUR : probleme d'overture du fichier varGlobale.h\n");
		exit(1);
	}
	fputs("#ifndef __varGlobale\n",fichierVarGlobale);
	fputs("#define __varGlobale\n",fichierVarGlobale);
}

void overtureFichierFonction(){
	fichierFonction = fopen("fonction.c","w");
	if(fichierFonction == NULL){
		printf("ERREUR : probleme d'overture du fichier fonction.c\n");
		exit(1);
	}
	fputs("#include <stdio.h>\n",fichierFonction);
	fputs("#include <string.h>\n",fichierFonction);
	fputs("#include <stdlib.h>\n",fichierFonction);
	fputs("#include \"varGlobale.h\"\n",fichierFonction);
	fputs("#include \"header.h\"\n",fichierFonction);
}

void prendreTypeRetoure(char *type){
	if(strcmp(type,"entier") == 0){
		ExFonction.typeRetoure = 1;
	}
	if(strcmp(type,"reel") == 0){
		ExFonction.typeRetoure = 2;
	}
	if(strcmp(type,"chaine") == 0){
		ExFonction.typeRetoure = 3;
	}
	if(strcmp(type,"caractere") == 0){
		ExFonction.typeRetoure = 4;
	}
}

void ecrireEnteteFonct(){
	identifiant *elem = NULL;
	char *leType = NULL;
	if(ExFonction.typeRetoure == 0){
		fputs("void ",fichierFonction);
		fputs("void ",fichierHeader);
	}
	if(ExFonction.typeRetoure == 1){
		fputs("int ",fichierFonction);
		fputs("int ",fichierHeader);
	}
	if(ExFonction.typeRetoure == 2){
		fputs("double ",fichierFonction);
		fputs("double ",fichierHeader);
	}
	if(ExFonction.typeRetoure == 3){
		fputs("char *",fichierFonction);
		fputs("char *",fichierHeader);
	}
	if(ExFonction.typeRetoure == 4){
		fputs("char ",fichierFonction);
		fputs("char ",fichierHeader);
	}
	fputs(ExFonction.nomFonction,fichierFonction);
	fputs("(",fichierFonction);
	fputs(ExFonction.nomFonction,fichierHeader);
	fputs("(",fichierHeader);
	
	elem = malloc(sizeof(identifiant));
	if(elem == NULL){
		printf("ERREUR : probleme d'allocation dynamique de la memoire dans (dans associerType).\n");
		exit(1);
	}
	elem = ExFonction.listeParametres.premier;

	while(elem != NULL){
			// determination du type de la variable ou la constante
		if(elem->numType == 1){ // le type entier
			leType = malloc(5*sizeof(char));
			if(leType == NULL){
				printf("ERREUR : probleme d'allocation dynamique de la memoire (dans declarationEnReChCa).\n ");
				exit(1);
			}
			strcpy(leType,"int ");
		}
		if(elem->numType == 2){ // le type reel
			leType = malloc(8*sizeof(char));
			if(leType == NULL){
				printf("ERREUR : probleme d'allocation dynamique de la memoire (dans declarationEnReChCa).\n ");
				exit(1);
			}
			strcpy(leType,"double ");
		}
		if(elem->numType == 3){ // le type chaine
			leType = malloc(7*sizeof(char));
			if(leType == NULL){
				printf("ERREUR : probleme d'allocation dynamique de la memoire (dans declarationEnReChCa).\n ");
				exit(1);
			}
			strcpy(leType,"char *");
		}
		if(elem->numType == 4){ // le type caractere
			leType = malloc(6*sizeof(char));
			if(leType == NULL){
				printf("ERREUR : probleme d'allocation dynamique de la memoire (dans declarationEnReChCa).\n ");
				exit(1);
			}
			strcpy(leType,"char ");
		}

		fputs(leType,fichierFonction);
		fputs(elem->mot,fichierFonction);
		if(elem->suivant != NULL) fputs(", ",fichierFonction);
		fputs(leType,fichierHeader);
		fputs(elem->mot,fichierHeader);
		if(elem->suivant != NULL) fputs(", ",fichierHeader);

		elem = elem->suivant;
	}
	fputs("){\n",fichierFonction);
	fputs(");\n",fichierHeader);
}

void verifierTypeRetoure(){
	if(ExFonction.typeRetoure == 0 && typeAffD != 0){
		printf("( la ligne %d ) ERREUR : le fonction \" %s \" ne retourn rien.\n",lineNumber,ExFonction.nomFonction);
		return;
	}
	if(typeAffD != ExFonction.typeRetoure){
		printf("( la ligne %d ) ERREUR : le type du retoure est incompatible.\n",lineNumber);
		return;
	}
}

pileFonctions creerPileFoncts(){
	pileFonctions pile;
	pile.nombreFonction = 0;
	pile.premier = NULL;
}

void empilerFonction(pileFonctions *pileF){
	fonction *fonctInter = NULL;
	pileF->nombreFonction++;
	fonctInter = malloc(sizeof(fonction));
	if(fonctInter == NULL){
		printf("ERREUR : probleme d'allocation dynamique de la memoire (dans empilerFonction).\n");
		exit(1);
	}
	fonctInter->nomFonction = ExFonction.nomFonction;
	fonctInter->typeRetoure = ExFonction.typeRetoure;
	fonctInter->listeParametres.premier = ExFonction.listeParametres.premier;
	fonctInter->listeParametres.nombreElement = ExFonction.listeParametres.nombreElement;
	fonctInter->suivant = pileF->premier;
	pileF->premier = fonctInter;
}

void fonctionEstValide(char *nomFonct){
	fonction *fonctInter = NULL;
	fonctInter = malloc(sizeof(fonction));
	if(fonctInter == NULL){
		printf("ERREUR : probleme d'allocation dynamique de la memoire (dans empilerFonction).\n");
		exit(1);
	}
	fonctInter = pileFoncs.premier;
	while(fonctInter != NULL){
		if(strcmp(fonctInter->nomFonction,nomFonct) == 0){
			printf("( la ligne %d ) ERREUR : une fonction a le meme nom \" %s \" est dejas declare.\n",lineNumber,nomFonct);
		}
		fonctInter = fonctInter->suivant;
	}
	free(fonctInter);
	fonctInter = NULL;
}

void fonctionExiste(char *nomf){
	fonction *fonctInter = NULL;
	int trouve = 0;
	fonctInter = malloc(sizeof(fonction));
	if(fonctInter == NULL){
		printf("ERREUR : probleme d'allocation dynamique de la memoire (dans fonctionExiste).\n");
		exit(1);
	}
	fonctInter = pileFoncs.premier;
	while(fonctInter != NULL){
		nomF = NULL;
		if(strcmp(fonctInter->nomFonction,nomf) == 0){
			trouve = 1; // la fonction est trouve
			if(fonctInter->listeParametres.nombreElement == 0) fonctPossedeArgs = 0;
			else fonctPossedeArgs = 1;
			nomF = malloc((strlen(fonctInter->nomFonction)+1)*sizeof(char));
			if(nomF == NULL){
				printf("ERREUR : probleme d'allocation dynamique de la memoire (dans fonctionExiste).\n");
				exit(1);
			}
			strcpy(nomF,fonctInter->nomFonction);
		}
		fonctInter = fonctInter->suivant;
	}
	if(trouve == 0 ){
		printf("( la ligne %d ) ERREUR : la fonction \" %s \" n'est pas trouve (elle n'est pas encors deffinit).\n",lineNumber,nomf);
	}
	fonctEstTrouve = trouve;
}

void fonctAParams(char *nomf){
	if(fonctEstTrouve == 1 && fonctPossedeArgs == 0 && numArgum != 1){
		printf("( la ligne %d ) ERREUR : la fonction \" %s \" n'a aucun parametres (il ne faut pas mettre des arguments).\n",lineNumber,nomf);
	}
}

void fonctNAPasParams(char *nomf){
	if(fonctEstTrouve == 1 && fonctPossedeArgs == 1 && numArgum == 1){
		printf("( la ligne %d ) ERREUR : la fonction \" %s \" a des parametres (tu doit mettre les arguments correspondants).\n",lineNumber,nomf);
	}
}

void argumentEstValide(char *Arg){
	int i = 0;
	char *chaineSecour = NULL;
	fonction *fonctInter = NULL;
	identifiant *elem = NULL;
	if(fonctEstTrouve == 1){
		fonctInter = malloc(sizeof(fonction));
		if(fonctInter == NULL){
			printf("ERREUR : probleme d'allocation dynamique de la memoire (dans fonctionExiste).\n");
			exit(1);
		}
		fonctInter = pileFoncs.premier;
		while(fonctInter != NULL){
			if(strcmp(fonctInter->nomFonction,nomF) == 0){
				elem = malloc(sizeof(identifiant));
				if(elem == NULL){
					printf("ERREUR : probleme d'allocation dynamique de la memoire dans (dans associerType).\n");
					exit(1);
				}
				elem = fonctInter->listeParametres.premier;	
				i = fonctInter->listeParametres.nombreElement;
				while(elem != NULL){
					if(i == numArgum){
						if(elem->numType != typeAffDO){
							printf("( la ligne %d ) ERREUR : dans la fonction \" %s \" le type de l'argument numero %d est incompatible.\n",lineNumber,fonctInter->nomFonction,numArgum);
							return;
						}
						else{
							if(chaineParametres == NULL){
								chaineParametres = malloc((strlen(Arg)+1)*sizeof(char));
								if(chaineParametres == NULL){
									printf("ERREUR : probleme d'allocation dynamique de la memoire (dans argumentEstValide).\n");
									exit(1);
								}
								strcpy(chaineParametres,Arg);
								return;
							}
							else{
								chaineSecour = malloc((strlen(chaineParametres)+1)*sizeof(char));
								strcpy(chaineSecour,chaineParametres);
								free(chaineParametres);
								chaineParametres = NULL;
								chaineParametres = malloc((strlen(Arg)+strlen(chaineSecour)+2)*sizeof(char));
								if(chaineParametres == NULL){
									printf("ERREUR : probleme d'allocation dynamique de la memoire (dans argumentEstValide).\n");
									exit(1);
								}
								strcpy(chaineParametres,Arg);
								strcat(chaineParametres,",");
								strcat(chaineParametres,chaineSecour);
								free(chaineSecour);
								chaineSecour = NULL;
								return;
							}
						}
					}
					i--;
					elem = elem->suivant;
				}
			}
			fonctInter = fonctInter->suivant;
		}
	}
}

void verefierNbrArgums(){
	fonction *fonctInter = NULL;
	if(fonctEstTrouve == 1){
		fonctInter = malloc(sizeof(fonction));
		if(fonctInter == NULL){
			printf("ERREUR : probleme d'allocation dynamique de la memoire (dans fonctionExiste).\n");
			exit(1);
		}
		fonctInter = pileFoncs.premier;
		while(fonctInter != NULL){
			if(strcmp(fonctInter->nomFonction,nomF) == 0){
				if(fonctInter->listeParametres.nombreElement != numArgum-1){
					printf("( la ligne %d ) ERREUR : dans la fonction %s le nombre d'argument entres est incorrect (tu as oblie ou tu as ajouter un argument de plus).\n",lineNumber,nomF);
					return;
				}
			}
			fonctInter = fonctInter->suivant;
		}
	}
}

void typeRetoureEstValide(char *nomf){
	fonction *fonctInter = NULL;
	if(nomFonctEstPasse == 0){
		fonctInter = malloc(sizeof(fonction));
		if(fonctInter == NULL){
			printf("ERREUR : probleme d'allocation dynamique de la memoire (dans fonctionExiste).\n");
			exit(1);
		}
		fonctInter = pileFoncs.premier;
		while(fonctInter != NULL){
			if(strcmp(fonctInter->nomFonction,nomf) == 0){
				if(typeAffG_appelFonct != 0){
					if(typeAffG_appelFonct != fonctInter->typeRetoure){
						printf("( la ligne %d ) ERREUR : le type de la donne retournee par la fonction \" %s \"est incompatible avec le type de la variable qui va contenir le resultat.\n",lineNumber,nomf);
						erreur = 1;
						return;
					}
					else{

						if(typeAffG_appelFonct == 3){
							affAppeleFonct = malloc(256*sizeof(char));
							if(affAppeleFonct == NULL){
								printf("ERREUR : probleme d'allocation dynamique de la memoire (dans typeRetoureEstValide).\n");
								exit(1);
							}
							strcpy(affAppeleFonct," ");
							if(niveauFonct == 0){
								fputs(chaineSource,fichierProgEnC);
								fputs(" = malloc((strlen(",fichierProgEnC);
							}
							else{
								fputs(chaineSource,fichierFonction);
								fputs(" = malloc((strlen(",fichierFonction);
							}
						}
					}
				}
			}
			fonctInter = fonctInter->suivant;
		}
		nomFonctEstPasse = 1;
	}
}

void comleterAffAppeleFonct(){
	if(niveauFonct == 0 && typeAffG_appelFonct == 3){
		fputs(")+1)*sizeof(char));\n",fichierProgEnC);
		fputs("if(",fichierProgEnC);
		fputs(chaineSource,fichierProgEnC);
		fputs(" == NULL){\n",fichierProgEnC);
		fputs("printf(\"ERREUR : probleme d'allocation dynamique de la memoire.\n\");\nexit(1);\n}\n",fichierProgEnC);
		fputs("strcpy(",fichierProgEnC);
		fputs(chaineSource,fichierProgEnC);
		fputs(",",fichierProgEnC);
		fputs(affAppeleFonct,fichierProgEnC);
		fputs(chaineParametres,fichierProgEnC);
		fputs("));\n",fichierProgEnC);
	}
	if(niveauFonct != 0 && typeAffG_appelFonct == 3){
		fputs(")+1)*sizeof(char));\n",fichierFonction);
		fputs("if(",fichierFonction);
		fputs(chaineSource,fichierFonction);
		fputs(" == NULL){\n",fichierFonction);
		fputs("printf(\"ERREUR : probleme d'allocation dynamique de la memoire.\n\");\nexit(1);\n}\n",fichierFonction);
		fputs("strcpy(",fichierFonction);
		fputs(chaineSource,fichierFonction);
		fputs(",",fichierFonction);
		fputs(affAppeleFonct,fichierFonction);
		fputs(chaineParametres,fichierFonction);
		fputs("));\n",fichierFonction);
	}
	
}

void ecrireLsParametres(){
	if(niveauFonct == 0){ fputs(chaineParametres,fichierProgEnC);}
	else fputs(chaineParametres,fichierFonction);
}


void fermeturFichierC(){
	fputs("return 0;\n}",fichierProgEnC);
	fclose(fichierProgEnC);
	fclose(fichierFonction);
	fputs("\n#endif",fichierHeader);
	fclose(fichierHeader);
	fputs("\n\n#endif",fichierVarGlobale);
	fclose(fichierVarGlobale);
}