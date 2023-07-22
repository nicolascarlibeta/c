

#include <stdbool.h>
#include "colas.h"
#include "colas_vectores.c"
#include "pilas.h"
#include "pilas_utilidades.h"
#include "listas.h"

//Ejercicio 2.

bool estaCola(Cola cola, TipoElemento x);
Cola c_insertar(Cola cola, TipoElemento elemento, int posicion);
Cola c_borrar(Cola cola, TipoElemento elemento);
Cola c_copiar(Cola cola);
Cola c_invertir(Cola cola);

//Ejercicio 3.

void l_desencolar(Cola cola, Lista lista);
bool c_sonIguales(Cola c1, Cola c2);

//Ejercicio 4.

Cola sinRepetidos(Cola cola);

//Ejercicio 6.

Lista valoresComunes(Pila pila, Cola cola);




//PILAS IMPLEMENTADAS CON PUNTEROS

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
