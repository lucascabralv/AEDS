/*
6 - Fazer a função que recebe um número inteiro n, um número real x e retorna o n-ésimo termo da sequência abaixo. 
Utilize a função desenvolvido na letra a da questão anterior. Além disso,você deve fazer um procedimento exercicio06() 
para ler os valores de n e de x, e chamar a função desenvolvido nesta questão. 2x/3,4xˆ2/5,6xˆ3/7,8xˆ4/9,10xˆ5/11...
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

void exercicio06(){
    int num;
    float xNum;
    printf("Digite um número inteiro\n");
    scanf("%d", &num);
    printf("Digite um número real\n");
    scanf("%g", &xNum);
    printf("\nA expressão do %dº termo é: (%d * %gˆ%d)/ %g\n\n", num, par(num), xNum, num, umSobreImpar(num));
    printf("\nO %dº número da sequência é %g\n\n", num, nSequencia(num, xNum));
    
}

int main(void) {
    exercicio06();
    return 0;
}