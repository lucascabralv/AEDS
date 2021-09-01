#include <stdio.h>
#include <stdlib.h>

void mostrar(int n){
    if(n > 0){
        int num;
        scanf("%d", &num);
        mostrar(n - 1);
        printf("%d ", num);
    }
}

int main(int argc, char const *argv[]){
    int n;
    printf("Quantos números irá digitar? ");
    scanf("%d", &n);
    printf("Digite os %d números:\n", n);
    mostrar(n);
    printf("\n");

    return 0;
}
