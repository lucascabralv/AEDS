/*
Print de arquivo recursivo
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void printFileRecursivo(FILE *fp){
	char linha[100];
	if (fgets(linha, 100, fp) != NULL){
		printf("%s", linha);
		printFileRecursivo(fp);
	}
}

void abreFile(char nomeArquivo[]){
	FILE *fp = fopen(nomeArquivo, "r");
	if(fp == NULL){
		printf("\nErro ao abrir arquivo\n");
	} else {
		printFileRecursivo(fp);
		fclose(fp);
	}
}

int main(void){
	char nomeArquivo[30];
	printf("Entre com o nome do arquivo\n-> ");
	scanf("%s", nomeArquivo);
	system("clear || cls");
	abreFile(nomeArquivo);
	printf("\nPrograma terminado\n");
}