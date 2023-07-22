

#include "colas.h"
#include "colas_utilidades.h"
#include "tipo_elemento.h"
#include "tipo_elemento.c" //
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


//IMPLEMENTACIÓN DE COLAS CON PUNTEROS

//Los ELEMENTOS son NODOS que guardan DATOS del Tipo TIPOELEMENTO y un APUNTADOR al SIGUIENTE NODO (ELEMENTO)

const static int TAMANIO_MAXIMO=10;

struct Nodo{ //ELEMENTOS O NODOS

    TipoElemento datos;
    struct Nodo *siguiente;

};

struct ColaRep{

    struct Nodo *frente, *final;

};

Cola c_crear(){

    Cola nuevaCola=(Cola)malloc(sizeof(struct ColaRep));
    nuevaCola->frente=NULL;
    nuevaCola->final=NULL;
    return nuevaCola;

}

bool c_es_vacia(Cola cola){

    return cola->frente==NULL;

}

bool c_es_llena(Cola cola){

    int l=c_longitud(cola);
    return l==TAMANIO_MAXIMO;
    
}

void c_encolar(Cola cola, TipoElemento elemento){

    struct Nodo *nuevoNodo=malloc(sizeof(struct Nodo));
    nuevoNodo->datos=elemento;
    nuevoNodo->siguiente=NULL;

    if (c_es_vacia(cola)){
        cola->frente=nuevoNodo;
        cola->final=nuevoNodo;
    }
    else{
        if (!c_es_llena(cola)){
            cola->final->siguiente=nuevoNodo;
            cola->final=nuevoNodo;
            }
    }

}

TipoElemento c_desencolar(Cola cola){

    TipoElemento e;
    struct Nodo *p=malloc(sizeof(struct Nodo));
    if (!c_es_vacia(cola)){

        p=cola->frente;
        cola->frente=p->siguiente;
        e=p->datos;
        free(p);

    }
    return e;

}

TipoElemento c_recuperar(Cola cola){

    TipoElemento e;
    if (!c_es_vacia(cola)){
        e=cola->frente->datos;
    }
    return e;

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

int c_longitud(Cola cola){

    int cantidad=0;
    if (c_es_vacia(cola)){
        return cantidad;
    }
    else{
        Cola caux=c_crear();
        TipoElemento elemento;
        while(!c_es_vacia(cola)){
            elemento=c_desencolar(cola);
            cantidad++;
            c_encolar(caux,elemento);
            }
        c_intercambiar(cola,caux);
        }
    return cantidad;

}
/*
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
int l=c_longitud(c);
printf("%d\n",l);
c_desencolar(c);
c_mostrar(c);
l=c_longitud(c);
printf("%d\n",l);
c_mostrar(c);
TipoElemento e=c_recuperar(c);
printf("%d",e->clave);


}
*/