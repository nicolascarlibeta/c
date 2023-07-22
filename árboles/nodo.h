#ifndef NODO_H
#define NODO_H
#include "tipo_elemento.h"

struct NodoArbolRep {
    TipoElemento datos;
    struct NodoArbolRep *hi;
    struct NodoArbolRep *hd;
    int FE;   //Factor de Equilibro de Cada nodo para el autobalanceo
};
typedef struct NodoArbolRep *NodoArbol;

// Retorna el hijo izquierdo
NodoArbol n_hijoizquierdo(NodoArbol N);

// Retorna el hijo derecho
NodoArbol n_hijoderecho(NodoArbol N);

// Crea un Nodo y lo retorna
NodoArbol n_crear(TipoElemento te);

// Retorna el TIPOELEMENTO de un Nodo o NULL si no existe el NODO (CONTENIDO NULO)
TipoElemento n_recuperar(NodoArbol N);

#endif // NODO_H
