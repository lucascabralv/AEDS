/*
3. Escreva um programa em C que abra um arquivo texto e que conte a quantidade de caracteres armazenados nele.
Imprima o número na tela. O programa deve solicitar ao usuário que digite o nome do arquivo.
*/

#include <stdio.h>
#include <string.h>

int main(void){
	int nLetras = 0;
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
			nLetras += strlen(linhasTxt);
		}
	}
	fclose(fp);
	printf("O arquivo possui %d caracteres.\n", nLetras);
	return 0;
}
