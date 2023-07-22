

#include "arbol-binario.h"
#include "nodo.c" //
#include "listas.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//////////////////////////////////////////////////////////////////////////////

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

void l_insertar(Lista lista, TipoElemento elemento, int pos){

    int posicion=lista->cantidad;
    TipoElemento variable; 

    while (posicion!=pos && lista->cantidad>0){
        variable=lista->valores[posicion-1]; //El manejo del vector se emplea con el ACCESO AL CAMPO VALORES (Vector)
        lista->valores[posicion-1]=lista->valores[posicion];
        lista->valores[posicion]=variable;
        --posicion;
    }

    lista->valores[pos]=elemento;
    lista->cantidad++;

}

void l_agregar(Lista lista, TipoElemento elemento){

    lista->valores[lista->cantidad]=elemento;
    lista->cantidad++;

}

TipoElemento l_recuperar(Lista lista, int pos){
    
    //return lista->valores[pos];
    return lista->valores[pos-1]; //Utilizamos pos-1 porque accedemos a la LISTA de forma ORDINAL (Elemento 1)
}

void l_borrar(Lista lista, int clave){
/*
    TipoElemento variable;
    int pos;

    

    for (int i=0;i<lista->cantidad;++i){
        if (lista->valores[i]->clave==clave){
            lista->valores[i]->clave=0;
            pos=i;
            while (pos<lista->cantidad-1){

                //ERROR! Se estan intercambiando las CLAVES pero no el ELEMENTO POR COMPLETO
                //lista->valores[pos]->clave=lista->valores[pos+1]->clave;
                
                variable=lista->valores[pos];
                lista->valores[pos]=lista->valores[pos+1];
                variable=lista->valores[pos+1]=variable;
                ++pos;
            }
            lista->cantidad=lista->cantidad-1;
        }
    }
*/

//IMPORTANTE! Cuando se INTERCAMBIAN los ELEMENTOS de una LISTA, es importante NO INTERCAMBIAR las CLAVES
//de las mismas

    int pos=0;
    while(pos<lista->cantidad){
        //Borrado habitual
        if (lista->valores[pos]->clave==clave){
            for (int i=pos;i<lista->cantidad;i++){
                lista->valores[i]=lista->valores[i+1];
            }
            lista->cantidad--; 
        }   
        else{
            pos++;
        }
    }


}

bool l_es_vacia(Lista lista){
    return lista->cantidad==0;
}

TipoElemento l_buscar(Lista lista, int clave) {
    int pos = 0;
    while (pos < lista->cantidad) {
        if (lista->valores[pos]->clave == clave) {
            return lista->valores[pos];
        }
        pos++;
    }
    return NULL;
}


void l_eliminar(Lista lista, int pos) {
    if (pos > l_longitud(lista)) {
        return;
    }
    // Ahora intento eliminar
    if (1 <= pos && pos <= l_longitud(lista)) {
        for (int i = pos - 1; i < lista->cantidad; i++) {
            lista->valores[i] = lista->valores[i + 1];
        }
        lista->cantidad--;
    }
}

//OPERACIONES del ITERADOR (Originalmente en un archivo de encabezado o cabecera (.h) del TAD Lista)
//Recordemos que se define una estructura "Iterador" (Recorrido de la lista)
//Dicha estructura contiene una LISTA (La cual queremos recorrer) y una POSICIÓN ACTUAL


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
    
    return iterador->lista->valores[iterador->posicionActual++];

}

//////////////////////////////////////////////////////////////////////////////






















//ARBOLES BINARIOS Y N-ARIOS

//Los ARBOLES son estructuras dinámicas compuestas por NODOS, que pueden tener un camino hacia
//DOS O MAS NODOS conocidos como HIJOS o SUB-ARBOLES IZQUIERDO y DERECHO.

//CONSIDERACIONES IMPORTANTES PARA EL MANEJO DE ARBOLES:
/*
1. TODO ARBOL posee un NODO llamado RAÍZ, y ese Nodo conceptualmente es ÚNICO (ÁRBOL PRINCIPAL)
2. Los Arboles son estructuras RECURSIVAS, donde cada Nodo a su vez es RAÍZ de un SUB-ÁRBOL
3. Cada Nodo tiene DOS APUNTADORES O CAMINOS: HIJO IZQUIERDO E HIJO DERECHO. Si es un Arbol BINARIO, 
CADA NODO tiene entre 0 hasta 2 HIJOS NODOS. Si es N-ARIO, CADA NODO tiene entre 0 hasta n HIJOS NODOS.
4. Solo se puede RECORRER EL ARBOL DESDE la RAÍZ HACIA ABAJO.
5. NO EXISTE un APUNTADOR DESDE los HIJOS hacia el NODO PADRE.
*/

//Estructura del ARBOL

const static int TAMANIO_MAXIMOA=40;

struct ArbolBinarioRep{

    NodoArbol raiz; //RAÍZ
    int cantidad; //CANTIDAD de NODOS o ELEMENTOS

};


//CREAR un ARBOL VACIO (SIN RAÍZ, SIN NODOS)
ArbolBinario a_crear(){

    ArbolBinario nuevoArbol=(ArbolBinario)malloc(sizeof(struct ArbolBinarioRep));
    nuevoArbol->raiz=NULL;
    nuevoArbol->cantidad=0;
    return nuevoArbol;

}

