pNodoA* procura_na_floresta(lista *inicio_floresta, lista *fim_floresta, char letra_inicial)
{
	lista *inicio=inicio_floresta;
	lista *fim=fim_floresta;
	
	
	if(letra_inicial<='n')
		while(1)
		{
			if(inicio->letra_index==letra_inicial)
				return inicio->letra_arvore;
			else
				inicio=inicio->prox;
		}
	else
		while(1) 
		{
			if(fim->letra_index==letra_inicial)
				return fim->letra_arvore;
			else
				fim=fim->ant;
		}
}