/*
7. Fazer um método recursivo que conte os dígitos de um determinado número.
*/

#include <stdio.h>
#include <math.h>

int digitCount(int n, int pot){
	int digitos = 0;
	if(n/pow(10,pot) >= 1){
		digitos++;
		pot++;
		digitos += digitCount(n, pot);
	}
	return digitos;
}

int main(void){
	int num;
	printf("\nDigite um número:\n");
	scanf("%d", &num);
	printf("\n-> O nº %d possui %d dígitos.\n", num, digitCount(num,0));
	return 0;
}
