/*
11. Faça um programa que leia três valores inteiros e chame uma função que receba estes 3 valores de entrada 
e retorne eles ordenados, ou seja, o menor valor na primeira variável, o segundo menor valor na variável do meio, 
e o maior valor na última variável. A função deve retornar o valor 1 se os três valores forem 
iguais e 0 se existirem valores diferentes. Exibir os valores ordenados na tela.
*/

#include <stdio.h>
void ordenar(int array[]){
	int hold;
	for (int pass = 0; pass < 3; pass++){
		for (int j = 0; j < 2; j++){
			if (array[j] > array[j + 1]){
				hold = array[j];
				array[j] = array[j + 1];
				array[j + 1] = hold;
			}
		}
	}
}

int main(void){
	int array[3];
	for(int i = 0; i < 3; i++){
		if(i == 0) printf("Digite um número:\n");
		else printf("Digite outro número:\n");
		scanf("%d", &array[i]);
	}
	ordenar(array);
	printf("\nOs números em ordem são:\n");
	for(int i = 0; i < 3; i++){
		printf("-> %d\n", array[i]);
	}
	printf("\n\n");
	return 0;
}
