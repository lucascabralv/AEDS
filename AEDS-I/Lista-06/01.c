/*
1.	Escreva um programa que declare um inteiro, um real e um char, e ponteiros para inteiro, 
real, e char. Associe as variáveis aos ponteiros (use &). Modifique os valores de cada variável usando os ponteiros. 
Imprima os valores das variáveis antes e após a modificação.
*/

#include <stdio.h>

int main(void){
	int inteiro = 10;
	float real = 3.14;
	char caractere = 'x';
	int *intPtr = &inteiro;
	float *realPtr = &real;
	char *charPtr = &caractere;

	printf("\nInteiro antes: %d\n", inteiro);
	*intPtr = 7;
	printf("Inteiro depois: %d\n", inteiro);

	printf("Real antes: %g\n", real);
	*realPtr = 3.141592;
	printf("Real depois: %g\n", real);

	printf("Char antes: %c\n", caractere);
	*charPtr = 'Z';
	printf("Char depois: %c\n", caractere);

	return 0;
}
