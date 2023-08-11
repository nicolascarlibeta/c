

#include "arbol-binario-busqueda.h"
#include "tipo_elemento.c" //
#include "nodo.h"

static const int TAMANIO_MAXIMO=10;
static const int NULO=-1;

//Creamos la estructura de NodoArbol para CURSORES
struct NodoArbolRep{

    TipoElemento datos;
    int hi, hd, siguiente;

};

struct ArbolBinarioBusquedaRep{

    //Cursor (Vector de Nodos)
    NodoArbol arbol; //No necesita ser un PUNTERO (NodoArbol es un ALIAS)
    int raiz;
    int libre;

};

//Al utilizar un ALIAS para una estructura (siendo este ALIAS un PUNTERO a la dicha estructura), utilizamos
//el operador '->' para acceder a los campos del registro.

ArbolBinarioBusqueda abb_crear(){

    ArbolBinarioBusqueda NuevoArbolB=(ArbolBinarioBusqueda)malloc(sizeof(struct ArbolBinarioBusquedaRep));
    NuevoArbolB->arbol=calloc(TAMANIO_MAXIMO,sizeof(struct NodoArbolRep));
    NuevoArbolB->raiz=NULO; 
    NuevoArbolB->libre=0;
    
    //Ahora, ENCADENAMOS los NODOS LIBRES
    for(int i=0; i<TAMANIO_MAXIMO; i++){
        int siguiente=i+1;
        NuevoArbolB->arbol[i].datos=NULL;
        NuevoArbolB->arbol[i].hi=NULO;
        NuevoArbolB->arbol[i].hd=NULO;
        if(siguiente<TAMANIO_MAXIMO){
            NuevoArbolB->arbol[i].siguiente=siguiente;
        }
        else{
            NuevoArbolB->arbol[i].siguiente=NULO;
        }
    }

    return NuevoArbolB;

}

bool abb_es_vacio(ArbolBinarioBusqueda a){
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     
    return a->raiz==NULO;

}

bool abb_es_lleno(ArbolBinarioBusqueda a){

    return a->libre==NULO;

}

NodoArbol abb_raiz(ArbolBinarioBusqueda a){

    //return a->arbol[a->raiz];
    //ACLARACIÓN: Al tratarse (NodoArbol) de un PUNTERO a una estructura,
    //debemos devolver la DIRECCIÓN de la estructura Struct NodoArbolRep
    return &(a->arbol[a->raiz]);

}

void abb_insertar(ArbolBinarioBusqueda a, TipoElemento te){

    if(!abb_es_lleno(a)){

        //Se presta un nodo libre
        int p=a->libre;
        a->libre=a->arbol[p].siguiente;

        //Se carga el ex-nodo libre
        //a->raiz=p; ACLARACIÓN: Linea del código ANTERIOR
        a->arbol[p].datos=te; //IMPORTANTE!!!
        a->arbol[p].siguiente=NULO;
        a->arbol[p].hi=NULO;
        a->arbol[p].hd=NULO;

        //Si es el 1ER ELEMENTO
        if(abb_es_vacio(a)){
            a->raiz=p;
        }

        else{
            int q=a->raiz, actual=0;
            while(q!=NULO){
                
                actual=q;
                if(te->clave>a->arbol[q].datos->clave){
                    q=a->arbol[q].hd;
                    if(q==NULO){
                        a->arbol[actual].hd=p;
                    }
                }
                else{
                    q=a->arbol[q].hi;
                    if(q==NULO){
                        a->arbol[actual].hi=p;
                    }
                }

            }

        }

    }

}

