/*
8. Fazer um método recursivo que determine se um número é ou não primo.
*/

#include <stdio.h>

int primo(int n, int div){
	int teste = 0;
	if(n >= div){
		if (n % div == 0){
			teste++;
		}
		div++;
		teste += primo(n,div);
	}
	return teste;
}

int main(void){
	int num;
	printf("\nDigite um número:\n");
	scanf("%d", &num);
	
	if(primo(num, 1) == 2){
		printf("\n-> O número %d é primo\n\n", num);
	}else{
		printf("\n-> O número %d não é primo\n\n", num);
	}
	return 0;
}
