
#include <stdio.h>
#include <stdlib.h>

typedef struct lista lista;
typedef struct TNodoA pNodoA;
typedef char TipoInfo;

struct TNodoA{
TipoInfo info;
int FB;
struct TNodoA *esq;
struct TNodoA *dir;
};

struct lista{
	char letra_index;
	pNodoA *letra_arvore;
	lista *prox;
	lista *ant;
};

lista* inicia_floresta(lista *floresta)
{
	char index;
	lista *ptaux=floresta;
	lista *ptant=NULL;
	for(index='a';index<='z';index++)
	{
		ptaux=(lista*) malloc(sizeof(lista));
		ptaux->letra_index=index;
		//ptaux->letra_avore=(pNodoA*) malloc(sizeof(pNodoA));
		ptaux->letra_arvore=NULL;
		ptaux->ant=ptant;
		ptaux->prox=NULL;
		ptant=ptaux;
		ptaux=ptaux->prox;
	}
	return ptant;
}

void imprime(lista *list)
{
	lista ptaux=list;
	
	do
	{
		printf("\n\nLetra %c", (ptaux->letra_index));
		printf("\nPróximo %c | Anterior %c", (ptaux->prox->letra_index),(ptaux->ant->letra_index));
		ptaux=ptaux->prox;
	}while(ptaux!=list);
}

main()
{
	lista *ind=NULL;
	lista *final;
	
	final=inicia_floresta(ind);
	fina->prox=ind;
	ind->ant=final;
	imprime(ind);
	
}
