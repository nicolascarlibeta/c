

#include "colas.h"
#include "tipo_elemento.h"
#include "tipo_elemento.c" //
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//COLAS

//Cuando queremos ENCOLAR (Agregar) UN NUEVO ELEMENTO a la Cola, lo hacemos
//desde la DERECHA, y si queremos DES-ENCOLAR (Eliminar) UN ELEMENTO de la Cola, lo hacemos desde la IZQUIERDA.
//Solo podemos acceder al elemento del FRENTE de la Cola (IZQUIERDA).

//IMPLEMENTACIÓN DE COLAS CON VECTORES

//Los ELEMENTOS son ESTRUCTURAS del Tipo TIPOELEMENTO

//Existen 3 VARIANTES en implementaciones con VECTORES: NO CIRCULAR, NO CIRCULAR MEJORADO Y CIRCULAR

//1. NO CIRCULAR.   

const static int TAMANIO_MAXIMO=10;

struct ColaRep{

    TipoElemento *valores; //vd
    int frente, final; //frente FIJO (NO CIRCULAR) y final

};

Cola c_crear(){

    Cola nuevaCola=(Cola)malloc(sizeof(struct ColaRep));
    nuevaCola->valores=calloc(TAMANIO_MAXIMO+1,sizeof(TipoElemento));
    nuevaCola->frente=0;
    nuevaCola->final=0;
    return nuevaCola;

}

bool c_es_vacia(Cola cola){

    return cola->frente<=0;

}

bool c_es_llena(Cola cola){

    return cola->final==TAMANIO_MAXIMO;
    
}

TipoElemento c_recuperar(Cola cola){

    TipoElemento elemento;
    if(!c_es_vacia(cola)){
        elemento=cola->valores[cola->frente];}
    return elemento;

}

void c_encolar(Cola cola, TipoElemento elemento){

    if (!c_es_llena(cola)){

        cola->final++;
        cola->valores[cola->final]=elemento;

    }
    //Indico que la Cola ya NO ESTÁ VACIA
    if (c_es_vacia(cola)){
        cola->frente=cola->final;
    }

}

TipoElemento c_desencolar(Cola cola){

    TipoElemento elemento;
    if (!c_es_vacia(cola)){
        elemento=cola->valores[cola->frente];
        int pos=cola->frente; 
        while(pos<=cola->final-1){
            cola->valores[pos]=cola->valores[pos+1];
            pos++;
        }
        cola->final--;
        if (cola->final<cola->frente){ //Indico que la Cola ESTÁ VACIA
            cola->frente=0;
            cola->final=0;
        }
    }
    return elemento;
    

}

void c_mostrar(Cola cola){

    Cola caux=c_crear();
    TipoElemento elemento;
    while(!c_es_vacia(cola)){
        elemento=c_desencolar(cola);
        printf("%d ",elemento->clave);
        c_encolar(caux,elemento);
        }
        printf("\n");
        
    c_intercambiar(cola,caux);

        

}

//FUNCIONES UTILES PARA COLAS (NO FORMAN PARTE DEL TAD)

void c_intercambiar(Cola cola, Cola caux){

    if (c_es_vacia(caux)){
        return;
    }
    else{
        TipoElemento elemento;
        while(!c_es_vacia(caux)){
            elemento=c_desencolar(caux);
            c_encolar(cola,elemento);
            }
        }

}


int main(){

Cola c=c_crear();
TipoElemento x=te_crear(3);
c_encolar(c,x);
TipoElemento x2=te_crear(9);
c_encolar(c,x2);
TipoElemento x3=te_crear(5);
c_encolar(c,x3);
TipoElemento x4=te_crear(7);
c_encolar(c,x4);
c_mostrar(c);
c_desencolar(c);
c_mostrar(c);


}