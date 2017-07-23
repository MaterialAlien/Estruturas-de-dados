#include <stdio.h>
#include <stdlib.h>
#include "Pilha.h"


int main ()
{
    TipoPilha *P1, *P2;
    TipoInfo dado;

    P1=InicializaPilha(P1);
    P2=InicializaPilha(P2);

    P1 = PushPilha(P1,1);
    P1 = PushPilha(P1,2);
    P1 = PushPilha(P1,3);
    P1 = PushPilha(P1,4);

    P2 = PushPilha(P2,4);
    P2 = PushPilha(P2,5);
    P2 = PushPilha(P2,6);
    P2 = PushPilha(P2,7);
    P2 = PushPilha(P2,8);

    ImprimirPilha(P1);

    ImprimirPilha(P2);


   system("pause");
}
