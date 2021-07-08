/*

4. Defina uma estrutura que irá representar bandas de música. Essa estrutura deve ter o nome da banda,
que tipo de música ela toca, o número de integrantes e em que posição do ranking essa banda está dentre as suas 5 bandas favoritas. 
Crie um looping para preencher as 5 estruturas de bandas criadas no exemplo passado. 
Após criar e preencher, exiba todas as informações das bandas/estruturas.

5. Na questão anterior crie uma função que peça o nome de uma banda ao usuário
e diga se ela está entre suas bandas favoritas ou não.
*/

#include <stdio.h>
#include<stdlib.h>
#include<string.h>

#define TAM 3

typedef struct{
	char nome[30];
	char tipo_musica[20];
	int num_integrantes;
	int ranking;
}Banda;

void definirBandas(Banda bandas[]){
	for(int i = 0; i < TAM; i++){
		printf("-> Escreve as infos da %dª banda\n", i + 1);
		printf("• Nome: ");
		scanf(" %[^\n]s", bandas[i].nome);
		printf("• Tipo Musical: ");
		scanf(" %[^\n]s", bandas[i].tipo_musica);
		printf("• Nº de Integrantes: ");
		scanf("%d", &bandas[i].num_integrantes);
		printf("• Ranking: ");
		scanf("%d", &bandas[i].ranking);
		system("clear || cls");
	}
	printf("\n--> Cadastro completo\n");
	printf("Aperte enter para continuar...\n");
	fflush(stdin);
	getchar();
	system("clear || cls");
}

void mostrarBandas(Banda bandas[]){
	printf("\n-->Bandas Cadastradas:\n\n");
	for(int i = 0; i < TAM; i++){
		printf("Banda: %s\n", bandas[i].nome);
		printf("Tipo Musical: %s\n", bandas[i].tipo_musica);
		printf("Nº de Integrantes: %d\n", bandas[i].num_integrantes);
		printf("Ranking: %d\n", bandas[i].ranking);
		printf("––––––––––––––––––––––––––––––––––––––\n");
	}
}

int pesquisar(Banda bandas[], char nomeChave[]){
	int resp = -1;
	for(int i = 0; i < TAM; i++){
		if(strcmp(bandas[i].nome, nomeChave) == 0){
			resp = i;
			i = TAM;
		}
	}
	return resp;
}

int main(void){
	Banda bandas[TAM];
	definirBandas(bandas);
	mostrarBandas(bandas);
	char nomePesquisa[30];
	int menu = 0;

	while(menu!=4){
		printf("1 - Cadastrar %d bandas\n", TAM);
		printf("2 - Mostrar as bandas\n");
		printf("3 - Pesquisar banda\n");
		printf("4 - Sair\n");
		fflush(stdin);
		printf("\nDigite um número");
		scanf("%d", &menu);
		system("clear || cls");

		switch(menu){
			case 1:{
				printf("1 - Cadastrar %d bandas\n", TAM);
				definirBandas(bandas);
				break;
			}
			case 2:{
				printf("2 - Mostrar as bandas\n");
				mostrarBandas(bandas);
				break;
			}
			case 3:{
				printf("3 - Pesquisar banda\n");
				printf("Digite um nome para pesquisar:\n-> ");
				scanf(" %[^\n]s", nomePesquisa);
				fflush(stdin);
				int resp = pesquisar(bandas, nomePesquisa);
				if(resp >= 0){
					printf("---> Banda %s encontrada\n", nomePesquisa);
				} else {
					printf("-x-> Nenhum banda encontrada\n");
					printf("\nAperte enter para continuar...\n");
					fflush(stdin);
					getchar();
				}
				break;
			}
			case 4:{
				printf("Programa finalizado...\n");
				break;
			}
			deafult:{
				printf("\nDigite um número válido: 1-3\n");
				break;
			}
		}
	}
	return 0;
}
