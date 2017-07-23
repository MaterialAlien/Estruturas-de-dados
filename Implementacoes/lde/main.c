#include <stdio.h>
#include <stdlib.h>
#include "LDE.h"


int main()
{

  char c='a';
  InfoNo dados;
  int codigo;


  PtNo *l;

  // Inicializa a lista
  l = inicializa();

  // se for diferente de x imprime o menu
  do{
    printf("1 - Inserir no Final\n");
    printf("2 - Inserir no Inicio\n");
    printf("3 - Imprimir\n");
    printf("4 - Imprimir Invertida\n");
    printf("5 - Destruir\n");
    printf("x - Sair do programa\n");
    // obtem o caracter
    c=getch();
    switch(c){
      case '1': {
                printf("Codigo: "); fflush(stdin);scanf("%d",&dados.codigo);
                printf("Nome: "); fflush(stdin);scanf("%s",dados.nome);
                printf("Preço: "); fflush(stdin);scanf("%f",&dados.preco);
                l=insereFinal(l,dados);
                break;
                }
     case '2': {
                printf("Codigo: "); fflush(stdin);scanf("%d",&dados.codigo);
                printf("Nome: "); fflush(stdin);scanf("%s",dados.nome);
                printf("Preço: "); fflush(stdin);scanf("%f",&dados.preco);
                //l=insereInicio(l,dados);
                insereInicio2(&l,dados);
                break;
                }
      case '3': {
                system("cls");
                imprime(l);
                break;
                }
      case '4': {
                system("cls");
                imprimeInvertida(l);
                break;
                }

      case '5': {
                l=destroi(l);
                break;
                }

    }
  }while (c!='x');
  return 0;
}

