

#include "listas.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>

//Listas

//Para implementar listas con VECTORES DINAMICOS, necesitamos crear un TIPO de DATO que nos ayude a categorizar
//el tipo de datos que queremos guardar dentro de la LISTA. Definimos el tipo "TipoElemento"

//Utilizamos la expresión "typedef" para definir el NUEVO TIPO
//Originalmente en un archivo de encabezado o cabecera (.h)

//Registro CLAVE-VALOR
/*
struct TipoElementoReg{
    int clave;
    void *valor; //Puntero a Void
}

typedef struct TipoElementoReg *TipoElemento;


//Utilizamos FUNCIONES particulares para asociarle sus valores a los campos CLAVE y VALOR, independientemente

//Ahora, IMPLEMENTAMOS EL TAD "LISTA" CON VECTORES DINÁMICOS
//Originalmente en un archivo de encabezado o cabecera (.h)

//Existen DOS tipos de estructuras/registros a implementar

//1. El TAD LISTA

struct ListaReg{
    TipoElemento *valores; //Vector de (TipoElementos)'s (puntero)
    int cantidad;
}

typedef struct ListaReg *Lista; //TAD Lista creada

//IMPORTANTE! El vector DEBE declararse bajo un TAMAÑO MAXIMO CONSTANTE

//2. El tipo "ITERADOR" (Utilizado para RECORRER LA LISTA)

struct IteradorReg{
    Lista lista;
    int posicionActual;
}

typedef struct IteradorReg *Iterador;

//Para el registro "Iterador" vamos a implementar ciertas OPERACIONES, las cuales podran acceder
//al contenido de la lista de manera que se asegure la integridad de los datos y de forma autorizada

//OPERACIONES del TAD LISTA (Originalmente en un archivo de encabezado o cabecera (.h) del TAD Lista)

Lista l_crear(); //Crear una LISTA NUEVA
int l_longitud(Lista lista); //Cantidad de ELEMENTOS
void l_insertar(Lista lista, TipoElemento elemento, int pos); //INSERTAR un elemento
void l_agregar(Lista lista, TipoElemento elemento); //AGREGAR un elemento


//OPERACIONES del ITERADOR (Originalmente en un archivo de encabezado o cabecera (.h) del TAD Lista)

//1. Un ITERADOR para recorrer la lista
//2. Un BOOLEANO que indique si EXISTEN ELEMENTOS POR RECORRER
//3. Una FUNCIÓN que RETORNE el elemento ACTUAL y AVANCE al elemento siguiente









*/

int main(){

//TipoElemento te=te_crear(4),te2=te_crear(7); //Creamos una variable y le asignamos la clave "4" (valor de variable)
//printf("%d",te->clave);
Lista l=l_crear(); //Creamos una NUEVA LISTA
int longitud;
/*
//l_agregar(l,te); //Agrego un elemento AL FINAL de la lista (En este caso, el único elemento)
//l->valores[0]->clave=7; //ERROR! Se accede a un campo "clave" de un TipoElemento que no se encuentra en la lista 
//printf("%d\n",l->valores[0]->clave);
*/
//Llenar la lista con (TipoElemento)s [Cargar el vector DINÁMICO]
for (int i=0;i<7;++i){
    TipoElemento te=te_crear(i);
    l_agregar(l,te);
}
/*
l_insertar(l,te2,3); //Inserto un TE de clave 7 en la posición 3

longitud=l_longitud(l);
//printf("%d\n",longitud); //La LONGITUD debe ser 1 a partir de ahora (Cantidad de elementos)
l_mostrarLista(l);
printf("\n");
l_borrar(l,4);
l_mostrarLista(l);
free(te); //Siempre que usemos MEMORIA DINÁMICA utilizamos free() para liberar el espacio prev. asignado
*/
l_borrar(l,6);
l_mostrarLista(l);


char numero[20];
char num[]="3,9";
strcpy(numero,num);
printf("%s",numero);
int pos=0;
bool entero=true;

//strlen(): Longitud de una cadena con caracteres no nulos
    

for (int pos=0;pos<strlen(numero);pos++){
    if (!isdigit(numero[pos])){
        printf(" No es entero");
        entero=false;
        break;}
}

printf(" Es entero %d",entero);

}