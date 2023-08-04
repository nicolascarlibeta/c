

#include "Proyecto1.h"
#include "listas_vectores.c" //
#include <stdio.h>
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

void VerLista(Lista PRODUCTOS){

    struct Producto *PROD;
    PROD=malloc(sizeof(struct Producto));
    
    p=fopen("productos.bin","rb");

    //LEEMOS la PRIMERA LINEA
    fread(PROD,sizeof(struct Producto),1,p);
    while(!feof(p)){
        TipoElemento P=te_crear_con_valor(PROD->precio,PROD->nombre_producto);
        l_agregar(PRODUCTOS,P);
        fread(PROD,sizeof(struct Producto),1,p);
    }
    
    fclose(p);
    
    struct Venta *VENTA;
    VENTA=malloc(sizeof(struct Venta));

    archivo=fopen("ventas.bin","rb");
    //LEEMOS la PRIMERA LINEA
    fread(VENTA,sizeof(struct Venta),1,archivo);
    printf("            Fecha       Producto        Cantidad Vendida\n");
    while(!feof(archivo)){
        printf("            %s %s             %d\n",VENTA->fecha,l_recuperar(PRODUCTOS,VENTA->producto)->valor,VENTA->cantidad);
        fread(VENTA,sizeof(struct Venta),1,archivo);
    }

    fclose(archivo); //IMPORTANTE!!! Cerrar el archivo al final

}


//Agregar PRODUCTOS a la LISTA DE PRODUCTOS

void AgregarProductos(){

    struct Producto *PROD;
    PROD=malloc(sizeof(struct Producto));

    printf("Que producto desea agregar?: ");
    scanf("%s",PROD->nombre_producto);
    printf("Cuanto vale este producto?: ");
    scanf("%d",&PROD->precio);

    archivo=fopen("productos.bin","ab");
    fwrite(PROD,sizeof(struct Producto),1,archivo);

    fclose(archivo);

}


//MOSTRAR PRODUCTOS de la lista

void MostrarProductos(){

    struct Producto *PROD;
    PROD=malloc(sizeof(struct Producto));
    int orden=1;

    archivo=fopen("productos.bin","rb");  

    printf("PRODUCTOS: \n");
    while(!feof(archivo)){
        fread(PROD,sizeof(struct Producto),1,archivo);
        printf("            %d. ................%s.\n",orden,PROD->nombre_producto);
        orden++;
    }

    fclose(archivo);

}


//AGREGAR datos

void AgregarDatos(){


    struct Venta *VENTA;
    VENTA=malloc(sizeof(struct Venta));
    
    archivo=fopen("ventas.bin","ab");

    int dia, mes, anio;

    printf("Ingrese el DIA de HOY: ");
    scanf("%d",&dia);
    printf("Ahora, ingrese el MES: ");
    scanf("%d",&mes);
    printf("Por ultimo, ingrese el ANIO: ");
    scanf("%d",&anio);
  

    //CARGAMOS sus CAMPOS
    VENTA->FechaHoy.tm_hour=0,
    VENTA->FechaHoy.tm_min=0,
    VENTA->FechaHoy.tm_sec=0,

    VENTA->FechaHoy.tm_mday=dia,
    VENTA->FechaHoy.tm_mon=mes-1,
    VENTA->FechaHoy.tm_year=anio-1900,

    VENTA->FechaHoy.tm_isdst=0;

    //Con strftime() convertimos el REGISTRO DE TIEMPO a CADENA DE CARACTERES
    strftime(VENTA->fecha,sizeof(VENTA->fecha),"%d/%m/%Y",&VENTA->FechaHoy);
  
    MostrarProductos();
    printf("Que producto vendio?: \n");
    scanf("%d",&(VENTA->producto));
    printf("Cuanta cantidad se vendio de ese producto?: ");
    scanf("%d",&(VENTA->cantidad));

    fwrite(VENTA,sizeof(struct Venta),1,archivo);

    fclose(archivo); //IMPORTANTE!!! Cerrar el archivo al final


}

//MODIFICAR datos

void ModificarDatos(Lista PRODUCTOS){

    //Para los archivos BINARIOS, utilizamos un PUNTERO a la ESTRUCTURA Venta
    struct Venta *VENTA;
    VENTA=malloc(sizeof(struct Venta));
    
    int dia, mes, anio, cant=0;
    bool esta=false;

    printf("Que datos desea modificar?: \n");
    printf("\n");
    printf("Ingrese el DIA: ");
    scanf("%d",&dia);
    printf("Ahora, ingrese el MES: ");
    scanf("%d",&mes);
    printf("Por ultimo, ingrese el ANIO: ");
    scanf("%d",&anio);

    archivo=fopen("ventas.bin","ab");

    printf("            Fecha       Producto        Cantidad Vendida\n");
    while(!feof(archivo) && !esta){
        //Primero leemos las lineas
        fread(VENTA,sizeof(struct Venta),1,archivo);
        if(VENTA->FechaHoy.tm_mday==dia && VENTA->FechaHoy.tm_mon==(mes-1) && 
        VENTA->FechaHoy.tm_year==(anio-1900)){
            cant++;
            printf("            %d.%s %s             %d\n",cant,VENTA->fecha,l_recuperar(PRODUCTOS,VENTA->producto)->valor,VENTA->cantidad);
        }
    }
    
    printf("Se encontraron %d resultados.",cant);

}


