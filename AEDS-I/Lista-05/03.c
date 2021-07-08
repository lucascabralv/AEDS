/*
3. Fazer um método recursivo que recebe um número inteiro e positivo n e calcula o somatório abaixo.
n + (n−1) +...+ 1 + 0
*/

#include <stdio.h>

int somatorio(int n){
	int soma = 0;
	if(n == 0){
		soma += 0;
	}
	else {
		soma = n + somatorio(n-1);
	}
	return soma;
}

int main(void){
	int num;
	printf("Digite um número:\n");
	scanf("%d", &num);
	printf("-> A soma de ");
	for(int i = num; i >=0; i--){
		if(i==0){
			printf("0 = %d\n\n", somatorio(num));
		}else {
			printf("%d + ", i);
		}
	}
	return 0;
}
