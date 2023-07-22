

#include "listas.h"
#include "tipo_elemento.c" //
#include <stdlib.h>
#include <stdio.h>

//IMPLEMENTACIÓN DE LISTAS CON VECTORES DE REGISTROS (Conocido como CURSORES)

//Consiste en un Vector de Registros donde se guardan elementos utilizados llamados NODOS, y
//espacios SIN UTILIZAR conocidos como (espacios) NODOS LIBRES.

static const int TAMANIO_MAXIMO=10;
static const int NULO=-1;

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


/*CREAR una LISTA: Cuando creamos una lista, esta se encuentra VACÍA, lo que significa que cada
espacio del vector (Lista) representa un NODO pero en este caso, un NODO LIBRE. Dichos NODOS deben
estar CONECTADOS entre si para poseer su característica de enlace.*/

Lista l_crear(){

    //Lista (NODOS NO LIBRES)
    Lista nuevaLista=(Lista)malloc(sizeof(struct ListaRep));

    //Vector de NODOS, cuyos NODOS guardan datos del tipo TipoElemento (CURSOR: LIBRES Y NO LIBRES)
    nuevaLista->cursor=calloc(TAMANIO_MAXIMO,sizeof(struct Nodo));
    nuevaLista->inicio=NULO; 
    nuevaLista->libre=0;
    nuevaLista->cantidad=0;

    //Ahora, ENCADENAMOS los NODOS LIBRES
    for(int i=0; i<TAMANIO_MAXIMO; i++){
        int siguiente=i+1;
        nuevaLista->cursor[i].datos=NULL;
        if(siguiente<TAMANIO_MAXIMO){
            nuevaLista->cursor[i].siguiente=siguiente;
        }
        else{
            nuevaLista->cursor[i].siguiente=NULO;
        }
    }

    return nuevaLista;

}


//FUNCIONES DE INFORMACIÓN

bool l_es_llena(Lista lista){

    return lista->cantidad==TAMANIO_MAXIMO;
    
}

bool l_es_vacia(Lista lista){

    return lista->cantidad==0;

}

int l_longitud(Lista lista){

    return lista->cantidad;

}


//AGREGAR un ELEMENTO

void l_agregar(Lista lista, TipoElemento elemento){

    if(!l_es_llena(lista)){

        //Le asigno el PRIMER LIBRE que encuentre
        int l=lista->libre;
        int sig_libre=lista->cursor[l].siguiente;
        lista->libre=sig_libre;

        //NUEVO ELEMENTO A AGREGAR (APUNTA A NULO (-1))
        lista->cursor[l].datos=elemento;
        lista->cursor[l].siguiente=NULO;

        //Si es el PRIMER ELEMENTO...
        if(l_es_vacia(lista)){
            lista->inicio=l;
        }

        else{//Ciclo hasta encontrar el nulo del nodo no libre
            //Lo agrego al final de ese nodo
            
            int sig=lista->inicio;
            while(lista->cursor[sig].siguiente!=NULO){
                sig=lista->cursor[sig].siguiente;
            }
            lista->cursor[sig].siguiente=l;
        }

        //Incremento la cantidad
        lista->cantidad++;

    }

}


//BORRAR un ELEMENTO

void l_borrar(Lista lista, int clave){

    if(!l_es_vacia(lista)){

        int q=lista->inicio;

        //Si es el PRIMER ELEMENTO...
        while (lista->cursor[q].datos->clave==clave){
            lista->inicio=lista->cursor[q].siguiente;
            lista->cursor[q].siguiente=lista->libre;
            lista->libre=q;
            q=lista->inicio;

            //IMPORTANTE! DEBEMOS DECREMENTAR LA CANTIDAD DE ELEMENTOS
            lista->cantidad--;
        }

        while(q!=NULO){
           if(lista->cursor[q].siguiente!=NULO && lista->cursor[lista->cursor[q].siguiente].datos->clave==clave){

                int p=lista->cursor[lista->cursor[q].siguiente].siguiente;
                lista->cursor[lista->cursor[q].siguiente].siguiente=lista->libre;
                lista->libre=lista->cursor[q].siguiente;
                lista->cursor[q].siguiente=p;
                
                //IMPORTANTE! DEBEMOS DECREMENTAR LA CANTIDAD DE ELEMENTOS
                lista->cantidad--;
           
        
            }
            else{
                q=lista->cursor[q].siguiente;
            }
        }
        
    }
    
}


//ELIMINAR un ELEMENTO (POR POSICIÓN)

