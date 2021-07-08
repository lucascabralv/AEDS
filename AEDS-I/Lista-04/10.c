/*
10 - Fazer uma função que recebe um número inteiro n, um número real x e retorna o somatório dosn primeiros 
termos da sequência mostrada na questão anterior. 
Além disso, você deve fazer umprocedimento exercicioXX() para chamar a função desenvolvido nesta questão.
*/

#include <stdio.h>
#include <math.h>

int par (int n){
    double an = 2 + (n-1) *2;
    return an;
}

int umSobreImpar (int n){
    int an = 3 + (n-1) *2;
    return an;
}
double fatorial(int n){
    double fatorialNum = 1;
    for(int i = n; i >=1; i--){
        fatorialNum *= i;
    }
    return fatorialNum;
}

double parSobreImpar(int n){
    double x = par(n)/fatorial(umSobreImpar(n));
    return x;
}

double nSequencia(int n, float x){
    double nTermo = parSobreImpar(n) * pow(x,n);
    return nTermo;
}

double nSomaSequencia(int n, float x){
    double soma = 0;
    for(int i = 1; i<= n; i++){
        soma += nSequencia(i,x);
    }
    return soma;
}

void exercicioX(){
    int num;
    float xNum;
    printf("Digite um número inteiro\n");
    scanf("%d", &num);
    printf("Digite um número real\n");
    scanf("%g", &xNum);

    printf("\nA soma dos %d primeiros números da sequência é %g\n\n", num, nSomaSequencia(num, xNum));
    
}

int main(void) {
    exercicioX();
    return 0;
}