

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "tp0_encabezado.h" //-------header (encabezado)


// Ejercicio 1

enum Referencia dondeEstaElPunto(int xc, int yc, int rc, int xp, int yp){
    float distancia; //No es un int. Se pueden comparar datos (int) con datos (float) 
    distancia=sqrt(pow(xp-xc,2)+pow(yp-yc,2));
    if (distancia==rc){
        distancia=EN_CIRCUNFERENCIA;}
    else if(distancia<rc){
        distancia=INTERNO;
    }
    else{
        distancia=EXTERNO;
    }

    return distancia;}


// Ejercicio 2

bool digitoEnNumero(long n, short d){
    short vector[10]={0};
    long entero=n;
    short ult_digito=0;
    bool resultado=false;


    while (entero!=0){
        ult_digito=entero%10;
        vector[ult_digito]=ult_digito;
        entero=entero/10;
    }


    if (vector[d]==d){
        resultado=true;
    }
    
    return resultado;

    }
    

// Ejercicio 3

enum Referencia dondeEstaElPuntoBis(struct Punto centroC, int rc, struct Punto p){

    float distancia; 
    distancia=sqrt(pow(p.x-centroC.x,2)+pow(p.y-centroC.y,2));
    if (distancia==rc){
        distancia=EN_CIRCUNFERENCIA;}
    else if(distancia<rc){
        distancia=INTERNO;
    }
    else{
        distancia=EXTERNO;
    }

    return distancia;};


// Ejercicio 5

int pisoConMasHabitantes(int edificio[CANT_PISOS][CANT_DEPARTAMENTOS]){

    int pisos[CANT_PISOS]={0},f,c,pos=0,i;
    for (f=0;f<CANT_PISOS;++f){
        for (c=0;c<CANT_DEPARTAMENTOS;++c){
            pisos[f]=pisos[f]+edificio[f][c];
        }
    ;}

    int mayor=pisos[0];

    for (i=0;i<CANT_PISOS;++i){
        if (pisos[i]>mayor){
            mayor=pisos[i];
            pos=i;
        }
    ;}
    
    return pos;
}

int cantidadDeViviendasVacias(int edificio[CANT_PISOS][CANT_DEPARTAMENTOS]){
    
    int vacio=0,f,c;
    for (f=0;f<CANT_PISOS;++f){
        for (c=0;c<CANT_DEPARTAMENTOS;++c){
            if (edificio[f][c]==0){
                ++vacio;
            }
        }
    ;}
    
    return vacio;

}

float promedioHabitantesPorVivienda(int edificio[CANT_PISOS][CANT_DEPARTAMENTOS]){

    int f,c,cant_viviendas=(CANT_PISOS*CANT_DEPARTAMENTOS);
    float promedio,suma=0;
    for (f=0;f<CANT_PISOS;++f){
        for (c=0;c<CANT_DEPARTAMENTOS;++c){
            suma=suma+edificio[f][c];
        }
    ;}
    
    return promedio=suma/cant_viviendas;
}

Vivienda viviendaConMasHabitantes(int edificio[CANT_PISOS][CANT_DEPARTAMENTOS]){

    int f,c,p,dept,mayor=0;
    char deptos[CANT_DEPARTAMENTOS+1]={'A','B','C','D','E','\0'};
    Vivienda v;
    for (f=0;f<CANT_PISOS;++f){
        for (c=0;c<CANT_DEPARTAMENTOS;++c){
            if (edificio[f][c]>mayor){
                mayor=edificio[f][c];
                p=f;
                dept=c;
            }
        }
    ;}

    v.piso=p;
    v.depto=deptos[dept];

    return v;
    
    
}


// Ejercicio 6

void corte_de_control(){
    
    int prev_cliente,cliente,anio,mes;
    float prev_mins,mins;

    // Manejador de Archivos FILE

    FILE *archivo;
    archivo=fopen("practica-0-ejercicio-6.txt","r");

    // Comprobar errores de apertura

    if (archivo==NULL){
        printf("Error de apertura\n");
    }

    // Descartar la primera linea de caracteres

    char *linea_caracteres=malloc(100);
    fscanf(archivo,"%[^\n] ",linea_caracteres);

    // Primera linea de valores enteros

    fscanf(archivo,"%d %d %d %f",&prev_cliente,&anio,&mes,&prev_mins);

   
    // Corte de control
    
    printf("Cliente   Total de minutos trabajados\n");
    while (!(feof(archivo))){ 
    fscanf(archivo,"%d %d %d %f",&cliente,&anio,&mes,&mins); //Comienza desde la SEGUNDA línea
        if (cliente==prev_cliente){
            prev_mins=prev_mins+mins;
        }
        else{
            printf("%d %2.f\n",prev_cliente,prev_mins);
            prev_cliente=cliente;
            prev_mins=mins;
        }
        if (feof(archivo)){ //Instrucción auxiliar para imprimir el último cliente antes de EOF
            printf("%d %2.f\n",prev_cliente,prev_mins);
        }
    }
    

    //Cierre del archivo

    fclose(archivo);
    

}

































