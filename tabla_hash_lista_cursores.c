

#include "tabla_hash.h"
#include "listas.h"
#include "listas_vectores.c" //
#include <stdlib.h>
#include <math.h>


//IMPLEMENTACIÓN CON LISTA DE COLISIONES (TABLAS HASH)

/*
Utilizamos una LISTA por cada ESPACIO dentro de la TABLA HASH llamada LISTA DE COLISIONES.
*/

static const int NULO=-1;

struct TipoRegistroTabla{

    TipoElemento tipo_elemento;
    bool ocupado;
    Lista lista_colisiones;
    int siguiente;

};

struct TablaHashRep{

    struct TipoRegistroTabla *tabla;
    int capacidad;
    int (*hash_function)(int); //PUNTERO a la FUNCIÓN HASH determinada
    int inicio;
    int libre;

};


//CREAR una TABLA HASH
TablaHash th_crear(int tamanio, int (*hash_function)(int)){

    TablaHash nuevaTablaHash=(TablaHash)malloc(sizeof(struct TablaHashRep));
    nuevaTablaHash->tabla=calloc(tamanio,sizeof(struct TipoRegistroTabla));
    nuevaTablaHash->capacidad=tamanio;
    nuevaTablaHash->hash_function=hash_function;
    nuevaTablaHash->inicio=NULO;
    nuevaTablaHash->libre=0;

    //Cargamos los DATOS del registro TipoRegistroTabla
    int i;
    for (i=0;i<tamanio-1;i++){
        nuevaTablaHash->tabla[i].tipo_elemento=NULL;
        nuevaTablaHash->tabla[i].ocupado=false;
        nuevaTablaHash->tabla[i].lista_colisiones=l_crear();
        nuevaTablaHash->tabla[i].siguiente=i+1;
    }
    nuevaTablaHash->tabla[i+1].siguiente=NULO;

    return nuevaTablaHash;
    
}

//INSERTAR una CLAVE
void th_insertar(TablaHash th, TipoElemento te){


    //FUNCIÓN HASH O DISPERSIÓN
    int h=th->hash_function(te->clave);

    if(!th->tabla[h].ocupado){
        th->tabla[h].tipo_elemento=te;
        th->tabla[h].ocupado=true;
    }

    else if(th->tabla[h].tipo_elemento!=te->clave && l_buscar(th->tabla[h].lista_colisiones,te->clave)==NULL){
        l_agregar(th->tabla[h].lista_colisiones,te);
    }


}

