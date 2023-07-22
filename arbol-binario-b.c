

#include "arbol-binario-busqueda.h"
#include "nodo.h"
#include "nodo.c" //


static const int TAMANIO_MAXIMO=10;

struct ArbolBinarioBusquedaRep{

    NodoArbol raiz;
    int cantidad;

};

ArbolBinarioBusqueda abb_crear(){

    ArbolBinarioBusqueda nuevoArbolBB=(ArbolBinarioBusqueda)malloc(sizeof(struct ArbolBinarioBusquedaRep));
    nuevoArbolBB->raiz=NULL;
    nuevoArbolBB->cantidad=0;
    return nuevoArbolBB;

}

NodoArbol abb_raiz(ArbolBinarioBusqueda a){

    return a->raiz;

}

bool abb_es_vacio(ArbolBinarioBusqueda a){

    return a->raiz==NULL;
    //return a->cantidad==0;

}


bool abb_es_lleno(ArbolBinarioBusqueda a){

    return a->cantidad==TAMANIO_MAXIMO;

}


void abb_insertarSub(ArbolBinarioBusqueda arbol, NodoArbol nodo, TipoElemento te){

    if(nodo==NULL){}

    else{
        if(te->clave<=nodo->datos->clave){
            abb_insertarSub(arbol,n_hijoizquierdo(nodo),te);
            if(n_hijoizquierdo(nodo)==NULL){
                NodoArbol N=n_crear(te);
                nodo->hi=N;
            }
        }
        else{
            abb_insertarSub(arbol,n_hijoderecho(nodo),te);
            if(n_hijoderecho(nodo)==NULL){
                NodoArbol N=n_crear(te);
                nodo->hd=N;
            }
        }
    }


}

void abb_insertar(ArbolBinarioBusqueda a, TipoElemento te){

    if(!abb_es_lleno(a)){
    //PRIMERO, CREAMOS EL NODO
    NodoArbol nuevoNodo=n_crear(te);

    //Si es el PRIMER ELEMENTO...
    if(abb_es_vacio(a)){
        a->raiz=nuevoNodo;
    }

    else{
        
        abb_insertarSub(a,abb_raiz(a),te);

        /*
        NodoArbol n=n_crear(n_recuperar(abb_raiz(a)));
        NodoArbol *actual;
        while(n!=NULL){

            actual=&n;
            if(te->clave<=n->datos->clave){
                n=n_hijoizquierdo(n);
                if(n==NULL){
                    actual->hi=nuevoNodo;
                }
            }

            else{
                n=n_hijoderecho(n);
                if(n==NULL){
                    actual->hd=nuevoNodo;
                }
            }
        
        }*/
        
    }

    a->cantidad++;
    
    }

}

void abb_buscarSub(ArbolBinarioBusqueda arbol, NodoArbol nodo, int clave, TipoElemento *te){

    
    if(nodo==NULL){
        te=NULL;
    }
    
    else{
        
        if(clave==nodo->datos->clave){
            *te=n_recuperar(nodo);
        }

        else if(clave>nodo->datos->clave){
            abb_buscarSub(arbol,n_hijoderecho(nodo),clave,te);
        }

        else{
            abb_buscarSub(arbol,n_hijoizquierdo(nodo),clave,te);
        }


    }

}

TipoElemento abb_buscar(ArbolBinarioBusqueda a, int clave){

    TipoElemento te=te_crear(0);

    if(!abb_es_vacio(a)){
        abb_buscarSub(a,abb_raiz(a),clave,&te);
    }

    else{
        te=NULL;
    }

    return te;

}

//Muestra el arbol a partir de un nodo (de ahi hacia abajo)
void pre_orden(NodoArbol N){
    TipoElemento x;
    if (N == NULL) {
        printf(".");
    }
    else {
        x = n_recuperar(N);
        printf(" %d", x->clave);
        //x->clave= x->clave * 2;//borrar
        pre_orden(n_hijoizquierdo(N));
        pre_orden(n_hijoderecho(N));
    }
}

//Muestra el arbol a partir de un nodo (de ahi hacia abajo)
void in_orden(NodoArbol N){
    TipoElemento x;
    if (N == NULL) {
        printf(".");
    }
    else {
        in_orden(n_hijoizquierdo(N));
        x = n_recuperar(N);
        printf(" %d", x->clave);
        in_orden(n_hijoderecho(N));
    }
}


int main(){

ArbolBinarioBusqueda A=abb_crear();
TipoElemento E=te_crear(10);
abb_insertar(A,E);
E=te_crear(7);
abb_insertar(A,E);
E=te_crear(12);
abb_insertar(A,E);
E=te_crear(15);
abb_insertar(A,E);
pre_orden(abb_raiz(A));

}