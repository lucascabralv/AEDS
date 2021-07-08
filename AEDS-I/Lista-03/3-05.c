/*
5 - Faça um programa para imprimir os múltiplos de 5.
*/

#include <stdio.h>

int main(void) {
    int n;
    printf("Quantos múltiplos de 5 você deseja imprimir?\n");
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        printf("%d\t", 5*i);
    }
    printf("\n");
    return 0;
}