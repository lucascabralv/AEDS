/*
8. Crie um programa que contenha um array de float contendo 10 elementos. 
Imprima o endereço de cada posição desse array.
*/

#include <stdio.h>

int main(void){
	float array[10];

	printf("\nDigite 10 números reais:\n");
	for(int i = 0; i < 10; i++){
		printf("\n-> ");
		scanf("%f", &array[i]);
	}
	printf("\n");
	for(int i = 0; i < 10; i++){
		printf("• Endereço da posição i: %p\n", &array[i]);
	}
	return 0;
}
