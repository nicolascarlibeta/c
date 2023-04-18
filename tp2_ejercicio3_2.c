

#include "tipo_elemento.h"
#include "tipo_elemento.c" //
#include "listas.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

void l_agregar(Lista lista, TipoElemento elemento){

    lista->valores[lista->cantidad]=elemento;
    lista->cantidad++;

}

TipoElemento l_recuperar(Lista lista, int pos){
    
    //return lista->valores[pos];
    return lista->valores[pos]; //Utilizamos pos-1 porque accedemos a la LISTA de forma ORDINAL (Elemento 1)
}

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


//Para realizar la siguiente función, implementamos un algoritmo tal que NO IMPORTE de que forma
//este IMPLEMENTADA la lista, sino que la ESPECIFICACIÓN sea correcta y que se den los MISMOS
//RESULTADOS para cada implementación. Para ello, solo vamos a hacer uso de las OPERACIONES
//principales del TAD Lista.

//MENU.
void listaPorTeclado(Lista lista){

    int numero, opcion;
    bool cerrar=false;
    //CREAMOS EL TIPOELEMENTO
    while (!(cerrar)){
        printf("Agregue un numero: ");
        scanf("%d",&numero);
        TipoElemento temp=te_crear(numero); //"Clave" como campo de datos
        l_agregar(lista,temp);
        printf("Desea agregar otro numero (1:SI - 2:NO): ");
        scanf("%d",&opcion);
        if (opcion==2){
            cerrar=true;}
        
        }

}

bool esMultiplo(Lista l1,Lista l2,bool *escalar,int *esc); //IMPLEMENTACIÓN hecha originalmente en un archivo de cabecera (.h)

bool esMultiplo(Lista l1,Lista l2,bool *escalar,int *esc){

    //IMPORTANTE! Para acceder a los elementos de una LISTA, debemos acceder al valor de su CLAVE
    Iterador iterl1=iterador(l1); //ACCEDO a la lista L1
    Iterador iterl2=iterador(l2); //ACCEDO a la lista L2
    TipoElemento e1=l_recuperar(l1,0);
    TipoElemento e2=l_recuperar(l2,0);
    int division=e2->clave/e1->clave; 
    bool multiplo=true;

    while(hay_siguiente(iterl1) || multiplo){
        TipoElemento numerol1=siguiente(iterl1); //RETORNA la ESTRUCTURA y AVANZA al siguiente
        TipoElemento numerol2=siguiente(iterl2); //RETORNA la ESTRUCTURA y AVANZA al siguiente
        if ((numerol2->clave%numerol1->clave)!=0){
            multiplo=false;
        }
        else{
            if ((numerol2->clave/numerol1->clave)!=division && (*escalar)){
                *escalar=false;
            }
        }
    }
    *esc=division;
    free(iterl1);
    free(iterl2);
    return multiplo;
  
}


int main(){

//Creamos dos LISTAS (L1 y L2)

Lista l1=l_crear();
Lista l2=l_crear();

//Verificamos si es L2 es MÚLTIPLO de L1 por un ESCALAR
bool escalar=true;
int esc=0;

listaPorTeclado(l1);
printf("Lista 1\n");
l_mostrarLista(l1);
printf("\n");
int cantidadL1=l_longitud(l1)-1;

listaPorTeclado(l2);
printf("Lista 2\n");
l_mostrarLista(l2);
int cantidadL2=l_longitud(l2)-1;

if (esMultiplo(l1,l2,&escalar,&esc)){ //Le pasamos la DIRECCIÓN de la variable al PUNTERO
    printf("Es multiplo\n");
}
else{
    printf("NO es multiplo\n");
}


free(l1); //IMPORTANTE! Liberar las LISTAS de la memoria
free(l2); //IMPORTANTE! Liberar las LISTAS de la memoria

}