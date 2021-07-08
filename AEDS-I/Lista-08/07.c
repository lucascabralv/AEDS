/*
7. Faça um programa que armazene em um registro de dados (estrutura composta) os dados de um 
funcionário de uma empresa, compostos de: Nome, Idade, Sexo (M/F), CPF, Data de Nascimento,
Codigo do Setor onde trabalha (0-99), Cargo que ocupa (string de até 30 caracteres) e Salário. 
Os dados devem ser digitados pelo usuário, armazenados na estrutura e exibidos na tela.
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
	int idade;
	char sexo[2];
	char cpf[12];
	int codigoSetor;
	char cargo[30];
	float salario;
	DataNasc dataNascimento;
} Pessoa;


void cadastrarPessoas(Pessoa pessoas[]){
	for(int i = 0; i < TAM; i++){
		printf("Nome:\n -> ");
		scanf(" %[^\n]s", pessoas[i].nome);

		printf("Sexo:\n -> ");
		scanf(" %[^\n]s", pessoas[i].sexo);

		printf("CPF:\n -> ");
		scanf(" %[^\n]s", pessoas[i].cpf);

		printf("Idade:\n -> ");
		scanf(" %d", &pessoas[i].idade);

		printf("Código do Setor:\n -> ");
		scanf(" %d", &pessoas[i].codigoSetor);

		printf("Salário:\n -> ");
		scanf(" %g", &pessoas[i].salario);

		printf("Cargo:\n -> ");
		scanf(" %[^\n]s", pessoas[i].cargo);

		printf("Data de nascimento:\n");
		printf(" -> Dia: ");
		scanf(" %d", &pessoas[i].dataNascimento.dia);
		printf(" -> Mês: ");
		scanf(" %d", &pessoas[i].dataNascimento.mes);
		printf(" -> Ano: ");
		scanf(" %d", &pessoas[i].dataNascimento.ano);

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
		printf("Sexo: %s\n", pessoas[i].sexo);
		printf("CPF: %s\n", pessoas[i].cpf);
		printf("Idade: %d\n", pessoas[i].idade);
		printf("Código do Setor: %d\n", pessoas[i].codigoSetor);
		printf("Salário: %g\n", pessoas[i].salario);
		printf("Cargo: %s\n", pessoas[i].cargo);
		printf("Data de nascimento:\n");
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
