#include <stdio.h>
#include <stdlib.h>

typedef struct rua TipoPilha;

struct rua{
       char nome[51];
       TipoPilha *elo;
};


TipoPilha* InicializaPilha (TipoPilha *Topo);
int Vazia (TipoPilha *Topo);
void ImprimirPilha (TipoPilha *Topo);
TipoPilha* PushPilha (TipoPilha *Topo, char *rua);
TipoPilha* PopPilha (TipoPilha **Topo, char *rua);
char* ConsultaPilha (TipoPilha *Topo);
TipoPilha* DestroiPilha (TipoPilha *Topo);
int Compara_pilhas(TipoPilha* E1, TipoPilha* E2);

