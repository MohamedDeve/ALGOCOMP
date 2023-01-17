#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "varGlobale.h"
#include "header.h"
int fonct1(char *var5, int const1){
int var6;
double var7;
char *var1;
const int const4 = 100;
const double const5 = 22.670000;
const char const6[] = " syntaxique";
var1 = malloc((strlen("analyse")+1)*sizeof(char));
if(var1 == NULL){
printf("ERREUR : probleme d'allocation dynamique de la memoire.");
exit(1);
}
strcpy(var1,"analyse");
var1 = malloc((strlen("analyse syntaxique")+1)*sizeof(char));
if(var1 == NULL){
printf("ERREUR : probleme d'allocation dynamique de la memoire.");
exit(1);
}
strcpy(var1,"analyse syntaxique");
printf("const6 = %s\n",const6);
var8 = 43.55;
return const4;
}
