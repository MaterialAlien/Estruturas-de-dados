
#include<stdio.h>
#include "abp.h"
#define TAM 20

main()
{
    printf("\n\nExercicio 1");

    pNodoA *arv1=NULL;
    pNodoA *arv2=NULL;
    int valor1,altura,valor2;

    arv1=inserirNodos(arv1,1);
    arv2=inserirNodos(arv2,2);

    printf("\n");
    Central(arv1);
    printf("\n");
    Central(arv2);
    printf("\n");
    printf("\n_______________________________________________________");

    printf("\n\nExercicio 2\n");

    printf("\nDigite um valor para encontrar na arvore 1: ");
    scanf("%d", &valor1);

    altura=profundidade(consultaABP2(arv1,valor1));

    if(altura>0)
        printf("\nA altura do no %d eh %d\n", valor1,altura);
    else
        printf("\nO noh %d nao esta na arvore\n", valor1);

    printf("\n_______________________________________________________");

    printf("\n\nExercicio 3");

    printf("\n\nDigite o valor 1: ");
    scanf("%d", &valor1);
    printf("\nDigite o valor 2: ");
    scanf("%d", &valor2);

    if(existeCaminho(arv1,valor1,valor2))
        printf("\nExiste um caminho entre %d e %d\n", valor1,valor2);
    else
        printf("\nNao Existe um caminho entre %d e %d\n", valor1,valor2);
    printf("\n_______________________________________________________");

    printf("\n\nExercicio 4\n");

    if(saoiguais(arv1,arv2))
        printf("\nAs arvores sao iguais\n");
    else
        printf("\nAs arvores nao sao iguais\n");
    printf("\n_______________________________________________________\n");
}
