/*
10 - Faça um programa que mostre na tela os n primeiros elementos da sequência 1, 3, 5, 7, 9,...
*/

#include <stdio.h>

int main(void) {
    int n, an;

    printf("Quantos números da sequência deseja imprimir?\n");
    scanf("%d", &n);
    for(int i = 1; i<=n; i++){
        an = 1 +(i-1)*2;
        printf("%d\t", an);
    }
    printf("\n");
    return 0;
}