
#include <stdbool.h>
#include "pilas.h"
#include "pilas_vectores.c"

//TRABAJO PRÁCTICO 3

//Ejercicio 2.

bool buscarClave(Pila pila, int clave);
void p_insertar(Pila pila, TipoElemento e, int pos);
void borrarClave(Pila pila, int clave);
void intercambiarValores(Pila pila, int pos1, int pos2);
Pila duplicarContenido(Pila pila);
int contarElementos(Pila pila);

//Ejercicio 3.

bool pilasIguales(Pila p1, Pila p2);

