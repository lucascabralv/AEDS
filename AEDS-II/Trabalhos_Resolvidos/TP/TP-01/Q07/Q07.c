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

// Descobre se o caractere é uma vogal
bool isVogal(char c){
    bool resp = false;
    if(c >= 97 && c <= 122){
        c = (c - 32);
    }
    if(c == 65 || c == 69 || c == 73 || c == 79 || c == 85){
        resp = true;
    }
    return resp;
}
// Se todas as letras são vogais retorna SIM
bool isAllVogal(char s[]) {
    bool resp = true;
    for(int i = 0; i < strlen(s)-1; i++){
        if(!isVogal(s[i])){
            resp = false;
            break;
        }
    }
    return resp;
}

// Se todas as letras não sao vogais e nem números retorna SIM
bool isAllConsoante(char s[]) {
    bool resp = true;
    for (int i = 0; i < strlen(s)-1; i++) {
        if (isVogal(s[i]) || ((s[i] >= 48) && (s[i] <= 57))){
            resp = false;
            break;
        }
    }
    return resp;
}
bool isAlgarismo(char c){
    bool resp = false;
    if(((c >= 48) && (c <= 57))){
        resp = true;
    }
    return resp;
}

// Se os caracteres possuirem na tabela ASCII os valores que os algarismos possuem então é um número inteiro
bool isInteiro(char s[]){
    bool resp = true;
    for (int i = 0; i < strlen(s)-1; i++) {
        if (!isAlgarismo(s[i])) {
            resp = false;
        }
    }
    return resp;
}

//  Se os caracteres possuirem na tabela ASCII os valores que os algarismos
// possuem e possui ao menos um ponto " . " retorna SIM
bool isReal(char s[]) {
    bool resp = true;
    int j = 0;
    for (int i = 0; i < strlen(s)-1; i++) {
        if (!isAlgarismo(s[i])) {
            if (!(s[i] == 46) && !(s[i] == 44)) {
                resp = false;
                break;
            } else{
                j++;
            }
        }
    }
    if(j > 1){
        resp = false;
    }
    return resp;
}

void testes(){
    char palavra[500];
    fgets(palavra, sizeof(palavra), stdin);
    while(!isFim(palavra)){
        printf(isAllVogal(palavra) ? "SIM " : "NAO ");
        printf(isAllConsoante(palavra) ? "SIM " : "NAO ");
        printf(isInteiro(palavra) ? "SIM " : "NAO ");
        printf(isReal(palavra) ? "SIM\n" : "NAO\n");
        fgets(palavra, sizeof(palavra), stdin);
    }
}

int main(void){
    testes();
}