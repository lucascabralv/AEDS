/*
1. Fazer um método recursivo que recebe um número inteiro e retorna o seu fatorial.
*/

#include <stdio.h>

int fatorial(int n){
	int resp;
	if (n == 1){
		resp = 1;
	}
	else{
		resp = n * fatorial(n - 1);
	}
	return resp;
}

int main(void){
	int num;
	printf("Digite um número\n");
	scanf("%d", &num);
	printf("\n-> Fatorial de %d é: %d\n", num, fatorial(num));
	return 0;
}
