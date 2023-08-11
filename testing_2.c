
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include "listas.h"
#include "listas_vectores.c" //


//BORRAR un elemento y todas las ocurrencias de un vector

void borrar(int vector[], int elemento, int *cantidad);

void borrar(int vector[], int elemento, int *cantidad){

//IMPORTANTE!!! Utilizamos la expresion "vector[]" para identificar el parametro

    int pos=0;
    while(pos<*cantidad){
        //Borrado habitual
        if (vector[pos]==elemento){
            for (int i=pos;i<*cantidad;i++){
                vector[i]=vector[i+1];
            }
            //cantidad--; //(!) cantidad NUNCA se modifica, NECESITA un return o un puntero
            //*cantidad--; //Los punteros NO ACEPTAN la expresion "*puntero--". Utilizamos *puntero=*puntero-1 por defecto
            *cantidad=*cantidad-1; 
        }   
        else{
            pos++;
        }
    }


}

//Ejercicio 1 (Retornar las claves mayores de una lista) -Generico -Iterativo

Lista RetornarMayores(Lista lista); //Originalmente en .h

Lista RetornarMayores(Lista lista){

    //Que sucede si esta VACIA?
    if (!(l_es_vacia(lista))){
        Iterador iter=iterador(lista);
        TipoElemento mayor=l_recuperar(lista,1); //Retorna el elemento COMPLETO, NO la clave solamente
        //while (hay_siguiente(lista)) //ERROR! La funcion hay_siguiente recibe un ITERADOR, donde se encuentra la LISTA
        while (hay_siguiente(iter))
        {
            TipoElemento elemento=siguiente(iter);
            if (elemento->clave>mayor->clave){
                //mayor->clave=elemento->clave //ERROR! Es CRUCIAL que se intercambie la ESTRUCTURA COMPLETA y NO los valores de los CAMPOS de forma individual
                mayor=elemento; //Utilizamos esta expresion para denotar que una estructura TIENE LOS MISMOS VALORES POR COMPLETO de otra estructura
            }
        }
        

        Lista l=l_crear();
        //while (hay_siguiente(lista)) ERROR! La funcion hay_siguiente recibe un ITERADOR, donde se encuentra la LISTA
        Iterador it=iterador(lista); //IMPORTANTE! ITERADOR NUEVO para cada ITERACION
        while (hay_siguiente(it))
        {
            //TipoElemento e=siguiente(lista); ERROR! La funcion siguiente() recibe como parametro un ITERADOR
            TipoElemento e=siguiente(it);
            if (e->clave==mayor->clave){
                l_agregar(l,e);
            }
        }
        return l; // Esta instruccion es CORRECTA //
        }
    else{
        printf("NO SE PUEDE REALIZAR: La lista esta vacia.\n");
    }


}


int main(){

Lista l=l_crear();
Lista l_may=l_crear();
for (int i=0;i<7;++i){
    if (i>5){
        TipoElemento te=te_crear((i*3)-7);
        l_agregar(l,te);}
    else{
       TipoElemento te=te_crear((i*(-3)));
       l_agregar(l,te);}
}
l_mostrarLista(l);
printf("\n");
l_may=RetornarMayores(l);
l_mostrarLista(l_may);
printf("\n");

}

















































/*
int vector[10], *puntero;
puntero=vector;
puntero[3]=10; 
*(puntero+3)=10; //Idem que puntero[3]=10;


//BORRAR un elemento del vector
void borrar(int vector[], int elemento); //Cuando utilizamos como parametro un vector, expresamos "nombre[]"
*/





















