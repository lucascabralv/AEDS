/*
Abre arquivo e substitui palavra
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char * replaceText(char linha[], char palavraAntiga[], char palavraNova[]){
	char *newLinha = (char*) malloc(100*sizeof(char));
	char *aux = strtok(linha, " ,.:?!\n\t\r");
	while(aux != NULL){
		if(strcmp(aux, palavraAntiga) == 0){
			strcat(newLinha, palavraNova);
		} else {
			strcat(newLinha, aux);
		}
		strcat(newLinha, " ");
		aux = strtok(NULL, " ,.:?!\n\t\r");
	}
	strcat(newLinha,"\n"); 
	return newLinha;
}

int main(void){
	char nomeArquivo[30], palavraNova[30], palavraAntiga[30], buffer[100];
	printf("Entre com o nome do arquivo\n-> ");
	scanf("%s", nomeArquivo);

	FILE *fp = fopen(nomeArquivo, "r");

	if(fp == NULL){
		printf("Erro ao abrir o arquivo\n\n");
		return -1;
	}

	printf("Entre com a palavra que deseja substituir\n-> ");
	scanf("%s", palavraAntiga);
	printf("Entre com a palavra irá substituir a anterior\n-> ");
	scanf(" %s", palavraNova);

	char *temp;
	while(!feof(fp)){
		fgets(buffer, 100, fp);
		temp = replaceText(buffer, palavraAntiga, palavraNova);
		memset(buffer, 0, 100);
		printf("%s", temp);
	}

	fclose(fp);
	printf("\nPrograma terminado\n");
}