/*
2. Fazer um método recursivo que recebe um número inteiro n e retorna o n-ésimo termo da equação
de recorrência abaixo:
T(1) = 2
T(2) = 3
T(n) = 5∗n+T(n−1)ˆn
*/

#include <stdio.h>
#include <math.h>

int equacao(int n){
	int numT;
	if(n == 1){
		numT = 2;
	} else if(n == 2){
		numT = 3;
	} else {
		numT = 5*n + pow(equacao(n-1), n);
	}
	return numT;
}

int main(void){
	int num;
	printf("Digite um número:\n");
	scanf("%d", &num);
	printf("-> O valor da equação é : %d\n\n", equacao(num));
	return 0;
}
