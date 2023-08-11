

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

void VerLista(Lista PRODUCTOS){   //ERROR al MOSTRAR. SIEMPRE SE MUESTRA EL ÚLTIMO PRODUCTO

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
    printf("            VENTAS: \n");
    printf("            Fecha       Producto        Cantidad Vendida\n");
    while(!feof(archivo)){
        printf("            %s %s             %d\n",VENTA->fecha,l_recuperar(PRODUCTOS,VENTA->producto)->valor,VENTA->cantidad);
        fread(VENTA,sizeof(struct Venta),1,archivo);
    }
    fclose(archivo); //IMPORTANTE!!! Cerrar el archivo al final
    

}


//Agregar PRODUCTOS

void AgregarProductos(){

    struct Producto *PROD;
    PROD=malloc(sizeof(struct Producto));
    p=fopen("productos.bin","ab");

    printf("Que producto desea agregar?: ");
    scanf("%49s",PROD->nombre_producto);
    printf("Cuanto vale este producto (p/Unidad)?: ");
    scanf("%d",&PROD->precio);

    fwrite(PROD,sizeof(struct Producto),1,p);

    fclose(p);
    
}


//MOSTRAR PRODUCTOS

void MostrarProductos(){

    struct Producto *PROD;
    PROD=malloc(sizeof(struct Producto));
    int orden=1;

    p=fopen("productos.bin","rb");  

    fread(PROD,sizeof(struct Producto),1,p);
    printf("PRODUCTOS: \n");
    while(!feof(p)){
        printf("            %d. ................%s.  $%d p/u.\n",orden,PROD->nombre_producto,PROD->precio);
        orden++;
        fread(PROD,sizeof(struct Producto),1,p);
    }

    fclose(p);
    

}

/*
//MODIFICAR PRODUCTOS

void ModificarProductos(){

    struct Producto *PROD;
    PROD=malloc(sizeof(struct Producto));
    int opcion=-1, cant=0;
    long pos=0, datos[50];

    printf("Que producto desea modificar?: \n");
    printf("\n");
    MostrarProductos();
    printf("Elija el campo a modificar: ");
    scanf("%d",&opcion);

    //LEEMOS la PRIMERA LINEA
    p=fopen("productos.bin","rb+");
    fread(PROD,sizeof(struct Producto),1,p);

    while(!feof(p)){

        if(l_recuperar){
            cant++;
            printf("            %d. %s   %s             %d\n",cant,VENTA->fecha,l_recuperar(PRODUCTOS,VENTA->producto)->valor,VENTA->cantidad);
            pos=ftell(archivo)-sizeof(struct Venta); //Indica la POSICIÓN ACTUAL del PUNTERO
            datos[cant]=pos;
        }
        fread(VENTA,sizeof(struct Venta),1,archivo);
    }
    
    printf("Se encontraron %d resultados.\n",cant);

    if(cant>0){

        int opcion=-1;
        
        printf("Cual resultado desea modificar?: ");
        scanf("%d",&pos);

        printf("Que campo desea modificar?: \n");
        printf("\n");
        printf("1. Cantidad: \n");
        printf("2. Producto: \n");
        printf("\n");
        printf("Elija el campo a modificar: ");
        scanf("%d",&opcion);

        //SITUAMOS el puntero en la POSICIÓN INDICADA
        //MODIFICAMOS los datos en esa posición
        if(opcion==1){
            printf("Ingrese la NUEVA CANTIDAD: ");
            scanf("%d",&VENTA->cantidad);
        }
        else if(opcion==2){
            printf("Ingrese el NUEVO PRODUCTO: ");
            scanf("%d",&VENTA->producto);
        }
        else{}
        fseek(archivo,datos[pos],SEEK_SET);
        fwrite(VENTA,sizeof(struct Venta),1,archivo);
        fclose(archivo); //Lo GUARDAMOS ANTES DE MOSTRAR
    }

    else{
        fclose(archivo);
    }

}

*/








//AGREGAR VENTAS

