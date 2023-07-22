

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

//////////////////////////////////////////////////////////////////////////////

//EXISTEN 2 FORMAS de RECORRER un ÁRBOL: En PROFUNDIDAD: 1. Pre-Orden, 2. In-Orden, 3. Post-Orden. y por ANCHURA:
//1. de IZQUIERDA a DERECHA, 2. de DERECHA a IZQUIERDA.

//Para MOSTRARLO solo en PROFUNDIDAD (3 FORMAS) y para CARGARLO solo en Pre-Orden
/*
void a_cArbol(ArbolBinario arbol, NodoArbol nodo, int subarbol){
    

    //1. Caso de Corte y Recursivo

    int numero;
    scanf("%d",&numero);
    NodoArbol n;
    TipoElemento e=te_crear(numero);

    //Debe CARGAR RECURSIVAMENTE CADA SUB-ARBOL (IZQ. Y DER.)
    if (numero==-1){
        n=a_conectar_hi(arbol,nodo,e);
    }
    else if(numero==1){
        n=a_conectar_hd(arbol,nodo,e);
    }
    else if(numero==0){
        n=a_establecer_raiz(arbol,e);
    }

    //SUBARBOL es un indicador
    a_cargarArbol(arbol,n,-1); //EMPIEZA CON ESTA INSTRUCCIÓN, HASTA que se CORTE
    a_cargarArbol(arbol,n,1); //Luego, AVANZA en esta instrucción

}
*/





int main(){




}











