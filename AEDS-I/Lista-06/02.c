/*
2. Escreva um programa que contenha duas variáveis inteiras. 
Leia essas variáveis do teclado. Em seguida, compare seus endereços e exiba o conteúdo do maior endereço.
*/

#include <stdio.h>

int main(void){
	int num1, num2;
	printf("Digite um número:\n");
	scanf("%d", &num1);
	printf("Digite outro número:\n");
	scanf("%d", &num2);

	if(&num1 > &num2){
		printf("\n-> O endereço de num1 é maior.\n");
		printf("Endereço de num1: %p\n", &num1);
		printf("E seu conteúdo é: %d\n", num1);
	}else{
		printf("\n-> O endereço de num2 é maior.\n");
		printf("Endereço de num2: %p\n", &num2);
		printf("E seu conteúdo é: %d\n", num2);
	}
	return 0;
}
