#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>
#include "interface.h"

main(int argc, char *argv[])
{
    FILE *arquivoDicionario, *arquivoConsulta,*arquivoSaida;
    lista *iniciofloresta=NULL,*fimfloresta;
    pNodoA *arvorePrevisoes, *arvoreNumeros=NULL;
    char peso[15],palavra[15],palavraLimite[15];
    int tamanhoPalavra,cont,flag;

    iniciofloresta=inicia_floresta(iniciofloresta);
    fimfloresta=pega_fim(iniciofloresta);

    clock_t start, end, elapsed; //para contar o tempo

//    if(argc!=4)//Teste do contador de paramentros
//    {
//        printf("\nNumero errado de argumentos para a execução do programa\n");
//        return 0;
//    }

    /*Abertura dos arquivos necessários para a execução do progra */
    arquivoDicionario=fopen("wikia.txt","r");
    arquivoConsulta=fopen("consulta.txt","r");
    arquivoSaida=fopen("saida.txt","w");

    if (arquivoDicionario==NULL || arquivoConsulta==NULL)//Teste de abertura de arquivos
    {
        printf("\nErro ao abrir os arquivos");
        return 0;
    }

    start=clock(); //inicia a contagem do tempo pra cronometrar formação da estrutura do dicionario;

    while(!feof(arquivoDicionario))//Lerá o arquivo a cada linha até o fim
    {
        fscanf(arquivoDicionario,"%s  %s",peso,palavra);//Extrai o peso e a palavra da linha atual//

        tamanhoPalavra=strlen(palavra);
        for(cont=0; cont<tamanhoPalavra; cont++)//Converte a palavra inteiramente para minusculo
            palavra[cont]=tolower(palavra[cont]);

        //Indentifica se a inicial da palavra é um caractere não-letra.
        //Se for uma não-letra, então
            //ela será inserida junto com o seu peso numa arvore exclusiva pra palavra que começam com não-letras;
        //Se não, insere a palavra/peso na floresta de arvores de palavras que iniciam com letras;
        if((palavra[0]<'A' || (palavra[0]>'Z' && palavra[0] < 'a') || (palavra[0]>'z')))
            {
                flag=1;
                arvoreNumeros=insere_na_arvore(arvoreNumeros,palavra,atoi(peso),&flag);
            }
        else
            insere_na_floresta(iniciofloresta,fimfloresta,palavra,atoi(peso));
    }
    end=clock();//Termina a contagem do tempo
    elapsed = 1000 * (end - start) / (CLOCKS_PER_SEC); //calcula o tempo decorrido em milissegundos
    fprintf(arquivoSaida,"\nO tempo gasto no processamento do arquivo %s foi de %ld ms","wiki.txt",elapsed);

//    printf("\n\nNumeros:\n");
//    if(arvoreNumeros==NULL)
//        printf("Vazio");
//    else
//        printaArvore(arvoreNumeros);
//
//    system("pause");
//
//    printaFloresta(iniciofloresta);

    fclose(arquivoDicionario);//Fechamento do arquivo dicionario

    start=clock();//inicia a contagem do tempo pra cronometrar consultas;
    while(!(feof(arquivoConsulta)))
    {
        fscanf(arquivoConsulta,"%s", palavra);//Pega a palavra da linha atual do arquivo
        tamanhoPalavra=strlen(palavra);// Calcula o tamanho dela
        for(cont=0; cont<tamanhoPalavra; cont++)//Torna todos as letras da palavra minusculas
            palavra[0]=tolower(palavra[0]);

        strcpy(palavraLimite,palavra);//Copia a palavra para uma segunda variavel chamada de palavraLimite
        palavraLimite[tamanhoPalavra-1]++;//O ultimo caractere da palavraLimite é incrementando em 1

        free(arvorePrevisoes);//Desaloca memória alocada anteriormente para a arvore de previsões
        arvorePrevisoes=NULL;

        //Indentifica se a inicial da palavra é um caractere não-letra.
        //Se for uma não-letra, então
            //suas previsões serão pesquisada na arvore exclusiva de palavras que começam com caracteres não-letras
            //A busca terá percorrimento sempre pela esquerda
        //Se não, insere a palavra na floresta de arvores de palavras que iniciam com letras;
        if((palavra[0]<'A' || (palavra[0]>'Z' && palavra[0] < 'a') || (palavra[0]>'z')))
        {
            flag=1;
            arvorePrevisoes=busca_previsoesESQUERDA(arvoreNumeros,palavra,palavraLimite,arvorePrevisoes,&flag);
        }

        else
            arvorePrevisoes=pega_previsoes(iniciofloresta,fimfloresta,palavra,palavraLimite);

        //Terminado a busca, começa a escrita das previsões no arquivo de saida
        //Se a arvore de previsões estiver fazia, é escrito que não há previsões para a palavra
        //Do contrário vai para a função escreve_previsoes
        fprintf(arquivoSaida,"\n\n%s:",palavra);
        if(arvorePrevisoes==NULL)
            fprintf(arquivoSaida,"\n     Nenhum resultado encontrado");
        else
        {
            cont=0;
            escreve_previsoes(arquivoSaida,arvorePrevisoes,&cont,800);
        }
    }

    end=clock();//Termina a contagem do tempo
    elapsed = 1000 * (end - start) / (CLOCKS_PER_SEC); //calcula o tempo decorrido em milissegundos
    fprintf(arquivoSaida,"\n\nO tempo gasto no processamento dos arquivos %s e %s foi de %ld ms\n","consulta.txt","saida.txt",elapsed);

    //Fechamento dos arquivos restantes
    fclose(arquivoConsulta);
    fclose(arquivoSaida);

    //Mensagem final indicando que o programa terminou sua execução com sucesso
    printf("\nDados processados com suceso. Consulte o resultado em %s\n","saida.txt");
}
