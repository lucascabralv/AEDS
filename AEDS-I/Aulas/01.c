/*
Teste se palavra escrita por usuario está no arquivo
*/

#include <stdio.h>
#include <string.h>

int main(void){
	int nLinhas = 0;
	char padrao[20];
	char linha[50];
	int nPalavras= 0;
	int nCaracteres = 0;

	printf("Entre com uma palavra a ser pesquisada:\n");
	scanf("%[^\n]s", padrao);

	FILE *fp = fopen("texto.txt", "r");

	if(fp == NULL){
		printf("Erro ao abrir arquivo\n");
		return -1;
	} else {
		while(!feof(fp)){
			fgets(linha, 50, fp);
			char *aux = strtok(linha, " ,.;:!?\n\r\t");
			while(aux != NULL){
				
				nPalavras++;
				if (strstr(aux, padrao) != NULL){
					printf("-> Padrão encontrado na linha (%d), palavra (%s)\n", nLinhas, aux);
				}
				if (strcasecmp(aux, padrao) == 0){
					printf("-> Palavra encontrada na linha (%d), palavra (%s)\n\n", nLinhas, aux);
				}
				aux = strtok(NULL, " ,.:;!?\n\r\t");
			}
			nLinhas++;
		}
		printf("\nO texto possui %d palavras e %d caracteres\n", nPalavras, nCaracteres);
	}

	fclose(fp);
	return 0;
}
