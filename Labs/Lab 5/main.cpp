#include <stdio.h>
#include <stdlib.h>
#include "Pilha.h"
#include <string.>


int main ()
{
    TipoPilha *E1, *E2;

    char op;
    E1=InicializaPilha(E1);
    E2=InicializaPilha(E2);
    char rua[51];

    printf("\nDigite o caminho 1");

    do
    {
        printf("\nDigite 1 para continua ou qualquer outra tecla para terminar esse caminho: ");
        scanf(" %c",&op);
        if(op=='1')
        {
            printf("\nDigite o nome da rua: ");
            fflush(stdin);
            gets(rua);
            E1=PushPilha(E1,rua);
        }
    }while(op=='1');

    printf("------------------------------------------");
    printf("\nDigite o caminho 2");

    do
    {
        printf("\nDigite 1 para continua ou qualquer outra tecla para terminar esse caminho: ");
        scanf(" %c",&op);
        if(op=='1')
        {
            printf("\nDigite o nome da rua: ");
            fflush(stdin);
            gets(rua);
            E2=PushPilha(E2,rua);
        }
    }while(op=='1');

    ImprimirPilha(E1);
    ImprimirPilha(E2);

    if((Compara_pilhas(E1,E2))==1)
        printf("\n\nCaminhos inversos\n");
    else
        printf("\n\nCaminhos n inversos\n");

   system("pause");
}
