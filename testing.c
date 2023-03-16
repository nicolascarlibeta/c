
#include <stdio.h>
#include <math.h>
#include "TP0_Repaso.h"

int funcion1(int); //declaracion

struct registro{  //Registro ANTES del main() para la declaración
    int variable1;
    float flotante1;
};

struct rv{  //Vector de Registros
    int edad, telefono;
};



int main(){

    int variable=29; //Variable del tipo Entero
    int i=0;
/*
//for (i=0;i<10;++i)
  //  printf("El número %i no es lo mismo que el número %i. ¿O Si?\n",i,i);
    
// Vectores

// TAD vector[cant.elementos];

int vector1[4]={3,5,1,7};
int vector2[2]={3,2};

// Cargar el vector


//for (asig1,cond,asig2) 

for (i=0;i<4;++i) 
    printf("%i\n",i);


// Funciones


//int funcion1(int){
//    return //variable
//}

*/
// Registros 

struct registro var_registro;
var_registro.variable1=4; //Variable para asignar el registro
printf("La variable1 tiene como dato un %d\n",var_registro.variable1);

// Registros y Vectores

struct rv vec1[10]; //Variable de Registro

//Cargar el vector de registro
while (i<10){
vec1[i].edad=i;
++i;}

//Mostrar el vector de registro
int x=0;
while (x<10){
printf("La edad es: %d\n",vec1[x].edad);
++x;
}

    
// Enumeración (Constantes)
enum enumeracion{
    CONSTANTE=1,
    CONSTANTE2
};

enum enumeracion var1;

printf("%d\n",var1);
    
int variable2=0;    
printf("%d",variable2);   
    
    
    
    
    }