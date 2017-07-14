#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "interface.h"

//Implementação básica de inserção em lista duplamente encadeada.
//Implementação igual a vista em aula. Cada item da lista representará uma letra do alfabeto
lista* inicia_Arvore(lista *floresta, char letra)
{
    lista *Pt, *PtAux;
    Pt = (lista*) malloc(sizeof(lista)); //aloca novo nodo
    Pt->letra_index = letra; //coloca dados no novo nodo
    Pt->letra_arvore=NULL;

    if ((floresta) == NULL) //lista vazia
    {
        floresta = Pt;
        Pt->ant = NULL;
        Pt->prox = NULL;
    }
    else
    {
        PtAux = floresta; //auxiliar no início da lista
        while (PtAux->prox != NULL) //PtAux avança até o último elemento da lista
            PtAux=PtAux->prox;
        PtAux->prox = Pt;
        Pt->ant = PtAux; //Encadeia Pt com PtAux
        Pt->prox = NULL;
    }
    return floresta;
}

//Percorre a lista até chegar no ultimo item, que retornará a estrutura que contiver a arvore AVL da letra 'z'
lista* pega_fim(lista *inicio)
{
    lista *ptaux=inicio;

    while(ptaux->prox!=NULL)
        ptaux=ptaux->prox;

    return ptaux;
}

//Inicia a lista duplamente encadeada, também chamada de floresta duplamente encadeada, por ser uma lista de arvores AVL
//Cada arvore da floresta representará uma letra do alfabeto
lista* inicia_floresta(lista *inicio)
{
    char index;

    for(index='a'; index<='z'; index++)
        inicio=inicia_Arvore(inicio,index);
    return inicio;
}


//As funções daqui até a linha 234 são usadas para inserir as palavras e seus pesos em arvores AVL. A chave de inserção é a palavra
//A palavra e o peso serão inseridos na arvore da letra inicial da palavra
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



pNodoA* rotacao_direita(pNodoA *pt)
{
    pNodoA* ptu;

    ptu = pt->esq;
    pt->esq = ptu->dir;
    ptu->dir = pt;
    pt->FB = 0;
    pt = ptu;
    return pt;
}

pNodoA* rotacao_esquerda(pNodoA *pt)
{
    pNodoA* ptu;

    ptu = pt->dir;
    pt->dir = ptu->esq;
    ptu->esq = pt;
    pt->FB = 0;
    pt = ptu;
    return pt;
}