void AgregarDatos(int *dia, int *mes, int *anio){

    Lista PRODUCTOS=l_crear();

    struct Venta *VENTA;
    VENTA=malloc(sizeof(struct Venta));
    
    archivo=fopen("ventas.bin","ab");

    printf("Ingrese el DIA de HOY: ");
    scanf("%d",dia);
    printf("Ahora, ingrese el MES: ");
    scanf("%d",mes);
    printf("Por ultimo, ingrese el ANIO: ");
    scanf("%d",anio);
  

    //CARGAMOS sus CAMPOS
    VENTA->FechaHoy.tm_hour=0,
    VENTA->FechaHoy.tm_min=0,
    VENTA->FechaHoy.tm_sec=0,

    VENTA->FechaHoy.tm_mday=*dia,
    VENTA->FechaHoy.tm_mon=(*mes-1),
    VENTA->FechaHoy.tm_year=(*anio-1900),

    VENTA->FechaHoy.tm_isdst=0;

    //Con strftime() convertimos el REGISTRO DE TIEMPO a CADENA DE CARACTERES
    strftime(VENTA->fecha,sizeof(VENTA->fecha),"%d/%m/%Y",&VENTA->FechaHoy);
  
    MostrarProductos();
    printf("Que producto vendio?: ");
    scanf("%d",&VENTA->producto);
    printf("Cuanta cantidad se vendio de ese producto?: ");
    scanf("%d",&VENTA->cantidad);

    fwrite(VENTA,sizeof(struct Venta),1,archivo);

    fclose(archivo); //IMPORTANTE!!! Cerrar el archivo al final
    
}


//MODIFICAR VENTAS
void ModificarDatos(Lista PRODUCTOS){

    //Primero, guardamos los datos de los PRODUCTOS en una LISTA
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

    //Para los archivos BINARIOS, utilizamos un PUNTERO a la ESTRUCTURA Venta
    struct Venta *VENTA;
    VENTA=malloc(sizeof(struct Venta));
    
    int dia, mes, anio, cant=0;
    long pos=0, datos[50];

    printf("Que datos desea modificar?: \n");
    printf("\n");
    printf("Ingrese el DIA: ");
    scanf("%d",&dia);
    printf("Ahora, ingrese el MES: ");
    scanf("%d",&mes);
    printf("Por ultimo, ingrese el ANIO: ");
    scanf("%d",&anio);
    system("cls");

    archivo=fopen("ventas.bin","rb+");

    printf("               Fecha        Producto        Cantidad Vendida\n");
    //Leemos la PRIMERA LINEA por FUERA DE LA FUNCIÓN
    fread(VENTA,sizeof(struct Venta),1,archivo);
    while(!feof(archivo)){

        if(VENTA->FechaHoy.tm_mday==dia && VENTA->FechaHoy.tm_mon==(mes-1) && 
        VENTA->FechaHoy.tm_year==(anio-1900)){
            cant++;
            printf("            %d. %s   %s             %d\n",cant,VENTA->fecha,l_recuperar(PRODUCTOS,VENTA->producto)->valor,VENTA->cantidad);
            pos=ftell(archivo)-sizeof(struct Venta); //Indica la POSICIÓN ACTUAL del PUNTERO
            datos[cant]=pos;
        }
        fread(VENTA,sizeof(struct Venta),1,archivo);
    }
    
    printf("Se encontraron %d resultados.\n",cant);

    if(cant>0){

        int opcion=-1;
        
        printf("Cual resultado desea modificar?: ");
        scanf("%d",&pos);

        printf("Que campo desea modificar?: \n");
        printf("\n");
        printf("1. Cantidad: \n");
        printf("2. Producto: \n");
        printf("\n");
        printf("Elija el campo a modificar: ");
        scanf("%d",&opcion);

        //SITUAMOS el puntero en la POSICIÓN INDICADA
        //MODIFICAMOS los datos en esa posición
        if(opcion==1){
            printf("Ingrese la NUEVA CANTIDAD: ");
            scanf("%d",&VENTA->cantidad);
        }
        else if(opcion==2){
            printf("Ingrese el NUEVO PRODUCTO: ");
            scanf("%d",&VENTA->producto);
        }
        else{}
        fseek(archivo,datos[pos],SEEK_SET);
        fwrite(VENTA,sizeof(struct Venta),1,archivo);
        fclose(archivo); //Lo GUARDAMOS ANTES DE MOSTRAR
    }

    else{
        fclose(archivo);
    }

}


//TOTAL por FECHA, MES Y AÑO
int TotalSub(int dia, int mes, int anio, Lista PRODUCTOS, int i){


    //Lo guardo en una lista
    struct Producto *PROD;
    PROD=malloc(sizeof(struct Producto));
    
    p=fopen("productos.bin","rb");

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
    int total=0, ganancia=0;

    fread(VENTA,sizeof(struct Venta),1,archivo);
    while(!feof(archivo)){

        if(i==1){
            if(VENTA->FechaHoy.tm_mday==dia && VENTA->FechaHoy.tm_mon==(mes-1)){
                    ganancia=(l_recuperar(PRODUCTOS,VENTA->producto)->clave * VENTA->cantidad);
                    total=total+ganancia;}
        }

        else if(i==2){
            if(VENTA->FechaHoy.tm_mon==(mes-1)){
                ganancia=(l_recuperar(PRODUCTOS,VENTA->producto)->clave * VENTA->cantidad);
                total=total+ganancia;}
        }
    
        else{
            if(VENTA->FechaHoy.tm_year==(anio-1900)){
                ganancia=(l_recuperar(PRODUCTOS,VENTA->producto)->clave * VENTA->cantidad);
                total=total+ganancia;}
        }
        
        fread(VENTA,sizeof(struct Venta),1,archivo);
        
    }

    fclose(archivo);

    return total;

}


