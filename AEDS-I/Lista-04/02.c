/*
2 - Fazer uma função void mostrarParesEmOrdemDecrescente(int n) que recebe um número inteiro n e mostra na tela (em ordem decrescente) todos os valores 
menores do que n para a sequência do exercício anterior. A sua função mostrarParesEmOrdemDecrescente deve utilizar a função par desenvolvido na questão anterior. 
Além disso, você deve fazer um procedimento exercicio02()para ler o valor de n e chamar a função desenvolvido nesta questão.
*/

#include <stdio.h>

int par (int n){
    int an = 2 + (n-1) *2;
    return an;
}

void mostarParesEmOrdemDecrescente(int n){
    int x, maior;
    x=0;
    maior = 0;
    while (maior < n){
        x++;
        maior = par(x); 
    }
    x--;

    for (int i = x; i > 0; i--){
        printf("%d\t", par(i));
    }
    printf("\n");
}

void exercicio02(){
    int num;
    printf("Digite um número\n");
    scanf("%d", &num);
    mostarParesEmOrdemDecrescente(num);
}

int main(void) {
    exercicio02();
    return 0;
}