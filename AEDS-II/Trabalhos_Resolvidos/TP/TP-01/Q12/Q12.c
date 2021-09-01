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

bool comparacao(char palavra[], int i){
    bool resp = true;
    if(i < (strlen(palavra)-1)/2){
        if(palavra[i] == palavra[(strlen(palavra) - i - 2)]){
            resp = true;
            i += 1;
            resp = comparacao(palavra, i);
        } else {
            resp = false;
        }
    }
    return resp;
}

// Faz a leitura da linha
void leitura(){
    char palavra[500] = "";
    fgets(palavra, sizeof(palavra),stdin);
    // Continua o loop até a palavra FIM ser achada
    while(!(isFim(palavra))){
        bool resp = comparacao(palavra, 0);
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