TipoElemento abb_buscar(ArbolBinarioBusqueda a, int clave){

    TipoElemento te=te_crear(0);

    if(!abb_es_vacio(a)){

        int q=a->raiz, pos=0;
        bool esta=false;
        //while(!esta){ ERROR! Esta condición logra que si el elemento NO SE ENCUENTRA, 
        //le termine PREGUNTANDO a un valor que es NULO. Es decir, terminaria en un error
        //semantico y en un BUCLE INFINITO. Lo correcto es detenerse si q es NULO
        while(q!=NULO && !esta){ 
            
            if(a->arbol[q].datos->clave==clave){
                pos=q;
                esta=true;
            }
        
            else{
                if(clave>a->arbol[q].datos->clave){
                    q=a->arbol[q].hd;
                }
                else{
                    q=a->arbol[q].hi;
                }
            }
        }

        te=a->arbol[pos].datos;

    }

    else{
        te=NULL;
    }

    return te;

}
/*
int menorSubarbolDerecho(ArbolBinarioBusqueda a, int pa, int *p){

    int q=pa, menor=0;
    while(q!=NULO){
        
        menor=q;
        if(a->arbol[q].hi!=NULO && a->arbol[a->arbol[q].hi].hi==NULO){
            *p=q;
        }
        q=a->arbol[q].hi;
    
    }
    
    return menor;

}

void abb_eliminarSub(ArbolBinarioBusqueda a, int pa, int h, int i){

       
        //Si tiene DOS HIJOS...
        if(a->arbol[h].hi!=NULO && a->arbol[h].hd!=NULO){
            
            //Buscamos el menor del subarbol derecho
            int q=a->arbol[h].hd, padre=h;
            int m=menorSubarbolDerecho(a,q,&padre);
            a->arbol[h].datos=a->arbol[m].datos;
            
            //Eliminamos el nodo repetido
            int p=a->libre;
            a->arbol[m].siguiente=p;
            a->libre=m;
            if(padre==h){
                a->arbol[padre].hd=NULO;
            }
            else{
                a->arbol[padre].hi=NULO;
            }

        } 
    
        //Si tiene UN SOLO HIJO...
        else if(a->arbol[h].hi!=NULO || a->arbol[h].hd!=NULO){
            
            int q=0;
            //Si es el IZQUIERDO...
            if(a->arbol[h].hi!=NULO){
                q=a->arbol[h].hi;}
            
            //Si es el DERECHO...
            else{
                q=a->arbol[h].hd;}

            //Eliminamos el nodo
            int p=a->libre;
            a->arbol[h].siguiente=p;
            a->libre=h;

            if(i==1){
                a->arbol[pa].hd=q;
            }
            else if(i=-1){
                a->arbol[pa].hi=q;
                }
            else{
                a->raiz=q;
            }
        }

        //Si es un NODO HOJA...
        else{
            int p=a->libre;
            a->arbol[h].siguiente=p;
            a->libre=h;
            if(i==1){
                a->arbol[pa].hd=NULO;
            }
            else if(i==-1){
                a->arbol[pa].hi=NULO;
            }
            else{
                a->raiz=NULO;
            }
        }

}


void abb_eliminar(ArbolBinarioBusqueda a, int claveABorrar){

    if(!abb_es_vacio(a)){

        //Si es el NODO RAIZ...
        if(abb_raiz(a)->datos->clave==claveABorrar){
            int raiz=a->raiz;
            abb_eliminarSub(a,0,raiz,0);
        }

        else{

        int q=a->raiz, padre=0, hijo=0;
        bool esta=false;

        while(!esta){
            
            //Una vez en el NODO RAIZ...
            //Si su HIJO IZQUIERDO es IGUAL a la CLAVE...
            if(a->arbol[a->arbol[q].hi].datos->clave==claveABorrar){
                padre=q;
                hijo=a->arbol[q].hi;
                esta=true;
                abb_eliminarSub(a,padre,hijo,-1);
            }
            //Si su HIJO DERECHO es IGUAL a la CLAVE...
            else if(a->arbol[a->arbol[q].hd].datos->clave==claveABorrar){
                padre=q;
                hijo=a->arbol[q].hd;
                esta=true;
                abb_eliminarSub(a,padre,hijo,1);
            }
            //SI NO, seguimos buscando POR IZQUIERDA Y POR DERECHA
            else{
                if(claveABorrar>a->arbol[q].datos->clave){
                    q=a->arbol[q].hd;
                }
                else{
                    q=a->arbol[q].hi;
                }
            }
        
        }

        }
                
    }

}

void abb_eliminarSub2(ArbolBinarioBusqueda a, int pa, int h, int i){

       
        //Si tiene DOS HIJOS...
        if(a->arbol[h].hi!=NULO && a->arbol[h].hd!=NULO){
            
            //Buscamos el menor del subarbol derecho
            int q=a->arbol[h].hd, padre=h;
            int m=menorSubarbolDerecho(a,q,&padre);
            a->arbol[h].datos=a->arbol[m].datos;
            
            //Eliminamos el nodo repetido
            int p=a->libre;
            a->arbol[m].siguiente=p;
            a->libre=m;
            if(padre==h){
                a->arbol[padre].hd=NULO;
            }
            else{
                a->arbol[padre].hi=NULO;
            }

        } 
    
        //Si tiene UN SOLO HIJO...
        else if(a->arbol[h].hi!=NULO || a->arbol[h].hd!=NULO){
            
            int q=0;
            //Si es el IZQUIERDO...
            if(a->arbol[h].hi!=NULO){
                q=a->arbol[h].hi;}
            
            //Si es el DERECHO...
            else{
                q=a->arbol[h].hd;}

            //Eliminamos el nodo
            int p=a->libre;
            a->arbol[h].siguiente=p;
            a->libre=h;

            if(i==1){
                a->arbol[pa].hd=q;
            }
            else if(i=-1){
                a->arbol[pa].hi=q;
                }
            else{
                a->raiz=q;
            }
        }

        //Si es un NODO HOJA...
        else{
            int p=a->libre;
            a->arbol[h].siguiente=p;
            a->libre=h;
            if(i==1){
                a->arbol[pa].hd=NULO;
            }
            else if(i==-1){
                a->arbol[pa].hi=NULO;
            }
            else{
                a->raiz=NULO;
            }
        }

}


void abb_eliminarSub(ArbolBinarioBusqueda arbol, int nodo, int clave, bool *esta){

    if(nodo==NULO){}

    else{

        if(clave==arbol->arbol[nodo].datos->clave){
            *esta=true;
        }

        else if(clave>arbol->arbol[nodo].datos->clave){
            abb_eliminarSub(arbol,arbol->arbol[nodo].hd,clave,esta);
            if(*esta){
                abb_eliminarSub2(arbol,nodo,arbol->arbol[nodo].hd,1);
                *esta=false; //Es IMPORTANTE determinar un CORTE para cuando la RECURSIVIDAD VUELVA HACIA ATRAS
            }
        }

        else{
            abb_eliminarSub(arbol,arbol->arbol[nodo].hi,clave,esta);
            if(*esta){
                abb_eliminarSub2(arbol,nodo,arbol->arbol[nodo].hi,-1);
                *esta=false; //Es IMPORTANTE determinar un CORTE para cuando la RECURSIVIDAD VUELVA HACIA ATRAS
            }
        }
    }

}

void abb_eliminar(ArbolBinarioBusqueda a, int claveABorrar){

    bool esta=false;
    int raiz=a->raiz;
    if(abb_raiz(a)->datos->clave==claveABorrar){
        abb_eliminarSub2(a,0,raiz,0);
    }
    else{
        abb_eliminarSub(a,raiz,claveABorrar,&esta);
    }

}
*/

