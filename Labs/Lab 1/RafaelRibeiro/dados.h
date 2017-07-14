/* Estrutura jogador com os campos nome(string),numero de jogos em que participou (int),
numero de gols(int) e numero de assist�ncias(int) */

 typedef struct jogador{
    char nome[20];
    int num_jogos,gols,assis;
} DADOS;

/*Fun��o utilizada para atribuir os dados */
void atribui_dados(DADOS *jogadores);

/*Fun��o utilizada para exibir os dados jogadores inseridos */
void exibe_estatisticas(DADOS *jogadores);

/*Fun��o utilizada para somar as estatitisticas de dois jogadors */
void soma(DADOS *jogadores);

/*Fun��o utilizada para saber se o jogador eh craque.*/
/*PARA SER CRAQUE TEM QUE TER UMA MEDIA DE GOLS MAIOR OU IGUAL A 2 OU UMA MEDIA DE ASSITENCIAS MAIOR OU IGUAL A 1*/
void eh_bom(DADOS *jogadores);

/*Fun��o extra utilizada para procurar os dados de um jogador determinado */
int procura_nome(DADOS *jogadores, char *texto);
