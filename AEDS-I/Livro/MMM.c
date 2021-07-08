/*
Calcula Média, Moda e Mediana
*/

#include <stdio.h>
#include <math.h>
#define arraySize 20
#define fMax 100

void printArray(int array[]);
void ordenarArray(int array[]);
void media(int array[]);
void moda(int array[], int freq[]);
void mediana(int array[]);

int main(void){
	printf("–––– Cáculo de Média, Mediana e Moda ––––\n");

	int array[arraySize];
	printf("––> Digite o valor de 20 números:\n");
	for(int i = 0; i < arraySize; i++){
		printf("-> ");
		scanf("%d", &array[i]);
	}

	//int array[arraySize] = {1,12,34,65,44,23,34,1,56,35,23,11,78,76,36,22,76,13,64,23};
	int frequencia[fMax];

	printf("\n\n *** ARRAY DESORDENADO ***\n");
	printArray(array);
	printf("\n\n *** ARRAY ORDENADO ***\n");
	ordenarArray(array);
	printArray(array);

	media(array);
	moda(array, frequencia);
	mediana(array);

	return 0;
}

/* –––––––––– PRINTAR ARRAY –––––––––– */

void printArray(int array[]){
	for(int i = 0; i < arraySize; i++){
		if(i % 5 == 0){
			printf("\n");
		}
		printf("%d\t", array[i]);
	}
	printf("\n\n");
}

/* –––––––––– ORDENAR ARRAY –––––––––– */

void ordenarArray(int array[]){
	int hold;
	for(int pass = 1; pass < arraySize; pass++){
		for(int j = 0; j < arraySize - 1; j++){
			if(array[j] > array[j + 1]){
				hold = array[j];
				array[j] = array[j + 1];
				array[j + 1] = hold;
			}
		}
	}
}

/* –––––––––– MÉDIA –––––––––– */

void media(int array[]){
	int soma = 0;
	int media;
	for (int j = 0; j < arraySize; j++){
		soma += array[j];
	}
	media = soma / arraySize;
	printf("\n\n--> A Média é: %d\n\n", media);
}

/* –––––––––– MODA –––––––––– */

void moda(int array[], int freq[]){
	int moda = 0;
	int countModa = 0;
	// Inicializa frequencia[]
	for(int i = 0; i < fMax; i++){
		freq[i] = 0;
	}
	for(int j = 0; j < arraySize; j++){
		++freq[array[j]];
	}
	for(int k = 0; k < fMax; k++){
		if(freq[k] > moda){
			countModa = freq[k];
			moda = k;
		}
	}
	printf("\n\n--> A Moda é: %d\n\n", moda);
}

/* –––––––––– MEDIANA –––––––––– */

void mediana(int array[]){
	float mediana;
	if(arraySize % 2 == 0){
		int n = floor(arraySize / 2);
		mediana = (array[n] + array[n-1])/(float)2;
	} else{
		mediana = array[arraySize/2];
	}
	printf("\n\n--> A Mediana é: %g\n\n", mediana);
} 