/*
1. Suponha que temos dois arquivos cujo as linhas são ordenadas lexigraficamente. 
Por exemplo,estes arquivos podem conter nomes de pessoas, linha a linha, em ordem alfabética. 
Escreva umprograma que receba, por linha de comando, os nomes destes dois arquivos e de um terceiro. 
Crie este terceiro arquivo contendo todas as linhas destes dois arquivos ordenadas lexicograficamente.
*/

#include <stdio.h>
#include <string.h>

int main(void){
	char nomeArquivo1[20], nomeArquivo2[20];
	char linha1[100], linha2[100];
	printf("Entre o nome do arquivo 1\n");
	scanf("%[^\n]s", nomeArquivo1);
	printf("Entre o nome do arquivo 2\n");
	scanf(" %[^\n]s", nomeArquivo2);
	FILE *fp1 = fopen(nomeArquivo1, "r");
	FILE *fp2 = fopen(nomeArquivo2, "r");

	if(fp1 == NULL || fp2 == NULL){
		printf("Erro ao abrir arquivos\n");
		return -1;
	}
	FILE *out = fopen("arquivoOut", "w");

	fgets(linha1, 100, fp1);
	fgets(linha2, 100, fp2);

	while (!feof(fp1) && !feof(fp2)){
		if(strcmp(linha1, linha2) < 0){
			fputs(linha1, out);
			fgets(linha1, 100, fp1);
		} else {
			fputs(linha2, out);
			fgets(linha2, 100, fp2);
		}
	}

	if(feof(fp1)){
		while(!feof(fp2)){
			fputs(linha2, out);
			fgets(linha2, 100, fp2);
		}
	}

	if(feof(fp2)){
		while(!feof(fp1)){
			fputs(linha1, out);
			fgets(linha1, 100, fp1);
		}
	}
	fclose(fp1);
	fclose(fp2);
	fclose(out);
	return 0;
}
