#include <stdio.h>
#include "dados.h"
#include <string.h>
#define TAMJOGADORES 3


int procura_nome(DADOS *jogadores,char *texto)
{
    int cont1;
    char nome[20];
    do
    {
        printf("%s",texto);
        fflush(stdin);
        gets(nome);
        for(cont1=0; cont1<TAMJOGADORES; cont1++)
            if(!(strcmp(nome,jogadores[cont1].nome)))
                return cont1;
    }
    while(1);
}

void atribui_dados(DADOS *jogadores)
{
    int cont1;

    for(cont1=0; cont1<TAMJOGADORES; cont1++)
    {
        printf("\nNome: ");
        fflush(stdin);
        gets(jogadores[cont1].nome);
        printf("Participacao em jogos: ");
        scanf("%d", &jogadores[cont1].num_jogos);
        printf("Gols: ");
        scanf("%d", &jogadores[cont1].gols);
        printf("Assistencias: ");
        scanf("%d", &jogadores[cont1].assis);
    }
}

void exibe_estatisticas(DADOS *jogadores)
{
    int cont1;

    for(cont1=0; cont1<TAMJOGADORES; cont1++)
    {
        printf("\n\nNome: %s", jogadores[cont1].nome);
        printf(" || Jogos: %d", jogadores[cont1].num_jogos);
        printf(" || Gols: %d || Assistencias: %d", jogadores[cont1].gols,jogadores[cont1].assis);
    }
    printf("\n\n");
}

void soma(DADOS *jogadores)
{
    DADOS jogador1,jogador2;
    char texto[]="Digite o nome do jogador que vc deseja somar suas estatisticas com outro: ";

    jogador1=jogadores[procura_nome(jogadores,texto)];
    jogador2=jogadores[procura_nome(jogadores,texto)];

    printf("\n\nEstatisticas somadas dos jogadores %s e %s", jogador1.nome,jogador2.nome);
    printf("\nJogos: %d", (jogador1.num_jogos+jogador2.num_jogos));
    printf("  || Gols: %d", (jogador1.gols+jogador2.gols));
    printf("  || Assistencias: %d", (jogador1.assis+jogador2.assis));
    printf("\n\n");
}

void eh_bom(DADOS *jogadores)
{
    DADOS jogador;
    char texto[]="Digite o nome do jogador que voce deseja saber se eh bom: ";
    jogador=jogadores[procura_nome(jogadores,texto)];

    if((jogador.gols/jogador.num_jogos)>=2 || (jogador.assis/jogador.num_jogos)>=3)
        printf("\nO jogador %s eh craque! :) \n", jogador.nome);
    else
        printf("\nO jogador %s n eh craque :( \n", jogador.nome);
}
