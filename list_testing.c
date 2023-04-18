

#include "listas.h"
#include <stdio.h>

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

