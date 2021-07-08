/*
13 - Fazer uma função que recebe um número inteiro n e retorna o n-ésimo termo da sequência de Fibonacci. 
Além disso, você deve fazer um procedimento exercicioXXIII() para chamar a função desenvolvido nesta questão.
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

void exercicioXIII(){
    int num;
    printf("Qual termo da sequência de Fibonacci deseja imprimir?\n");
    scanf("%d", &num);
    printf("\nO %dº termo é %d\n\n",num, fibonacci(num));
}

int main(void) {
    exercicioXIII();
    return 0;
}
