#include <stdio.h>
#include <stdlib.h>
#include "abp.h"



pNodoA* InsereArvore(pNodoA *a, tipoinfo ch)
{
     if (a == NULL)
     {
         a =  (pNodoA*) malloc(sizeof(pNodoA));
         a->info = ch;
         a->esq = NULL;
         a->dir = NULL;
         return a;
     }
     else
          if (ch < a->info)
              a->esq = InsereArvore(a->esq,ch);
          else if (ch >= a->info)
              a->dir = InsereArvore(a->dir,ch);
     return a;
}

void preFixado(pNodoA *a)
{
     if (a!= NULL)
     {
          printf("%d\n",a->info);
          preFixado(a->esq);
          preFixado(a->dir);
      }
}

void Central(pNodoA *a)
{
     if (a!= NULL)
     {
          Central(a->esq);
          printf(" %d|",a->info);
          Central(a->dir);
      }
}

void posFixado(pNodoA *a)
{
     if (a!= NULL)
     {
          posFixado(a->esq);
          posFixado(a->dir);
          printf("%d\n",a->info);
      }
}

pNodoA* consultaABP(pNodoA *a, tipoinfo chave) {

    while (a!=NULL){
          if (a->info == chave )
             return a; //achou então retorna o ponteiro para o nodo
          else
            if (a->info > chave)
               a = a->esq;
            else
               a = a->dir;
            }
            return NULL; //se não achou
}

pNodoA* consultaABP2(pNodoA *a, tipoinfo chave) {
    if (a!=NULL) {


       if (a->info == chave)
         return a;
       else
           if (a->info > chave)
                return consultaABP2(a->esq,chave);
            if (a->info < chave)
                return consultaABP2(a->dir,chave);

            else return a;
       }
       else return NULL;
}
pNodoA* inserirNodos(pNodoA *arv, int index)
{
    int numero;
    char continuar='1';
    printf("\n\nContinuar a inserir na arvore %d?\n1 para sim ou qualquer outra tecla para nao: ",index);
    fflush(stdin);
    continuar=getchar();

    if(continuar=='1')
        do
        {
            fflush(stdin);
            printf("\nDigite um numero para inserir na arvore %d: ",index);
            fflush(stdin);
            scanf("%d", &numero);
            arv=InsereArvore(arv, numero);
            printf("\n\nContinuar a inserir na arvore %d?\n1 para sim ou qualquer outra tecla para nao: ",index);
            fflush(stdin);
            continuar=getchar();
            fflush(stdin);
        }
        while(continuar=='1');

    return arv;
}
int profundidade(pNodoA *arv )
{
    int profdir, profesq;

    if(arv==NULL)
        return 0;
    else
    {
        profesq=profundidade(arv->esq);
        profdir=profundidade(arv->dir);

        if(profdir>profesq)
            return (1+profdir);
        else
            return (1+profesq);
    }
}

int existeCaminho(pNodoA *arv, int num1, int num2)
{
    pNodoA *nodo1=(pNodoA*) malloc(sizeof(pNodoA));
    pNodoA *nodo2=(pNodoA*) malloc(sizeof(pNodoA));

    nodo1=consultaABP2(arv, num1);
    nodo2=consultaABP2(arv, num2);
    if (nodo1!=NULL && nodo2!=NULL)
        if(((consultaABP2(nodo1,nodo2->info))!=NULL) || ((consultaABP2(nodo2,nodo1->info))!=NULL))
            return 1;

    return 0;
}

int saoiguais(pNodoA *arv1, pNodoA *arv2)
{
    if(arv1==NULL && arv2==NULL)
        return 1;
    else if( ((arv1!=NULL) && (arv2==NULL)) || ((arv1==NULL) && (arv2!=NULL)))
        return 0;
    else if((arv1->info==arv2->info) && saoiguais(arv1->dir,arv2->dir) && saoiguais(arv1->esq,arv2->esq))
        return 1;
    else
        return 0;
}
