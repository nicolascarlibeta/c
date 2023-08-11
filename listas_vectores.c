

#include "tipo_elemento_c.c" //
#include "listas.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

//Definimos la CONSTANTE de MÁXIMA
//#define TAMANIO_MAXIMO=100;
static const int TAMANIO_MAXIMO=100; //

struct ListaRep{
    TipoElemento *valores; //Vector de (TipoElementos)'s (puntero)
    int cantidad;
};

struct IteradorRep{
    Lista lista;
    int posicionActual;
};

Lista l_crear(){

//Creamos un vector de TipoElemento (Vector DINAMICO) con const. de máxima
/*
TipoElemento nuevaLista=malloc(sizeof(TAMANIO_MAXIMO));
return nuevaLista;
*/
//ERROR! El vector es *valores, asociado al TAD Lista. Forma correcta.
//Creamos una variable del tipo Lista y luego administramos sus campos
Lista nuevaLista=(Lista)malloc(sizeof(struct ListaRep)); //El TAD LISTA NO es un tipo de datos
nuevaLista->valores=calloc(TAMANIO_MAXIMO,sizeof(TipoElemento)); //TipoElemento SI es un tipo de datos
nuevaLista->cantidad=0;
return nuevaLista;

}

void l_mostrarLista(Lista lista){

/*
    Iterador iter=iterador(lista); //Creamos un iterador
    TipoElemento elemento;
    while (hay_siguiente(iter)){          #NO SE UTILIZA EL ITERADOR PARA LA FUNCIÓN
        elemento=siguiente(iter); //TipoElemento printf()
        printf("%d ",elemento);
        hay_siguiente(iter); //Booleano
    }
*/

    int i;
    for (i=0;i<lista->cantidad;++i){
        //printf("%d",lista->valores[i]) ERROR! No estoy accediendo a los elementos del vector
        printf("%d ",lista->valores[i]->clave); 
    }
    printf("\n");

}

int l_longitud(Lista lista){

    //Longitud se refiera a el TAMAÑO del vector dinamico actualmente
    //return TAMANIO_MAXIMO;
    //TAD Lista - vector, cantidad
    //ERROR! La longitud representa la CANTIDAD DE ELEMENTOS que tiene actualmente la lista
    return lista->cantidad;

}

void l_insertar(Lista lista, TipoElemento elemento, int pos){

    int posicion=lista->cantidad;
    TipoElemento variable; 

    while (posicion!=pos && lista->cantidad>0){
        variable=lista->valores[posicion-1]; //El manejo del vector se emplea con el ACCESO AL CAMPO VALORES (Vector)
        lista->valores[posicion-1]=lista->valores[posicion];
        lista->valores[posicion]=variable;
        --posicion;
    }

    lista->valores[pos]=elemento;
    lista->cantidad++;

}

void l_agregar(Lista lista, TipoElemento elemento){

    lista->valores[lista->cantidad]=elemento;
    lista->cantidad++;

}

TipoElemento l_recuperar(Lista lista, int pos){
    
    //return lista->valores[pos];
    return lista->valores[pos-1]; //Utilizamos pos-1 porque accedemos a la LISTA de forma ORDINAL (Elemento 1)
}

void l_borrar(Lista lista, int clave){
/*
    TipoElemento variable;
    int pos;

    

    for (int i=0;i<lista->cantidad;++i){
        if (lista->valores[i]->clave==clave){
            lista->valores[i]->clave=0;
            pos=i;
            while (pos<lista->cantidad-1){

                //ERROR! Se estan intercambiando las CLAVES pero no el ELEMENTO POR COMPLETO
                //lista->valores[pos]->clave=lista->valores[pos+1]->clave;
                
                variable=lista->valores[pos];
                lista->valores[pos]=lista->valores[pos+1];
                variable=lista->valores[pos+1]=variable;
                ++pos;
            }
            lista->cantidad=lista->cantidad-1;
        }
    }
*/

//IMPORTANTE! Cuando se INTERCAMBIAN los ELEMENTOS de una LISTA, es importante NO INTERCAMBIAR las CLAVES
//de las mismas

    int pos=0;
    while(pos<lista->cantidad){
        //Borrado habitual
        if (lista->valores[pos]->clave==clave){
            for (int i=pos;i<lista->cantidad;i++){
                lista->valores[i]=lista->valores[i+1];
            }
            lista->cantidad--; 
        }   
        else{
            pos++;
        }
    }


}

bool l_es_vacia(Lista lista){
    return lista->cantidad==0;
}


bool l_es_llena(Lista lista){
    return lista->cantidad==TAMANIO_MAXIMO;
}


TipoElemento l_buscar(Lista lista, int clave) {
    int pos = 0;
    while (pos < lista->cantidad) {
        if (lista->valores[pos]->clave == clave) {
            return lista->valores[pos];
        }
        pos++;
    }
    return NULL;
}


void l_eliminar(Lista lista, int pos) {
    if (pos > l_longitud(lista)) {
        return;
    }
    // Ahora intento eliminar
    if (1 <= pos && pos <= l_longitud(lista)) {
        for (int i = pos - 1; i < lista->cantidad; i++) {
            lista->valores[i] = lista->valores[i + 1];
        }
        lista->cantidad--;
    }
}

//OPERACIONES del ITERADOR (Originalmente en un archivo de encabezado o cabecera (.h) del TAD Lista)
//Recordemos que se define una estructura "Iterador" (Recorrido de la lista)
//Dicha estructura contiene una LISTA (La cual queremos recorrer) y una POSICIÓN ACTUAL


//1. Un ITERADOR para recorrer la lista
Iterador iterador(Lista lista){

    //Iterador iter;//
    Iterador iter=malloc(sizeof(struct IteradorRep));
    iter->lista=lista; //Guardamos la lista
    iter->posicionActual=0; //Se va a inicializar en el primer elemento (posición 0)
    return iter;
}

//2. Un BOOLEANO que indique si EXISTEN ELEMENTOS POR RECORRER
bool hay_siguiente(Iterador iterador){

    return iterador->posicionActual<iterador->lista->cantidad;

}

//3. Una FUNCIÓN que RETORNE el elemento ACTUAL y AVANCE a la posición siguiente
TipoElemento siguiente(Iterador iterador){
    
    return iterador->lista->valores[iterador->posicionActual++];

}
