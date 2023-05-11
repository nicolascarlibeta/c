
#include "tipo_elemento.h"
#include "tipo_elemento.c" //
#include "listas.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



//MENU.
void listaPorTeclado(Lista lista){

    int numero, opcion;
    bool cerrar=false;
    //CREAMOS EL TIPOELEMENTO
    while (!(cerrar)){
        printf("Agregue un numero: ");
        scanf("%d",&numero);
        TipoElemento temp=te_crear(numero); //"Clave" como campo de datos
        l_agregar(lista,temp);
        printf("Desea agregar otro numero (1:SI - 2:NO): ");
        scanf("%d",&opcion);
        if (opcion==2){
            cerrar=true;}
        
        }

}



bool esMultiplo(Lista l1,Lista l2,int *pos1,int *pos2,bool *escalar); //IMPLEMENTACIÓN hecha originalmente en un archivo de cabecera (.h)

bool esMultiplo(Lista l1,Lista l2,int *pos1,int *pos2,bool *escalar){

    //IMPORTANTE! Para acceder a los elementos de una LISTA, debemos acceder al valor de su CLAVE

    bool multiplo;
    int resultado=l2->valores[l2->cantidad-1]->clave/l1->valores[l1->cantidad-1]->clave;

    if(*pos1<0){ 
        multiplo=true;
    }
    else if ((l2->valores[*pos2]->clave%l1->valores[*pos1]->clave)!=0){
        multiplo=false; 
    }
    else{
        int resultado_sig=l2->valores[*pos2]->clave/l1->valores[*pos1]->clave;
        if(resultado!=resultado_sig && escalar){
            *escalar=false;
        }
        *pos1=*pos1-1;
        *pos2=*pos2-1;
        return esMultiplo(l1,l2,pos1,pos2,escalar);
    }

    return multiplo;

}



//Para realizar la siguiente función, implementamos un algoritmo tal que NO IMPORTE de que forma
//este IMPLEMENTADA la lista, sino que la ESPECIFICACIÓN sea correcta y que se den los MISMOS
//RESULTADOS para cada implementación. Para ello, solo vamos a hacer uso de las OPERACIONES
//principales del TAD Lista.




int main(){

//Creamos dos LISTAS (L1 y L2)

Lista l1=l_crear();
Lista l2=l_crear();

//Verificamos si es L2 es MÚLTIPLO de L1 por un ESCALAR
bool escalar=true;

listaPorTeclado(l1);
printf("Lista 1\n");
l_mostrarLista(l1);
printf("\n");
int cantidadL1=l_longitud(l1)-1;

listaPorTeclado(l2);
printf("Lista 2\n");
l_mostrarLista(l2);
int cantidadL2=l_longitud(l2)-1;

if (esMultiplo(l1,l2,&cantidadL1,&cantidadL2,&escalar)){ //Le pasamos la DIRECCIÓN de la variable al PUNTERO
    printf("Es multiplo\n");
}
else{
    printf("NO es multiplo\n");
}
printf("Escalar es %d",escalar);










}

#include "tipo_elemento.h"
//#include "tipo_elemento.c" //
#include "listas.h"
#include "listas_vectores.c"
//#include "listas_apuntadores.c"
//#include "listas_cursores.c"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

//Para realizar la siguiente función, implementamos un algoritmo tal que NO IMPORTE de que forma
//este IMPLEMENTADA la lista, sino que la ESPECIFICACIÓN sea correcta y que se den los MISMOS
//RESULTADOS para cada implementación. Para ello, solo vamos a hacer uso de las OPERACIONES
//principales del TAD Lista.


//Validar un numero entero

bool validacionEnteroEj3(char num[], int *n);

bool validacionEnteroEj3(char num[], int *n){

    int pos=0;
    bool entero=true;

    // Validamos que solo se hayan ingresado números enteros
    for (int pos=0;pos<strlen(num);pos++){
        if (!isdigit(num[pos])){
            entero=false;
            break;}
            
}   *n=atoi(num);
    return entero;

    }

    
//MENU.

bool listaPorTeclado(Lista lista, int l);

