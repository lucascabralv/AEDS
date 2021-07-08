/*
Faça um programa para armazenar um livro de receitas. Para isso, crie um vetor com cinco receitas compostas por: 
nome (máximo de 25 letras), quantidade de ingredientes e ingredientes. 
Então, crie e leia o vetor de receitas e procure pelo nome de uma, caso ela exista no vetor 
os seus ingredientes devem ser impressos.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 3

typedef struct {
    char nome[25];
    char ingredientes[100];
    char quantidade_ingredientes[100];
} Receita;

void criaReceitas(Receita receitas[]);
int pesquisarReceitas(Receita receitas[], char palavraPesquisada[]);

//MAIN

int main(void){
    char palavra[25];
    int resultado;
    Receita receitas[TAM];
    criaReceitas(receitas);
    int teste = 1;
    while(teste == 1){
        printf("Digite o nome da receita que deseja procurar:\n -> ");
        scanf(" %[^\n]s", palavra);

        resultado = pesquisarReceitas(receitas, palavra);
        if(resultado >= 0){
            printf("\nReceita encontrada\n");
            printf(" • Ingredientes: %s\n", receitas[resultado].ingredientes);
            printf(" • Quantidade: %s\n", receitas[resultado].quantidade_ingredientes);
        } else{
            printf("-->Receita não encontrada\n");
        }
    //

        printf("Deseja continuar? 0 -> NÃO // 1 -> SIM\n");
        scanf("%d", &teste);
        system("cls || clear");
    }
    return 0;
}

void criaReceitas(Receita receitas[]){
    for(int i = 0; i < TAM; i++){
        printf("\n-> Digite o nome da %dª receita:  ", i+1);
        scanf(" %[^\n]s", receitas[i].nome);
        printf("\nDigite os ingredientes da %dª receita > Separe-os por ; < :\n", i + 1);
        scanf(" %[^\n]s", receitas[i].ingredientes);
        printf("\nDigite as quantidades dos ingredientes da %dª receita > Separe-as por ; < :\n", i + 1);
        scanf(" %[^\n]s", receitas[i].quantidade_ingredientes);
        system("cls || clear");
    }

}

int pesquisarReceitas(Receita receitas[], char palavraPesquisada[]){
    int resp = -1;
	for(int i = 0; i < TAM; i++){
		if(strcmp(receitas[i].nome, palavraPesquisada) == 0){
			resp = i;
			i = TAM;
		}
	}
	return resp;
}