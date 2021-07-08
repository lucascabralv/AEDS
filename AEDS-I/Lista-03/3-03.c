/*
3 - Faça um programa que imprima todos os elementos da série de Fibonacci menores que L.
*/

#include <stdio.h>
#include <stdbool.h>

int main(void) {
    int L, numA, numB, soma;
    numA = 1;
    numB = 1;
    bool i = true;
    printf("Digite até qual números você deseja imprimir:\n");
    scanf("%d", &L);
    if(L>=1)
        printf("1\t1\t");
    while(i == true){
        soma = numA + numB;
        numA = numB;
        numB = soma;
        if (soma <= L){
            printf("%d\t",soma);
        }
        else {
            i = false;
        }
    }
    printf("\n");
    return 0;
}