void abb_eliminar(ArbolBinarioBusqueda A, int clave){
    if (A->raiz==NULO){
        return;
    }
    else{
        int p = A->raiz;
        bool encontrado = false;
        while (p!=NULO && encontrado == false){
            if (clave > A->arbol[p].datos->clave){
                p = A->arbol[p].hd;
            }
            else if (clave < A->arbol[p].datos->clave){
                p = A->arbol[p].hi;
            }
            else{
                encontrado = true;
            }
        }
        if (encontrado){
            int q;
            int padre = A->raiz;
            if (A->arbol[padre].hi != NULO || A->arbol[padre].hd != NULO){
                if (A->arbol[padre].hd != NULO){
                    q = A->arbol[padre].hd;
                    while(A->arbol[q].hi != NULO){
                        padre = q;
                        q = A->arbol[q].hi;
                    }
                    A->arbol[p].datos = A->arbol[q].datos;
                    A->arbol[padre].hi = A->arbol[q].hd;
                }
                else{
                    q = A->arbol[padre].hi;
                    while (A->arbol[q].hd != NULO){
                        padre = q;
                        q = A->arbol[q].hd;
                    }
                    A->arbol[p].datos = A->arbol[q].datos;
                    A->arbol[padre].hd = A->arbol[q].hi;
                }
                A->arbol[q].hi = NULO;
                A->arbol[q].hd = NULO;
                A->arbol[q].siguiente = A->libre;
                A->libre = q;
            }
            else{
                A->arbol[padre].siguiente = A->libre;
                A->libre = padre;
                A->raiz = NULO;
            }
        }
    }
}







