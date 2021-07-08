/*
10. Crie um programa que contenha um array contendo 5 elementos inteiros.
Leia esse array do teclado e imprima o endereço das posições contendo valores pares.
*/

#include <stdio.h>

int main(void){
	int array[5];
	printf("Digite 5 números inteiros\n\n");
	for (int i = 0; i < 5; i++){
		printf("-> ");
		scanf("%d", &array[i]);
	}
	
	printf("\nOs pares são:\n");

	for (int i = 0; i < 5; i++){
		if(array[i]%2 == 0){
			printf("\n-> %d", array[i]);
		}
	}
	printf("\n\n");
	return 0;
}
