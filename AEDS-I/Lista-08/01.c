/*
1.Crie um programa que permita armazenar o nome, a altura e da data de nascimento de até 10 pessoas. Cada pessoa
deve ser representada por uma struct dentro de um vetor. A data de nascimento também deve ser uma struct.
O nome e a altura de cada pessoa devem ser informados pelo teclado. A geração da data de nascimento deve
ser feita aleatoriamente através de uma função.
*/

#include <stdio.h>
#include <stdlib.h>

#define TAM 10

typedef struct {
	int dia;
	int mes;
	int ano;
} DataNasc;

typedef struct {
	char nome[30];
	float altura;
	DataNasc dataNascimento;
} Pessoa;

void gerarData(Pessoa *pessoa){
	pessoa -> dataNascimento.dia = rand()%30 + 1;
	pessoa -> dataNascimento.mes = rand()%11 + 1;
	pessoa -> dataNascimento.ano = rand()%121 + 1900;
	fflush(stdin);
}

void cadastrarPessoas(Pessoa pessoas[]){
	for(int i = 0; i < TAM; i++){
		printf("Digite o nome da %dª pessoa:\n -> ", i+1);
		scanf(" %[^\n]s", pessoas[i].nome);
		printf("Digite altura da %dª pessoa:\n -> ", i+1);
		scanf("%g", &pessoas[i].altura);
		gerarData(&pessoas[i]);
		printf("Data de nascimento:\n -> %d/%d/%d\n", pessoas[i].dataNascimento.dia, pessoas[i].dataNascimento.mes, pessoas[i].dataNascimento.ano);
		printf("Aperte enter para continuar...\n");
		getchar();
		fflush(stdin);
		system("cls || clear");
	}
}

void mostrarPessoas(Pessoa pessoas[]){
	printf("-> Mostrando info de %d pessoas\n\n", TAM);
	for(int i = 0; i < TAM; i++){
		printf("Nome: %s\n", pessoas[i].nome);
		printf("Altura: %g\n", pessoas[i].altura);
		printf("Data de nascimento: %d/%d/%d \n", pessoas[i].dataNascimento.dia, pessoas[i].dataNascimento.mes, pessoas[i].dataNascimento.ano);
		printf("------------------------\n");
	}
}

int main(void){
	Pessoa pessoas[TAM];
	printf("-> Cadastre %d pessoas\n", TAM);
	printf("Aperte enter para começar...\n");
	getchar();
	system("cls || clear");
	cadastrarPessoas(pessoas);
	system("cls || clear");
	mostrarPessoas(pessoas);

	return 0;
}
