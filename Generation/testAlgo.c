#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "header.h"
int var3 ,var2 ,var1;
char var4;
char *var5;
double var8;
const int const1 = 34;
const char const2[] = "compilation";
const char const3 = 'c';
int main(){
var1 = 77;
var2 = var1+const1;
var3 = var1+200;
var5 = malloc((strlen("ours de compilation")+1)*sizeof(char));
if(var5 == NULL){
printf("ERREUR : probleme d'allocation dynamique de la memoire.");
exit(1);
}
strcpy(var5,"ours de compilation");
var2 = const3+var1;
var5 = malloc((strlen("cours de compilation")+1)*sizeof(char));
if(var5 == NULL){
printf("ERREUR : probleme d'allocation dynamique de la memoire.");
exit(1);
}
strcpy(var5,"cours de compilation");
printf("\n####> BONJOUR, DEBUT TEST << ALGOCOMP >> :)\n\n");
printf("var5 = %s\n",var5);
printf("const1 = %d\n",const1);
if( const1 > 100 && var3 < 55 ){
var5 = malloc((strlen("vrai")+1)*sizeof(char));
if(var5 == NULL){
printf("ERREUR : probleme d'allocation dynamique de la memoire.");
exit(1);
}
strcpy(var5,"vrai");
}
else{
var5 = malloc((strlen("faux")+1)*sizeof(char));
if(var5 == NULL){
printf("ERREUR : probleme d'allocation dynamique de la memoire.");
exit(1);
}
strcpy(var5,"faux");
}
for(var1=0; var1 > 10; var1+=1){
printf(" %d",var1);
}
printf("\n");
var1 = 222;
var2 = 100;
do{
while( var1 < 56 && var1 == 99 ){
do{
printf("const3 = %c\n",const3);
}while( var2 == 0);
var3 = 34;
}
printf("var2 = %d\n",var2);
var2 = var2+1;
}while( var2 <= 104);
var2 = fonct1(var5,33);
printf("entrez var3 puis var4 :\n");
return 0;
}