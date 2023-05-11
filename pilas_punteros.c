

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "pilas.h"
#include "pilas_op_esp.h"
#include "tipo_elemento.h"
#include "tipo_elemento.c" //


//PILAS IMPLEMENTADAS CON PUNTEROS

const static int TAMANIO_MAXIMO=10;

struct Nodo{
    TipoElemento datos;
    struct Nodo *siguiente;
};

struct PilaRep{
    struct Nodo *tope; //APUNTA al elemento del TOPE
};

//CREAR una NUEVA PILA
Pila p_crear(){

    Pila nuevaPila=(Pila)malloc(sizeof(struct PilaRep));
    nuevaPila->tope=NULL;

    return nuevaPila;

}

bool p_es_llena(Pila pila){

    int pos=0;
    Pila paux=p_crear();
    TipoElemento elemento;
    while (!p_es_vacia(pila)){
        //Recorremos la pila
        elemento=p_desapilar(pila);
        p_apilar(paux,elemento);
        pos++;
    }
    p_intercambiar(pila,paux);

    return pos==TAMANIO_MAXIMO;

}

bool p_es_vacia(Pila pila){

    return pila->tope==NULL;

}

//RETORNAR el ELEMENTO del TOPE
TipoElemento p_tope(Pila pila){ //Verificamos que la pila NO ESTE VACIA

    if (p_es_vacia(pila)){
        return NULL;
    }
    else{
        return pila->tope->datos;}

}

//APILAR un ELEMENTO
void p_apilar(Pila pila, TipoElemento elemento){

    if (!p_es_llena(pila)){
        //Se crea un Nuevo Elemento (Nuevo NODO)
        struct Nodo *nuevoNodo=malloc(sizeof(struct Nodo));
        nuevoNodo->datos=elemento; //Se guardan los DATOS del TipoElemento en el NODO
        nuevoNodo->siguiente=NULL;

        //Apilar al TOPE
        if (!p_es_vacia(pila)){ //Si la PILA NO ESTA VACIA, el nuevo NODO se conecta con los demás
            nuevoNodo->siguiente=pila->tope;
        }
        pila->tope=nuevoNodo;   
    }

}

//DES-APILAR un ELEMENTO
TipoElemento p_desapilar(Pila pila){

    if (p_es_vacia(pila)){
        return NULL;}

    else{ //Se desapila DESDE el TOPE
      struct Nodo *topeActual=pila->tope; //Apuntador al NODO del TOPE
      TipoElemento elemento=topeActual->datos; //Traspaso los datos del NODO del TOPE (Datos de TipoElemento)
      pila->tope=topeActual->siguiente; //Apunta al siguiente NODO del TOPE
      free(topeActual); //Liberamos el espacio de memoria del puntero *topeActual
      return elemento; 
}

}

//MOSTRAR una PILA POR PANTALLA
void p_mostrar(Pila pila){   

    if (p_es_vacia(pila)){
        return;}

    else{ //Primero la desapilo
        Pila paux=p_crear();
        TipoElemento elemento;
        while (!p_es_vacia(pila)){
            elemento=p_desapilar(pila);
            printf("%d\n",elemento->clave);
            p_apilar(paux,elemento);
        }
        p_intercambiar(pila,paux);
        printf("\n");

}

}

//FUNCIÓN que INTERCAMBIA los elementos de una PILA (Pila AUXILIAR) a otra (NO PERTENECE AL TAD PILA)

void p_intercambiar(Pila pila, Pila pilaAux){
    
    if (p_es_vacia(pilaAux)){
        return; //Si una funcion retorna VOID, se debera retornar vacio (return)
    }
    else{
        while(!p_es_vacia(pilaAux)){
            TipoElemento elemento=p_desapilar(pilaAux);
            p_apilar(pila,elemento);
        }
    }

}

int p_longitud(Pila pila){ 
    
    Pila paux=p_crear();
    TipoElemento elemento;
    int cantidad=0;
    while(!p_es_vacia(pila)){
        elemento=p_desapilar(pila);
        p_apilar(paux,elemento);
        cantidad++;
    }

    p_intercambiar(pila,paux);
    return cantidad;

}

/*
int main(){

//Crear una pila
Pila p=p_crear();
//Le agrego elementos
TipoElemento elemento=te_crear(4);
p_apilar(p,elemento); //Apilo el 4
p_mostrar(p); //Muestro la pila
bool esllena=p_es_llena(p);
int longitud=p_longitud(p);
printf("%d  %d",esllena,longitud);

elemento3=p_desapilar(p);
elemento3=p_tope(p);
printf("Tope: %d\n",elemento3->clave); 
p_mostrar(p); //Muestro la pila
Pila paux=p_crear();
p_intercambiar(paux,p);
p_mostrar(paux);

free(p);

}*/