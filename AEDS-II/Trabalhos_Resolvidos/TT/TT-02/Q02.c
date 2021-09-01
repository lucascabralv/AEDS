#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int maiorNumero(int n1, int n2, int n3){
    int resp;
    if(n1 > n2 && n1 > n3){
        resp = n1;
    } else if(n2 > n1 && n2 > n3){
        resp = n2;
    } else {
        resp = n3;
    }
    return resp;
}

void achaIdade(){
    int mae, filho1, filho2, filho3;
    scanf("%d", &mae);
    while(mae != 0){
        scanf("%d", &filho1);
        scanf("%d", &filho2);
        filho3 = mae - (filho1 + filho2);
        printf("%d\n", maiorNumero(filho1, filho2, filho3));
        scanf("%d", &mae);
    }
}

int main(void){
    achaIdade();
    return 0;
}