bool listaPorTeclado(Lista lista, int l){

    int numero, opcion=1;
    bool cerrar=false, ok=true;
    //CREAMOS EL TIPOELEMENTO
    while (!(cerrar)){ //Cargamos los elementos HASTA que creemos la LISTA COMPLETA
        printf("Agregue un numero: ");
        scanf("%d",&numero); //Validamos como cadena de strings
        
        if (numero==0 && l==1){
            printf("ERROR!. La lista L1 NO puede contener UNO O MAS ceros como elemento. Reintentelo.");
            ok=false;
            break;}
        
        TipoElemento temp=te_crear(numero); //"Clave" como campo de datos
        l_agregar(lista,temp);
        printf("Desea agregar otro numero? (1:SI - 2:NO): ");
        scanf("%d",&opcion);
        if ((opcion!=1 && opcion!=2)){
            printf("ERROR!. Debe ingresar SOLO las opciones del menu: (Enter:SI - 2:NO). Reintentelo.");
            cerrar=true;
            ok=false;}
        else if (opcion==2){
            cerrar=true;}   
        }

    return ok;
}


bool esMultiplo(Lista l1,Lista l2,bool *escalar,int *esc); //IMPLEMENTACIÓN hecha originalmente en un archivo de cabecera (.h)

bool esMultiplo(Lista l1,Lista l2,bool *escalar,int *esc){

    //IMPORTANTE! Para acceder a los elementos de una LISTA, debemos acceder al valor de su CLAVE
    Iterador iterl1=iterador(l1); //ACCEDO a la lista L1
    Iterador iterl2=iterador(l2); //ACCEDO a la lista L2
    TipoElemento e1=l_recuperar(l1,1),e2=l_recuperar(l2,1);
    float division=e2->clave/e1->clave; 
    bool multiplo=true;

    if (l1->cantidad!=l2->cantidad){
        multiplo=false;
    }

    while(hay_siguiente(iterl1) && multiplo){ //Para que se deje de buscar si L2=L1*q, basta con que UNO sea FALSO
        TipoElemento numerol1=siguiente(iterl1); //RETORNA la ESTRUCTURA y AVANZA al siguiente
        TipoElemento numerol2=siguiente(iterl2); //RETORNA la ESTRUCTURA y AVANZA al siguiente
        if ((numerol2->clave%numerol1->clave)!=0){
            multiplo=false;
        }
        else{
            if ((numerol2->clave/numerol1->clave)!=division && escalar){
                *escalar=false;
            }
        }
    }
    *esc=division;
    free(iterl1); //Liberamos los ITERADORES
    free(iterl2); //Liberamos los ITERADORES
    return multiplo;
  
}


int main(){

//Creamos dos LISTAS (L1 y L2)

Lista l1=l_crear();
Lista l2=l_crear();

//Verificamos si es L2 es MÚLTIPLO de L1 por un ESCALAR
bool escalar=true,ok;
int l=1,esc=0;

//Lista L1
printf("Creamos la lista L%d.\n",l);
ok=listaPorTeclado(l1,l);
if (ok){
    l++;
    printf("Lista L1\n");
    l_mostrarLista(l1);
    printf("\n");

    //Lista L2
    printf("Creamos la lista L%d.\n",l);
    ok=listaPorTeclado(l2,l);
    if (ok){
    printf("Lista L2\n");
    l_mostrarLista(l2);
    printf("\n");

    if (esMultiplo(l1,l2,&escalar,&esc) && escalar){ //Le pasamos la DIRECCIÓN de la variable al PUNTERO
        printf("La lista L2 es MULTIPLO de L1 por el escalar %d\n",esc);
    }
    else if (esMultiplo(l1,l2,&escalar,&esc)){ //Le pasamos la DIRECCIÓN de la variable al PUNTERO
        printf("La lista L2 es MULTIPLO de L1\n");
    }
    else{
        printf("La lista L2 es NO es MULTIPLO de L1\n");
        }
    }
    }


free(l1); //IMPORTANTE! Liberar las LISTAS de la memoria
free(l2); //IMPORTANTE! Liberar las LISTAS de la memoria



}

