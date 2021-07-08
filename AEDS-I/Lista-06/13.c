/*
13. Crie uma função que receba como parâmetro
um array e o imprima. Não utilize índices para percorrer o array, apenas aritmética de ponteiros.
*/

#include <stdio.h>
#include <string.h>

void imprimir(char array[]){
	char *ptrFrase = array;
	printf("\n\n-> ");
	for(int i = 0; i < strlen(array); i++){
		printf("%c", ptrFrase[i]);
	}
	printf("\n\n");
}
int main(void){
	char frase[100];
	printf("\n• Digite uma frase:\n");
	scanf("%[^\n]s", frase);
	imprimir(frase);
	return 0;
}
