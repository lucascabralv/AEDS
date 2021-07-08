/*
3 - Fazer uma função double umSobreImpar(int n)que recebe um número inteiro n e retorna o n-ésimo termo da sequência 1/3,1/5,1/7,1/9,1/11....
 Além disso, você deve fazer um procedimento exercicio03() para ler o valor de n e chamar a função desenvolvido nesta questão.
*/

#include <stdio.h>

double umSobreImpar (int n){
    int an = 3 + (n-1) *2;
    /* OUTRA SOLUÇÃO
    double x = 1/an;
    return x;
    */
    return an;
}

void exercicio03(){
    int num;
    printf("Digite um número\n");
    scanf("%d", &num);
    printf("\nO %dº número da sequência é 1/%g\n", num, umSobreImpar(num));
}

int main(void) {
    exercicio03();
    return 0;
}