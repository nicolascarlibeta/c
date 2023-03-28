
#include <stdbool.h> 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#ifndef tp1_encabezado
#define tp1_encabezado


//Ejercicio 1

bool esPalindromo(char cadena, int *letras);

//bool esPalindromo(char cadena, int *letras){
//
//    //Corte
//
//
//    //Recursión
//;}
    

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

//Ejercicio 4

double division(int x,int y,int cont);

double division(int x,int y,int cont){

    //Corte
    if (x==0){
        return cont;
    }
    
    //Recursión
    else{
    cont=cont+1;
    return division(x-y,y,cont);
    }
}



#endif