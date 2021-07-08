/*
6. Crie uma estrutura representando os alunos de um determinado curso. A estrutura deve conter a matrícula do aluno, 
nome, nota da primeira prova, nota da segunda prova e nota da terceira prova.
(a) Permita ao usuário entrar com os dados de 5 alunos.
(b) Encontre o aluno com maior nota da primeira prova.
(c) Encontre o aluno com maior média geral.
(d) Encontre o aluno com menor média geral
(e) Para cada aluno diga se ele foi aprovado ou reprovado, considerando o valor 6 para aprovação.
*/

#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

#define TAM 3

typedef struct{
	char nome[30];
	int matricula;
	float notas[2];
	float media;
	char aprovado[4];
}Aluno;

void cadastrarAlunos(Aluno alunos[]);
void mostrarAlunos(Aluno alunos[]);
void mostrarAluno(Aluno aluno);
void provaUm(Aluno alunos[]);
void maiorMedia(Aluno alunos[]);
void menorMedia(Aluno alunos[]);

int main(void){
	Aluno alunos[TAM];
	int menu = 0;
	while(menu!=6){
		printf("1 - Cadastrar %d alunos\n", TAM);
		printf("2 - Mostrar os alunos\n");
		printf("3 - Encontre o aluno com maior nota da primeira prova.\n");
		printf("4 - Encontre o aluno com maior média geral.\n");
		printf("5 - Encontre o aluno com menor média geral.\n");
		printf("6 - Sair\n");
		fflush(stdin);
		printf("\nDigite um número:  ");
		scanf("%d", &menu);
		system("clear || cls");

		switch(menu){
			case 1:{
				printf("1 - Cadastrar %d alunos\n", TAM);
				cadastrarAlunos(alunos);
				break;
			}
			case 2:{
				printf("2 - Mostrar os alunos\n");
				mostrarAlunos(alunos);
				break;
			}
			case 3:{
				printf("3 - Encontre o aluno com maior nota da primeira prova.\n");
				provaUm(alunos);
				break;
			}
			case 4:{
				printf("4 - Encontre o aluno com maior média geral.\n");
				maiorMedia(alunos);
				break;
			}
			case 5:{
				printf("5 - Encontre o aluno com menor média geral.\n");
				menorMedia(alunos);
				break;
			}
			case 6:{
				printf("Programa finalizado...\n");
				break;
			}
			deafult:{
				printf("\nDigite um número válido: 1-5\n");
				break;
			}
		}
	}

	return 0;
}

void cadastrarAlunos(Aluno alunos[]){
	for(int i = 0; i < TAM; i++){
		system("clear || cls");
		printf("-> Cadastro %dº aluno\n", i + 1);
		printf(" • Nome: ");
		scanf(" %[^\n]s", alunos[i].nome);
		printf(" • Matrícula: ");
		scanf("%d", &alunos[i].matricula);
		printf(" • Nota 1ª Prova: ");
		scanf("%g", &alunos[i].notas[0]);
		printf(" • Nota 2ª Prova: ");
		scanf("%g", &alunos[i].notas[1]);
		fflush(stdin);
		alunos[i].media =  (alunos[i].notas[0] + alunos[i].notas[1])/2;
		if (alunos[i].media >= 6){
			printf("--> Aluno aprovado!\nMédia: %g\n", alunos[i].media);
			strcpy(alunos[i].aprovado, "SIM");
		}else{
			printf("--> Aluno não aprovado!\nMédia: %g\n", alunos[i].media);
			strcpy(alunos[i].aprovado, "NÃO");
		}
		printf("\nAperte enter para continuar...\n");
		getchar();
		system("clear || cls");
	}
}

void mostrarAluno(Aluno aluno){
	printf("Nome: %s\n", aluno.nome);
	printf("Matrícula: %d\n", aluno.matricula);
	printf("Nota 1: %g\n", aluno.notas[0]);
	printf("Nota 2: %g\n", aluno.notas[1]);
	printf("Média Geral: %g\n", aluno.notas[1]);
	printf("Aprovado? %s\n", aluno.aprovado);
}

void mostrarAlunos(Aluno alunos[]){
	for(int i = 0; i < TAM; i++){
		mostrarAluno(alunos[i]);
		printf("–––––––––––––––––––––––––––––––\n");
	}
	printf("Aperte enter para continuar...\n");
	fflush(stdin);
	getchar();
	system("clear || cls");
}

void maiorMedia(Aluno alunos[]){
	int aluno;
	float aux = -1;
	for(int i = 0; i < TAM; i++){
		if(alunos[i].media > aux){
			aux = alunos[i].media;
			aluno = i;
		}
	}
	printf(" --> O aluno com a maior média é:\n");
	mostrarAluno(alunos[aluno]);
	fflush(stdin);
	printf("Aperte enter para continuar...\n");
	getchar();
	system("clear || cls");
}

void menorMedia(Aluno alunos[]){
	int aluno;;
	float aux = TAM;
	for(int i = 0; i < TAM; i++){
		if(alunos[i].media < aux){
			aux = alunos[i].media;
			aluno = i;
		}
	}
	printf(" --> O aluno com a menor média é:\n");
	mostrarAluno(alunos[aluno]);
	fflush(stdin);
	printf("Aperte enter para continuar...\n");
	getchar();
	system("clear || cls");
}

void provaUm(Aluno alunos[]){
	int aluno;
	float aux = -1;
	for(int i = 0; i < TAM; i++){
		if(alunos[i].notas[0] > aux){
			aux = alunos[i].media;
			aluno = i;
		}
	}
	printf(" --> O aluno com a maior nota na primeira prova:\n");
	mostrarAluno(alunos[aluno]);
	fflush(stdin);
	printf("Aperte enter para continuar...\n");
	getchar();
	system("clear || cls");
}