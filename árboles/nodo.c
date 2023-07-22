
#include "nodo.h"
#include "tipo_elemento.c" //
#include <stdio.h>
#include <stdlib.h>

//ARBOLES

//Los ARBOLES son estructuras dinámicas compuestas por NODOS, que pueden tener un camino hacia
//DOS O MAS NODOS conocidos como HIJOS o SUB-ARBOLES IZQUIERDO y DERECHO.

//El NODO conceptualmente representara el ELEMENTO almacenado en la estructura del ARBOL. Los DATOS almacenados
//en el Nodo seran de TipoElemento, ademas de contener un PUNTERO (CAMINO) tanto hacia su HIJO IZQ. como HIJO DER.
//Por ultimo, cada nodo puede contener un FE (Factor de Equilibrio) para el AUTO-BALANCEO.

//CREAR un NODO
NodoArbol n_crear(TipoElemento te){

    NodoArbol nuevoNodo=(NodoArbol)malloc(sizeof(struct NodoArbolRep));
    nuevoNodo->datos=te;
    nuevoNodo->hi=NULL;
    nuevoNodo->hd=NULL;
    nuevoNodo->FE=0;

    return nuevoNodo;

}

//RETORNA el TIPOELEMENTO del NODO (SI NO EXISTE EL NODO, retorna NULL)
TipoElemento n_recuperar(NodoArbol N){

    if (N==NULL){
        return NULL;
    }
    else{
        TipoElemento nodo=te_crear(0);
        nodo=N->datos; //TipoElemento=TipoElemento (ESTRUCTURA A ESTRUCTURA);
        return nodo;
    }

}

//RETORNA el HIJO IZQUIERDO (PUNTERO)
NodoArbol n_hijoizquierdo(NodoArbol N){
    
    if (N==NULL){
        return NULL;
    }
    else{
        return N->hi;
    }

}

//RETORNA el HIJO DERECHO (PUNTERO)
NodoArbol n_hijoderecho(NodoArbol N){
    
    if (N==NULL){
        return NULL;
    }
    else{
        return N->hd;
    }

}


/*
int main(){


TipoElemento e=te_crear(14);
NodoArbol nodo=n_crear(e);
TipoElemento x=n_recuperar(nodo);
NodoArbol hi=n_hijoizquierdo(nodo);
NodoArbol hd=n_hijoderecho(nodo);

}*/





