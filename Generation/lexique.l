%{ 

#include "syntaxeY.h" //fichier genere par syntaxe.y
#include "generation.h"
extern int lineNumber; // definie dans syntaxe.y, utilise pour compter \n
extern char *nomProgramme;
extern int estNomProgramme;
extern int finDeclaration;
extern pileIdentifs pileIdentifiants;
extern pileValConst pileConstantes;
extern int estConstante;
extern int estVariable;
extern int nbrVarDecEnC; 
extern int nbrConstDecEnC; 
extern int numeroType; 
extern int typeAffG; 
extern int typeAffD; 
extern int typeAffDO;
extern int symboleOperation; 
extern int nature;
extern int debutInstrAff;
extern int typeVarSwitch;
extern int estInstrEcrireOuLire;
extern int boucleTQueFinie;
extern int boucleFTQueFinie;
extern int estFonction;
extern int niveauFonct;
extern int estAppelFonct;
extern int typeAffG_appelFonct;
extern int nomFonctEstPasse;
extern int varEstGlobale;
extern char *nomF;
extern char *chaineSource;
extern char *chainePrincipale;
extern char *chaineSecondere;
extern char *valConstante; 
extern FILE *fichierProgEnC;
extern FILE *fichierHeader;
extern FILE *fichierFonction;
extern FILE *fichierVarGlobale;

%}

%option noyywrap
nombre   [0-9]
entier  {nombre}+
reel    {entier}"."{nombre}* 
chaine   \"[^"]*\" 
caractere  \".\"



%%

[" "\t]  			{   /* rien */ 		}
"\n"				{ ++lineNumber;  }
"entier"			{  return ENTIER_D;	}
"reel"				{  return REEL_D;	}
"chaine"			{  return CHAINE_D;	}
"caractere"         {  return CARACTERE_D; } /*hani zet had type hit darori*/ 
"ALGO"|"algo" 	 		{ return ALGO;		}
"vars"|"VARS" 			{ estVariable = 1; estConstante = 0; return VARS;	}
"csts"|"CSTS"			{ estVariable = 0; estConstante = 1; return CSTS;	}
"debut"|"DEBUT" 		{ finDeclaration = 1; return DEBUT;		}
"fin"|"FIN" 		  	{  return  FIN;		}

":"				{ return DXPT;		}
";"				{ debutInstrAff = 1;  return PTVIRG;	}
","				{ return VIRG;		}


"+"     			{  return SOMM;	}
"-"	  			{  return SOUSTR; }
"*"				{  return PROD;	}
"/"   				{  return DIV;	}
"("      			{  return PAR_OUV;	}
")"      			{  return PAR_FERM;	}


"<" 				{ if(niveauFonct == 0) fputs(" < ",fichierProgEnC); else fputs(" < ",fichierFonction); return INF;}
">" 				{  if(niveauFonct == 0) fputs(" > ",fichierProgEnC); else  fputs(" > ",fichierFonction); return SUP;}
"<=" 				{ if(niveauFonct == 0) fputs(" <= ",fichierProgEnC); else fputs(" <= ",fichierFonction); return INF_EG;}
">=" 				{  if(niveauFonct == 0) fputs(" >= ",fichierProgEnC); else fputs(" >= ",fichierFonction); return SUP_EG;}
"==" 				{   if(niveauFonct == 0) fputs(" == ",fichierProgEnC); else fputs(" == ",fichierFonction); return EG; }
"="   				{   return AFF; }
"!="   				{ if(niveauFonct == 0) fputs(" != ",fichierProgEnC); else fputs(" != ",fichierFonction); return DIFF; }


"ET"|"et"  			{   typeAffD = 0; typeAffG = 0; if(niveauFonct == 0) fputs(" && ",fichierProgEnC); else fputs(" && ",fichierFonction); return CONJ;}
"OU"|"ou" 			{   typeAffD = 0; typeAffG = 0; if(niveauFonct == 0) fputs(" || ",fichierProgEnC); else fputs(" || ",fichierFonction); return DISJ;}
"NON"|"non" 			{ if(niveauFonct == 0) fputs(" !",fichierProgEnC); else fputs(" !",fichierFonction); return NEG;}

