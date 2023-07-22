

#include "pilas.h"
#include "pilas_utilidades.h"
#include "pilas_vectores.c"


bool buscarClave(Pila pila, int clave){

    bool esta=false;

    if (p_es_vacia(pila)){
        esta=false;
    }
    else{ 

    Pila paux=p_crear(); //CREAMOS LA PILA AUXILIAR
    TipoElemento e=te_crear(0);    

    while(!p_es_vacia(pila) && !esta){
        e=p_desapilar(pila);
        p_apilar(paux,e);
        if (e->clave==clave){
            esta=true;
        }

    }
    p_intercambiar(pila,paux);
}
    return esta;


}


Pila insertarElemento(Pila pila, TipoElemento elemento, int posicion){

    Pila p1=p_crear();

    //Si la PILA está VACIA, se APILA como NUEVO TOPE
    

    //SIEMPRE que debamos INSERTAR un elemento en un TAD, corroboramos que NO ESTE LLENO
    if (!p_es_llena(pila)){

    Pila paux1=p_crear(),paux=p_crear();
    TipoElemento e=te_crear(0); //e=0

        while(!p_es_vacia(pila)){
            e=p_desapilar(pila);
            //APILAMOS 2 VECES (UN ELEMENTO EN CADA PILA AUXILIAR)
            p_apilar(paux,e); //Original
            p_apilar(paux1,e); //Pila 1
        }
        p_intercambiar(pila,paux); //Original
        p_intercambiar(p1,paux1); //Pila 1
        free(paux); //Liberamos la P.AUX

        if (p_es_vacia(pila)){
            p_apilar(p1,elemento);
            }

        else{     
        int pos=1;
        while(pos!=posicion){ //El ciclo while ejecuta TODAS LAS INSTRUCCIONES RESTANTES, sin importar
            e=p_desapilar(p1); //si PREVIAMENTE se cumplió un determinado valor de verdad para su fin.
            p_apilar(paux1,e);
            pos++; 
        }
        p_apilar(p1,elemento);
        p_intercambiar(p1,paux1);
        } 

    }

    return p1;


}





int main(){

Pila p1=p_crear();
TipoElemento elemento;
//Cargo la pila 1
for (int i=0;i<5;i++){
    elemento=te_crear(i*3);
    p_apilar(p1,elemento);
}
p_mostrar(p1);
bool esta=buscarClave(p1,0);
printf("%d\n",esta);
printf("\n");
p_mostrar(p1);

TipoElemento e=te_crear(4);
Pila p2=insertarElemento(p1,e,3);
p_mostrar(p2);
p_mostrar(p1);


}



