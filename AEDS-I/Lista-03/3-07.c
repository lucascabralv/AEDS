/*
Faça um programa para calcular o N-ésimo termo da sequência de Fibonacci (1, 1, 2, 3, 5, 8, 13,21, ...).
*/

#include <stdio.h>

int main(void) {
    int n, numA, numB, soma;
    numA = 1;
    numB = 1;
    printf("Digite posição da Sequência de Fibonacci deseja saber:\n -> ");
    scanf("%d", &n);
    if (n == 1 || n == 2){
        soma = 1;
    }
    for(int i=0;i<n-2; i++){
        soma = numA + numB;
        numA = numB;
        numB = soma;
    }
    printf("\n-> O %dº termo é: %d\n", n, soma);
    return 0;
}