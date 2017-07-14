#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Pilha.h"


TipoPilha* InicializaPilha (TipoPilha *Topo)
{
    return NULL;
}

int Vazia (TipoPilha *Topo)
{
    if (Topo==NULL)
       return 1;
    else
       return 0;
}

void ImprimirPilha (TipoPilha *Topo)
{
     TipoPilha *ptaux;

     if (Topo != NULL)
     {
        puts("---Imprimindo pilha---");
        for (ptaux=Topo; ptaux!=NULL; ptaux=ptaux->elo)
            puts(ptaux->nome);
        puts("-------Fim pilha------");
     }
     else
       puts("Pilha vazia");

}



TipoPilha* PushPilha (TipoPilha *Topo, char* rua)
{
       TipoPilha *novo; //novo elemento
       TipoPilha *ptaux = Topo; //ponteiro auxiliar para percorrer a lista

       /*aloca um novo nodo */
       novo = (TipoPilha*) malloc(sizeof(TipoPilha));
       novo->elo = NULL;

       /*insere a informação no novo nodo*/
       strcpy(novo->nome,rua);

       /*encaeia o elemento*/
       novo->elo = Topo;
       Topo = novo;
       return Topo;
}


TipoPilha* PopPilha (TipoPilha *Topo, char *rua) //retorna 1 se exclui e zero se não exclui
{
   TipoPilha* ptaux;

   if (Topo == NULL)
     return NULL;   //não tem nada na pilha
   else
   {
        ptaux = Topo;          //guarda o endereço do topo
        strcpy(rua,Topo->nome);
        Topo = Topo->elo;     //o próximo passa a ser o topo
        free(ptaux);           //libera o que estava no topo
        return Topo;
   }
}

char* ConsultaPilha (TipoPilha *Topo)
{
 if (Topo==NULL)
       return "vazio";
 else
   return Topo->nome;

}

int Compara_pilhas(TipoPilha* E1, TipoPilha* E2)
{
    TipoPilha *E3=(TipoPilha*) (malloc(sizeof(TipoPilha)));
    int EhInversa=1;
    char rua[50],rua1[50],rua2[50];

    E3=InicializaPilha(E3);

    while(E2!=NULL)
    {
        E2=PopPilha(E2,rua);
        E3=PushPilha(E3,rua);
    }


    while(E1!=NULL && E3!=NULL)
    {
       E1=PopPilha(E1,rua1);
       E3=PopPilha(E3,rua2);

       if((strcmp(rua1,rua2))!=0)
            EhInversa=0;
    }

    if (E1!=E3)
        EhInversa=0;

    return EhInversa;

}

TipoPilha* DestroiPilha (TipoPilha *Topo)
{
        TipoPilha *ptaux;
        while (Topo != NULL)
        {
          ptaux = Topo;          //guarda o endereço do topo
          Topo = Topo->elo;     //o próximo passa a ser o topo
          free(ptaux);           //libera o que estava no topo
        }
        return NULL;
}



