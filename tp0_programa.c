
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tp0_encabezado.h"



int main(){



// Semilla generadora de números aleatorios (srand())

srand(time(NULL));


/*
int x0,y0,r,x,y,resultado;


printf("Introduzca la coordenada x del centro de la circunferencia: \n");
scanf("%d",&x0);
printf("Introduzca la coordenada y del centro de la circunferencia: \n");
scanf("%d",&y0);
printf("Introduzca el radio de la circunferencia: \n");
scanf("%d",&r);
printf("Introduzca la coordenada x del punto: \n");
scanf("%d",&x);
printf("Introduzca la coordenada y del punto: \n");
scanf("%d",&y);

resultado=dondeEstaElPunto(x0,y0,r,x,y);

if (resultado==-1){
    printf("Se encuentra DENTRO de la circunferencia\n");}
else if (resultado==0){
    printf("Se encuentra SOBRE la circunferencia\n");
}
else{
    printf("Se encuentra FUERA de la circunferencia\n");
}



long entero;
short digito;
bool resultado;
printf("Ingrese un número entero: \n");
scanf("%ld",&entero); //se utiliza "%ld" (long decimal) para valores enteros largos
printf("Ingrese un digito: \n");
scanf("%hd",&digito); //se utiliza "%hd" (long decimal) para valores enteros cortos

resultado=digitoEnNumero(entero,digito);

if (resultado==true){
    printf("El digito se encuentra dentro del número\n");}
else{
    printf("El digito NO se encuentra dentro del número\n");
}



int r,resultado;
//Los valores de los campos del registro estan asignados por fuera de la función
struct Punto centroC={0,0}, p={1,1}; 

printf("Introduzca el radio de la circunferencia: \n");
scanf("%d",&r);

resultado=dondeEstaElPuntoBis(centroC,r,p);

if (resultado==-1){
    printf("Se encuentra DENTRO de la circunferencia\n");}
else if (resultado==0){
    printf("Se encuentra SOBRE la circunferencia\n");
}
else{
    printf("Se encuentra FUERA de la circunferencia\n");
}



int resultado,resultado2,f,c;
int edificio[CANT_PISOS][CANT_DEPARTAMENTOS];
float resultado3=0.000;
Vivienda resultado4;

// Cargar la matriz

for (f=0;f<CANT_PISOS;++f){
    for (c=0;c<CANT_DEPARTAMENTOS;++c){
        edificio[f][c]=rand()%10;
    }
}


// Imprimir la matriz

for (f=0;f<CANT_PISOS;++f){
    for (c=0;c<CANT_DEPARTAMENTOS;++c){
        printf("%d ",edificio[f][c]);
    }
    printf("\n");
}


//resultado=pisoConMasHabitantes(edificio);
//printf("El piso que tiene mas habitantes de todo el edificio es el piso %d \n",resultado+1);
//resultado2=cantidadDeViviendasVacias(edificio);
//printf("La cantidad de viviendas vacias en todo el edificio es de %d viviendas\n",resultado2);
//resultado3=promedioHabitantesPorVivienda(edificio);
//printf("El promedio de la cantidad de habitantes por vivienda es de %f\n",resultado3);
//resultado4=viviendaConMasHabitantes(edificio);
//printf("La vivienda que tiene mas habitantes en todo el edificio es %hd-%c\n",resultado4.piso+1,resultado4.depto);
*/


corte_de_control();

















}

