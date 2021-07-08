/*
14. Implemente uma função que receba como parâmetro um array de números reais de tamanho N e 
retorne quantos numeros negativos há nesse array. Essa função deve obedecer ao prototipo:
   int negativos(float *vet, int N);
*/

#include <stdio.h>

int negativos(float *vet, int N){
	int count = 0;
	for(int i = 0; i < N; i++){
		if(vet[i] < 0){
			count++;
		}
	}
	return count;
}

int main(void){
	int N;
	float array[30];
	float *vet;
	printf("Quantos número deseja digitar? (Máx 30)\n");
	scanf("%d", &N);
	printf("• Digite os %d números:\n", N);
	for(int i = 0; i < N; i++){
		printf("\n-> ");
		scanf("%g", &array[i]);
	}
	vet = array;
	int nNegativos = negativos(vet, N);
	printf("\n\n---> Você digitou %d números negativos\n\n", nNegativos);
	return 0;
}
