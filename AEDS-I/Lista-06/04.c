/*
4. Faça um programa que leia dois valores inteiros e chame uma função que receba estes 2 valores de entrada e 
retorne o maior valor na primeira variável 
e o menor valor na segunda variável. Escreva o conteúdo das 2 variáveis na tela.
*/

#include <stdio.h>

void compara(int n, int m){
	// Como não é possível fazer return de dois valores, entendi que era pra printar na tela.
	if(n > m){
		printf("\n\n––> Anteriormente como Num1[%d] > Num2[%d], então agora Num1 = %d e Num2 = %d\n\n", n, m, n, m);
	}else if(n < m){
		printf("\n\n––> Anteriormente como Num1[%d] > Num2[%d], ", n, m);
		int aux = n;
		n = m;
		m = aux;
		printf("então agora ficará Num1 = %d e Num2 = %d\n\n", n, m);
	}else {
		printf("\n\n––> Os números %d e %d são iguais\n\n", n, m);
	}
}

int main(void){
	int num1, num2;
	printf("Digite um número\n");
	scanf("%d", &num1);
	printf("Digite outro número\n");
	scanf("%d", &num2);
	compara(num1, num2);
	return 0;
}
