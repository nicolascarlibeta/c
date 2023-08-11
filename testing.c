
#include <stdio.h>
#include <stdlib.h> 
#include <math.h>


void orden(int a[]){

    int i, o, aux;
    for(i=0; i<4; i++){
        for(o=i; o<4; o++){
            if(a[i]<a[o]){
                aux=a[i];
                a[i]=a[o];
                a[o]=aux;
            }
        }
    }


}

void imprimir(int b[]){
    int i;
    for(i=0; i<4; i++){
        printf("%i ",b[i]);
    }
    printf("\n");
}



int main(){

    int v[4]={9,4,2,14};
    orden(v);
    imprimir(v);
}








    
    
  