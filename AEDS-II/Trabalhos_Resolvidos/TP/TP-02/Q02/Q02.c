#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    // Atributos
    char nome[50];
    char formato[50];
    char duracao[50];
    char pais[50];
    char idioma[50];
    char emissora[50];
    char transmissao[50];
    int episodios;
    int temporadas;
} Series;

char* removeEComercial(char* old){
    char *newLine = (char*) malloc(sizeof(strlen(old)));
    int i = 0, j = 0;
    while(i < strlen(old)){
        if(old[i] == '&'){
            i++;
            while(old[i] != ';'){
                i++;
            }
        } else {
            newLine[j] = old[i];
            j++;
        }
        i++;
        newLine[j] = '\0';
    }
    return newLine;
} 

char* removeTags(char* old){
    char *newLine = (char*) malloc(sizeof(strlen(old)));
    int i = 0, j = 0;
    while(i < strlen(old)){
        if(old[i] == '<'){
            i++;
            while(old[i] != '>'){
                i++;
            }
        } else {
            newLine[j] = old[i];
            j++;
        }
        i++;
        newLine[j] = '\0';
    }
    return newLine;
} 
int removeTagsInt(char* old){
    char *newLine = (char*) malloc(sizeof(strlen(old)));
    int i = 0, j = 0;
    char *ptr;
    int resp;
    while(i < strlen(old)){
        if(old[i] == '<'){
            i++;
            while(old[i] != '>'){
                i++;
            }
        } else {
            newLine[j] = old[i];
            j++;
        }
        i++;
        newLine[j] = '\0';
    }
    resp = strtol(newLine, &ptr, 10);
    return resp;
}
char* removeEnter(char* old){
    old[strlen(old)-1] = ' ';
    return old;
}

// Se a palavra fim for lida, retorna true
bool isFim(char s[]){
    bool resp = false;
    if(strlen(s) == 4 && s[0] == 'F' && s[1] == 'I' && s[2] == 'M'){
        resp = true;
    }
    return resp;
}

void ler(char arquivo[]){
    Series serie;
    char pathArquivo[100];
    strcat(pathArquivo, "/Users/lucascabral/Desktop/series/");
    strcat(pathArquivo, arquivo);
    //FILE *fp = fopen(strtok(pathArquivo, "\n"), "r");
    FILE *fp = fopen("/Users/lucascabral/Desktop/series/13_Reasons_Why.html", "r");
    if(fp == NULL){
        printf("Erro");
    } else {
        char buf[2000];
        fgets(buf, 2000, fp);
        
        //NOME
        while(strstr(buf, "infobox_v2") == NULL){
            fgets(buf, 2000, fp);
        }
        fgets(buf, 2000, fp);
        fgets(buf, 2000, fp);
        strcpy(serie.nome, removeTags(buf));

        //FORMATO
        while(strstr(buf, "Formato") == NULL){
            fgets(buf, 2000, fp);
        }
        fgets(buf, 2000, fp);
        strcpy(serie.formato, removeTags(buf));

        //DURAÇÃO
        while(strstr(buf, "Duração") == NULL){
            fgets(buf, 2000, fp);
        }
        fgets(buf, 2000, fp);
        strcpy(serie.duracao, removeTags(buf));
        //PAIS DE ORIGEM
        while(strstr(buf, "País de origem") == NULL){
            fgets(buf, 2000, fp);
        }
        fgets(buf, 2000, fp);
        strcpy(serie.pais, removeTags(buf));

        //IDIOMA
        while (strstr(buf, "Idioma original") == NULL){
            fgets(buf, 2000, fp);
        }
        fgets(buf, 2000, fp);
        strcpy(serie.idioma, removeTags(buf));

        //EMISSORA
        while (strstr(buf, "Emissora de televisão original") == NULL){
            fgets(buf, 2000, fp);
        }
        fgets(buf, 2000, fp);
        strcpy(serie.emissora, removeTags(buf));

        //TRANSMISSÃO
        while (strstr(buf, "Transmissão original") == NULL){
            fgets(buf, 2000, fp);
        }
        fgets(buf, 2000, fp);
        strcpy(serie.transmissao, removeTags(buf));

        //TEMPORADAS
        while (strstr(buf, "temporadas") == NULL){
            fgets(buf, 2000, fp);
        }
        fgets(buf, 2000, fp);
        serie.temporadas = (int) removeTagsInt(buf);

        //EPISÓDIOS
        while (strstr(buf, "N.º de episódios") == NULL){
            fgets(buf, 2000, fp);
        }
        fgets(buf, 2000, fp);
        serie.episodios = (int) removeTagsInt(buf);

        printf("%s%s%s%s%s%s%s%d %d\n", removeEnter(serie.nome), removeEnter(serie.formato), 
        removeEnter(serie.duracao), removeEComercial(removeEnter(serie.pais)),
        removeEComercial(removeEnter(serie.idioma)), 
        removeEnter(serie.emissora), removeEnter(serie.transmissao),
        serie.temporadas, serie.episodios);
    }
    fclose(fp);
}

int main(int argc, char const *argv[]){
    char palavra[50];
    fgets(palavra, sizeof(palavra), stdin);
    while(!isFim(palavra)){
        ler(palavra);
        fgets(palavra, sizeof(palavra), stdin);
    }
    return 0;
}
