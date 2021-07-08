/*
12 - Seja a sequência da questão anterior, mostre somente os elementos maiores que a e menores que b, onde a e b são lidos do teclado.
*/

#include <stdio.h>

int main(void) {
    int n, an, menor, maior;
    int num = 1;
    an = 0;

    printf("Você irá imprimir os valores da sequência que estão entre A e B\n");
    printf("Digite o valor de A: ");
    scanf("%d", &menor);
    printf("Digite o valor de B: ");
    scanf("%d", &maior);

    while(an < maior){
      an = 1 +(num-1)*2;
      if(an > menor && an < maior){
        printf("%d\t", an);
      }
      num++;
    }
    printf("\n\n");
    return 0;
}