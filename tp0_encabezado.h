

#include <stdbool.h>

#ifndef TP0_Repaso
#define TP0_Repaso

// Ejercicio 1

enum Referencia
{
    INTERNO = -1,
    EN_CIRCUNFERENCIA,
    EXTERNO
};

//enum Referencia dondeEstaElPunto(int xc, int yc, int rc, int xp, int yp);

// Ejercicio 2

bool digitoEnNumero(long n, short d);

// Ejercicio 3

struct Punto {
    int x, y;
};



enum Referencia dondeEstaElPuntoBis(struct Punto centroC, int rc, struct Punto p);

int main(){


struct Punto p;
struct Punto b;
int integer;
int resultado;

resultado=dondeEstaElPuntoBis(p,integer,b);


}








#endif //TP0_Repaso