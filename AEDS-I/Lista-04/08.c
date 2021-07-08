/*
8 - Fazer uma função que recebe um número inteiro n e retorna o seu fatorial1. 
Além disso, você deve fazer um procedimento exercicio08() para ler o valor de n e chamar a função desenvolvidonesta questão.
*/

#include <stdio.h>

int fatorial(int n){
    int fatorialNum = 1;
    for(int i = n; i >=1; i--){
        fatorialNum *= i;
    }
    return fatorialNum;
}
void exercicio08(){
    int num;
    printf("Digite um número para descobrir seu fatorial\n");
    scanf("%d",  &num);
    printf("\n%d! = %d\n\n", num, fatorial(num));
}
int main(void) {
    exercicio08();
    return 0;
}