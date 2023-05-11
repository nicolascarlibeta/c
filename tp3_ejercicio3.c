
#include "Tp3.h"
#include "../tiposDeDato/tipo_elemento.h"
#include "../Validaciones/validaciones.h"
#include "../Pilas/pilas.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool pilasIguales(Pila p1, Pila p2){

    bool iguales=true;
    
    if (p_largo_pila(p1)!=p_largo_pila(p2)){
        iguales=false;} //1. Si las pilas NO TIENEN LA MISMA LONGITUD, NO SON IGUALES
    else{
        Pila paux=p_crear(); //ÚNICA PILA AUXILIAR
        TipoElemento e1,e2,*vector=calloc(p_largo_pila(p1),sizeof(TipoElemento));
        int pos=0;
        while(iguales && !p_es_vacia(p1)){
            e1=p_desapilar(p1);
            e2=p_desapilar(p2);
            if (e1->clave!=e2->clave){
                iguales=false;
            }
            p_apilar(paux,e1);
            vector[pos]=e2; //Guardo el elemento 2
            pos++;
        }
        p_copiar_pila(p1,paux);
        TipoElemento elemento;
        for (int j=pos-1;j>=0;j--){
            elemento=vector[j];
            p_apilar(p2,elemento);
    }

    }

    return iguales;
    
}

int main(){

Pila p1=p_crear(),p2=p_crear();

cargarPila(p1); //Cargo la pila 1
printf("Pila 1: \n");
p_mostrar(p1); //Muestro la pila 1
cargarPila(p2); //Cargo la pila 2
printf("Pila 2: \n");
p_mostrar(p2); //Muestro la pila 2

if(pilasIguales(p1,p2)){
    printf("Las pilas son IGUALES.\n");
}
else{
    printf("Las pilas NO SON IGUALES.\n");
}

printf("Verificamos que las pilas no esten destruidas: \n");
printf("Pila 1: \n");
p_mostrar(p1); //Muestro la pila 1
printf("Pila 2: \n");
p_mostrar(p2); //Muestro la pila 2
printf("La COMPLEJIDAD ALGORITMICA de este ejercicio es O(n), es decir, de complejidad LINEAL, debido a que si n representa el tamanio del problema general en un algortimo, en este caso n representa la CANTIDAD DE ELEMENTOS que pueda llegar a tener la pila. En el PEOR de los casos, el algoritmo tiene que estar desapilando las pilas desde 1 a N veces de forma lineal, para ir comparando si definitivamente las pilas son iguales.");

}