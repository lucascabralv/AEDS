/*
7 - Fazer uma função que recebe um número inteiro n, um real x e retorna o produto dos n primeirostermos da sequência acima. 
Utilize a função desenvolvida na questão acima. 
Além disso, vocêdeve fazer um procedimento exercicio07() para ler os valores de n e de x, e chamar a funçãodesenvolvida nesta questão.
*/

#include <stdio.h>
#include <math.h>

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

double nSequencia(int n, float x){
    double nTermo = parSobreImpar(n) * pow(x,n);
    return nTermo;
}

double produtoSequencia(int n, float x){
    double produto = 1;
    for(int i = 1; i <= n; i++){
        produto *= nSequencia(i, x);
    }
    return produto;
}
void exercicio07(){
    int num;
    float xNum;
    printf("Digite um número inteiro\n");
    scanf("%d", &num);
    printf("Digite um número real\n");
    scanf("%g", &xNum);
    printf("\nO produto dos %d primeiros números da sequência é: %g\n\n", num, produtoSequencia(num, xNum));
    
}
int main(void) {
    exercicio07();
    return 0;
}