void Total(int d, int m, int a, int i, Lista PRODUCTOS){

    bool automatico=false;

    if(i!=0){
        printf("Que total desea obtener?: \n");
        printf("\n");
        printf("1. Total de un dia: \n");
        printf("2. Total de un mes: \n");
        printf("3. Total anual: \n");
        printf("\n");
        printf("Elija una opcion: ");
        scanf("%d",&i);
    }

    else{
        i=1;
        automatico=true;
    }

    switch(i){
        case 1: if(!automatico){ 
            printf("Ingrese el DIA: ");
            scanf("%d",&d);
            printf("Ahora, ingrese el MES: ");
            scanf("%d",&m);
        }
        int TD=TotalSub(d,m,a,PRODUCTOS,i);
        printf("El total de hoy es de: $%d\n",TD);
        break;

        case 2: 
        printf("Ingrese el MES: ");
        scanf("%d",&m);
        int TM=TotalSub(d,m,a,PRODUCTOS,i);
        printf("El total por mes es de: $%d\n",TM);
        break;

        case 3: 
        printf("Ingrese el ANIO: ");
        scanf("%d",&a);
        int TA=TotalSub(d,m,a,PRODUCTOS,i);
        printf("El total anual es de: $%d\n",TA);
        break;

    }

    
}


//PROMEDIO por FECHA, MES Y AÑO
int PromedioSub(int dia, int mes, int anio, Lista PRODUCTOS, int i){

    //Lo guardo en una lista
    struct Producto *PROD;
    PROD=malloc(sizeof(struct Producto));
    
    p=fopen("productos.bin","rb");

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
    int cantidad=0, total=0, ganancia=0;

    fread(VENTA,sizeof(struct Venta),1,archivo);
    while(!feof(archivo)){

        if(i==1){
            if(VENTA->FechaHoy.tm_mday==dia && VENTA->FechaHoy.tm_mon==(mes-1)){
                ganancia=(l_recuperar(PRODUCTOS,VENTA->producto)->clave * VENTA->cantidad);
                total=total+ganancia;
                cantidad++;}
        }

        else if(i==2){
            if(VENTA->FechaHoy.tm_mon==(mes-1)){
                ganancia=(l_recuperar(PRODUCTOS,VENTA->producto)->clave * VENTA->cantidad);
                total=total+ganancia;
                cantidad++;}
        }
    
        else{
            if(VENTA->FechaHoy.tm_year==(anio-1900)){
                ganancia=(l_recuperar(PRODUCTOS,VENTA->producto)->clave * VENTA->cantidad);
                total=total+ganancia;
                cantidad++;}
        }

        fread(VENTA,sizeof(struct Venta),1,archivo);

    }

    fclose(archivo);

    int promedio=total/cantidad;

    return promedio;

}


void Promedio(int d, int m, int a, int i, Lista PRODUCTOS){

    bool automatico=false;

    if(i!=0){
        printf("Que promedio desea obtener?: \n");
        printf("\n");
        printf("1. Promedio del dia: \n");
        printf("2. Promedio de un mes: \n");
        printf("3. Promedio anual: \n");
        printf("\n");
        printf("Elija una opcion: ");
        scanf("%d",&i);
    }

    else{
        i=1;
        automatico=true;
    }

    switch(i){
        case 1:
        if(!automatico){ 
        printf("Ingrese el DIA: ");
        scanf("%d",&d);
        printf("Ahora, ingrese el MES: ");
        scanf("%d",&m);}
        int PD=PromedioSub(d,m,a,PRODUCTOS,i);
        printf("El promedio de hoy es de: $%d\n",PD);
        break;

        case 2: 
        printf("Ingrese el MES: ");
        scanf("%d",&m);
        int PM=PromedioSub(d,m,a,PRODUCTOS,i);
        printf("El promedio mensual es de: $%d\n",PM);
        break;

        case 3: 
        printf("Ingrese el ANIO: ");
        scanf("%d",&a);
        int PA=PromedioSub(d,m,a,PRODUCTOS,i);
        printf("El promedio anual es de: $%d\n",PA);
        break;

    }

    
}


