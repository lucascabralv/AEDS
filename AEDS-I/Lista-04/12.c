/*
12 - Fazer uma função que recebe um número inteiro n e imprima os n primeiros múltiplos de 5.
Além disso, você deve fazer um procedimento exercicioXXI() para chamar a função desenvolvido nesta questão.
*/

#include <stdio.h>

void multiplos(int n){
    for(int i = 0; i < n ; i++){
        printf("%d\t", 5*i);
    }
    printf("\n");
}
void exercicioXII(){
    int num;
    printf("Digite quantos múltiplos de 5 deseja imprimir\n");
    scanf("%d", &num);
    multiplos(num);
}
int main(void) {
    exercicioXII();
    return 0;
}