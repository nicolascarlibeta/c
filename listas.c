

#include "tipo_elemento.c" //
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

void l_borrar(Lista lista, int clave){

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
    
    TipoElemento elementoActual=iterador->lista->valores[iterador->posicionActual];
    iterador->posicionActual++;
    return elementoActual;

}

int main(){


TipoElemento te=te_crear(4),te2=te_crear(7); //Creamos una variable y le asignamos la clave "4" (valor de variable)
//printf("%d",te->clave);
Lista l=l_crear(); //Creamos una NUEVA LISTA
int longitud;

//l_agregar(l,te); //Agrego un elemento AL FINAL de la lista (En este caso, el único elemento)
//l->valores[0]->clave=7; //ERROR! Se accede a un campo "clave" de un TipoElemento que no se encuentra en la lista 
//printf("%d\n",l->valores[0]->clave);

//Llenar la lista con (TipoElemento)s [Cargar el vector DINÁMICO]
for (int i=0;i<7;++i){
    l_agregar(l,te);
}

l_insertar(l,te2,3); //Inserto un TE de clave 7 en la posición 3

longitud=l_longitud(l);
//printf("%d\n",longitud); //La LONGITUD debe ser 1 a partir de ahora (Cantidad de elementos)
l_mostrarLista(l);
printf("\n");
l_borrar(l,4);
l_mostrarLista(l);
free(te); //Siempre que usemos MEMORIA DINÁMICA utilizamos free() para liberar el espacio prev. asignado


}