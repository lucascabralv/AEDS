/*
1 - Desenvolva um algoritmo RECURSIVO que dado uma palavra imprima-a em ordem reversa, ou seja, do final para o começo.
*/

#include <stdio.h>
#include <string.h>

void printRecRev(char palavra[], int index){
    int indexB = index;
    if (index <= strlen(palavra)){
        index++;
        printRecRev(palavra, index);
        printf("%c", palavra[indexB]);
    } 
}

int main(void){
    int index = 0;
    char palavra[20];

    printf("\n-> Digite uma palavra:    ");
    scanf("%[^\n]s", palavra);

    printf("\n • ");

    printRecRev(palavra, index);

    printf("\n\n");
    return 0;
}
