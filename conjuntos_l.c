

#include "conjuntos.h"
#include "listas.h"
#include "listas_vectores.c" //
#include <stdlib.h>
#include <stdbool.h>


//IMPLEMENTACIÓN DE CONJUNTOS MEDIANTE LISTAS
//Los CONJUNTOS son una colección de VALORES SIN REPETIR Y NO ORDENADOS junto a una serie de OPERACIONES
//que actuan sobre ellos.

struct ConjuntoRep{

    Lista conjunto; //CONJUNTO IMPLEMENTADO EN LISTAS

};

//CREAR un CONJUNTO
Conjunto cto_crear(){

    Conjunto nuevoCto=(Conjunto)malloc(sizeof(struct ConjuntoRep));
    nuevoCto->conjunto=l_crear();
    return nuevoCto;

}

//FUNCIONES DE INFORMACIÓN
bool cto_es_lleno(Conjunto conjunto){
    return l_es_llena(conjunto->conjunto);
}

bool cto_es_vacio(Conjunto conjunto){
    return l_es_vacia(conjunto->conjunto);
}

int cto_cantidad_elementos(Conjunto conjunto){
    return l_longitud(conjunto->conjunto);
}

//AGREGAR un ELEMENTO
void cto_agregar(Conjunto conjunto, TipoElemento elemento){
    if(l_buscar(conjunto->conjunto,elemento->clave)==NULL){
        l_agregar(conjunto->conjunto,elemento);}
}

//ELIMINAR un ELEMENTO
void cto_borrar(Conjunto conjunto, int clave){
    l_borrar(conjunto->conjunto,clave);
}

//Si una CLAVE dada PERTENECE al CONJUNTO
bool cto_pertenece(Conjunto conjunto, int clave){

    bool pertenece=false;
    if(l_buscar(conjunto->conjunto,clave)!=NULL){
        pertenece=true;
    }
    return pertenece;

}

//RECUPERAR un ELEMENTO
TipoElemento cto_recuperar(Conjunto conjunto, int posicion_ordinal){
    return l_recuperar(conjunto->conjunto,posicion_ordinal);
}

//MOSTRAR el CONJUNTO
void cto_mostrar(Conjunto conjunto){
    l_mostrarLista(conjunto->conjunto);
}

//UNIÓN, INTERSECCIÓN Y DIFERENCIA
Conjunto cto_union(Conjunto conjunto_a, Conjunto conjunto_b){

    Conjunto conjunto_c=cto_crear();
    Iterador iter=iterador(conjunto_a->conjunto);
    Iterador iterB=iterador(conjunto_b->conjunto);
    TipoElemento elemento=te_crear(0);
    while(hay_siguiente(iter)){
        elemento=siguiente(iter);
        cto_agregar(conjunto_c,elemento);
    }

    while(hay_siguiente(iterB)){
        elemento=siguiente(iterB);
        if(!cto_pertenece(conjunto_a,elemento->clave)){
            cto_agregar(conjunto_c,elemento);
        }
    }

    return conjunto_c;

}


Conjunto cto_interseccion(Conjunto conjunto_a, Conjunto conjunto_b){

    Conjunto conjunto_c=cto_crear();
    Iterador iter=iterador(conjunto_a->conjunto);
    TipoElemento elemento=te_crear(0);
    while(hay_siguiente(iter)){
        elemento=siguiente(iter);
        if(cto_pertenece(conjunto_b,elemento->clave)){
            cto_agregar(conjunto_c,elemento);
        }
    }

    return conjunto_c;

}


Conjunto cto_diferencia(Conjunto conjunto_a, Conjunto conjunto_b){

    Conjunto conjunto_c=cto_crear();
    Iterador iter=iterador(conjunto_a->conjunto);
    TipoElemento elemento=te_crear(0);
    while(hay_siguiente(iter)){
        elemento=siguiente(iter);
        if(!cto_pertenece(conjunto_b,elemento->clave)){
            cto_agregar(conjunto_c,elemento);
        }
    }

    return conjunto_c;

}