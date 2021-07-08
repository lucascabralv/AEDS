/*
12. Elabore uma função que receba duas strings como parâmetros e verifique 
se a segunda string ocorre dentro da primeira. Use aritmética de ponteiros para acessar os caracteres das strings.
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool compara(char frase[], char palavra[]){
	char *ptrF = frase;
	char *ptrP = palavra;
	bool resp;
	for (int i = 0; i < (strlen(frase) - strlen(palavra)); i++){
			resp = true;
			for (int j = 0; j < strlen(palavra); j++){
				if(ptrF[i+j] != ptrP[j]){
					resp = false;
					j= strlen(palavra);
				}
			}
			if(resp == true){
				i = strlen(frase);
			}
	}
	return resp;
}

int main(void){
	char frase[35] = "O rato roeu a roupa do rei de roma";
	char palavra[10];
	printf("\nDigite uma palavra para testar se ela está dentro da frase:\n\"O rato roeu a roupa do rei de roma\"\n-> Palavra:");
	scanf("%[^\n]s", palavra);
	if(compara(frase, palavra) == true)
		printf("\n-> %s está na frase\n", palavra);
	else
		printf("\n-> %s NÃO está na frase\n", palavra);
	return 0;
}
