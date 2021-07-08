/*
5 - Fazer:
(a) Uma função double parSobreImpar(int n)que recebe um número inteiro n e retorna o n-ésimo termo da sequência 2/3,4/5,6/7,8/9,10/11,....  
A sua função deve utilizar os funçãos par e umSobreImpar desenvolvidos anteriormente.

(b) Uma função double somaParSobreImpar(int n)que recebe um número inteiro n e retorna o valor do somatório dos n primeiros termos da sequência anterior. 
A sua função somaParSobreImpar deve utilizar a função parSobreImpar.
(c) Um procedimento exercicio05() para ler o valor de n e chamar as funções desenvolvidas nesta questão.
*/

#include <stdio.h>

int par (int n){
    double an = 2 + (n-1) *2;
    return an;
}

double umSobreImpar (int n){
    double an = 3 + (n-1) *2;
    return an;
}

double parSobreImpar(int n){
    double x = par(n)/umSobreImpar(n);
    return x;
}
double somaParSobreImpar(int n){
    double soma = 0;
    for (int i = 1; i <= n; i++){
        soma += parSobreImpar(i);
    }
    return soma;
}

void exercicio05(){
    int num;
    printf("Digite um número\n");
    scanf("%d", &num);
    printf("\nO %dº número da sequência é %g", num, parSobreImpar(num));
    printf("\nA soma dos %d primeiros números da sequência é %g\n\n", num, somaParSobreImpar(num));
}

int main(void) {
    exercicio05();
    return 0;
}