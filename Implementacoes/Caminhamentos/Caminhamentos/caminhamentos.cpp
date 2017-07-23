#include <stdio.h>
#include <stdlib.h>
#include "caminhamentos.h"


void visita (int vis[max+1], int v)
{
     printf("%d\n",v);
     vis[v]= true;
}

void DFS (int grafo[max+1][max+1], int v, int vis[max+1])
{
    int w;
    visita(vis,v);
    for(w = 1; w<=max ; w++)    //percorre os vértices adjacentes a v
      if ((grafo[v][w]== 1) && (vis[w]==false))  //encontra um vértice adjacente a v que ainda nao tenha sido visitado
         DFS(grafo, w, vis); //chamada recursiva para o vértice adjacente a v
}



void BFS (int grafo[max+1][max+1], int v, int vis[max+1])
{
    int w;
    TipoFila *FV;
    

    visita(vis,v);
    FV = cria_fila();
    FV = insere(FV,v);
    while (!vazia(FV))
    {
       v = remove(&FV);
       for(w = 1; w<=max ; w++)    //percorre os vértices adjacentes a v
          if ((grafo[v][w]== 1) && (vis[w]==false))  //encontra um vértice adjacente a v que ainda nao tenha sido visitado
          {
              FV = insere(FV,w);
              visita(vis,w);
           }
   
    }
}

