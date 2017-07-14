#include <stdio.h>
#include <string.h>

struct arv{
	char peso[10];
	char palavra[10];
	struct arv *esquerda;
	struct arv *direita;
};

typedef struct arv arv;

arv* inserir (arv  *arvore,char *peso_, char *palavra_)
{
	int diferenca;
	if(arvore==NULL)
	{
		strcpy(arvore->peso,peso_);
		strcpy(arvore->palavra,palavra_);
		arvore->direita=NULL;
		arvore->esquerda=NULL;
	}
	else
	{
		diferenca=strcmp(palavra_,arvore->palavra);
		
		if(diferenca > 0 || diferenca==0)
			arvore->direita=inserir(arvore->direita,peso_,palavra_);
		else
			arvore->esquerda=insesir(arvore->esquerda,peso_,palavra_);
	}
	
	return arvore;
}

void imprimirCentral(arv *arvore)
{
	if(arvore!=NULL)
	{
		imprimirCentral(arvore->esquerda);
		puts(arvore->palavra);
		printf("\n");
		imprimirCentral(arvore->direita);
	}
}

main()
{
	arv *arvore= (arv*) malloc(sizeof(arv));
	arvore=NULL;
	char nome_[10],peso_[10];
	char continuar;
	
	printf("\nContinua a inserir palavras na arvore?");
	printf("1 para sim, qualquer outra tecla para nao: ");
	fflush(sdtin);
	scanf("%c", &continuar);

	while(continuar=='1')
	{
		printf("\nDigite a palara ser inserida na arvore: ");
		gets(nome_)
		printf("\nDigite o peso da palavra: ");
		gets(peso_);
		arvore=inserir(arvore,peso_,nome_);
		
		printf("\nContinua a inserir palavras na arvore?");
		printf("1 para sim, qualquer outra tecla para nao: ");
		fflush(sdtin);
		scanf("%c", &continuar);
	}
	
	imprimirCentral(arvore);

	
}
