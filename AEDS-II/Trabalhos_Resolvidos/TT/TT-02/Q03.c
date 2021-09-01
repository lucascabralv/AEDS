#include <stdio.h>
#include <stdbool.h>

int main(void){
    int anoAtual;
    int ultimaPassagem = 1986;
    int intervalo = 76;
    scanf("%d", &anoAtual);
    while(anoAtual != 0){
        int proximaPassagem = ultimaPassagem;
        bool achou = false;
        while(achou == false){
            proximaPassagem += intervalo;
            if(anoAtual < proximaPassagem){
                achou = true;
            }
        }
        printf("%d\n", proximaPassagem);
        scanf("%d", &anoAtual);
    }
}