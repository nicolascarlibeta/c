

#include "tabla_hash.h"
#include "listas.h"
#include "listas_vectores.c" //
#include <stdlib.h>
#include <math.h>


//IMPLEMENTACIÓN CON LISTA DE COLISIONES (TABLAS HASH)

/*
Utilizamos una LISTA por cada ESPACIO dentro de la TABLA HASH llamada LISTA DE COLISIONES.
*/


struct TipoRegistroTabla{

    TipoElemento tipo_elemento;
    bool ocupado;
    Lista lista_colisiones;

};

struct TablaHashRep{

    struct TipoRegistroTabla *tabla;
    int capacidad;
    int (*hash_function)(int); //PUNTERO a la FUNCIÓN HASH determinada

};


//CREAR una TABLA HASH
TablaHash th_crear(int tamanio, int (*hash_function)(int)){

    TablaHash nuevaTablaHash=(TablaHash)malloc(sizeof(struct TablaHashRep));
    nuevaTablaHash->tabla=calloc(tamanio,sizeof(struct TipoRegistroTabla));
    nuevaTablaHash->capacidad=tamanio;
    nuevaTablaHash->hash_function=hash_function;

    //Cargamos los DATOS del registro TipoRegistroTabla
    for (int i=0;i<tamanio;i++){
        nuevaTablaHash->tabla[i].tipo_elemento=NULL;
        nuevaTablaHash->tabla[i].ocupado=false;
        nuevaTablaHash->tabla[i].lista_colisiones=l_crear();
    }

    return nuevaTablaHash;
    
}


//INSERTAR una CLAVE
void th_insertar(TablaHash th, TipoElemento te){

    //FUNCIÓN HASH O DE DISPERSIÓN (HASHING)
    int pos_disp=th->hash_function(te->clave);

    if (th->tabla[pos_disp].ocupado==false){
        th->tabla[pos_disp].tipo_elemento=te; //Es VALIDO (te=te)
        th->tabla[pos_disp].ocupado=true;
        }

    else{
        if(th->tabla[pos_disp].tipo_elemento->clave!=te->clave && 
        l_buscar(th->tabla[pos_disp].lista_colisiones,te->clave)==NULL){
            l_agregar(th->tabla[pos_disp].lista_colisiones,te);
            }
    }
       
}


//ELIMINAR una CLAVE
void th_eliminar(TablaHash th, int clave){

    //HASHING
    int pos=th->hash_function(clave);
    TipoElemento te=te_crear(0);

    if(th->tabla[pos].ocupado){

        if (th->tabla[pos].tipo_elemento->clave==clave){
            if (l_es_vacia(th->tabla[pos].lista_colisiones)){
                th->tabla[pos].ocupado=false;
            }

            else{
                te=l_recuperar(th->tabla[pos].lista_colisiones,1);
                th->tabla[pos].tipo_elemento=te;
                l_eliminar(th->tabla[pos].lista_colisiones,1);
            }
        }
        else if (th->tabla[pos].tipo_elemento->clave!=clave && !l_es_vacia(th->tabla[pos].lista_colisiones)){
            l_borrar(th->tabla[pos].lista_colisiones,clave);
            
        }
    }

}


//RECUPERAR un ELEMENTO
TipoElemento th_recuperar(TablaHash th, int clave){

    //HASHING
    int pos=th->hash_function(clave);

    TipoElemento te=te_crear(0);
    if(th->tabla[pos].ocupado){

        //POR TABLA HASH
        if(th->tabla[pos].tipo_elemento->clave==clave){
            te=th->tabla[pos].tipo_elemento;
        }
        //POR LISTA DE COLISIONES
        else{
            te=l_buscar(th->tabla[pos].lista_colisiones,clave);
        }
    }

    else{
        te=NULL;
    }

    return te;


}


void th_mostrar_interna(TablaHash th, bool soloOcupados) {
    printf("Contenido de la tabla hash:\n");
    for (int i = 0; i < th->capacidad; i++) {
        struct TipoRegistroTabla registroTabla = th->tabla[i];
        if (registroTabla.ocupado) {
            printf("  tabla[%i] [ocupado] %i", i, registroTabla.tipo_elemento->clave);
            Iterador iter = iterador(registroTabla.lista_colisiones);
            while (hay_siguiente(iter)) {
                TipoElemento e = siguiente(iter);
                printf(" -> %i ", e->clave);
            }
            free(iter);
            printf("\n");
        } else if (!soloOcupados) {
            printf("  tabla[%i] [ libre ]\n", i);
        }
    }
    printf("\n");
}

void th_mostrar(TablaHash th) {
    th_mostrar_interna(th, false);
}

void th_mostrar_solo_ocupados(TablaHash th) {
    th_mostrar_interna(th, true);
}


