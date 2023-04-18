
//Recursividad

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>


//RECURSIVIDAD DIRECTA SIMPLE

//Factorial (n!)


//Comportamiento de la Pila (Stack)
//Factorial de 5 (5!)

//1 (LIFO)
//1*[factorial(0)=1])
//2*factorial(1))
//3*factorial(2))
//4*factorial(3)) 
//5*factorial(4)) BASE DE LA PILA O STACK


int factorial(int n);                                               

int factorial(int n){

    //Caso BASE o DE CORTE
    if (n==0){
        return 1;
    }

    //Caso RECURSIVO o DE RECURSIÓN
    else{
        return (n*factorial(n-1));}
    
}


//Suma de los primeros n terminos


int sumaPrimNTerminos(int n);

int sumaPrimNTerminos(int n){
    
    //Caso BASE o DE CORTE
    if (n==1){
        return 1;
    }

    //Caso RECURSIVO o DE RECURSIÓN
    else{
        return (n+sumaPrimNTerminos(n-1));
    }


}


//Potencia (a*a*a*a...*a [n veces])

int potencia(int a,int n);

int potencia(int a,int n){
    
    //Corte
    if (n==0){
        return 1;
    }

    //Recursión
    else{
    return (a*potencia(a,n-1));
    }

}

void esunpalindromo(char *cadena, int letras);
void esunpalindromo(char *cadena, int letras){

    int i;
    char nuevaC[11];

    for (i=0;i<letras;++i){
        nuevaC[i]=cadena[i];
    }

    puts(nuevaC);

}

int CifraPos (int N, int P){
    if (P == 1) { return (N % 10); } // Esto es lo que retorna
    else {
    return CifraPos ((N / 10), P-1);}
    }



int main(){

/*
int fact=factorial(39);

printf("%d\n",fact);

int suma=sumaPrimNTerminos(9);

printf("%d\n",suma);

int pot=potencia(2,0);

printf("%d\n",pot);

strcpy(string pegado,string copiado)

char cadena[20]="Hola Mundo";

printf("%c\n",cadena[19]);


int resultado,numero=2409,posicion=3;
resultado=CifraPos(numero,posicion);
printf("%d\n",resultado);
*/




}