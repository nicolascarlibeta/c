

#include "listas.h"
#include <stdlib.h>

//IMPLEMENTACIÓN DE LISTAS CON VECTORES DE REGISTROS (Conocido como CURSORES)

//Consiste en un Vector de Registros donde se guardan elementos utilizados llamados NODOS, y
//espacios SIN UTILIZAR conocidos como (espacios) NODOS LIBRES.

static const int TAMANIO_MAXIMO=100;

struct Nodo{
    TipoElemento datos;
    int siguiente;
};

struct ListaRep{
    struct Nodo *cursor;
    int inicio;
    int libre;
    int cantidad;
};

struct IteradorRep{
    Lista lista;
    int posicionActual;
};

//CREAR una NUEVA LISTA
Lista l_crear(){

    //Vector de Nodos (CURSOR: LIBRES Y NO LIBRES)
    struct Nodo cursor=calloc(TAMANIO_MAXIMO,sizeof(struct Nodo));

    //Lista (NODOS NO LIBRES)
    Lista nuevaLista=malloc(sizeof(struct ListaRep));
    nuevaLista->inicio=NULL;
    nuevaLista->cantidad=0;

    //ENCADENAMOS los NODOS LIBRES
    for(int i=0;i<TAMANIO_MAXIMO;++i){
        
    }
    

}