
#include <stdbool.h> 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#ifndef tp1_encabezado
#define tp1_encabezado


//Ejercicio 1

bool esPalindromo(char *cadena, int inicio, int fin);

bool esPalindromo(char *cadena, int inicio, int fin){

    bool resultado; //El resultado NO SE BORRA, porque NO ESTA DEFINIDO
 
    //Base
    if (inicio==fin){
        resultado=true;
        }
    else if (cadena[inicio]!=cadena[fin]){
        resultado=false;
    }

    //Recursivo
    else{
        return esPalindromo(cadena,inicio+1,fin-1);
    }

    return resultado;

    }


//Ejercicio 2

int producto(int x,int y);

int producto(int x,int y){
    
    //Corte
    if (y==1){
        return x;
    }

    //Recursión
    else{
    return (x+producto(x,y-1));
    }
}


//Ejercicio 3

int fibonacci(int n);

int fibonacci(int n){
    
    //Corte
    if (n==0 || n==1){
        return n;
    }

    //Recursión
    else{
        return fibonacci(n-1)+fibonacci(n-2);
        
    }

}

//Ejercicio 5

/*
int agregarSeparadorMiles(char **numero,int fin,int *digitos);

int agregarSeparadorMiles(char **numero,int fin,int *digitos){

    //Base
    if (fin==0){
        return 1; 
    }
    else if (*digitos==3){
        *digitos=0;
        *numero=realloc(*numero,sizeof(int)*(fin+1));
        
        return true;
    }
    //Recursivo
    else{
        *digitos=*digitos+1;
        return agregarSeparadorMiles(numero,fin-1,digitos);
    }

//TAD *puntero=calloc(bytes)
    

}
*/

//Ejercicio 10

int explosion(int n,int b,int *pos,int *lista);

int explosion(int n,int b,int *pos,int *lista){
    
    
    int n1=n/b, n2=n-(n/b), num=0;
    //Base
    if (n1<=b && n2<=b){
        lista[*pos]=n1;
        lista[*pos+1]=n2;
    }
    //Recursivo
    else{
    if (n1>b){
        num=n1;
        lista[*pos]=n2;}
    else{
        num=n2;
        lista[*pos]=n1;}
    
    //pos+1--> ERROR! (no esta sumando ningun valor)
    *pos=*pos+1; //El valor de pos se va acumulando dentro de la variable apuntada
    return explosion(num,b,pos,lista);
    }    
        
    }    

//Ejercicio adicional (Invertir una cadena de caracteres por recursión)

char InvertirCadena(char cadena);

//Ejercicio adicional 2 (Insertar un caracter en una cadena de string)

void InsertarCaracter(char* s1, char c, int posi);

void InsertarCaracter(char* s1, char c, int posi){

    //Base
    if (long==posi){
        return true;
    }
    else{
        
    }


}


#endif