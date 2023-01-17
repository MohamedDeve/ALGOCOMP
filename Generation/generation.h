#define tailleMaxChaine 10 // la taille maximalle d'un mot cle
// la pile utilise pour stocker les identifiants 
typedef struct element identifiant;
struct element{
	char *mot;
	char *valVarChaine;
	int estInitialise;/* cette variable va indique qu'une variable est initialise ou non */
	int numType;/* 1- pour entier 2- pour reel 3- pour chaine 4- pour caractere*/
	int niveauFonction;
	int estConst; /* la variable qui permet de dire si cette donne est une variable ( si sa valeur est 0 ) ou une constante ( si sa valeur est 1)*/
	identifiant *suivant;
};
typedef struct pileIdentifs pileIdentifs;
struct pileIdentifs{
	int nombreElement;
	identifiant *premier;
};

// la pile utilise pour stocker les valeur des constantes
typedef struct constante constante;
struct constante{
	int valConstanteE; // la valeur d'une constante entier
	double valConstanteD; // la valeur d'une constante reel
	char *valConstanteS; // la valeur d'une constante de type chaine
	int valConstanteC; // la valeur d'une constante de type caractere
	constante *suivant;
};
typedef struct pileValConst pileValConst;
struct pileValConst{
	int nombreConstantes;
	constante *premier;
};

// la pile utilise pour stocker le nom et les parametres d'une fonction
typedef struct fonction fonction;
struct fonction{
	char *nomFonction;
	int typeRetoure;
	pileIdentifs listeParametres;
	fonction *suivant;
};
typedef struct pileFonctions pileFonctions;
struct pileFonctions{
	int nombreFonction;
	fonction *premier;
};

// des fonctions liees a la phase symentique 
void saisirNomProgramme(char * identifiant);
void identEstValide(char *identifiant);
pileIdentifs creerPileIdentifes();
void empilerIdentif(pileIdentifs *p,char *identif);
int identifEstDeclarer(pileIdentifs p,char *identif);
void variableEstDeclaree(pileIdentifs p,char *identif);

// des fonction liee a la generation de code
void overtureFichierC(char *nomAlgo);
void declarationEnReChCa(char *typeVouC);
pileValConst creerPileConsts();
void prendreValConst(char * valeurC);
void empilerValConst(pileValConst *p,pileIdentifs *pE, char *typeC);
void prendreTypeDec(char *typeVC);
void associerType();
void prendreTypeAff(char *ident,int direction);
void prendreSymOp(char *symbole);
void prendreChaine(char *chainePr,int nature);
void typeAffDestValide(char *identOuVal,int nature);
void prendreChSource(char *chaineS);
void executerAffCh();
int vallCouVexiste(char *ident);
void prendreNomConst(char *nom);
char *corrigerChaine(char *chaineNC);
void identifEstInitialise(char *ident);
void exprComprEstValide(int typeExpr);
void typeVarSwitchEstValide(int typeVar);
void typeCasEstValide(int typeCas);
void stockerMessageCh(char *message);
void stockerMessageIdent(char *nomIdent);
void formerMeg();
void viderChaines();
void prendreTypeLire(char *type);
void prendreNomIdent(char *nomIdent);
void prendreIdentPour(char *ident);
void typeVarPourEstValide();
void typePasEstValide();
void verifierTypeRetoure();
void ecrireEnteteFonct();
void prendreTypeRetoure(char *type);
void overtureFichierFonction();
void overtureFichierHeader();
void prendreNomParametre(char *nomp);
void prendreNomFonction(char *nomf);
void fonctionEstValide(char *nomFonct);
void empilerFonction(pileFonctions *pileF);
pileFonctions creerPileFoncts();
void comleterAffAppeleFonct();
void typeRetoureEstValide(char *nomf);
void verefierNbrArgums();
void argumentEstValide(char *Arg);
void fonctNAPasParams(char *nomf);
void fonctionExiste(char *nomf);
void fonctAParams(char *nomf);
void ecrireLsParametres();
void fermeturFichierC();
void overtureFichierVarGlobale();