/*
11 - Faça um programa que mostre na tela os n primeiros elementos da sequência anterior que 
forem divisíveis por três AND múltiplos de cinco OR divisíveis por sete
*/

#include <stdio.h>

int main(void) {
    int n, an;
    int i = 0;
    int num = 1;

    printf("Quantos números da sequência deseja imprimir?\n");
    scanf("%d", &n);
    while(i<n){
      an = 1 +(num-1)*2;
      if((an%3==0 && an%5==0) || an%7 ==0){
        i++;
        printf("%d\t", an);
      }
      num++;
    }
    printf("\n\n");
    return 0;
}