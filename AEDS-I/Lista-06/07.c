/*
7. Faça um programa que modifique as vogais de uma frase. O programa deve ler uma frase (max. 100 caracteres) e 
armazeá-la num vetor. Imprimir a frase lida trocando as vogais, isto é, trocar ’a’ pelo ’i’, ’e’ pelo ’o’, ’i’ pelo ’u’, ’o’ 
pelo ’a’ e o ’u’ pelo ’e’. Usar uma função void (procedimento) para realizar a troca e uma função para realizar 
a impressão da frase trocada. A função deve ter como parâmetro um ponteiro char referente ao vetor
*/

#include <stdio.h>
#include <string.h>

void printar(char frase[]){
		printf("\n-> %s", frase);
}
void trocar(char frase[], char *ptr){
	for(int i = 0; i < strlen(frase); i++){
		if (frase[i] == 'a' || frase[i] == 'A'){
			ptr[i] = 'i';
		}
		else if (frase[i] == 'e' || frase[i] == 'E'){
			ptr[i] = 'o';
		}
		else if (frase[i] == 'i' || frase[i] == 'I'){
			ptr[i] = 'u';
		}
		else if (frase[i] == 'o' || frase[i] == 'O'){
			ptr[i] = 'a';
		}
		else if (frase[i] == 'u' || frase[i] == 'U'){
			ptr[i] = 'e';
		}
	}
}

int main(void){
	char frase[100];
	printf("\nEscreva uma frase:\n-> ");
	fgets(frase, sizeof(frase), stdin);
	trocar(frase, &frase[0]);
	printar(frase);
	return 0;
}