//Función adicional del TAD: Calcular la altura de la rama mas larga de un subarbol, según un nodo

void abb_altura(ArbolBinarioBusqueda a, int nodo, int cantidad, int *altura){

    //Recorrido en in-orden
    if(nodo==NULO){
        if(cantidad>*altura){
            *altura=cantidad;
        }
    }

    else{
        abb_altura(a,a->arbol[nodo].hi,cantidad+1,altura);
        abb_altura(a,a->arbol[nodo].hd,cantidad+1,altura);
    }

}
/*
void abb_AlturaDeNodoSub(ArbolBinarioBusqueda a, int nodo, int clave, int cantidad, int *altura){

    if(nodo==NULO){}

    else{
        abb_AlturaDeNodoSub(a,a->arbol[nodo].hi,clave,cantidad+1,altura);

        if(a->arbol[nodo].datos->clave==clave){
            abb_altura(a,nodo,0,altura);
        }

        abb_AlturaDeNodoSub(a,a->arbol[nodo].hd,clave,cantidad+1,altura);
    }

}*/

void abb_AlturaDeNodoSub(ArbolBinarioBusqueda a, int nodo, int clave, int cantidad, int *altura){

    if(nodo==NULO){}

    else{

        if(a->arbol[nodo].datos->clave==clave){
            abb_altura(a,nodo,0,altura);
        }

        else if(clave>a->arbol[nodo].datos->clave){
            abb_AlturaDeNodoSub(a,a->arbol[nodo].hd,clave,0,altura);
        }

        else{
            abb_AlturaDeNodoSub(a,a->arbol[nodo].hi,clave,0,altura);
        }

    }

}

int abb_AlturaDeNodo(ArbolBinarioBusqueda a, int clave){

    int raiz=a->raiz, altura=0;
    abb_AlturaDeNodoSub(a,raiz,clave,0,&altura);
    return altura;

}

//ESTA FUNCIÓN ES SOLO DE PRUEBA, NO IMITAR!!!!! 
void in_orden(ArbolBinarioBusqueda A, int q){
    TipoElemento x;
    if (q == NULO) {
        printf(".");
    }
    else {
        in_orden(A, A->arbol[q].hi);    
        x = A->arbol[q].datos;
        printf(" %d", x->clave);
        in_orden(A, A->arbol[q].hd);
    }
}      

void pre_orden(ArbolBinarioBusqueda A, int q){
    TipoElemento x;
    if (q == NULO) {
        printf(".");
    }
    else {
        x = A->arbol[q].datos;
        printf(" %d", x->clave);
        //x->clave= x->clave * 2;//borrar
        pre_orden(A, A->arbol[q].hi);
        pre_orden(A, A->arbol[q].hd);
    }
}

int main(){

ArbolBinarioBusqueda arbolbb=abb_crear();
TipoElemento x=te_crear(10);
abb_insertar(arbolbb,x);
x=te_crear(9);
abb_insertar(arbolbb,x);
x=te_crear(14);
abb_insertar(arbolbb,x);
x=te_crear(6);
abb_insertar(arbolbb,x);
pre_orden(arbolbb,arbolbb->raiz);
printf("\n");
abb_eliminar(arbolbb,9);
pre_orden(arbolbb,arbolbb->raiz);
printf("\n");


}