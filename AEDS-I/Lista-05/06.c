/*
6. Fazer um método recursivo que calcule o MDC (máximo divisor comum) de dois inteiros positivos m e n
*/

#include <stdio.h>

int mdc(int n1, int n2){
	if (n2 == 0){
		return n1;
	}
	else{
		return mdc(n2, n1 % n2);
	}
}

int main(void){
	int num1, num2;
	printf("\nDigite um número:\n");
	scanf("%d", &num1);
	printf("Digite outro número:\n");
	scanf("%d", &num2);
	printf("\n-> M.D.C de %d e %d é: %d\n\n", num1, num2, mdc(num1,num2));
	return 0;
}
