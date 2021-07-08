/*
9 - Leia um número inteiro I e um número real R. Enquanto I maior que 10, imprima o valor de I na
tela, decremente o valor de I em duas unidades e enquanto R menor que 10, imprima os valores
de R e I na tela e incremente o valor de R em uma unidade.
*/

#include <stdio.h>

int main(void) {
    int I;
    float R;
    printf("Digite um valor para I\n-> ");
    scanf("%d", &I);
    printf("Digite um valor para R\n-> ");
    scanf("%g", &R);
    printf("\n");
    while( I > 10){
        printf("%d\t", I);
        I -= 2;
    }
    printf("\n\n");
    while(R < 10){
        printf("%g %d\t", R,I);
        R++;
    }
    printf("\n\n");
    return 0;
}