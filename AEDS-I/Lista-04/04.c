/*
4 - Fazer uma função double somaUmSobreImpar(int n) que recebe um número inteiro n e retorna o valor do somatório dos n primeiros termos da sequência anterior. 
A sua função somaUmSobreImpar deve utilizar a função umSobreImpar desenvolvido na questão anterior. 
Além disso, você devefazer um procedimento exercicio04() para ler o valor de n e chamar a função desenvolvido nestaquestão.
*/

#include <stdio.h>


double umSobreImpar (int n){
    double an = 3 + (n-1) *2;
    double x = 1/an;
    return x;
}

double somaUmSobreImpar(int n){
    double soma = 0;
    for (int i = 1; i <= n; i++){
        soma += umSobreImpar(i);
    }
    return soma;
}

void exercicio04(){
    int num;
    printf("Digite um número\n");
    scanf("%d", &num);
    printf("\nA soma dos %d primeiros números da sequência é %g\n", num, somaUmSobreImpar(num));
}

int main(void) {
    exercicio04();
    return 0;
}