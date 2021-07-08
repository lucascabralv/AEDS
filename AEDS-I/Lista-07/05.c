/*
Considere um arquivo texto que armazene números em ponto flutuante em cada uma de suas linhas. 
Escreva um programa em C que determine o valor máximo, 
o valor mínimo e a média desses valores armazenados no arquivo. Imprima esses valores na tela.
*/

#include <stdio.h>

void ordenarArray(float array[], int arraySize){
	float hold;
	for (int pass = 1; pass < arraySize; pass++){
		for (int j = 0; j < arraySize - 1; j++){
			if (array[j] > array[j + 1]){
				hold = array[j];
				array[j] = array[j + 1];
				array[j + 1] = hold;
			}
		}
	}
}

int main(void){
	float array[100];
	char arquivo[30];
	int i = 0;
	float media = 0;
	float menor;

	printf("Digite o nome do arquivo:\n-> ");
	scanf("%[^\n]s", arquivo);

	FILE *fp = fopen(arquivo, "r");

	if(fp == NULL){
		printf("Erro ao abrir arquivo\n");
	} else {
		while(!feof(fp)){
			fscanf(fp, "%g", &array[i]);
			i++;
		}
		fclose(fp);
		for(int j = 0; j < i; j++){
			media += array[j];
		}
		media = media/i;

		ordenarArray(array, i);
		printf("A média é %g e o menor valor é: %g\n", media, array[0]);
	}
	return 0;
}
