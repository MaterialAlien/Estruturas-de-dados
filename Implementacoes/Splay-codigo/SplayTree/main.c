#include <stdio.h>
#include <stdlib.h>
#include "Splay.h"

int main(int argc, char *argv[])
{
  
  PtNodo* arv = NULL;
  arv = Insere(arv,30);
  /*arv = Insere(10,arv);
  arv = Insere(20,arv);*/
  Desenha(arv,0);
  /*arv =  Consulta(arv, 40);
  Desenha(arv,0);
  arv =  Consulta(arv, 10);
  Desenha(arv,0);
  arv = Remove(arv, 40);
  Desenha(arv,0);
  arv = Remove(arv, 20);
  Desenha(arv,0);
  Destroi(arv);
  */system("PAUSE");	
  return 0;
}
