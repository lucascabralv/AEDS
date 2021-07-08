/*
5. Fazer um método recursivo que multiplique dois números naturais, através de somas sucessivas
*/

#include <stdio.h>

int mult(int n,int m){
	int soma = 0;
	if(m == 1){
		soma += n;
	} else {
		soma += n + mult(n,--m);
	}
	return soma;
}


int main(void){
	int num1, num2;
	printf("Digite um número:\n");
	scanf("%d", &num1);
	printf("Digite outro número:\n");
	scanf("%d", &num2);
	printf("-> %d x %d = %d\n\n",num1,num2,mult(num1,num2));
	return 0;
}
