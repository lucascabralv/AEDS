/*
2 - Faça um programa que imprima os L primeiros elementos da serie de Fibonacci
*/

#include <stdio.h>

int main(void) {
    int L, numA, numB, soma;
    numA = 1;
    numB = 1;
    printf("Digite quantos números da sequência de Fibonacci você deseja imprimir:\n");
    scanf("%d", &L);
    printf("1\t1\t");
    for(int i=0;i<L-2; i++){
        soma = numA + numB;
        numA = numB;
        numB = soma;
        printf("%d\t",soma);
    }
    printf("\n");
    return 0;
}