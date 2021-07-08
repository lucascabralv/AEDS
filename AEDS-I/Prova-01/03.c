/*
3- Faça um programa que receba do usuário o nome de um arquivo binário.
Abra esse arquivo e preencha-o com 10 inteiros lidos pelo teclado. Ao final, coloque também a média dos valores.
*/

#include <stdio.h>
#include <stdlib.h>

int main(void){
    char nomeArquivo[20];
    int numeros[10];
    float media = 0;
    printf("Digite o nome do arquivo:\n");
    scanf("%s", nomeArquivo);

    FILE *fp = fopen(nomeArquivo, "wb");
    printf("Digite 10 números:\n");
    for(int i = 0; i < 10; i++){
        scanf("%d", &numeros[i]);
        fwrite(&numeros[i], sizeof(int), 1, fp);
        media += numeros[i];
    }
    media = media / 10;
    fwrite(&media, sizeof(float), 1, fp);
    printf("\n->Arquivo criado com sucesso!\n");
    fclose(fp);
    return 0;
}
