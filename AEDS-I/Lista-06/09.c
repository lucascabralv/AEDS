/*
9. Crie um programa que contenha um array de inteiros contendo 5 elementos. 
Utilizando apenas aritmetica de ponteiros, leia esse array do teclado e imprima o dobro de cada valor lido.
*/

#include <stdio.h>

int main(void){
	int array[5];
	int *ptr;
	ptr = array;
	printf("Digite 5 números inteiros\n\n");
	for(int i = 0; i < 5; i++){
		printf("-> ");
		scanf("%d", &ptr[i]);
	}
	for (int i = 0; i < 5; i++){
		printf("\n-> %d x 2 = %d", ptr[i], ptr[i]*2);
	}
	printf("\n\n");
	return 0;
}