//PRODUCTO MÁS Y MENOS VENDIDO

int ProductoMomVSub(int i){

    
    struct Venta *VENTA;
    VENTA=malloc(sizeof(struct Venta));

    archivo=fopen("ventas.bin","rb");
    int productos[50];
    memset(productos,-1,sizeof(productos));

    fread(VENTA,sizeof(struct Venta),1,archivo);
    while(!feof(archivo)){

        productos[VENTA->producto]++;
        fread(VENTA,sizeof(struct Venta),1,archivo);

    }

    fclose(archivo);
    
    int m=-1;
    if(i==1){
        int mayor=productos[1];
        m=1;
        for(int j=2; j<sizeof(productos) && productos[j]!=-1; j++){

            if(productos[j]>mayor){
                mayor=productos[j];
                m=j;
            }

        }
    }

    else{
        int menor=productos[1];
        m=1;
        for(int j=2; j<sizeof(productos) && productos[j]!=-1; j++){

            if(productos[j]<menor){
                menor=productos[j];
                m=j;
            }

        }
    }

    return m;

}


void ProductoMomV(){

    //Lo guardo en una lista
    Lista PRODUCTOS=l_crear();

    struct Producto *PROD;
    PROD=malloc(sizeof(struct Producto));
    
    p=fopen("productos.bin","rb");

    fread(PROD,sizeof(struct Producto),1,p);
    while(!feof(p)){
        TipoElemento P=te_crear_con_valor(PROD->precio,PROD->nombre_producto);
        l_agregar(PRODUCTOS,P);
        fread(PROD,sizeof(struct Producto),1,p);
    }
    
    fclose(p);

    int i;
    printf("Que tipo de producto desea obtener?: \n");
    printf("\n");
    printf("1. Producto MAS VENDIDO: \n");
    printf("2. Producto MENOS VENDIDO: \n");
    printf("\n");
    printf("Elija una opcion: ");
    scanf("%d",&i);

    switch(i){

        int PMV, PmV;
        case 1: PMV=ProductoMomVSub(i);
        printf("El producto mas vendido es el/la %s",l_recuperar(PRODUCTOS,PMV)->valor);
        break;
        case 2: PmV=ProductoMomVSub(i);
        printf("El producto menos vendido es el/la %s",l_recuperar(PRODUCTOS,PmV)->valor);
        break;
    
    }

    
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
    printf("            a. PRODUCTOS: \n");
    printf("\n");
    printf("            1. Ver la lista de productos\n");
    printf("            2. Agregar productos a la lista\n");
    printf("            3. Modificar la lista de productos\n");
    printf("\n");
    printf("            b. VENTAS: \n");
    printf("\n");
    printf("            4. Ver la lista de ventas\n");
    printf("            5. Registrar las ventas del dia\n");
    printf("            6. Modificar datos de la lista de ventas\n");
    printf("            7. Ver el total de ventas (por dia/mensual/anual)\n");
    printf("            8. Ver el promedio de ventas (por dia/mensual/anual)\n");
    printf("            9. Otras utilidades\n");
    printf("\n");
    printf("            0. Salir\n");
    printf("\n");

}


void MenuOpciones(int opcion){

    Lista PRODUCTOS=l_crear();

    switch(opcion){
        limpiar_pantalla();
        case 1: MostrarProductos();
        break;
        case 2: AgregarProductos();
        limpiar_pantalla();
        MostrarProductos();
        break;
        //case 3: ModificarProductos();
        //break;
        case 4: VerLista(PRODUCTOS);
        free(PRODUCTOS);
        break;
        int d, m, a;
        case 5: AgregarDatos(&d,&m,&a);
        limpiar_pantalla();
        VerLista(PRODUCTOS);
        Total(d,m,a,0,PRODUCTOS);
        break;
        case 6: VerLista(PRODUCTOS);
        printf("\n");
        ModificarDatos(PRODUCTOS);
        limpiar_pantalla();
        VerLista(PRODUCTOS);
        free(PRODUCTOS);
        break;
        case 7: Total(0,0,0,-1,PRODUCTOS);
        break;
        case 8: Promedio(0,0,0,-1,PRODUCTOS);
        break;
        case 9: ProductoMomV();
        break;
    }
    
}


int main(){

int opcion=-1;

while(opcion!=0){
    menuPrincipal();
    printf("Elija una opcion: ");
    scanf("%d",&opcion);
    limpiar_pantalla();
    MenuOpciones(opcion);
    if(opcion!=0){
        system("pause");
    }
}

}






