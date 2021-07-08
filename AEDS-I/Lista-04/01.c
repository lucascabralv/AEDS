/*
1 - Fazer uma função int par(int n)que recebe um número inteiro n e retorna o n-ésimo termo da sequência 2,4,6,8,10,12.... 
Além disso, você deve fazer um procedimento exercicio01() para ler o valor de n e chamar a função desenvolvido nesta questão.
*/

#include <stdio.h>

int par (int n){
    int an = 2 + (n-1) *2;
    return an;
}

void exercicio01(){
    int num;
    printf("Digite um número\n");
    scanf("%d", &num);
    printf("\nO %dº número da sequência é %d\n", num, par(num));
}

int main(void) {
    exercicio01();
    return 0;
}