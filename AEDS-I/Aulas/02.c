/*
STRUCT
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define TAM 100

typedef struct{
	char nome[50];
	int idade;
	char cpf[12];
	float altura;
	float peso;
}Aluno;

void cadastrar(Aluno *aluno){
	printf("Entre com seu nome:\n-> ");
	scanf(" %[^\n]s", aluno->nome);
	printf("Entre com seu CPF:\n-> ");
	scanf(" %[^\n]s", aluno->cpf);
	printf("Entre com sua idade:\n-> ");
	scanf("%d", &aluno->idade);
	printf("Entre com sua altura:\n-> ");
	scanf("%g", &aluno->altura);
	printf("Entre com seu peso:\n-> ");
	scanf("%g", &aluno->peso);
	fflush(stdin);
	printf("\nAperte enter para continuar...\n");
	getchar();
	system("clear || cls");
}

void mostrar(Aluno aluno[], int count){
	for (int i = 0; i < count; i++){
		printf("––> Nome: %s\n", aluno[i].nome);
		printf("––> CPF: %s\n", aluno[i].cpf);
		printf("––> Idade: %d\n", aluno[i].idade);
		printf("––> Altura: %g\n", aluno[i].altura);
		printf("––> Peso: %g\n", aluno[i].peso);
		printf("______________________________\n\n");
	}
	printf("\nAperte enter para continuar...\n");
	getchar();
}
void mostrarAluno(Aluno aluno){
	printf("––> Nome: %s\n", aluno.nome);
	printf("––> CPF: %s\n", aluno.cpf);
	printf("––> Idade: %d\n", aluno.idade);
	printf("––> Altura: %g\n", aluno.altura);
	printf("––> Peso: %g\n", aluno.peso);
	printf("\nAperte enter para continuar...\n");
	getchar();
}

int pesquisar(Aluno aluno[], char nomeChave[], int count){
	int resp = -1;
	for(int i = 0; i < count; i++){
		if(strcmp(aluno[i].nome, nomeChave) == 0){
			resp = i;
			i = count;
		}
	}
	return resp;
}

void mostrarNomeAlunos(Aluno aluno[], int count){
	for(int i = 0; i < count; i++){
		printf(" • %s\n", aluno[i].nome);
	}
	printf("–––––––––––––––––––––––––––\n");
	printf("Aperte enter para continuar...\n");
	getchar();
}

int mostrarMenu(int count){
	int menuNumber;
	system("clear || cls");
	printf("1 - Cadastrar um aluno\n");
	printf("2 - Mostrar lista de alunos\n");
	printf("3 - Mostrar infos dos %d alunos\n", count);
	printf("4 - Pesquisar se há aluno\n");
	printf("5 - Salvar registros\n");
	printf("6 - Recuperar registros\n");
	printf("7 - Sair\n");
	printf("––> Escolha um número: ");
	scanf("%d", &menuNumber);
	fflush(stdin);
	system("clear || cls");
	return menuNumber;
}

void salvarDados(Aluno aluno[], int count){
	FILE *fp = fopen("DadosAlunos.txt", "w");
	for(int i = 0; i < count; i++){
		fprintf(fp, "%s##", aluno[i].nome);
		fprintf(fp, "%s##", aluno[i].cpf);
		fprintf(fp, "%d##", aluno[i].idade);
		fprintf(fp, "%g##", aluno[i].altura);
		fprintf(fp, "%g##\n", aluno[i].peso);
	}
	fclose(fp);
}

void recuperarDados(Aluno aluno[], int *count){
	FILE *fp = fopen("DadosAlunos.txt", "r");
	if(fp == NULL){
		printf("\nErro ao abrir arquivo\n\n");
	} else {
		char linha[100];
		fgets(linha, 100, fp);
		while(!feof(fp)){
			char *temp = strtok(linha, "##");

			strcpy(aluno[*count].nome, temp);
			temp = strtok(NULL, "##");
			strcpy(aluno[*count].cpf, temp);
			temp = strtok(NULL, "##");
			aluno[*count].idade = atoi(temp);
			temp = strtok(NULL, "##");
			aluno[*count].altura = atof(temp);
			temp = strtok(NULL, "##");
			aluno[*count].peso = atof(temp);
			*count = *count +1;
			fgets(linha, 100, fp);
		}
	}
	fclose(fp);
}

int main(void){
	Aluno alunos[TAM];
	Aluno aluno;
	bool menu = true;
	int menuNumber;
	char nomePesquisa[50];
	int count = 0;
	int recuperarRegistrosn = 1;

	recuperarDados(alunos, &count);

	while(menu == true){
		menuNumber = mostrarMenu(count);
		switch(menuNumber){
			case 1:
				if(count < TAM){
					printf("1 - Cadastrar um aluno\n");
					printf("Cadastrar %dº aluno\n\n", count+1);
					cadastrar(&aluno);
					alunos[count] = aluno;
					count++;
				} else {
					printf("ERRO: Limite de alunos atingido!\n");
				}
				break;
			case 2:
				printf("2 - Mostrar lista de alunos\n\n");
					mostrarNomeAlunos(alunos, count);
				break;
			case 3:
				printf("3 - Mostrar infos dos %d alunos\n\n", count);
				mostrar(alunos, count);
				fflush(stdin);
				break;
			case 4:
				printf("4 - Pesquisar se há aluno\n");
				printf("Digite um nome para pesquisar:\n-> ");
				scanf(" %[^\n]s", nomePesquisa);
				fflush(stdin);
				int resp = pesquisar(alunos, nomePesquisa, count);
				if(resp >= 0){
					printf("---> Aluno %s encontrado\n", nomePesquisa);
					mostrarAluno(alunos[resp]);
				} else {
					printf("-x-> Nenhum aluno encontrado\n");
					printf("\nAperte enter para continuar...\n");
					getchar();
				}

				break;
			case 5:
				printf("5 - Salvar registros\n");

				salvarDados(alunos, count);

				printf("\n--> Registro concluído\n");
				printf("\nAperte enter para continuar...\n");
				getchar();
				break;
			case 6:
				printf("6 - Recuperar registros\n");
				//Já faz ao iniciar o programa
				printf("\n-->Concluído... enter para continuar\n");
				getchar();
				break;
			case 7:
				salvarDados(alunos, count);
				printf("-> Finalizado...\n");
				menu = false;
				break;
		}
		fflush(stdin);
	}
	system("clear || cls");
	return 0;
}
