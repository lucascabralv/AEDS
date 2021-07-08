/*
4 - Faça um programa que calcule o n-ésimo elemento de uma progressão geométrica (PG) e o imprima na tela. 
O usuário deve entrar com os valores da razão e do 1º termo da PG. 
Lembre-se que uma PG é dada pela seguinte fórmula: an=a1∗qˆ(n−1), onde an é o n-ésimo elemento da PG, a1 é o 1º elemento da PG e q é a razão.
• 1ª Forma: Mostre o algoritmo pedido.
• 2ª Forma: Mostre o algoritmo pedido sem utilizar a operação de exponenciação.
• 3ª Forma: Mostre o algoritmo pedido sem utilizar as operações de exponenciação e multiplicação.
*/

#include <stdio.h>
#include <math.h>

int main(void) {
    int an, n, a1, q, potencia, soma1, soma2;

    printf("===============================================\n\n");
    
    printf("Digite qual termo da PA você deseja saber:\n-> n = ");
    scanf("%d", &n);
    printf("\nDigite qual o 1º termo da PA:\n-> a1 = ");
    scanf("%d", &a1);
    printf("\nDigite qual a razão da PA:\n-> q = ");
    scanf("%d", &q);

    printf("\n***************\n");

    //1ª Forma
    an = a1 * pow(q, n-1);
    printf("\n--> 1ª forma\n%dº termo da PG é: %d\n", n,an);

    //2ª Forma
    potencia = 1;
    for(int i=0; i < n-1; i++){
        potencia = potencia * q;
    }
    an = a1 * potencia;
    printf("\n\n--> 2ª forma\n%dº termo da PG é: %d\n", n,an);

    //3ª Forma
    soma1 = 0;
    soma2 = 0;
    int aux = q;

    for(int i=1; i < n-1; i++){
        soma1 = 0;
        for(int j = 0; j < q; j++){
            soma1 = soma1 + aux;
        }
        aux = soma1;
    }

    for(int i=0; i < a1; i++){
        soma2 = soma2 + soma1;
    }
    an = soma2;
    printf("\n\n--> 3ª forma\n%dº termo da PG é: %d\n", n,an);

    printf("\n===============================================\n\n");
    return 0;
}