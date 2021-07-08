/*
1 - Fazer um programa para ler n números inteiros e imprimir a soma deles. O valor de deve ser lido do teclado.
*/

#include <stdio.h>

int main(void) {
    int n, num, soma;
    soma = 0;
    printf("Digite quantos números você deseja somar:\n");
    scanf("%d", &n);
    for(int i=1;i<=n; i++){
        printf("-> %dº número = ", i);
        scanf("%d", &num);
        soma += num;
    }
    printf("\nA soma de todos o números digitados é: %d\n", soma);
    return 0;
}