pNodoA* rotacao_dupla_direita (pNodoA* pt)
{
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

pNodoA* rotacao_dupla_esquerda (pNodoA* pt)
{
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


pNodoA* Caso1 (pNodoA* a, int *ok)
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

pNodoA* Caso2 (pNodoA *a, int *ok)
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

pNodoA* insere_na_arvore(pNodoA *a, char *palavra,int peso, int *ok)
{
    /* Insere nodo em uma árvore AVL, onde A representa a raiz da árvore,
      x, a chave a ser inserida e h a altura da árvore */

    if (a == NULL)
    {
        a = (pNodoA*) malloc(sizeof(pNodoA));
        a->peso=peso;
        stpcpy(a->palavra,palavra);
        //printf("\n%s    %s",peso,palavra);
        //printf("\n%d   %s",a->peso,a->palavra);
        a->esq = NULL;
        a->dir = NULL;
        a->FB = 0;
        *ok = 1;
    }
    else if (strcmp(palavra,a->palavra)<0)
    {
        a->esq = insere_na_arvore(a->esq,palavra,peso,ok);
        if (*ok)
        {
            switch (a->FB)
            {
            case -1:
                a->FB = 0;
                *ok = 0;
                break;
            case  0:
                a->FB = 1;
                break;
            case  1:
                a=Caso1(a,ok);
                break;
            }
        }
    }
    else
    {
        a->dir = insere_na_arvore(a->dir,palavra,peso,ok);
        if (*ok)
        {
            switch (a->FB)
            {
            case  1:
                a->FB = 0;
                *ok = 0;
                break;
            case  0:
                a->FB = -1;
                break;
            case -1:
                a = Caso2(a,ok);
                break;
            }
        }
    }
    return a;
}


//Extramente util para debugação. A cada inserção de palavra, pode ser printado a nova floresta com a palavra inserida,
//acompanho assim o e seu crescimento em tempo real;
//Printa a arvore no sentido Central esquerda, com as palavras sendo printadas de forma crescente
void printaArvore(pNodoA *arvore_letra)
{
    if(arvore_letra!=NULL)
    {
        printaArvore(arvore_letra->esq);
        printf("%s - %d |", arvore_letra->palavra,arvore_letra->peso);
        printaArvore(arvore_letra->dir);
    }
}

//Também extremamente util para debugação do código
//Para cada letra do alfabeto será printa sua respectiva arvore AVL
void printaFloresta(lista *inicio)
{
    lista *ptaux=inicio;

    system("pause");
    while(ptaux!=NULL)
    {
        system("pause");
        printf("\n\n%c:\n",ptaux->letra_index);
        if(ptaux->letra_arvore==NULL)
            printf("Vazio");
        else
            printaArvore(ptaux->letra_arvore);

        ptaux=ptaux->prox;
    }
}

//Dado uma palavra para inserir na floresta, essa função procura arvore correta.

//1- Se a inicial da palavra for igual ou menor do que 'n', a busca começará a partir do inicio da floresta
//que é a letra 'a', indo em direção crescente;
//2-Se a inicial da palavra for maior do que 'n', a busca começará a partir do fim da floresta
//que é a letra 'z', indo em direção crescente;

//3- Ao chegar a arvore da letra inicial da palavra, retorna a estrutura inteira dessa.
//A principio foi implementado para retornar somente a arvore, porém o código não funcionava direito
lista* busca_arvore(lista *iniciofloresta, lista *fimfloresta,char *palavra)
{
    lista *ptaux;
    char index=*palavra;
    if(index<='n')//1
    {
        ptaux=iniciofloresta;
        while(ptaux->letra_index!=index)//3
            ptaux=ptaux->prox;
    }
    else//2
    {
        ptaux=fimfloresta;
        while(ptaux->letra_index!=index)//3
            ptaux=ptaux->ant;
    }
    return ptaux;//3
}

//Função para inserir a tupla palavra/peso na floresta
//1- Primeiro busca a arvore AVL correspondente a letra inicial da palavra;
//2- Achado sua arvore AVL, insere a palavra/peso nela, sendo a palavra a chave de ordenação
void insere_na_floresta(lista *iniciofloresta,lista*fimfloresta,char *palavra,int peso)
{
    lista *ptaux;
    int ok=1;
    lista *arvoreProcurada=busca_arvore(iniciofloresta,fimfloresta,palavra);//1
    //printf("\n %s   %s\n",palavra,peso);
    arvoreProcurada->letra_arvore=insere_na_arvore(arvoreProcurada->letra_arvore,palavra,peso,&ok);//2
}

//Dado uma arvore de previsoes, escreve no arquivo de saida tantas previsões quanto a quantidade passada por linha de comando
//1-Sempre que uma previsão é escrita no arquivo, um contador passado por referencia é incrementado
//2- A função termina quando todas a palavras/pesos da arvore de previsões forem escritas ou até quando o contador for menor que o limite
void escreve_previsoes(FILE *arquivoSaida,pNodoA *arvorePrevisoes, int *cont,int limitePrevisoes)
{

    if(arvorePrevisoes!=NULL)//2
    {
        escreve_previsoes(arquivoSaida,arvorePrevisoes->dir,cont,limitePrevisoes);
        if(*cont<limitePrevisoes)//2
        {
            fprintf(arquivoSaida,"\n     %.10d - %s",arvorePrevisoes->peso,arvorePrevisoes->palavra);//1
            *cont=(*cont)+1;//1
            escreve_previsoes(arquivoSaida,arvorePrevisoes->esq,cont,limitePrevisoes);
        }
    }
}


//Insere palavra junto com seus pesos na arvore de previsões, que é uma arvore ABP.
//Como não haverá busca na arvore, apenas caminhamento, não há motivo para fazer qualquer outro tipo de arvore
//A chave de ordenação nessa arvore é o peso
//A implementação dessa função é exatamente igual a função de inserção em ABP mostrada em sala de aula
pNodoA* insere_previsoes(pNodoA *arvore, int peso, char *palavra)
{
    pNodoA *novo;
    if(arvore==NULL)
    {
        arvore=(pNodoA*) malloc((sizeof(pNodoA)));
        strcpy(arvore->palavra,palavra);
        arvore->peso=peso;
        arvore->FB=0;
        arvore->esq=NULL;
        arvore->dir=NULL;
    }
    else if(peso<=arvore->peso)
        arvore->esq=insere_previsoes(arvore->esq,peso,palavra);
    else
        arvore->dir=insere_previsoes(arvore->dir, peso, palavra);
    return arvore;
}

//Função para encontrar previsões de uma palavra percorrendo a arvore da letra inicial desta palavra pela esquerda
//1-A função começar a inserir as palavras da arvore da floresta na arvore de previsões quando a palavra atual do percorrimento
//da arvore for maior que a palavra cujas previsões eu quero pesquisar;
//2-Quando a palavra atual do percorrimento for maior que a palavraLimite - que foi calculada na função main -
//é desligado um flag passado por referência para a função;
//3-A função de busca termina quando o percorrimento acabar ou quando a flag estiver desligada;
pNodoA* busca_previsoesESQUERDA(pNodoA *arvore,char *palavra, char *palavraLimite, pNodoA *arvorePrevisoes,int *flag)
{

    if(arvore!=NULL && (*flag))//3
    {
        arvorePrevisoes=busca_previsoesESQUERDA(arvore->esq, palavra,palavraLimite,arvorePrevisoes,flag);
        if(strcmp(palavra,arvore->palavra)<0)//1
            if (strcmp(arvore->palavra,palavraLimite)<0)//2
                arvorePrevisoes=insere_previsoes(arvorePrevisoes,arvore->peso,arvore->palavra);
            else
                *flag=0;//2
        arvorePrevisoes=busca_previsoesESQUERDA(arvore->dir, palavra,palavraLimite,arvorePrevisoes,flag);
    }

    return arvorePrevisoes;
}

//Função para encontrar previsões de uma palavra percorrendo a arvore da letra inicial desta palavra pela direita
//1-A função começar a inserir as palavras da arvore da floresta na arvore de previsões quando a palavra atual do percorrimento
//da arvore for menor que a palavraLimite - que foi calculada na função main -
//2-Quando a palavra atual do percorrimento for menor que a palavra cujas previsões eu quero pesquisar
//é desligado um flag passado por referência para a função;
//3-A função de busca termina quando o percorrimento acabar ou quando a flag estiver desligada;
pNodoA* busca_previsoesDIREITA(pNodoA *arvore,char *palavra, char *palavraLimite, pNodoA *arvorePrevisoes,int *flag)
{
    if(arvore!=NULL && (*flag))//3
    {
        arvorePrevisoes=busca_previsoesDIREITA(arvore->dir, palavra,palavraLimite,arvorePrevisoes,flag);
        if(strcmp(palavraLimite,arvore->palavra)>0)//1
            if (strcmp(arvore->palavra,palavra)>0)//2
                arvorePrevisoes=insere_previsoes(arvorePrevisoes,arvore->peso,arvore->palavra);
            else
                *flag=0;//2
        arvorePrevisoes=busca_previsoesDIREITA(arvore->esq, palavra,palavraLimite,arvorePrevisoes,flag);
    }

    return arvorePrevisoes;
}

//Pega a arvore de previsões de uma palavra que estiver no arquivo de consultas
//Devemos identificamos qual percorrimento a busca de previsões vai fazer
//Como toda as letras iniciais das palavras de uma arvore vão ser iguais, o ordenamento delas dentro dentro destas arvores
//vai ser decidido a partir das segundas letras destas palavras
//1-Buscamos a arvore que corresponde a letra inicial da palavra consultada;
//2-Se a segunda letra da palvra vier antes do n, então será feita a busca pela previsões da palvra começando pela esquerda, de forma crescente;
//3-Do contrário, a busca pelas previsões será feita a partir da dereita, de forma decrescente
pNodoA* pega_previsoes(lista *iniciofloresta, lista *fimfloresta,char *palavra,char *palavraLimite)
{
    int flag=1;
    pNodoA *arvorePrevisoes=NULL;
    lista *arvoreProcurada=busca_arvore(iniciofloresta,fimfloresta,palavra);//1
    char segundaLetra=*(palavra+1);

    if (segundaLetra < 'n')//2
        arvorePrevisoes=busca_previsoesESQUERDA(arvoreProcurada->letra_arvore,palavra,palavraLimite,arvorePrevisoes,&flag);
    else//3
        arvorePrevisoes=busca_previsoesDIREITA(arvoreProcurada->letra_arvore,palavra,palavraLimite,arvorePrevisoes,&flag);

    return arvorePrevisoes;
}







