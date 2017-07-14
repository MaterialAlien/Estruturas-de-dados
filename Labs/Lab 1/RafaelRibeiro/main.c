#include <stdio.h>
#include "dados.h"
#define TAMJOGADORES 3

int main()
{
    DADOS jogadores[TAMJOGADORES];

    atribui_dados(jogadores);
    exibe_estatisticas(jogadores);
    soma(jogadores);
    eh_bom(jogadores);

    return 0;
}
