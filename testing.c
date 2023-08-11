

#include "listas_vectores.c" //
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//Handler (MANEJADOR DE ARCHIVOS POR FUERA DE LAS FUNCIONES)
FILE *archivo;
FILE *p; //Archivo de productos

//Estructura GLOBAL del registro de VENTAS
struct Venta{

    char fecha[50];
    int producto, cantidad;

    //Definimos el ALIAS para el registro
    struct tm FechaHoy;

};

//Estructura GLOBAL de PRODUCTOS
struct Producto{

    char nombre_producto[50];
    int precio;

};


//Ver la LISTA COMPLETA

void VerLista(Lista PRODUCTOS){   //ERROR al MOSTRAR. SIEMPRE SE MUESTRA EL ÚLTIMO PRODUCTO

    struct Producto *PROD;
    PROD=malloc(sizeof(struct Producto));
    
    p=fopen("productos.bin","rb");
    char producto[50];

    //LEEMOS la PRIMERA LINEA
    fread(PROD,sizeof(struct Producto),1,p);
    while(!feof(p)){
        strcpy(producto,PROD->nombre_producto);
        TipoElemento P=te_crear_con_valor(PROD->precio,producto);
        l_agregar(PRODUCTOS,P);
        fread(PROD,sizeof(struct Producto),1,p);
    }
    
    fclose(p);
    
    struct Venta *VENTA;
    VENTA=malloc(sizeof(struct Venta));

    archivo=fopen("ventas.bin","rb");
    //LEEMOS la PRIMERA LINEA
    fread(VENTA,sizeof(struct Venta),1,archivo);
    printf("            VENTAS: \n");
    printf("            Fecha       Producto        Cantidad Vendida\n");
    printf("            %s %s             %d %d\n",VENTA->fecha,l_recuperar(PRODUCTOS,VENTA->producto)->valor,VENTA->cantidad,l_recuperar(PRODUCTOS,VENTA->producto)->clave);
    fclose(archivo); //IMPORTANTE!!! Cerrar el archivo al final
    

}


int main(){

    Lista PRODUCTOS=l_crear();
    VerLista(PRODUCTOS);



}