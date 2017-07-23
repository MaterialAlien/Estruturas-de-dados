#include <stdio.h>
#include <stdlib.h>
#include "LDE.h"

PtNo* inicializa(void)
{
       return NULL;
}



void imprime(PtNo* PtLista)
{
     PtNo* ptaux=PtLista;
     if (PtLista == NULL)
        puts("lista vazia");
     else
     do {
         printf("Codigo = %d Nome = %s Preco = %f\n",
              ptaux->info.codigo,
              ptaux->info.nome,
              ptaux->info.preco);
         ptaux = ptaux->prox;
     } while (ptaux != NULL);
}

void imprimeInvertida(PtNo *PtLista){
  PtNo *PtAux;
  if (PtLista==NULL){
       printf("Lista vazia ! ");
  }else
  {
      PtAux=PtLista;
      while (PtAux->prox!=NULL)
            PtAux=PtAux->prox;

      while (PtAux!=NULL) {
          printf("Codigo = %d Nome = %s Preco = %f\n",
              PtAux->info.codigo,
              PtAux->info.nome,
              PtAux->info.preco);
          PtAux=PtAux->ant;
      }
 }
}

PtNo* insereInicio(PtNo *PtLista, InfoNo Dado)
{
  PtNo *Pt;
  Pt = (PtNo*) malloc(sizeof(PtNo));

  Pt->info = Dado;

  Pt->ant = NULL;
  Pt->prox = PtLista;
  if (PtLista != NULL)
     PtLista->ant = Pt;
  PtLista = Pt;
  return PtLista;
}

void insereInicio2(PtNo **PtLista, InfoNo Dado)
{
  PtNo *Pt;
  Pt = (PtNo*) malloc(sizeof(PtNo));

  Pt->info = Dado;

  Pt->ant = NULL;
  Pt->prox = *PtLista;
  if (*PtLista != NULL)
     (*PtLista)->ant = Pt;
  *PtLista = Pt;
}

PtNo* insereFinal(PtNo *PtLista, InfoNo Dado)
{
  PtNo *Pt, *PtAux;
  Pt = (PtNo*) malloc(sizeof(PtNo));	//aloca novo nodo
  Pt->info = Dado;			//coloca dados no novo nodo
 if ((PtLista) == NULL)		//lista vazia
  {
     PtLista = Pt;
     Pt->ant = NULL;
     Pt->prox = NULL;
  }
 else {				// lista tem pelo menos um nodo
    PtAux = PtLista;			 //auxiliar no início da lista
    while (PtAux->prox != NULL) 	//PtAux avança até o último elemento da lista
         PtAux=PtAux->prox;
    PtAux->prox = Pt;
    Pt->ant = PtAux;		//Encadeia Pt com PtAux
    Pt->prox = NULL;
  }
    return PtLista;
}

PtNo* destroi(PtNo* ptLista)
{
   PtNo *ptaux; //ponteiro auxiliar para percorrer a lista
   while (ptLista != NULL)
   {
         ptaux = ptLista;
         ptLista = ptLista->prox;
         free(ptaux);
   }
   free(ptLista);
   return NULL;
}




