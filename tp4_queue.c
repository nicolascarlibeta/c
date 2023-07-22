

#include "tp4_encabezado.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

//Ejercicio 2.

bool estaCola(Cola cola, TipoElemento x){

    Cola caux=c_crear();
    TipoElemento e=te_crear(0);
    bool esta=false;
    while(!c_es_vacia(cola)){
        e=c_desencolar(cola);
        if (x->clave==e->clave && !esta){
            esta=true;
        }
        c_encolar(caux,e);      
    }
    c_intercambiar(cola,caux);

    return esta;

} 

Cola c_insertar(Cola cola, TipoElemento elemento, int posicion){

    Cola caux=c_crear();
    Cola caux2=c_crear(); //Caux2 para Cola ORIGINAL
    TipoElemento e=te_crear(0);
    int pos=0;
    while(!c_es_vacia(cola)){
        e=c_desencolar(cola);
        pos++;
        if (pos==posicion){
            c_encolar(caux,elemento);
            c_encolar(caux,e);
        }
        else{
            c_encolar(caux,e);      
        }
        c_encolar(caux2,e); //Cola ORIGINAL     
    }
    c_intercambiar(cola,caux2);

    return caux;

}

Cola c_borrar(Cola cola, TipoElemento elemento){

    Cola caux=c_crear();
    Cola caux2=c_crear(); //Cola ORIGINAL
    TipoElemento x=te_crear(0);
    while(!c_es_vacia(cola)){
        x=c_desencolar(cola);
        if (x->clave!=elemento->clave){
            c_encolar(caux,x);
        }
        c_encolar(caux2,x);
    }
    c_intercambiar(cola,caux2);

    return caux;

}

Cola c_copiar(Cola cola){

    Cola caux=c_crear();
    Cola caux2=c_crear(); //ORIGINAL
    if (!c_es_vacia(cola)){
        TipoElemento x=te_crear(0);
        while(!c_es_vacia(cola)){
            x=c_desencolar(cola);
            c_encolar(caux,x);
            c_encolar(caux2,x); //Original
        }
        c_intercambiar(cola,caux2);
        }

    return caux;

}

Cola c_invertir(Cola cola){

    Cola caux=c_crear();
    Cola caux2=c_crear(); //O
    Pila pila=p_crear();
    TipoElemento x=te_crear(0);
    while(!c_es_vacia(cola)){

        x=c_desencolar(cola);
        p_apilar(pila,x);
        c_encolar(caux2,x); //O

    }
    while(!p_es_vacia(pila)){
        x=p_desapilar(pila);
        c_encolar(caux,x);
    }
    c_intercambiar(cola,caux2);

    return caux;

}


//Ejercicio 3.

void l_desencolar(Cola cola, Lista lista){

    Iterador iter=iterador(lista);
    TipoElemento e=te_crear(0);
    while(hay_siguiente(iter)){
        e=siguiente(iter);
        c_encolar(cola,e);
    }


}

bool c_sonIguales(Cola c1, Cola c2){

    bool iguales=true;

    if (c_longitud(c1)!=c_longitud(c2)){
        iguales=false;
    }
    else{
        Cola caux=c_crear(); //ÚNICA COLA AUX.
        Lista lista=l_crear();
        TipoElemento x=te_crear(0),x2=te_crear(0); //x2
        while(!c_es_vacia(c1)){
        
            x=c_desencolar(c1);
            x2=c_desencolar(c2);
         
            if (x->clave!=x2->clave && iguales){
                iguales=false;}

            c_encolar(caux,x);
            l_agregar(lista,x2); //x2
            
            }
        
        c_intercambiar(c1,caux);
        l_desencolar(c2,lista);

        }
    
    return iguales;
                
}


//Ejercicio 4.

Cola sinRepetidos(Cola cola){

    int mayor=0;
    Cola caux=c_crear();
    Cola caux2=c_crear(); //Original
    TipoElemento e=te_crear(0);
    e=c_desencolar(cola);
    c_encolar(caux,e);
    mayor=e->clave;
    while(!c_es_vacia(cola)){
        
        e=c_desencolar(cola);
        if (e->clave>mayor){
            mayor=e->clave;
        }
        c_encolar(caux,e);

    }
    c_intercambiar(cola,caux);
    
    int vector[mayor+1];
    memset(vector,0,sizeof(vector));
    //SINTAXIS del "memset()": memset(vector,número de inic.,sizeof(vector))
    
    while(!c_es_vacia(cola)){
        
        e=c_desencolar(cola);
        vector[e->clave]++;
        c_encolar(caux,e);

    }
    c_intercambiar(cola,caux);
    
    while(!c_es_vacia(cola)){
        
        e=c_desencolar(cola);
        
        if (vector[e->clave]==1){
            c_encolar(caux,e);}

        c_encolar(caux2,e); //Original

    }
    c_intercambiar(cola,caux2);

    return caux;

    
}


//Ejercicio 6.

Lista valoresComunes(Pila pila, Cola cola){

    struct Registro{
        int clave;
        int pos;
        };

    struct Registro vector_p[50], 
    vector_c[50];
    memset(vector_p,0,sizeof(vector_p));
    memset(vector_c,0,sizeof(vector_c));
    Pila paux=p_crear();
    Cola caux=c_crear();
    Lista lista=l_crear();
    TipoElemento p=te_crear(0),c=te_crear(0);
    int posicion_p=p_longitud(pila), pos=0;
    while(!p_es_vacia(pila)){

        p=p_desapilar(pila);
        vector_p[p->clave].clave++;
        vector_p[p->clave].pos=posicion_p;
        p_apilar(paux,p);
        posicion_p--;
        pos++;

    }
    p_intercambiar(pila,paux);
    pos=0;

    while(!c_es_vacia(cola)){

        c=c_desencolar(cola);
        vector_c[c->clave].clave++;
        vector_c[c->clave].pos=pos+1;
        pos++;
        c_encolar(caux,c);
    }
    c_intercambiar(cola,caux);
    pos=0;

    if (vector_p[pos].clave>0 && vector_c[pos].clave>0){
        l_agregar(lista);
        }

    



}


int main(){

Cola c=c_crear();
Cola cola=c_crear();
TipoElemento x=te_crear(12);
c_encolar(c,x);
TipoElemento x2=te_crear(6);
c_encolar(c,x2);
TipoElemento x3=te_crear(12);
c_encolar(c,x3);
TipoElemento x4=te_crear(8);
c_encolar(c,x4);
c_mostrar(c);

cola=sinRepetidos(c);
c_mostrar(cola);
c_mostrar(c);






}