

#include "tp3_encabezado.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>


//TRABAJO PRÁCTICO 3

//Ejercicio 2.

bool buscarClave(Pila pila, int clave){

    bool existe=false;
    if (!p_es_vacia(pila)){
        Pila paux=p_crear();
        TipoElemento elemento;
        while (!p_es_vacia(pila)){
            elemento=p_desapilar(pila);
            if (elemento->clave==clave){
                existe=true;
            }
            p_apilar(paux,elemento);
            }
        p_intercambiar(pila,paux);
    }
    return existe;

}

void p_insertar(Pila pila, TipoElemento e, int pos){
    
    if (!p_es_llena(pila)){
        Pila paux=p_crear();
        TipoElemento elemento;
        int tope=p_longitud(pila);
        //Apila los elementos en auxiliar
        while (tope>=pos){
            elemento=p_desapilar(pila);
            p_apilar(paux,elemento);
            tope--;
        }
        //Inserta el elemento e
        p_apilar(pila,e);
        //Vuelva a desapilar los elementos
        p_intercambiar(pila,paux);
    }

    else{
        return;
    }

}

void borrarClave(Pila pila, int clave){ 

    if (!p_es_vacia(pila)){
        Pila paux=p_crear();
        TipoElemento e;
        bool borrar=false;
        while(!borrar && !p_es_vacia(pila)){
            e=p_desapilar(pila);
            if (e->clave!=clave){
                p_apilar(paux,e);}
            else{
                p_intercambiar(pila,paux);
                borrar=true;}
        }
                    
        if (p_es_vacia(pila)){
            p_intercambiar(pila,paux);}
    }

}
        
void intercambiarValores(Pila pila, int pos1, int pos2){

    Pila paux=p_crear(); 
    int tope=p_longitud(pila);
    TipoElemento elemento,epaux,e1,e2;
  
    while(tope>0){
        elemento=p_desapilar(pila); //Lee el elemento y lo compara
        if (tope==pos1){ //Desapila PILA y Apila en PAUX, y luego Desapila PAUX y Apila en PILA
            e1=te_crear_con_valor(elemento->clave,elemento->valor);   
        }
        else if (tope==pos2){
            e2=te_crear_con_valor(elemento->clave,elemento->valor);
        }
        p_apilar(paux,elemento);
        tope--; //Hago el conteo hacia atras
    }

    int topaux=1;
    while(!p_es_vacia(paux)){
        epaux=p_desapilar(paux);
        if (topaux==pos1){ 
            p_apilar(pila,e2);
        }
        else if (topaux==pos2){ 
            p_apilar(pila,e1);
        }
        else{
            p_apilar(pila,epaux);
        }
        topaux++; //Hago el conteo hacia adelante (Pila INVERSA)
    }


    
}

Pila duplicarContenido(Pila pila){

    Pila nuevaPila=p_crear(); //Usamos 3 pilas auxiliares
    Pila paux=p_crear(); 
    Pila paux2=p_crear(); 
    Pila paux3=p_crear(); 
    TipoElemento elemento;
    while (!p_es_vacia(pila)){
        elemento=p_desapilar(pila);
        p_apilar(paux,elemento); //Apila en paux
        p_apilar(paux2,elemento); //Apila en paux2
        p_apilar(paux3,elemento); //Apila en paux3
    }
    p_intercambiar(pila,paux); //paux para original
    p_intercambiar(nuevaPila,paux2); //paux2 para nueva pila
    p_intercambiar(nuevaPila,paux3); //paux3 para duplicar contenido
    free(paux);
    free(paux2); //Liberamos las pilas vacias
    free(paux3);
    return nuevaPila;

}

int contarElementos(Pila pila){

    int cantidad=0;
    Pila paux=p_crear();
    TipoElemento elemento;
    while (!p_es_vacia(pila)){
        elemento=p_desapilar(pila);
        p_apilar(paux,elemento);
        cantidad++;
        }

    p_intercambiar(pila,paux);

    return cantidad;
    
}

//Ejercicio 3.

bool pilasIguales(Pila p1, Pila p2){

    bool iguales=true;
    
    if (p_longitud(p1)!=p_longitud(p2)){
        iguales=false;} //1. Si las pilas NO TIENEN LA MISMA LONGITUD, NO SON IGUALES
    else{
        Pila paux=p_crear(); //ÚNICA PILA AUXILIAR
        TipoElemento e1,e2,*vector=calloc(p_longitud(p1),sizeof(TipoElemento));
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
        p_intercambiar(p1,paux);
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
TipoElemento elemento;
//Cargo la pila 1
for (int i=0;i<5;i++){
    elemento=te_crear(i*2);
    p_apilar(p1,elemento);
}
//Cargo la pila 2
for (int i=0;i<5;i++){
    elemento=te_crear(i*2);
    p_apilar(p2,elemento);
}
p_mostrar(p1);
p_mostrar(p2);

bool iguales=pilasIguales(p1,p2);
printf("%d\n",iguales);
printf("\n");

p_mostrar(p1);
p_mostrar(p2);

printf("La COMPLEJIDAD ALGORITMICA de este ejercicio es O(n), es decir, de complejidad LINEAL, debido a que si n representa el tamanio del problema general en un algortimo, en este caso n representa la CANTIDAD DE ELEMENTOS que pueda llegar a tener la pila. En el PEOR de los casos, el algoritmo tiene que estar desapilando las pilas desde 1 a N veces de forma lineal, para ir comparando si definitivamente las pilas son iguales.");

}


