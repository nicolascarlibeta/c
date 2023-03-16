

#include <stdio.h>
#include <math.h>
#include "tp0_encabezado.h" //-------header (encabezado)


// Ejercicio 1
/*
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
    
*/

// Ejercicio 3

enum Referencia dondeEstaElPuntoBis(struct Punto centroC, int rc, struct Punto p){
    //centroC.x=0;
    //centroC.y=0;
    //p.x=1;
    //p.y=1;
    float distancia; 
    distancia=sqrt(pow(2,2)+pow(2,2));
    if (distancia==rc){
        distancia=EN_CIRCUNFERENCIA;}
    else if(distancia<rc){
        distancia=INTERNO;
    }
    else{
        distancia=EXTERNO;
    }

    return distancia;};


struct Punto {
    int x, y;
};


int main(){
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

*/

int x0,y0,r,x,y,resultado;
struct Punto centroC;
struct Punto p;


//printf("Introduzca la coordenada x del centro de la circunferencia: \n");
//scanf("%d",&x0);
//printf("Introduzca la coordenada y del centro de la circunferencia: \n");
//scanf("%d",&y0);
printf("Introduzca el radio de la circunferencia: \n");
scanf("%d",&r);
//printf("Introduzca la coordenada x del punto: \n");
//scanf("%d",&x);
//printf("Introduzca la coordenada y del punto: \n");
//scanf("%d",&y);

resultado=dondeEstaElPuntoBis(centroC,r,p);

if (resultado==-1){
    printf("Se encuentra DENTRO de la circunferencia\n");}
else if (resultado==0){
    printf("Se encuentra SOBRE la circunferencia\n");
}
else{
    printf("Se encuentra FUERA de la circunferencia\n");
}





















}


































