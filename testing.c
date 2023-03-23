
#include <stdio.h>
#include <stdlib.h> //Necesaria para utilizar la funcion "malloc(int)"
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

int leer_archivo(){
    
    int cliente, anio, mes, mins;

    //Handler (Manejador de archivos del tipo FILE)

    FILE *archivo;
    archivo=fopen("testing.txt","r");

    //Verificamos que el archivo se ABRE CORRECTAMENTE

    if (archivo==NULL){
        printf("¡ERROR: open_error!\n");
        return -1;
    }

    //Leer la primera linea (Caracter)
    
    char *primera_linea=malloc(100); //------Asociamos un puntero a una CADENA DE CARACTERES DINÁMICA
    fscanf(archivo,"%[^\n] ",primera_linea); //En este caso, la cadena de control es "%[^\n]_"
    printf("%s\n",primera_linea);


    //Leer TODO el archivo

    while (fscanf(archivo,"%d %d %d %d",&cliente,&anio,&mes,&mins)!=EOF){ //Mientras no se llegue al FIN de Archivo
        printf("%d %d %d %d\n",cliente,anio,mes,mins); //Mostrar por pantalla
    }


    //IMPORTANTE: Cerrar el archivo para EVITAR ERRORES

    fclose(archivo);

}






int main(){
/*
    int variable=29; //Variable del tipo Entero
    int i=0;

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



// Matrices (Vector bidimensional)

// Vector
int vector[5];

// Matriz
int matriz[5][5]={0};
int f,c;

// Cargar la matriz

for (f=0;f<5;++f){
    for (c=0;c<5;++c){
        matriz[f][c]=14;
    }
;}


// Imprimir por pantalla la matriz

for (f=0;f<5;++f){
    for (c=0;c<5;++c){
        printf("%i ",matriz[f][c]);
    }
    printf("\n");
}
       

// función typedef


typedef struct registro{int campo1,campo2;} tipo_dato;

tipo_dato tad;

tad.campo1=0;
 


//FILE *archivo;
//archivo=fopen("practica-0-ejercicio-6.txt","r");

 
leer_archivo();



//Punteros

int *puntero,variable; // Declaración de puntero a entero

puntero=&variable; // El puntero "apunta" a la variable
*puntero=5; // El contenido se guarda en la variable a la que apunta <puntero> 

printf("%d\n",variable); // Imprime el contenido de la variable
printf("%d\n",puntero); // Imprime la dirección de memoria de la variable

*/
// Punteros y Vectores

int vector[20],*punt_vec;
punt_vec=&vector[0];
*punt_vec=12;

*(punt_vec+3)=7;

//printf("%d\n",vector[3]);

//Operaciones con punteros

*(punt_vec+2)=9;
punt_vec=punt_vec+10;
*punt_vec=2;
vector[4]=*(punt_vec-10);
printf("%d\n",vector[4]);

// Punteros y Funciones

//Dos TIPOS de DECLARACIONES (f->p y p->f)

//Función que DEVUELVE un PUNTERO

int *funcion();

//PUNTERO a una función

void (*puntero_a_funcion)();

//void funcion{
//    printf("Hola Mundo\n");
//}

puntero_a_funcion=funcion; //guarda la direccion de la "variable" funcion

puntero_a_funcion(); //Llama a la funcion apuntada por puntero_a_funcion














}















    
    
  