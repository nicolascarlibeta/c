#ifndef NODO_H
#define NODO_H
#include "tipo_elemento.h"

struct NodoArbolRep;
typedef struct NodoArbolRep *NodoArbol;

// retorna el hijo izquierdo
NodoArbol n_hijoizquierdo(NodoArbol N);

// retorna el hijo derecho
NodoArbol n_hijoderecho(NodoArbol N);

// Crea un Nodo y lo retorna
NodoArbol n_crear(TipoElemento te);

// Retorna el TIPOELEMENTO de un Nodo o NULL si no existe el NODO (CONTENIDO NULO)
TipoElemento n_recuperar(NodoArbol N);

#endif // NODO_H
