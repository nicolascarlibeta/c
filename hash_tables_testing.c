

#include <stdlib.h>
#include <stdio.h>
#include <string.h>



int main(){

char cadena[40]="Hola";
char cadena2[40]="Hola";

char *p, *pd;

p=cadena;
pd=cadena2;
if(strcmp(p,pd)==0){
    printf("Si");
}

}