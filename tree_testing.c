
#include "arbol-binario.h"
#include "arbol-binario.c" //
#include "listas.h" 
#include "listas_vectores.c" //
#include "nodo.c" //
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

//////////////////////////////////////////////////////////////////////////////

//EXISTEN 2 FORMAS de RECORRER un ÁRBOL: En PROFUNDIDAD: 1. Pre-Orden, 2. In-Orden, 3. Post-Orden. y por ANCHURA:
//1. de IZQUIERDA a DERECHA, 2. de DERECHA a IZQUIERDA.

//Para MOSTRARLO solo en PROFUNDIDAD (3 FORMAS) y para CARGARLO solo en Pre-Orden
/*
void a_cArbol(ArbolBinario arbol, NodoArbol nodo, int subarbol){
    

    //1. Caso de Corte y Recursivo

    int numero;
    scanf("%d",&numero);
    NodoArbol n;
    TipoElemento e=te_crear(numero);

    //Debe CARGAR RECURSIVAMENTE CADA SUB-ARBOL (IZQ. Y DER.)
    if (numero==-1){
        n=a_conectar_hi(arbol,nodo,e);
    }
    else if(numero==1){
        n=a_conectar_hd(arbol,nodo,e);
    }
    else if(numero==0){
        n=a_establecer_raiz(arbol,e);
    }

    //SUBARBOL es un indicador
    a_cargarArbol(arbol,n,-1); //EMPIEZA CON ESTA INSTRUCCIÓN, HASTA que se CORTE
    a_cargarArbol(arbol,n,1); //Luego, AVANZA en esta instrucción

}

void a_cargarArbol (ArbolBinario arbol);

void a_cargarArbol (ArbolBinario arbol){

    a_cArbol(arbol,NULL,0);

}
*/


void listadeHojasSub(ArbolBinario arbol, NodoArbol nodo, Lista lista){

    //1. Base
    if (nodo==NULL){}

    //2. Recursivo
    else{
        TipoElemento elemento=te_crear(0);
        if(n_hijoizquierdo(nodo)==NULL && n_hijoderecho(nodo)==NULL){
            elemento=n_recuperar(nodo);
            l_agregar(lista,elemento);
        }
        //Recorrido RECURSIVO DOBLE
        listadeHojasSub(arbol,n_hijoizquierdo(nodo),lista);
        listadeHojasSub(arbol,n_hijoderecho(nodo),lista);
    }

}

Lista ldeHojas(ArbolBinario arbol){

    Lista l=l_crear();
    listadeHojasSub(arbol,a_raiz(arbol),l);
    return l;

}




void NodosDosHijosSub(ArbolBinario arbol, NodoArbol nodo, int *cantidad){

    //1. Base
    if(nodo==NULL){}

    //2. Recursivo
    else{
        if(n_hijoizquierdo(nodo)!=NULL && n_hijoderecho(nodo)!=NULL){
            *cantidad=*cantidad+1;
        }

        //DOBLE RECORRIDO RECURSIVO (POR CADA HIJO)
        NodosDosHijosSub(arbol,n_hijoizquierdo(nodo),cantidad);
        NodosDosHijosSub(arbol,n_hijoderecho(nodo),cantidad);

    }


}


int NodosDosHijos(ArbolBinario arbol){

    int cantidad=0;
    NodosDosHijosSub(arbol,a_raiz(arbol),cantidad);
    return cantidad;

}








int main(){






}











