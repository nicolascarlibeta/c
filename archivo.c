
#include <stdio.h>

//--------------------------------------------------------------------
// lectura del archivo del TP0 - Ejercicio 6
//--------------------------------------------------------------------
int lectura() {
    int cliente;
    int anio;
    int mes;
    int hs;
    int lineas = 0;

    FILE *txt;

    txt = fopen("practica-0-ejercicio-6.txt", "r");

    if (txt == NULL) {
        printf("Error de Apertura !!! \n");
        return -1;
    }

    char *file_contents = malloc(100);
    fscanf(txt, "%[^\n] ", file_contents);
    printf("%s \n",file_contents);

    while (fscanf(txt, "%d %d %d %d", &cliente, &anio, &mes, &hs) != EOF) {
        printf("Linea[ %d ]: %d %d %d %d \n", lineas, cliente, anio, mes, hs);
        lineas++;
    }

    fclose(txt);

    printf("\n");

    return lineas;
}