struct TipoInfoNo{
       int codigo;
       char nome[20];
       float preco;
       };
typedef struct TipoInfoNo InfoNo;

struct TipoPtNo{
       InfoNo info;
       struct TipoPtNo* ant;
       struct TipoPtNo* prox;
       };
typedef struct TipoPtNo PtNo;



PtNo* inicializa(void);
void imprime(PtNo* PtLista);
void imprimeInvertida(PtNo *PtLista);
PtNo* insereInicio(PtNo *PtLista, InfoNo Dado);
void insereInicio2(PtNo **PtLista, InfoNo Dado);
PtNo* insereFinal(PtNo *PtLista, InfoNo Dado);
PtNo* destroi(PtNo* ptLista);



