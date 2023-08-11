

#include "tp6_encabezado.h"
#include <stdio.h>
#include <string.h>



//TRABAJO PRÁCTICO 6.

// Ejercicio 4 (Con Archivo .txt)

void guardarLegajoABM(TablaHash th){

    //Handler (Manejador de archivos FILE)
    FILE *archivo;
    archivo=fopen("alumnos.txt","r");

    //Leemos los registros
    int legajo, te;
    char nom[20], dom[20];

    while(!(feof(archivo))){
        fscanf(archivo,"%d %s %s %d",&legajo,&nom,&dom,&te);
        TipoElemento e=te_crear(legajo);
        th_insertar(th,e); //INSERTAMOS EL LEGAJO COMO CLAVE EN LA TABLA HASH
        }

    fclose(archivo); 

}

void ABM_Alumnos(){

    //Handler (Manejador de archivos FILE)
    FILE *archivo;
    archivo=fopen("alumnos.txt","a");

    //Escribimos el archivo
    int legajo, te;
    char nom[20], dom[20];

    printf("Ingrese el LEGAJO del alumno: ");
    scanf("%d",&legajo);
    printf("Ingrese el APELLIDO,NOMBRE del alumno: ");
    scanf("%s",&nom);
    printf("Ingrese el DOMICILIO del alumno: ");
    scanf("%s",&dom);
    printf("Ingrese el TELEFONO del alumno: ");
    scanf("%d",&te);

    fprintf(archivo,"%d %s %s %d\n",legajo,nom,dom,te);

    fclose(archivo); 

}


// Ejercicio 6 (Con Archivo .txt)

void ABM_Vacunados(){

    //Handler (Manejador de archivos FILE)
    FILE *archivo;
    archivo=fopen("vacunados.txt","a");

    //Escribimos el archivo
    char *fecha[40], *nom[50], *ape[50], *dni[8];

    printf("Ingrese la fecha de vacunacion (dd/MM/aaaa): ");
    scanf("%s",&fecha);
    printf("Ingrese el NOMBRE: ");
    scanf("%s",&nom);
    printf("Ingrese el APELLIDO: ");
    scanf("%s",&ape);
    printf("Ingrese el DNI: ");
    scanf("%s",&dni);

    fprintf(archivo,"%s %s %s %s\n",fecha,nom,ape,dni);

    fclose(archivo); 

}

void VacunadosPorFecha(TablaHash th, char *f){

    //Manejador de archivos FILE
    FILE *archivo;
    archivo=fopen("vacunados.txt","r");
    
    //Leemos los registros
    char fecha[40], nom[50], ape[50], dni[8], *fe;

    while(!feof(archivo)){
        fscanf(archivo,"%s %s %s %s",fecha,nom,ape,dni); //LEEMOS la LÍNEA del ARCHIVO
        fe=fecha;
        if(strcmp(fe,f)==0){
            //Convertimos a entero
            int clave=(int)strtol(dni,NULL,10);
            TipoElemento e=te_crear(clave);
            th_insertar(th,e);
        }
    }

    fclose(archivo);

}

//FUNCIÓN HASH
int hash_por_modulo(int clave){
    return clave%10;
}

int hash_por_plegamiento(int clave){
    
    int u,p,dir;
    u=clave%1000;
    p=clave/1000;
    dir=u+p;
    return dir;
    
}


int main(){

    /*
    TablaHash th=th_crear(2000,&hash_por_plegamiento);
    ABM_Alumnos();
    guardarLegajoABM(th);
    th_mostrar_solo_ocupados(th);
    
    TablaHash th=th_crear(2000,&hash_por_modulo);
    char fecha[40];
    printf("Hola, por favor ingrese una fecha valida: ");
    scanf("%s",fecha);
    //ABM_Vacunados();
    VacunadosPorFecha(th,fecha);
    th_mostrar_solo_ocupados(th);
    */
    TablaHash th=th_crear(10,&hash_por_modulo);
    TipoElemento X=te_crear(40);
    th_insertar(th,X);
    X=te_crear(15);
    th_insertar(th,X);
    X=te_crear(10);
    th_insertar(th,X);
    X=te_crear(20);
    th_insertar(th,X);
    X=te_crear(35);
    th_insertar(th,X);
    th_eliminar(th,15);
    th_eliminar(th,40);
    th_mostrar(th);


}
