/*
2. Escreva um programa em C para contar a quantidade de palavras de um arquivo texto.
*/

#include <stdio.h>
#include <string.h>

int main(void){
	int nPalavras = 0;
	char linhasTxt[100];
	char arquivo[25];

	printf("Digite o nome do arquivo:\n");
	scanf(" %[^\n]s", arquivo);

	FILE *fp = fopen(arquivo, "r");

	if (fp == NULL){
		printf("Erro ao abrir arquivo\n");
		return -1;
	}
	else{
		while (!feof(fp)){
			fgets(linhasTxt, 100, fp);
			nPalavras++;
		}
	}

fclose(fp);
printf("O arquivo possui %d palavras\n", nPalavras);
return 0;
}
