


//Ejercicios Adicionales

//Cantidad de NODOS INTERIORES

void ninSub(ArbolBinario arbol, NodoArbol nodo, int *cantidad){

    if(nodo==NULL){}

    else{
        if((n_hijoizquierdo(nodo)!=NULL || n_hijoderecho(nodo)!=NULL) && nodo!=a_raiz(arbol)){
            *cantidad=*cantidad+1;
        }

        ninSub(arbol,n_hijoizquierdo(nodo),cantidad);
        ninSub(arbol,n_hijoderecho(nodo),cantidad);
    }

}

int nodosIN(ArbolBinario A){

    int cantidad=0;
    if(a_cantidad_elementos(A)==0){}
    else{
        ninSub(A,a_raiz(A),&cantidad);
    }
    return cantidad;

}


//SUBFUNCIÓN
void buscarNodoSub(ArbolBinario arbol, NodoArbol nodo, Lista lista, int clave){

    TipoElemento datos=te_crear(0);

    //1. Base
    if (nodo==NULL){}

    else{
        datos=n_recuperar(nodo);
        if(datos->clave==clave){
            datos=te_crear_con_valor(clave,(NodoArbol)&nodo);
        }
        //DOBLE RECURSIVIDAD
        buscarNodoSub(arbol,n_hijoizquierdo(nodo),lista,clave);
        buscarNodoSub(arbol,n_hijoderecho(nodo),lista,clave);
    }


}

//ARBOL ESPEJO (FUNCIÓN RECURSIVA)
/*
void arbolEspSub(ArbolBinario arbol, NodoArbol nodo, ArbolBinario a_espejo, NodoArbol nodo_es, int indicador){

    //1. Base
    if(nodo==NULL){}

    //2. Recursivo
    else{
        TipoElemento te=te_crear(0), hi=te_crear(0), hd=te_crear(0);
        te=n_recuperar(nodo);
        hi=n_recuperar(n_hijoizquierdo(nodo));
        hd=n_recuperar(n_hijoderecho(nodo));
    
        if (indicador==-1){
            nodo_es=a_conectar_hi(a_espejo,nodo_es,hd);
        }                   
        else if (indicador==1){
            nodo_es=a_conectar_hd(a_espejo,nodo_es,hi);
        }
        else{
            nodo_es=a_establecer_raiz(a_espejo,te);
        }

        //RECORRIDO POR HIJO IZQUIERDO E HIJO DERECHO
        arbolEspSub(arbol,n_hijoizquierdo(nodo),a_espejo,nodo_es,-1);
        arbolEspSub(arbol,n_hijoderecho(nodo),a_espejo,nodo_es,1);

    }
}

ArbolBinario arbolEspejo(ArbolBinario arbol){

    ArbolBinario espejo=a_crear();
    arbolEspSub(arbol,a_raiz(arbol),espejo);

}
*/

//NODOS con DOS HIJOS

void NodosDosHijosSub(ArbolBinario arbol, NodoArbol nodo, int *cantidad){

    //1. Base
    if(nodo==NULL){}

    //2. Recursivo
    else{
        if(n_hijoizquierdo(nodo)!=NULL && n_hijoderecho(nodo)!=NULL){
            *cantidad=*cantidad+1;
        }

        //DOBLE RECORRIDO RECURSIVO (POR CADA HIJO)
        NodosDosHijosSub(arbol,n_hijoizquierdo(nodo),cantidad);
        NodosDosHijosSub(arbol,n_hijoderecho(nodo),cantidad);

    }


}

int NodosDosHijos(ArbolBinario arbol){

    int cantidad=0;
    NodosDosHijosSub(arbol,a_raiz(arbol),&cantidad);
    return cantidad;

}

/*
//ARBOL LLENO (VERSIÓN ALTERNATIVA)

void arbolLlenoSub(ArbolBinario arbol, NodoArbol nodo, bool *lleno, int cantidad, int *nivel, int *primer){

    //1. Base
    if(n_hijoizquierdo(nodo)==NULL || n_hijoderecho(nodo)==NULL){
        *lleno=false;
        if(n_hijoizquierdo(nodo)==NULL && n_hijoderecho(nodo)==NULL){
            *lleno=true;
            //Guardo el valor UNA VEZ
            if (*primer<1){
                *nivel=cantidad;
                *primer=*primer+1;}

            else if(*nivel!=cantidad){
                *lleno=false;}
        
        }
    }

    else{
        arbolLlenoSub(arbol,n_hijoizquierdo(nodo),lleno,cantidad+1,nivel,primer);
        arbolLlenoSub(arbol,n_hijoderecho(nodo),lleno,cantidad+1,nivel,primer);
    }


}

bool esArbolLLeno(ArbolBinario arbol){

    int primer=0, nivel=0;
    bool lleno=true;
    arbolLlenoSub(arbol,a_raiz(arbol),&lleno,0,&nivel,&primer);
    return lleno;

}*/

int main(){

    int n, nivel; 
    ArbolBinario a;
    TipoElemento x;
    NodoArbol N;
    
    printf("Creando el Arbol Binario Vacio (Tamanio = 10) !\n");
    a = a_crear();

    //Creo el arbol
    a = a_crear();
    cargar_arbol_binario(a); //Lo cargo

    //MOSTRAR el ARBOL en PRE-ORDEN
    printf("-----------------------------------------------------\n");
    printf("Pre-Orden Desde la raiz\n");
    pre_orden(a_raiz(a));
    printf("\n");

    //ALTURA del ARBOL
    printf("-----------------------------------------------------\n");
    printf("Altura del Arbol: %d \n", a_altura(a));
    printf("-----------------------------------------------------\n");

    //ARBOL LLENO
    printf("-----------------------------------------------------\n");
    bool lleno=esArbolLLeno(a);
    printf("Arbol Lleno: %d \n",lleno);
    printf("-----------------------------------------------------\n");
    
    //ARBOL LLENO 2
    printf("-----------------------------------------------------\n");
    bool lleno2=a_esLLeno(a);
    printf("Arbol Lleno: %d \n",lleno2);
    printf("-----------------------------------------------------\n");

    //EJERCICIOS 
    Lista lista=listaDeHojas(a);
    printf("Lista de Nodos HOJAS: \n");
    l_mostrarLista(lista);
    printf("\n");

    Lista l=listaDeNInteriores(a);
    printf("Lista de Nodos INTERIORES: \n");
    l_mostrarLista(l);
    printf("\n");

    int cantidad=NodosDosHijos(a);
    printf("La cantidad de nodos con 2 hijos son: %d\n",cantidad);
    printf("\n");

    int cant=nodosIN(a);
    printf("%d",cant);

    


}