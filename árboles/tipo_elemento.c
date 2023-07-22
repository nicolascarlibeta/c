

#include "tipo_elemento.h"
#include <stdlib.h>


//Definimos las funciones del TipoElemento (Asignar CLAVE y asignar VALOR)

//Creamos una variable del tipo TipoElemento y le asignamos una CLAVE
TipoElemento te_crear(int clave){

    TipoElemento te=(TipoElemento)malloc(sizeof(struct TipoElementoRep));
    te->clave=clave;
    te->valor=NULL;
    return te;

}

TipoElemento te_crear_con_valor(int clave, void *valor){

    TipoElemento te=malloc(sizeof(TipoElemento));
    te->clave=clave;
    te->valor=valor;
    return te;

}