"SI"|"si"			{  debutInstrAff = 0; typeAffD = 0; typeAffG = 0; if(niveauFonct == 0) fputs("if( ",fichierProgEnC); else fputs("if( ",fichierFonction); return SI;		}
"ALORS"|"alors"			{  debutInstrAff = 1;if(niveauFonct == 0)  fputs(" ){\n",fichierProgEnC); else fputs(" ){\n",fichierFonction); return ALORS;	}
"SINON"|"sinon" 		{   debutInstrAff = 1; if(niveauFonct == 0) fputs("}\nelse{\n",fichierProgEnC); else fputs("}\nelse{\n",fichierFonction); return SINON;	}
"SELON"|"selon" 		{  debutInstrAff = 0; typeAffD = 0; typeAffG = 0; if(niveauFonct == 0) fputs("switch( ",fichierProgEnC); else fputs("switch( ",fichierFonction); return SELON;	}
"CAS"|"cas"	 		{  debutInstrAff = 0; typeAffD = 0; typeAffG = 0; if(niveauFonct == 0) fputs("case ",fichierProgEnC); else fputs("case ",fichierFonction);  return CAS;		}
"POUR"|"pour"			{ debutInstrAff = 1; typeAffD = 0; typeAffG = 0; return POUR;		}
"DE"|"de"			{  return DE;		}
"JUSQUA"|"jusqua"		{  return JUSQUA;	}
"PAS"|"pas"			{  typeAffD = 0; return PAS;		}
"FAIRE"|"faire"			{  debutInstrAff = 1; return FAIRE;	}
"TANTQUE"|"tantque"		{  return TANTQUE;}
"RETOURNE"|"retourne"		{  return RETOURNE;     }
"LIRE"|"lire"			{  debutInstrAff = 0; typeAffD = 0; typeAffG = 0; estInstrEcrireOuLire = 1; return LIRE;		}
"ECRIRE"|"ecrire"		{  debutInstrAff = 0; typeAffD = 0; typeAffG = 0; estInstrEcrireOuLire = 1; return ECRIRE;	}
"fonction"|"FONCTION"   { return FONCTION; }

[a-zA-Z][a-zA-Z0-9_]*   { if(estNomProgramme == 0) {saisirNomProgramme(yytext);overtureFichierC(nomProgramme);return IDENT;} /* compilation de la declaration */ if(finDeclaration == 0){identEstValide(yytext); return IDENT;} /* compilation du corp */ if(finDeclaration == 1 && estAppelFonct == 0){if(estFonction != 1){ variableEstDeclaree(pileIdentifiants,yytext);} prendreTypeAff(yytext,1);   if(estInstrEcrireOuLire != 1 && estFonction != 1){if(typeAffG != 3){ if(niveauFonct == 0) fputs(yytext,fichierProgEnC); else{ fputs(yytext,fichierFonction); if(varEstGlobale == 1){fputs(yytext,fichierVarGlobale); fputs(";",fichierVarGlobale); varEstGlobale = 0;}}}} if(typeAffG == 3 && debutInstrAff == 1){ prendreChSource(yytext);} debutInstrAff = 0; return IDENT;} if(estAppelFonct == 1 && nomFonctEstPasse == 0){if(niveauFonct == 0){typeRetoureEstValide(yytext); fputs(yytext,fichierProgEnC);} else {typeRetoureEstValide(yytext); fputs(yytext,fichierFonction);} return IDENT;} if(estAppelFonct == 1 && nomFonctEstPasse == 1){variableEstDeclaree(pileIdentifiants,yytext); return IDENT;}}
{entier}			{ return ENTIER;	}
{reel}				{ return REEL;		}
{caractere}			{ return CARACTERE;	}
{chaine}			{ return CHAINE;	}
.				{ return yytext[0]; }
%%

