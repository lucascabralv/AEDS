/*
5. Elaborar um programa que leia dois valores inteiros (A e B). Em seguida faça uma função que retorne 
a soma do dobro dos dois numeros lidos. 
A função deverá armazenar o dobro de A na propria variável A e o dobro de B na própria variável B.
*/

#include <stdio.h>

int sumDouble(int a, int b, int *aPtr, int *bPtr){
	*aPtr = 2*a;
	*bPtr = 2*b;
	int dobroSoma = *aPtr + *bPtr;

	return dobroSoma;
}

int main(void){
	int A, B;
	printf("Digite um número\n");
	scanf("%d", &A);
	printf("Digite outro número\n");
	scanf("%d", &B);
	int resultado = sumDouble(A, B, &A, &B);
	printf("\n\n->A soma do dobro dos números é %d\n\n", resultado);
	return 0;
}
