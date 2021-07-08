/*
15. Escreva uma função que receba um array de inteiros V e os endereços de duas variáveis inteiras, min e max, 
e armazene nessas variáveis o valor mínimo e máximo do array. Escreva também uma função main que use essa função.
*/

#include <stdio.h>

void ordenar(int array[], int v){
	int hold;
	for (int pass = 0; pass < v; pass++){
		for (int j = 0; j < v-1; j++){
			if (array[j] > array[j + 1]){
				hold = array[j];
				array[j] = array[j + 1];
				array[j + 1] = hold;
			}
		}
	}
}

void executar(int array[], int *min, int *max, int v){
	ordenar(array, v);
	*min = array[0];
	*max = array[v-1];
	printf("\n-> O valor mínimo do Array é: %d", *min);
	printf("\n-> O valor máximo do Array é: %d", *max);
}

int main(void){
	int array[30];
	int min, max, arraySize;
	printf("Quantos números irá digitar? (Máx.: 30)\n");
	scanf("%d", &arraySize);
	printf("Digite os %d números:\n", arraySize);

	for(int i = 0; i < arraySize; i++){
		printf("\n->");
		scanf("%d", &array[i]);
	}
	printf("\n");
	executar(array, &min, &max, arraySize);
	printf("\n\n");
	return 0;
}