//ESTABLECER o INSERTAR una RAÍZ (Solo puede existir UN NODO RAÍZ del ARBOL)
NodoArbol a_establecer_raiz(ArbolBinario a, TipoElemento te){
    
    NodoArbol nr=n_crear(te);
    if (a->raiz!=NULL){ //SOLO SE PUEDE ESTABLECER UNA ÚNICA RAÍZ
        nr=a->raiz;
    }
    else{
        a->raiz=nr;
        a->cantidad++;   
    }
    return nr;
    

}

//CONECTAR un HIJO IZQUIERDO
NodoArbol a_conectar_hi(ArbolBinario a, NodoArbol pa, TipoElemento te){

    NodoArbol hijoizq=n_crear(te);
    pa->hi=hijoizq;
    a->cantidad++;
    return hijoizq;

}

//CONECTAR un HIJO DERECHO
NodoArbol a_conectar_hd(ArbolBinario a, NodoArbol pa, TipoElemento te){

    NodoArbol hijoder=n_crear(te);
    pa->hd=hijoder;
    a->cantidad++;
    return hijoder;

}

//RETORNAR el NODO RAÍZ del ÁRBOL
NodoArbol a_raiz(ArbolBinario a){

    return a->raiz;

}

//VERIFICAR que el ÁRBOL está LLENO
bool a_es_lleno(ArbolBinario a){

    return a->cantidad==TAMANIO_MAXIMOA;

}

//VERIFICAR que el ÁRBOL está VACIO
bool a_es_vacio(ArbolBinario a){

    return a->raiz==NULL;

}

//CANTIDAD de NODOS del ÁRBOL
int a_cantidad_elementos(ArbolBinario a){

    return a->cantidad;

}

//Función adicional: Calcular la altura del subarbol (rama mas larga) de un nodo dado

/*
void a_altura_subarbolSub2(ArbolBinario a, NodoArbol nodo_actual, int cantidad, int *altura){

    if(nodo_actual==NULL){
        if(cantidad>*altura){
            *altura=cantidad;
        }
    }

    else{
        a_altura_subarbolSub2(a,n_hijoizquierdo(nodo_actual),cantidad+1,altura);
        a_altura_subarbolSub2(a,n_hijoderecho(nodo_actual),cantidad+1,altura);
    }

}


void a_altura_subarbolSub(ArbolBinario a, NodoArbol n, int clave, int *altura){

    if(n==NULL){}

    else{
        if(n_recuperar(n)->clave==clave){
            a_altura_subarbolSub2(a,n,0,altura);
        }

        a_altura_subarbolSub(a,n_hijoizquierdo(n),clave,altura);
        a_altura_subarbolSub(a,n_hijoderecho(n),clave,altura);
    }

}


int a_altura_subarbol(ArbolBinario A, int clave){

    int altura_subarbol=0;
    a_altura_subarbolSub(A,a_raiz(A),clave,&altura_subarbol);
    return altura_subarbol-1;

}
*/

//CARGAR el ÁRBOL (PRE-ORDEN)
bool ingresoEntero(int* n){
    char s[10];
    bool resultado = true;
    *n=0;
    printf("Ingrese una clave numerica o '.' para nulo: ");
    scanf("%s", s);
    if (s[0]=='.'){
        resultado = false;
    }else{
        for (int i = 0; s[i] != '\0'; i++) {
            if ((s[i]>='0')&&(s[i]<='9')){
                *n = *n * 10 + (s[i] - 48);}
        }
    }
    return resultado;
}


void Cargar_SubArbol(ArbolBinario A, NodoArbol N, int sa){
    TipoElemento X;
    NodoArbol N1;
    int n;
    bool b;
    if(!a_es_lleno(A)){
        b= ingresoEntero(&n);
        if (b){
            X= te_crear(n);
            
            if(sa == -1) N1 = a_conectar_hi(A, N, X);
            else if(sa == 1) N1 = a_conectar_hd(A, N, X);
            else N1 = a_establecer_raiz(A, X);

            Cargar_SubArbol(A, N1, -1);
            Cargar_SubArbol(A, N1, 1);
        }
    }    
}


void cargar_arbol_binario(ArbolBinario A){
    Cargar_SubArbol(A, NULL, 0);
}


//MOSTRAR POR PANTALLA (PRE-ORDEN)
void pre_orden(NodoArbol N){
    TipoElemento x;
    if (N == NULL) {
        printf(".");
    }
    else {
        x = n_recuperar(N);
        printf(" %d", x->clave);
        pre_orden(n_hijoizquierdo(N));
        pre_orden(n_hijoderecho(N));
    }
}

//MOSTRAR POR PANTALLA (IN-ORDEN)
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

//MOSTRAR POR PANTALLA (POST-ORDEN)
void post_orden(NodoArbol N){
    TipoElemento x;
    if (N == NULL) {
        printf(".");
    }
    else {
        post_orden(n_hijoizquierdo(N));
        post_orden(n_hijoderecho(N));
        x = n_recuperar(N);
        printf(" %d", x->clave);
    }
}