void l_eliminar(Lista lista, int pos){

    int q=lista->inicio;
    if(!l_es_vacia(lista) && pos>=1 && pos<=l_longitud(lista)){
        //Si es el PRIMER ELEMENTO (POSICIÓN)...
        if(pos==1){

            /*lista->inicio=lista->cursor[pos-1].siguiente;
            lista->cursor[pos-1].siguiente=lista->libre;
            lista->libre=pos;    ERROR! La posición ORDINAL NO COINCIDE con la posición FÍSICA del ELEMENTO*/

            lista->inicio=lista->cursor[q].siguiente;
            lista->cursor[q].siguiente=lista->libre;
            lista->libre=q;

        }

        /*while(lista->cursor[q].datos!=NULL){}  ERROR! (-1) NO ES una POSICIÓN VÁLIDA de un VECTOR.*/
        else{        
            for(int i=1; i<pos-1; i++){
                q=lista->cursor[q].siguiente;
                }

            int p=lista->cursor[q].siguiente;
            lista->cursor[q].siguiente=lista->cursor[p].siguiente;
            lista->cursor[p].siguiente=lista->libre;
            lista->libre=p;
            }

        lista->cantidad--;
    }

}


//INSERTAR un ELEMENTO

void l_insertar(Lista lista, TipoElemento elemento, int pos){

    if(!l_es_llena(lista)){

        //Si es la PRIMERA POSICIÓN...
        if(pos==1){

            //Libre le presta un nodo
            int p=lista->libre;
            lista->libre=lista->cursor[p].siguiente;

            int q=lista->inicio;
            lista->inicio=p;
            lista->cursor[p].datos=elemento;
            lista->cursor[p].siguiente=q;
            lista->cantidad++;
        }

        else if(pos>1 && pos<=l_longitud(lista)){
            int q=lista->inicio;
            for(int i=1; i<pos-1; i++){
                q=lista->cursor[q].siguiente;
                    }

            //Libre le presta un nodo
            int p=lista->libre;
            lista->libre=lista->cursor[p].siguiente;

            lista->cursor[p].datos=elemento;
            lista->cursor[p].siguiente=lista->cursor[q].siguiente;
            lista->cursor[q].siguiente=p;
            lista->cantidad++;
        }
        
        else if(pos>l_longitud(lista)){
            l_agregar(lista,elemento);
        }
        
 
    }


}


TipoElemento l_recuperar(Lista lista, int pos) {
    int temp2 = lista->inicio;
    for (int i = 0; i < pos - 1; i++) {
        temp2 = lista->cursor[temp2].siguiente;
    }
    return lista->cursor[temp2].datos;
}


TipoElemento l_buscar(Lista lista, int clave) {
    int p = lista->inicio;
    while (p != NULO) {
        if (lista->cursor[p].datos->clave == clave) {
            return lista->cursor[p].datos;
        }
        p = lista->cursor[p].siguiente;
    }
    return NULL;
}


void l_mostrar(Lista lista) {
    int temp2 = lista->inicio;
    printf("Contenido de la lista: ");
    while (temp2 != NULO) {
        printf("%d ", lista->cursor[temp2].datos->clave);
        temp2 = lista->cursor[temp2].siguiente;
    }
    printf("\n");
}


//Función adicional: Insertar un elemento en orden ascendente

void InsertarClaveOrdenada(Lista lista, TipoElemento elemento){

    //Comprobamos que no este LLENA
    if(!l_es_llena(lista)){

        //Si es el PRIMER ELEMENTO
        if(l_es_vacia(lista)){
            l_agregar(lista,elemento);
        }

        else{
            //Comprobamos si es menor que el PRIMER ELEMENTO
            if(elemento->clave<=l_recuperar(lista,1)->clave){
                l_insertar(lista,elemento,1);
            }

            else{
                //Comenzamos iterando desde lista->inicio
                int q=lista->inicio;
                bool insertar=false; 
                while(q!=NULO && !insertar){
                    if(lista->cursor[q].siguiente!=NULO && 
                    elemento->clave<=lista->cursor[lista->cursor[q].siguiente].datos->clave){

                        //Prestamos un nodo libre
                        int p=lista->libre;
                        lista->libre=lista->cursor[p].siguiente;
                        //IMPORTANTE! Siempre debemos GUARDAR el ELEMENTO dentro de la NUEVA POSICIÓN
                        lista->cursor[p].datos=elemento;

                        int sig=lista->cursor[q].siguiente;
                        lista->cursor[p].siguiente=sig;
                        lista->cursor[q].siguiente=p;
                        insertar=true;
                        
                    }
                    q=lista->cursor[q].siguiente;
                }

                if(q==NULO){
                    l_agregar(lista,elemento);
                }

                else{
                    lista->cantidad++;
                }

            }

        }

    }

}


//---------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------
// Rutinas del ITERADOR
//---------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------

Iterador iterador(Lista lista) {
    Iterador iter = (Iterador) malloc(sizeof(struct IteradorRep));
    iter->lista = lista;
    iter->posicionActual = lista->inicio;
    return iter;
}

bool hay_siguiente(Iterador iterador) {
    return (iterador->posicionActual != NULO);
}

TipoElemento siguiente(Iterador iterador) {
    TipoElemento actual = iterador->lista->cursor[iterador->posicionActual].datos;
    iterador->posicionActual = iterador->lista->cursor[iterador->posicionActual].siguiente;
    return actual;
}


