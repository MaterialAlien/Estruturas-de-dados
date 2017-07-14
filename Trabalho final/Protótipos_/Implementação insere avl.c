#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "avl.h"


typedef struct lista lista;
typedef struct TNodoA pNodoA;
typedef char TipoInfo;

struct lista{
	char letra_index;
	pNodoA *letra_arvore;
	lista *prox;
	lista *ant;
};



struct TNodoA{
	TipoInfo palavra[10];
	TipoInfo peso[10];
	int FB;
	pNodoA *esq;
	pNodoA *dir;
};


int Altura (pNodoA *a)
{
    int Alt_Esq, Alt_Dir;
    if (a == NULL)
      return 0;
    else
    {
       Alt_Esq = Altura (a->esq);
       Alt_Dir = Altura (a->dir);
       if (Alt_Esq > Alt_Dir)
         return (1 + Alt_Esq);
       else
         return (1 + Alt_Dir);
     }
}

int Calcula_FB(pNodoA *a)
{
    return (Altura(a->esq) - Altura(a->dir));
}

pNodoA* rotacao_direita(pNodoA *pt){
   pNodoA* ptu;

   ptu = pt->esq; 
   pt->esq = ptu->dir; 
   ptu->dir = pt; 
   pt->FB = 0;
   pt = ptu; 
   return pt;
}

pNodoA* rotacao_esquerda(pNodoA *pt){
   pNodoA* ptu;

   ptu = pt->dir; 
   pt->dir = ptu->esq; 
   ptu->esq = pt; 
   pt->FB = 0;
   pt = ptu; 
   return pt;
} 

pNodoA* rotacao_dupla_direita (pNodoA* pt){
   pNodoA* ptu, *ptv;

   ptu = pt->esq; 
   ptv = ptu->dir; 
   ptu->dir = ptv->esq; 
   ptv->esq = ptu; 
   pt->esq = ptv->dir; 
   ptv->dir = pt; 
   if (ptv->FB == 1)   pt->FB = -1;
      else pt->FB = 0;
   if (ptv->FB == -1)  ptu->FB = 1;
      else ptu->FB = 0;
   pt = ptv; 
   return pt;
} 

pNodoA* rotacao_dupla_esquerda (pNodoA* pt){
   pNodoA *ptu, *ptv;

   ptu = pt->dir; 
   ptv = ptu->esq; 
   ptu->esq = ptv->dir; 
   ptv->dir = ptu; 
   pt->dir = ptv->esq; 
   ptv->esq = pt; 
   if (ptv->FB == -1) pt->FB = 1;
     else pt->FB = 0;
   if (ptv->FB == 1) ptu->FB = -1;
      else ptu->FB = 0;
   pt = ptv; 
   return pt;
}


pNodoA* Caso1 (pNodoA* a , int *ok)
{
   pNodoA *ptu; 

	ptu = a->esq;
	if (ptu->FB == 1) 
        	a = rotacao_direita(a);
  
    else
        a = rotacao_dupla_direita(a);
	
    a->FB = 0;
	*ok = 0;
	return a;
}

pNodoA* Caso2 (pNodoA *a , int *ok)
{
    pNodoA *ptu; 

	ptu = a->dir;
	if (ptu->FB == -1) 
       	a=rotacao_esquerda(a);
   
    else
       a=rotacao_dupla_esquerda(a);
    
	a->FB = 0;
	*ok = 0;
	return a;
}

pNodoA* InsereAVL (pNodoA *a, TipoInfo *palavra_,TipoInfo *peso_, int *ok)
{
/* Insere nodo em uma Ჶore AVL, onde A representa a raiz da Ჶore,
  x, a chave a ser inserida e h a altura da Ჶore */

     if (a == NULL) 
     {
     	a = (pNodoA*) malloc(sizeof(pNodoA));
        strcpy((a->peso),*peso_);
        strcpy((a->palavra),*palavra_);
        a->esq = NULL;
        a->dir = NULL;
        a->FB = 0; 
	*ok = 1;
     }
     else
     if (strcmp(*palavra_,(a->palavra)) < 0) 
     {
		a->esq = InsereAVL(a->esq,palavra_,peso_,ok);
        if (*ok) 
        {
   		    switch (a->FB) {
        	  case -1:  a->FB = 0; *ok = 0; break;
			  case  0:  a->FB = 1;  break;
			  case  1:  a=Caso1(a,ok); break;
            }
         }
     }
	 else
     {
  		    a->dir = InsereAVL(a->dir,palavra_,peso_,ok);
            if (*ok)
            { 
              switch (a->FB) {
                case  1:  a->FB = 0; *ok = 0; break;
                case  0:  a->FB = -1; break;
			    case -1:  a = Caso2(a,ok); break;
             }
            }
     }
     return a;
}

