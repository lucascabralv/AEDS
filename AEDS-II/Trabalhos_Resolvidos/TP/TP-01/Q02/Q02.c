#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Se a palavra fim for lida, retorna true
bool isFim(char s[]){
    bool resp = false;
    if(strlen(s) == 4 && s[0] == 'F' && s[1] == 'I' && s[2] == 'M'){
        resp = true;
    }
    return resp;
}

// Faz a leitura da linha
void leitura(){
    char palavra[500] = "";
    fgets(palavra, sizeof(palavra),stdin);
    // Continua o loop até a palavra FIM ser achada
    while(!(isFim(palavra))){
        bool resp = true;
        for(int i = 0; i < (strlen(palavra)-1)/2; i++){
            // Compara a letra na posição i com a última-i-1, o - 2 é para que a simetria fique exata,
            // já que em uma palavra de cinco letras, a última letra está na posição 4 e já que 
            //em C existe o marcador de fim do array de char
            if (palavra[i] != palavra[(strlen(palavra) - i - 2)]){
                resp = false;
            }
        }
        if(resp == true){
            printf("SIM\n");
        } else {
            printf("NAO\n");
        }
        fgets(palavra, sizeof(palavra), stdin);
    }
}

int main(void){
    leitura();
    return 0;
}