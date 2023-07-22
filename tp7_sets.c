

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
        while(cto_pertenece(C,clave)){
            printf("No se pueden ingresar claves REPETIDAS. Reintentelo: ");
            scanf("%d",&clave);}
        TipoElemento elemento=te_crear(clave);
        cto_agregar(C,elemento);
        }
        
}

bool cto_esSubconjunto(Conjunto A, Conjunto S){

    bool esSub=true;
    int i=1, cardinalidad=cto_cantidad_elementos(S);
    TipoElemento e=te_crear(0);
    while(esSub && i<=cardinalidad){ 
        e=cto_recuperar(S,i);
        if(!cto_pertenece(A,e->clave)){
            esSub=false;
        }
        i++;
    }

    return esSub;

}

bool cto_sonIguales(Conjunto A, Conjunto B){

    bool iguales=true;
    TipoElemento e=te_crear(0);
    if(cto_cantidad_elementos(A)!=cto_cantidad_elementos(B)){
        iguales=false;
    }
    else{
        int i=1, cardinalidad=cto_cantidad_elementos(A);
        while(iguales && i<=cardinalidad){
            e=cto_recuperar(A,i);
            if(!cto_pertenece(B,e->clave)){
                iguales=false;
            }
            i++;
        }
    }

    return iguales;

}

//TRABAJO PRÁCTICO 7

//Ejercicio 3


//Ejercicio 4

bool cto_porTransitividad(Conjunto A, Conjunto B, Conjunto C){

    bool transitividad=false;
    if(cto_esSubconjunto(B,A) && cto_esSubconjunto(C,B)){
        transitividad=cto_esSubconjunto(C,A);
    }
    return transitividad;

}

//Ejercicio 5

Conjunto cto_diferencia_simetrica(Conjunto A, Conjunto B){

    Conjunto DS=cto_union(cto_diferencia(A,B),
    cto_diferencia(B,A));
    return DS;

}

//Ejercicio 6

bool cto_subconjunto_propio(Conjunto A, Conjunto B){

    bool SP=false;
    if(cto_esSubconjunto(B,A) && !cto_sonIguales(A,B)){
        SP=true;
    }
    return SP;

}

//Ejercicio 7

bool cto_subconjunto_parcial(Conjunto A, Conjunto B){

    TipoElemento e=te_crear(0);
    bool subPar=false;
    bool subTot=false;
    int cardinalidad=cto_cantidad_elementos(A),
    mitad=cardinalidad/2, i=1, p=0;
    printf("%d",mitad);
    while(p<mitad && i<=cardinalidad){
        e=cto_recuperar(A,i);
        if(cto_pertenece(B,e->clave)){
            p++;
        }
        i++;
    }

    if(p>=mitad){
        subPar=true; 
    }

    return subPar;

}

//Ejercicios adicionales

Conjunto cto_crear_cto_Universal(int *rango){

    Conjunto C=cto_crear();
    //Desde 0 hasta cardinalidad-1
    int cardinalidad;
    printf("Ingrese la cardinalidad del conjunto universal: ");
    scanf("%d",&cardinalidad);
    *rango=cardinalidad-1;
    for(int i=0; i<cardinalidad; i++){
        TipoElemento e=te_crear(i);
        cto_agregar(C,e);
    }

    return C;

}

Conjunto cto_cargar_Subconjunto(int rango){

    int clave, cardinalidad;
    Conjunto C=cto_crear();
    TipoElemento e=te_crear(0);
    printf("Ingrese la cardinalidad del subconjunto: ");
    scanf("%d",&cardinalidad);
    while(cardinalidad>rango+1){
        printf("Intente nuevamente. Ingrese la cardinalidad del subconjunto: ");
        scanf("%d",&cardinalidad);
    }

    for(int i=0; i<cardinalidad; i++){
        printf("Ingrese una clave: ");
        scanf("%d",&clave);
        while((clave>rango) || (clave<0) || (cto_pertenece(C,clave))){
            printf("Intente nuevamente. Ingrese la clave: ");
            scanf("%d",&clave);
        }
        e=te_crear(clave);
        cto_agregar(C,e);
    }
    
    return C;

}

Conjunto cto_complemento(Conjunto A, Conjunto B){

    Conjunto C=cto_diferencia(A,B);
    return C;

}

bool cto_leydeDeMorgan(Conjunto A, Conjunto B, Conjunto U){

    //1era igualdad
    Conjunto AuB=cto_union(A,B);
    Conjunto cAuB=cto_complemento(U,AuB);

    //2da igualdad
    Conjunto cA=cto_complemento(U,A), cB=cto_complemento(U,B);
    Conjunto cAnB=cto_interseccion(cA,cB);

    return cto_sonIguales(cAuB,cAnB);

}


int main(){

Conjunto A=cto_crear();
Conjunto B=cto_crear();
cto_cargar(A);
cto_mostrar(A);
cto_cargar(B);
cto_mostrar(B);



}