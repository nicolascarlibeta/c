

#include "conjuntos.h"
#include "conjuntos_l.c" //
#include <stdio.h>



void cto_cargar(Conjunto C){

    int clave, cardinalidad;
    printf("Ingrese la cardinalidad del conjunto: ");
    scanf("%d",&cardinalidad);
    for(int i=0; i<cardinalidad; i++){
        printf("Ingrese una clave: ");
        scanf("%d",&clave);
        TipoElemento elemento=te_crear(clave);
        cto_agregar(C,elemento);
        }

}



int main(){


Conjunto A=cto_crear();
Conjunto B=cto_crear();
cto_cargar(A);
cto_cargar(B);
Conjunto C=cto_union(A,B);
cto_mostrar(A);
cto_mostrar(B);
cto_mostrar(C);
C=cto_interseccion(A,B);
cto_mostrar(C);
C=cto_diferencia(A,B);
cto_mostrar(C);




}



