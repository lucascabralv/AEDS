/*
6. Crie um programa que contenha uma função que permita passar por parâmetro dois numeros inteiros A e B. 
A função deverá calcular a soma entre estes dois números e armazenar o resultado na variável A. Esta função não deverá possuir retorno,
mas deverá modificar o valor do primeiro parâmetro. Imprima os valores de A e B na função principal.
*/

#include <stdio.h>
void soma(int a, int b, int *aPtr){
	int soma = a + b;
	*aPtr = soma;
}

int main(void){
	int num1, num2;
	printf("Digite um número\n");
	scanf("%d", &num1);
	printf("Digite outro número\n");
	scanf("%d", &num2);
	soma(num1, num2, &num1);
	printf("\n\n-> O valor de num1(n1+n2) = %d\n->O valor de num2 = %d\n\n", num1, num2);
	return 0;
}
