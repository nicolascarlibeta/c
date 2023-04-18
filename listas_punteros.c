
#include "listas.h"
#include <stdlib.h>

//IMPLEMENTACIÓN DE LISTAS CON APUNTADORES

//Utilizamos el concepto de NODO, el cual contiene dos datos IMPORTANTES: el DATO en cuestión y
//un ENLACE al elemento SIGUIENTE. Dicho enlace es un PUNTERO a TipoElemento, y éste APUNTA al siguiente NODO o 
//al siguiente ELEMENTO.

//Definimos un NODO (Estructura enlazada)
struct Nodo{
    TipoElemento datos; //Los DATOS que se van a almacenar dentro del NODO, un ELEMENTO que conforma la LISTA
    struct Nodo *siguiente;
};

//Definimos el TAD LISTA. El concepto de LISTA que vamos a utilizar se conoce como LISTA SIMPLEMENTE ENLAZADA,
//es decir, una LISTA que va a estar compuesta de ciertos ELEMENTOS conocidos como NODOS. Dentro de los NODOS, 
//vamos a poder guardar los DATOS que va a contener la lista y a su vez, la DIRECCIÓN del elemento SIGUIENTE.
//De esta forma, podemos ENLAZAR los elementos de la lista de forma UNIDIRECCIONAL (de izq. a der.).
//Por lo tanto, la LISTA se conforma de ciertos NODOS ENLAZADOS y un PUNTERO al INICIO del PRIMER NODO,
//que determina donde se encuentra el INICIO de la LISTA. Por último, el ULTIMO nodo que conforme a la LISTA
//apuntará a un valor NÚLO (NULL), y asi se determinará el FINAL DE LA LISTA. 

struct ListaRep{
    struct Nodo *inicio; //Puntero a Struct Nodo (Apunta a la dirección de un NODO)
    int cantidad; //LONGITUD de la LISTA
}; //Utilizamos ";" para separar los TAD Registros

//ITERADOR (REGISTRO)
struct IteradorRep{     //NO contiene la LISTA como cuando implementabamos vectores
    struct Nodo *posicionActual; 
};

//CREAR una Lista con PUNTEROS
Lista l_crear(){

    Lista nuevaLista=malloc(sizeof(struct ListaRep));
    nuevaLista->inicio=NULL; //¿Por que se accede con el operador si no es un puntero (->)?
    nuevaLista->cantidad=0;

    return nuevaLista;

}

//AGREGAR un elemento al FINAL de la lista
void l_agregar(Lista lista,TipoElemento elemento){

    //Creamos un NODO (Elemento para agregar a la lista)
    struct Nodo *nuevoNodo=malloc(sizeof(struct Nodo));
    nuevoNodo->datos=elemento;
    nuevoNodo->siguiente=NULL;

    //No EXISTE una INDEXACIÓN. Se debe RECORRER la lista POR COMPLETO.
    //Si la lista NO esta vacia
    struct Nodo *nodoInicial=lista->inicio; //Nodo INICIAL
    //Si el NODO INICIAL actual apunta a NULL, entonces CONECTAMOS el NODO INICIAL al NUEVO NODO
    while (nodoInicial->siguiente!=NULL){
        nodoInicial=nodoInicial->siguiente;}

    nodoInicial->siguiente=nuevoNodo;    
    lista->cantidad++; 

}

//LONGITUD de una lista
int l_longitud(Lista lista){
    return lista->cantidad;
}

//INSERTAR un elemento a una lista
void l_insertar(Lista lista,TipoElemento elemento,int pos){

    //Creamos un nuevo nodo
    struct Nodo *nuevoNodo=malloc(sizeof(struct Nodo));
    nuevoNodo->datos=elemento;
    
    //Insertar en la PRIMERA POSICIÓN
    if (pos==0){
        nuevoNodo->siguiente=lista->inicio;
        lista->inicio=nuevoNodo;
    }

    //Insertar INTERNAMENTE
    else{
        int posicion=0;
        struct Nodo *nodoInicial=lista->inicio;
        while (posicion!=pos-1){
            nodoInicial=nodoInicial->siguiente;
            posicion++;
        }
        nuevoNodo->siguiente=nodoInicial->siguiente; //n se conecta a 3
        nodoInicial->siguiente=nuevoNodo; //2 se conecta a n
        lista->cantidad++;}

}
