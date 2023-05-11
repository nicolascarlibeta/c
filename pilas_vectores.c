
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "pilas.h"
#include "pilas_op_esp.h"
#include "tipo_elemento.h"
#include "tipo_elemento.c" //


//PILAS IMPLEMENTADAS CON VECTORES DINÁMICOS

const static int TAMANIO_MAXIMOP=10; //UTILIZAMOS TODOS LOS ELEMENTOS DEL VECTOR EXCEPTO EL PRIMERO (p->valores[0])


struct PilaRep{
    TipoElemento *valores; //Vector Dinámico de TipoElementos
    int tope; //Indica donde se encuentra el TOPE de la PILA (BASE es 0) 
}; 

//CREAR una NUEVA PILA
Pila p_crear(){
    //Se utiliza el primer elemento del vector como TOPE (pila->valores[0])
    Pila nuevaPila=(Pila)malloc(sizeof(struct PilaRep));
    nuevaPila->valores=calloc((TAMANIO_MAXIMOP+1),sizeof(TipoElemento));
    nuevaPila->tope=0; //El 0 indica que NO EXISTEN elementos en el TOPE
    return nuevaPila;

}

bool p_es_llena(Pila pila){

    return pila->tope==TAMANIO_MAXIMOP;

}

bool p_es_vacia(Pila pila){

    return pila->tope==0;

}

//APILAR un nuevo ELEMENTO en el TOPE de la PILA (ÚNICA MANERA)

void p_apilar(Pila pila, TipoElemento elemento){

    if (p_es_llena(pila)){
        return;
    }
    else{
        pila->tope++;
        pila->valores[pila->tope]=elemento;
    }

}

//DES-APILAR un ELEMENTO del TOPE y RETORNARLO

TipoElemento p_desapilar(Pila pila){

    if (p_es_vacia(pila)){
        return NULL;
    }
    else{
        TipoElemento elemento=pila->valores[pila->tope];
        pila->tope--;
        return elemento;
    }

}

//RETORNAR el ELEMENTO del TOPE de la PILA

TipoElemento p_tope(Pila pila){

    if (p_es_vacia(pila)){
        return NULL;
    }
    else{
        return pila->valores[pila->tope];
        
    }

}

//MOSTRAR la PILA por PANTALLA
void p_mostrar(Pila pila){   

    if (p_es_vacia(pila)){
        return;}

    else{ //Primero la desapilo
        Pila paux=p_crear();
        TipoElemento elemento;
        while (!p_es_vacia(pila)){
            elemento=p_desapilar(pila);
            printf("%d\n",elemento->clave);
            p_apilar(paux,elemento);
        }
        p_intercambiar(pila,paux);
        printf("\n");

}

}

//FUNCIÓN que INTERCAMBIA los elementos de una PILA (Pila AUXILIAR) a otra (NO PERTENECE AL TAD PILA)

void p_intercambiar(Pila pila, Pila pilaAux){
    
    if (p_es_vacia(pilaAux)){
        return; //Si una funcion retorna VOID, se debera retornar vacio (return)
    }
    else{
        while(!p_es_vacia(pilaAux)){
            TipoElemento elemento=p_desapilar(pilaAux);
            p_apilar(pila,elemento);
        }
    }

}

int p_longitud(Pila pila){ 
    
    Pila paux=p_crear();
    TipoElemento elemento;
    int cantidad=0;
    while(!p_es_vacia(pila)){
        elemento=p_desapilar(pila);
        p_apilar(paux,elemento);
        cantidad++;
    }

    p_intercambiar(pila,paux);
    return cantidad;

}

/*
int main(){

//Crear una pila
Pila p=p_crear();
//Le agrego elementos
TipoElemento elemento=te_crear(4);
TipoElemento elemento2=te_crear(9);
TipoElemento elemento3;
p_apilar(p,elemento); //Apilo el 4
p_apilar(p,elemento2); //Apilo el 9
p_mostrar(p); //Muestro la pila
elemento3=p_desapilar(p);
elemento3=p_tope(p);
printf("Tope: %d\n",elemento3->clave); 
p_mostrar(p); //Muestro la pila
Pila paux=p_crear();
p_intercambiar(paux,p);
p_mostrar(paux);

free(p);
free(paux);

}*/