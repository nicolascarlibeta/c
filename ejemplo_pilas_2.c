#include <stdio.h>
#include <stdlib.h>
#include "pilas.h"
#include "listas.h"

Lista InvertirLista(Lista L){
    Lista l2 = l_crear();
    Pila p = p_crear();
    Iterador i = iterador(L);
    TipoElemento x;

    while (hay_siguiente(i)){
        x = siguiente(i);
        p_apilar(p, x);
    }

    while (!p_es_vacia(p)){
        x = p_desapilar(p);
        l_agregar(l2, x);
    }

    return l2;
}

int main(){
    Lista l = l_crear();
    Lista l2;
    TipoElemento x;
    for(int i=0; i < 10; i++){
        x = te_crear(i);
        l_agregar(l, x);
    }
    l2 = InvertirLista(l);
    l_mostrar(l);
    l_mostrar(l2);

}
