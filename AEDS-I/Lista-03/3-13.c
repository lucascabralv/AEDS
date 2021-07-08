/*
13 - Faça um programa que leia um caractere e se esse for uma letra maiúscula, imprima “Maiúscula”. 
Senão, se ele for uma letra minúscula, imprima “Minúscula”. Senão, se for um dígito, imprima dígito. Senão imprima “Outro caractere”.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
    char caractere[2];

    printf("Digite um caractere\n-> ");
    scanf("%c", caractere);

    if(caractere[0] >= 97 && caractere[0] <= 122){
        printf("Minúscula\n");
    }
    else if(caractere[0] >= 65 && caractere[0] <= 90){
        printf("Maiúscula\n");
    }
    else {
        printf("Outro caractere\n");
    }
    return 0;
}