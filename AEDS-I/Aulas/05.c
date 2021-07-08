/*
Print de arquivo recursivo de trás pra frente
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void printFileRecursivo(FILE *fp){
	char linha[100];
	if (fgets(linha, 100, fp) != NULL){
		// Chama a próxima antes de printar
		printFileRecursivo(fp);
		printf("%s", linha);
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