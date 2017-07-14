lista* inicia_floresta(lista *floresta)
{
	char index;
	lista *ptaux=floresta;
	lista *ptant=NULL;
	for(index='a';index<='z';index++)
	{
		ptaux=(lista*) malloc(sizeof(lista));
		ptaux->letra_index=index;
		//ptaux->letra_avore=(pNodoA*) malloc(sizeof(pNodoA));
		ptaux->letra_arvore=NULL;
		ptaux->ant=ptant;
		ptaux->prox=NULL;
		ptant=ptaux;
		ptaux=ptaux->prox;
	}
	return ptant;
}
	