

#include "colas.h"
#include "colas_utilidades.h" //NO FORMAN PARTE DEL TAD COLAS
#include "colas_vectores.c"



//COLAS

//Cuando queremos ENCOLAR (Agregar) UN NUEVO ELEMENTO a la Cola, lo hacemos
//desde la DERECHA, y si queremos DES-ENCOLAR (Eliminar) UN ELEMENTO de la Cola, lo hacemos desde la IZQUIERDA.
//Solo podemos acceder al elemento del FRENTE de la Cola (IZQUIERDA).

bool buscarElemento(Cola cola, TipoElemento elemento){

    bool esta=false;

    if(!c_es_vacia(cola)){

        Cola caux=c_crear();
        TipoElemento e=te_crear(0);

        while(!c_es_vacia(cola)){
            e=c_desencolar(cola);
            c_encolar(caux,e);
            if(!esta){ //OBSERVACIÓN! Se pueden unificar las comparaciones en UNA SOLA
                if(e->clave==elemento->clave && e->valor==elemento->valor){
                    esta=true;
                }
            }
        }
        c_intercambiar(cola,caux);


    }

    return esta;

}


Cola colarse(Cola cola, TipoElemento elemento, int posicion){

    Cola caux=c_crear(),c1=c_crear();
    TipoElemento e=te_crear(0);
    int pos=1;
    
    if (!c_es_llena(cola)){
    while(!c_es_vacia(cola)){

        e=c_desencolar(cola);
        c_encolar(caux,e); //Original
        if (pos==posicion){
            c_encolar(c1,elemento);
        }
        c_encolar(c1,e); //Cola PRINCIPAL
        pos++;

    }
    c_intercambiar(cola,caux);
    }

    return c1;
    

}


Cola c_borrar(Cola cola, TipoElemento elemento){

    Cola c1=c_crear(),caux=c_crear();
    if(!c_es_vacia(cola)){

        TipoElemento e=te_crear(0); 

        while(!c_es_vacia(cola)){
            e=c_desencolar(cola);
            c_encolar(caux,e);
            if(e->clave!=elemento->clave){
                c_encolar(c1,e);}
                
        }
        c_intercambiar(cola,caux); //Original se preserva

    }

    return c1;


}



int main(){

Cola cola=c_crear();
TipoElemento elemento=te_crear(0),e=te_crear(0);

//Cargo la cola 1
for (int i=0;i<5;i++){
    elemento=te_crear(i*3);
    c_encolar(cola,elemento);
}
TipoElemento e2=te_crear(6);
c_encolar(cola,e2);

c_mostrar(cola);

bool esta=buscarElemento(cola,e);
printf("%d",esta);
printf("\n");

c_mostrar(cola);

TipoElemento ele=te_crear(4);
Cola c=colarse(cola,ele,3);
c_mostrar(c);
c_mostrar(cola);

TipoElemento te=te_crear(6);
Cola c1=c_borrar(cola,te);
c_mostrar(c1);
c_mostrar(cola);




}