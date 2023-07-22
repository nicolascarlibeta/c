

#include "tabla_hash.h"
#include "tipo_elemento.h"
#include "tipo_elemento.c" //
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>


//IMPLEMENTACIÓN POR ZONA OVERFLOW (TABLAS HASH)

/*
Utilizamos una TABLA EXTERNA conocida como ZONA DE OVERFLOW. Las CLAVES solo pueden ubicarse en dicha zona
de forma LINEAL o DE FORMA CUADRÁTICA.
*/

struct TipoRegistroTabla{

    TipoElemento tipo_elemento;
    bool ocupado;

};

struct TablaHashRep{

    struct TipoRegistroTabla *tabla; //VECTOR de tipo TipoRegistroTabla (TABLA HASH)
    struct TipoRegistroTabla *zona_overflow; //VECTOR SECUNDARIO de tipo TipoRegistroTabla (ZONA DE OVERFLOW)
    int capacidad;
    int (*hash_function)(int); //PUNTERO a la FUNCIÓN HASH determinada

};


//CREAR una TABLA HASH
TablaHash th_crear(int tamanio, int (*hash_function)(int)){

    TablaHash nuevaTablaHash=(TablaHash)malloc(sizeof(struct TablaHashRep));
    //CREAMOS EL VECTOR DE TIPOREGISTROTABLAS (th->tabla)
    nuevaTablaHash->tabla=calloc(tamanio,sizeof(struct TipoRegistroTabla));
    nuevaTablaHash->capacidad=tamanio;
    nuevaTablaHash->hash_function=hash_function;

    //CREAMOS la ZONA DE OVERFLOW (th->zona_overflow)
    nuevaTablaHash->zona_overflow=calloc(tamanio,sizeof(struct TipoRegistroTabla));

    //Cargamos los DATOS del registro TipoRegistroTabla 
    for (int i=0;i<tamanio;i++){
        nuevaTablaHash->tabla[i].tipo_elemento=NULL;
        nuevaTablaHash->tabla[i].ocupado=false;
        nuevaTablaHash->zona_overflow[i].tipo_elemento=NULL;
        nuevaTablaHash->zona_overflow[i].ocupado=false;
    }

    return nuevaTablaHash;
    
}


//INSERTAR una CLAVE
void th_insertar(TablaHash th, TipoElemento te){

    //FUNCIÓN HASH O DE DISPERSIÓN (HASHING)
    int pos_disp=th->hash_function(te->clave);
    bool repetido=false, libre=false;

    if (!th->tabla[pos_disp].ocupado){
        th->tabla[pos_disp].tipo_elemento=te; 
        th->tabla[pos_disp].ocupado=true;
        }

    //POR ZONA DE OVERFLOW
    else{
        if(th->tabla[pos_disp].tipo_elemento->clave!=te->clave){
            int i=0;
            while(th->zona_overflow[i].ocupado){
                if(th->zona_overflow[i].tipo_elemento->clave==te->clave && !repetido){
                    repetido=true;
                }
                i++;
            }

            if(!repetido){
                th->zona_overflow[i].tipo_elemento=te;
                //IMPORTANTE! DEBEMOS IDENTIFICAR QUE EL ELEMENTO ESTÁ OCUPADO
                th->zona_overflow[i].ocupado=true;
            }

        }
    
        }
        
}
   

//ELIMINAR una CLAVE
void th_eliminar(TablaHash th, int clave){

    //HASHING
    int pos=th->hash_function(clave);
    int i=0;
    bool colisiones=false;

    //POR TABLA HASH
    if(th->tabla[pos].ocupado && th->tabla[pos].tipo_elemento->clave==clave){
            th->tabla[pos].ocupado=false;
        }

    //POR ZONA DE OVERFLOW
    else{
        bool esta=false;
        while(!esta && i<th->capacidad){
            if(th->zona_overflow[i].tipo_elemento->clave==clave){
                th->zona_overflow[i].ocupado=false;
                esta=true;
            }
            i++;
        }
        }

}


//RECUPERAR un ELEMENTO
TipoElemento th_recuperar(TablaHash th, int clave){

    //HASHING
    int pos=th->hash_function(clave);

    TipoElemento te=te_crear(0);
    bool esta=false;

    //POR TABLA HASH
    if(th->tabla[pos].ocupado && th->tabla[pos].tipo_elemento->clave==clave){
        te=th->tabla[pos].tipo_elemento;
        esta=true;
        }

    //POR ZONA DE OVERFLOW
    else{
        int i=0;
        while(!esta && i<th->capacidad){
            if(th->zona_overflow[i].tipo_elemento->clave==clave){
                te=th->zona_overflow[i].tipo_elemento;
                esta=true;
            }
            i++;
        }
    }

    if(!esta){
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
            printf("\n");
        } else if (!soloOcupados) {
            printf("  tabla[%i] [ libre ]\n", i);
        }
    }
    printf(" Zona de overflow:\n");
    for (int i = 0; i < th->capacidad; i++) {
        struct TipoRegistroTabla registroTabla = th->zona_overflow[i];
        if (registroTabla.ocupado) {
            printf("  zo[%i] [ocupado] %i", i, registroTabla.tipo_elemento->clave);
            printf("\n");
        } else if (!soloOcupados) {
            printf("  zo[%i] [ libre ]\n", i);
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