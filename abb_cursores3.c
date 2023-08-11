#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "tipo_elemento.h"
const static int TAM_MAX = 100;
const static int NULO = -1;

struct NodoArbol{
    TipoElemento datos;
    int siguiente;
    int hi;
    int hd;
    int FE;
};

struct ArbolBinarioBusquedaRep {
    struct NodoArbol *cursor;
    int raiz;
    int libre;
    int cantidad;
};

typedef struct ArbolBinarioBusquedaRep *ArbolBinarioBusqueda;

void abb_eliminar(ArbolBinarioBusqueda A, int clave){
    if (A->raiz==NULO){
        return;
    }
    else{
        int p = A->raiz;
        bool encontrado = false;
        while (p!=NULO && encontrado == false){
            if (clave > A->cursor[p].datos->clave){
                p = A->cursor[p].hd;
            }
            else if (clave < A->cursor[p].datos->clave){
                p = A->cursor[p].hi;
            }
            else{
                encontrado = true;
            }
        }
        if (encontrado){
            int q;
            int padre = A->raiz;
            if (A->cursor[padre].hi != NULO || A->cursor[padre].hd != NULO){
                if (A->cursor[padre].hd != NULO){
                    q = A->cursor[padre].hd;
                    while(A->cursor[q].hi != NULO){
                        padre = q;
                        q = A->cursor[q].hi;
                    }
                    A->cursor[p].datos = A->cursor[q].datos;
                    A->cursor[padre].hi = A->cursor[q].hd;
                }
                else{
                    q = A->cursor[padre].hi;
                    while (A->cursor[q].hd != NULO){
                        padre = q;
                        q = A->cursor[q].hd;
                    }
                    A->cursor[p].datos = A->cursor[q].datos;
                    A->cursor[padre].hd = A->cursor[q].hi;
                }
                A->cursor[q].hi = NULO;
                A->cursor[q].hd = NULO;
                A->cursor[q].siguiente = A->libre;
                A->libre = q;
            }
            else{
                A->cursor[padre].siguiente = A->libre;
                A->libre = padre;
                A->raiz = NULO;
            }
        }
    }
}







