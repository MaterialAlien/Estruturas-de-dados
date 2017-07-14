#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

typedef struct lista lista;
typedef struct TNodoA pNodoA;

struct lista
{
    char letra_index;
    pNodoA *letra_arvore;
    lista *prox;
    lista *ant;
};

struct TNodoA
{
    char palavra[10];
    int peso;
    int FB;
    pNodoA *esq;
    pNodoA *dir;
};
//Inicia a estrutura que irá receber as palavras do wikitionary. Uma floresta - lista - de arvores
lista* inicia_floresta(lista *inicio);

//Na floresta vaverá uma arvore para cada letra do alfabeto. Essa função inicia cada uma delas
lista* inicia_Arvore(lista *floresta, char letra);

//Função com o objetivo de pegar o enedereço da arvore 'z', a arvore final da floresta
lista* pega_fim(lista *inicio);

//Calcula a altura. Útil para calcular o fator do nodo de uma arvore
int Altura (pNodoA *a);

//A partir da altura retonarda, calcula o fator do nodo de uma arvore
int Calcula_FB(pNodoA *a);

//Funções relacionada a operação com arvores AVL
pNodoA* rotacao_direita(pNodoA *pt);
pNodoA* rotacao_esquerda(pNodoA *pt);
pNodoA* rotacao_dupla_direita (pNodoA* pt);
pNodoA* rotacao_dupla_esquerda (pNodoA* pt);
pNodoA* Caso1 (pNodoA* a, int *ok);
pNodoA* Caso2 (pNodoA *a, int *ok);
pNodoA* insere_na_arvore(pNodoA *a, char *palavra,int peso, int *ok);

//Preparação para o inicio da inserção de dados na floresta. Chama a função insere_na_arvore
//setando as variaveis necessárias para execução desta função
void insere_na_floresta(lista *iniciofloresta,lista*fimfloresta,char *palavra,int peso);

//Printa a arvore de uma letra. ´til para debugar o código
void printaArvore(pNodoA *arvore_letra);

//Printa a floresta/dicionario. ´til para debugar o código
void printaFloresta(lista *inicio);

//Dado uma letra, retorna a arvore desta letra
lista* busca_arvore(lista *iniciofloresta, lista *fimfloresta,char *palavra);

//Dado um prefixo do arquivo de consulta, retorna uma arvore com TODAS as previsoes desse prefixo.
pNodoA* pega_previsoes(lista *iniciofloresta, lista *fimfloresta,char *palavra,char *palavraLimite);

//Constroi a arvore de previsoes prcurando a partir da esquerda da arvore
pNodoA* busca_previsoesESQUERDA(pNodoA *arvore,char *palavra, char *palavraLimite, pNodoA *arvorePrevisoes,int *flag);

//Constroi a arvore de previsoes prcurando a partir da direita da arvore
pNodoA* busca_previsoesDIREITA(pNodoA *arvore,char *palavra, char *palavraLimite, pNodoA *arvorePrevisoes,int *flag);

//Insere efetivamente uma palavra do dicionario na arvore de previsoes
pNodoA* insere_previsoes(pNodoA *arvore, int peso, char *palavra);

//Escreve as previsoes no arquivo de saida
void escreve_previsoes(FILE *arquivoSaida,pNodoA *arvorePrevisoes, int *cont,int limitePrevisoes);

