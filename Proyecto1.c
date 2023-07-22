

#include "Proyecto1.h"
#include <stdio.h>
#include <time.h>


//Ver la LISTA COMPLETA
void VerLista(){

    FILE *archivo;
    archivo=fopen("info_ventas.txt","r");

    //Leemos las lineas del archivo de texto
    //Utilizamos fscanf y las guardamos en variables
    char *fecha[40], *producto[50]; int cantidad;

    printf("Fecha   Producto    Cantidad Vendida\n");
    while(!feof(archivo)){
        fscanf(archivo,"%s %s %d %d",fecha,producto,&cantidad);
        printf("%s %s %d\n",fecha,producto,cantidad);
    }

    fclose(archivo); //IMPORTANTE!!! Cerrar el archivo al final

}

//AÑADIR DATOS a la lista

void AgregarDatos(){

    FILE *archivo;
    archivo=fopen("info_ventas.txt","a");

    //Leemos las lineas del archivo de texto
    //Utilizamos fscanf y las guardamos en variables
    char *fecha[40], *producto[50]; int cantidad;

    printf("fecha?: ");
    scanf("%s",fecha);
    printf("producto?: ");
    scanf("%s",producto);
    printf("cant?: ");
    scanf("%d",&cantidad);
    fprintf(archivo,"%s %s %d\n",fecha,producto,cantidad);

    fclose(archivo); //IMPORTANTE!!! Cerrar el archivo al final


}


void ListaDeVentas(int opcion){

    //Interruptor
    switch(opcion){
        case 1: VerLista();
        case 2: AgregarDatos();
    }
    
    //Total de una fecha
    while(!feof(archivo)){
        fscanf(archivo,"%s %s %d",fecha,producto,&cantidad);
        if(fecha==fecha por usuario){
            entonces int ganancia=ganancia+cantidad;
        }
    }

    //Total mensual
    while(!feof(archivo)){
        fscanf(archivo,"%s %s %d",fecha,producto,&cantidad);
        if(mes==mes por usuario){
            entonces int ganancia=ganancia+cantidad;
        }
    }

    //Total anual
    while(!feof(archivo)){
        fscanf(archivo,"%s %s %d",fecha,producto,&cantidad);
        if(anio==año por usuario){
            entonces int ganancia=ganancia+cantidad;
        }
    }

    printf("Ganancia: ",ganancia);

    //Promedio de una fecha
    while(!feof(archivo)){
        fscanf(archivo,"%s %s %d",fecha,producto,&cantidad);
        if(fecha==fecha por usuario){
            entonces int ganancia=ganancia+cantidad;
            int contador=+1;
        }
    }
    int promedio=ganancia/contador;

    //Promedio de una mes
    while(!feof(archivo)){
        fscanf(archivo,"%s %s %d",fecha,producto,&cantidad);
        if(mes==mes por usuario){
            entonces int ganancia=ganancia+cantidad;
            int contador=+1;
        }
    }
    int promedio=ganancia/contador;

    //Promedio anual
    while(!feof(archivo)){
        fscanf(archivo,"%s %s %d",fecha,producto,&cantidad);
        if(anio==anio por usuario){
            entonces int ganancia=ganancia+cantidad;
            int contador=+1;
        }
    }
    int promedio=ganancia/contador;
    
}




int main(){

AgregarDatos();

}








