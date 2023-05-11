#include <stdio.h>
#include <stdlib.h>
#include "pilas.h"

char* pasar_a_base(int n, int b){
    char* numero = (char*)calloc(30, 1);
    Pila p = p_crear();
    TipoElemento x;
    int resto;
    int i = 0;

    while (n > 0){
        resto = n % b;
        n = n / b;
        x = te_crear(resto);
        p_apilar(p, x);
    }

    while (!p_es_vacia(p)){
        x = p_desapilar(p);
        if (x->clave <= 9){*(numero+i) = 48 + x->clave;}
        else{*(numero+i) = 55 + x->clave;}
        i++;
    }

    return numero;   
}

int main(){
    int nro, base;
    char* nro_base;
    printf("Ingrese numero: ");
    scanf("%d", &nro);
    printf("Ingrese base: ");
    scanf("%d", &base);
    nro_base = pasar_a_base(nro, base);
    printf("Numero convertido: %s\n", nro_base);

}