/*
14 - Fazer uma função que recebe um número inteiro n e retorna o maior elemento da sequência de
Fibonacci que seja menor que n. 
Além disso, você deve fazer um procedimento exercicioXX()para chamar a função desenvolvido nesta questão.
*/

#include <stdio.h>

int fibonacci(int n){
    int numA, numB, fibNum;
    numA = 1;
    numB = 1;
    if(n <= 2)
        fibNum = 1;
    else {
        for(int i=0; i < n-2; i++){
            fibNum = numA + numB;
            numA = numB;
            numB = fibNum;
        }
    }
    return fibNum;
}
int fibonacciMaior(int n){
    int maior = 0;
    int i=0;
    while(maior <= n){
        i++;
        maior = fibonacci(i);
    }
    maior = fibonacci(i-1);
    return maior;
}

void exercicioXIV(){
    int num;
    printf("Digite um número\n");
    scanf("%d", &num);
    printf("\nO maior número da sequência até %d é: %d\n\n",num, fibonacciMaior(num));
}

int main(void) {
    exercicioXIV();
    return 0;
}
