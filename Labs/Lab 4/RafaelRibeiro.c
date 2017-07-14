#include <stdio.h>
#include <stdlib.h>  //necessaria para o malloc
#include <string.h> //necessaria para o strcm

typedef struct TipoNo ptLSE;

struct TipoNo{
       int numero;
       ptLSE *prox;
       ptLSE *ant;
       };

ptLSE* cria_lista(void)
{
    return NULL;
}

ptLSE* insere(ptLSE *lista, int num)

{
    ptLSE *aux,*aux2=NULL; //ponteiros auxiliares para guardar uma posi��o no itera��o da LSD
    ptLSE *pos = NULL; //ponteiro auxiliar para gurdar o termo a direita do termo repetido
    ptLSE *novo = NULL; //ponteiro auxiliar com m�ltiplas fun��es
     // Se for achado um numero repetido, a variavel novo receber� a fun��o de guardar o numero a esquerda do nuemro repetido
     // Se n�o, ela ser� usado para guardar o numero no final  da lista
    ptLSE *ptaux = lista; //ponteiro auxiliar para percorrer a lista
    novo = (ptLSE*) malloc(sizeof(ptLSE));
    novo->numero=num;
    novo->prox=NULL;

    while (ptaux != NULL) // Ponteiro auxiliar para percorrer a LSD
    {
        if(ptaux->numero == num) // Detecta se o numero a inserir na lista j� existe na lista
        {

            novo->numero=num-1; // N�mero a ser inserido a esquerda do numero repetido
            novo->prox=ptaux;  // Aponta para o ponteiro atual em que est� o while
            novo->ant=aux2;


            pos=(ptLSE*) malloc(sizeof(ptLSE)); // Aloca��o de mem�ria para um ponteiro auxiliar
            aux=ptaux->prox; // Variavel auxiliar recebe o pr�ximo endere�o da lista
            ptaux->prox=pos; // Pr�ximo endere�o da lista recebe pos
            pos->ant=ptaux;
            pos->numero=num+1; // N�mero a ser inserido a direita de numero repetido
            pos->prox=aux; // O endere�o depois de pos se torna aux

            if (aux2==NULL) // Lista sem nenhum termo a esquerda do termo repetido
            {
                lista=novo;
                novo->ant=NULL;
            }
            else
            {
                aux2->prox=novo; // Lista com termo a esquerda do termo repetido

            }

            return lista; // Retorno da lista atualizada se o termo digitado for repetido
        }
        aux2=ptaux;
        ptaux = ptaux->prox;
    }
    if (aux2 == NULL) // Lista vazia, primeiro termo a ser inserido na lista
        {
            lista = novo;
            lista->ant=NULL;
        }
    else
        {
            novo->ant=aux2;
            aux2->prox=novo; // Se o termo digitado n�o for encontrado na lista, ent�o ele � adicionado no fim da lista
        }

    return lista;// Retorno da lista atualizada se o termo digitado n�o for repetido
}
void imprime(ptLSE *lista)
{
    ptLSE *ptaux;
    if (lista == NULL)
        puts("\nlista vazia");
    else
        for (ptaux=lista; ptaux!=NULL; ptaux=ptaux->prox)
            printf("%d  ", ptaux->numero);
}


ptLSE* destroi(ptLSE *lista)
{
    ptLSE *ptaux; //ponteiro auxiliar para percorrer a lista
    while (lista != NULL)
    {
        ptaux = lista;
        lista = lista->prox;
        free(ptaux);
    }
    free(lista);
    return NULL;
}

int main(void)

{
    ptLSE *lista;
    int numero, cont=1;
    lista = cria_lista();
    do
    {
        printf("Digite o numero a ser inserido na lista: ");
        scanf("%d", &numero);
        lista = insere(lista, numero);
        printf("Continua? 1 para sim || Qualquer outra tecla para nao: \n");
        scanf("%d", &cont);
    }
    while (cont==1);

    printf("\nExibindo a lista...\n");
    imprime(lista);

    lista=destroi(lista);
    printf("\n\n");
    imprime(lista);
}
