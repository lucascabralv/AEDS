/*
3. Faça um programa que leia 2 valores inteiros e chame uma função que receba estas 2 variáveis e 
troque o seu conteúdo, ou seja, esta função é chamada passando duas variáveis A e B por exemplo e, 
após a execução da função, A conterá o valor de B e B terá o valor de A.
*/

#include <stdio.h>

void trocaVal(int n, int m){
	int *ptr1 = &n;
	int *ptr2 = &m;
	int aux;

	aux = *ptr2;
	*ptr2 = *ptr1;
	*ptr1 = aux;

	printf("\n-> Num1 dentro da função trocaVal()= %d\n", *ptr1);
	printf("\n-> Num2 dentro da função trocaVal()= %d\n", *ptr2);
}
void trocaValPtr(int *x, int *y){
	int aux;
	aux = *x;
	*x = *y;
	*y = aux;
}

int main(void){
	int num1, num2;
	printf("Digite um número\n");
	scanf("%d", &num1);
	printf("Digite outro número\n");
	scanf("%d", &num2);
	//Não entendi se o enunciado pediu pra trocar os valores de num1 e num2,
	//ou se era pra trocar os valores das variaveis correspondentes dentro da função, fiz dos dois jeitos;

	trocaVal(num1 ,num2);

	trocaValPtr(&num1, &num2);

	printf("\n\n-> Num 1 fora das funções após executar trocaValPtr() = %d\n", num1);
	printf("\n-> Num 2 fora das funções após executar trocaValPtr() = %d\n\n", num2);

	return 0;
}
