/*
4. Fazer um método recursivo que imprima de um número natural em base binária
*/

#include <stdio.h>
#include <math.h>

int binario(int n, int pot){
	int soma = 0;
	if(n/2==1){
		soma += (n % 2) * pow(10, pot);
		soma += 1 * pow(10, ++pot);
	} else{
		soma += (n % 2) * pow(10, pot);
		pot++;
		soma += binario((n / 2), pot);
	}
	return soma;
}

int main(void){
	int num;
	printf("Digite um número:\n");
	scanf("%d", &num);
	printf("-> %d\n\n",binario(num, 0));
	return 0;
}