//Total de una FECHA
void TotalporFecha(int dia, int mes, Lista PRODUCTOS){


    //Lo guardo en una lista
    struct Producto *PROD;
    PROD=malloc(sizeof(struct Producto));
    
    p=fopen("productos.bin","rb");

    while(!feof(archivo)){
        fread(PROD,sizeof(struct Producto),1,p);
        TipoElemento P=te_crear_con_valor(PROD->precio,PROD->nombre_producto);
        l_agregar(PRODUCTOS,P);
    }
    

    fclose(p);

    struct Venta *VENTA;
    VENTA=malloc(sizeof(struct Venta));

    archivo=fopen("ventas.bin","rb");
    int total=0, ganancia=0;

    while(!feof(archivo)){
        fread(VENTA,sizeof(struct Venta),1,archivo);
        if(VENTA->FechaHoy.tm_mday==dia && VENTA->FechaHoy.tm_mon==(mes-1)){
            ganancia=(l_recuperar(PRODUCTOS,VENTA->producto)->clave * VENTA->cantidad);
            total=total+ganancia;
        }
    }

    fclose(archivo);

    printf("El total de venta del dia es: %d",total);

}


//Total MENSUAL
void TotalporMes(int mes, Lista PRODUCTOS){


    //Lo guardo en una lista
    struct Producto *PROD;
    PROD=malloc(sizeof(struct Producto));
    
    p=fopen("productos.bin","rb");

    while(!feof(p)){
        fread(PROD,sizeof(struct Producto),1,p);
        TipoElemento P=te_crear_con_valor(PROD->precio,PROD->nombre_producto);
        l_agregar(PRODUCTOS,P);
    }
    

    fclose(p);

    struct Venta *VENTA;
    VENTA=malloc(sizeof(struct Venta));

    archivo=fopen("ventas.bin","rb");
    int total=0, ganancia=0;

    while(!feof(archivo)){
        fread(VENTA,sizeof(struct Venta),1,archivo);
        if(VENTA->FechaHoy.tm_mon==(mes-1)){
            ganancia=(l_recuperar(PRODUCTOS,VENTA->producto)->clave * VENTA->cantidad);
            total=total+ganancia;
        }
    }

    fclose(archivo);

    printf("El total de venta del dia es: %d",total);

}


//Total ANUAL
void TotalAnual(int anio, Lista PRODUCTOS){


    //Lo guardo en una lista
    struct Producto *PROD;
    PROD=malloc(sizeof(struct Producto));
    
    p=fopen("productos.bin","rb");

    while(!feof(archivo)){
        fread(PROD,sizeof(struct Producto),1,p);
        TipoElemento P=te_crear_con_valor(PROD->precio,PROD->nombre_producto);
        l_agregar(PRODUCTOS,P);
    }
    

    fclose(p);

    struct Venta *VENTA;
    VENTA=malloc(sizeof(struct Venta));

    archivo=fopen("ventas.bin","rb");
    int total=0, ganancia=0;

    while(!feof(archivo)){
        fread(VENTA,sizeof(struct Venta),1,archivo);
        if(VENTA->FechaHoy.tm_year==(anio-1900)){
            ganancia=(l_recuperar(PRODUCTOS,VENTA->producto)->clave * VENTA->cantidad);
            total=total+ganancia;
        }
    }

    fclose(archivo);

    printf("El total de venta del dia es: %d",total);

}


//Promedio por FECHA

void PromedioPorFecha(int dia, int mes, Lista PRODUCTOS){

    //Lo guardo en una lista
    struct Producto *PROD;
    PROD=malloc(sizeof(struct Producto));
    
    p=fopen("productos.bin","rb");

    while(!feof(archivo)){
        fread(PROD,sizeof(struct Producto),1,p);
        TipoElemento P=te_crear_con_valor(PROD->precio,PROD->nombre_producto);
        l_agregar(PRODUCTOS,P);
    }
    
    fclose(p);

    struct Venta *VENTA;
    VENTA=malloc(sizeof(struct Venta));

    archivo=fopen("ventas.bin","rb");
    int cantidad=0, total=0, ganancia=0;

    while(!feof(archivo)){
        fread(VENTA,sizeof(struct Venta),1,archivo);
        if(VENTA->FechaHoy.tm_mday==dia && VENTA->FechaHoy.tm_mon==(mes-1)){
            ganancia=(l_recuperar(PRODUCTOS,VENTA->producto)->clave * VENTA->cantidad);
            total=total+ganancia;
            cantidad++;
        }
    }

    fclose(archivo);

    int promedio=total/cantidad;

    printf("El total de venta del dia es: %d",promedio);

}


void limpiar_pantalla(){
    system("cls");
}


void menuPrincipal(){

    printf("            |||||||||||||||||||||||||||||||\n");
    printf("            ||||||| EL BAR DE CLARA |||||||\n");
    printf("            |||||||||||||||||||||||||||||||\n");
    printf("\n");
    printf("            Que te gustaria hacer?\n");
    printf("\n");
    printf("            1. Ver la lista de ventas\n");
    printf("            2. Registrar las ventas del dia\n");
    printf("            3. Modificar datos de la lista de ventas\n");
    printf("            4. Ver el promedio de ventas (por dia/mensual/anual)\n");
    printf("\n");

}

void MenuOpciones(int opcion){

    Lista PRODUCTOS=l_crear();

    switch(opcion){
        case 1: VerLista(PRODUCTOS);
        break;
        case 2: AgregarDatos();
        limpiar_pantalla();
        VerLista(PRODUCTOS);
        break;
    }
    
   
    
}



int main(){

int opcion=-1;

menuPrincipal();
printf("Eliga una opcion: ");
scanf("%d",&opcion);
limpiar_pantalla();
MenuOpciones(opcion);



}








