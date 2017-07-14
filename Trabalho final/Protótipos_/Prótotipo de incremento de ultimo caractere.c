#include <stdio.h>
#include <string.h>
 
 
main()
{
	char palavra1[10],palavra2[10];
 
	printf("Digite uma palavra: ");
	gets(palavra1);
 
	strcpy(palavra2,palavra1);
 
	palavra2[-2]++;
 
	printf("\n");
	puts(palavra2);
}