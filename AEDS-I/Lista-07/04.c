/*
4. Escreva um programa em C que solicite ao usuário a digitação do nome de um arquivo texto já existente,
 e que então gere um outro arquivo, que será uma cópia do primeiro.
*/

#include <stdio.h>
#include <string.h>

int main(void){
	char nomeArquivo[30];
	char arquivoNovo[40] = "";
	

	printf("Digite o nome do arquivo que deseja copiar:\n-> ");
	scanf("%[^\n]s", nomeArquivo);

	FILE *fp = fopen(nomeArquivo, "r");
	if(fp == NULL){
		printf("Erro ao abrir arquivo\n");
		return -1;
	} else {
		strcpy(arquivoNovo, nomeArquivo);
		char nomeCopia[5] = "copy";
		strcat(arquivoNovo, nomeCopia);

		FILE *fpCopy = fopen(arquivoNovo, "w");
		while (!feof(fp)){
			char texto[100];
			fgets(texto, 100, fp);
			fputs(texto, fpCopy);
		}
		fclose(fpCopy);
		printf("\nArquivo cópia criado com sucesso\n");
	}
	fclose(fp);
	return 0;
}
