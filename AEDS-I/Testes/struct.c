/*
STRUCTS
*/

#include <stdio.h>
#include <stdlib.h>

// IMOVEL STRUCT
typedef struct {
	char nome[30];
	long int cep;
	char endereco[100];
	float preco;
	char corretorNome[40];
}Imovel;

//CORRETOR STRUCT
typedef struct{
	char nome[30];
	long int cpf;
	int idade;
	int imoveis[100];
	int imoveisNum;
	Imovel imovel[20];
}Corretor;


//Declara funções
int showMenu();
void cadastrarImovel(Imovel *imovel);


//Define o tamanho dos arrays
#define IMOV_TAM 100
#define CORR_TAM 100

//MAIN
int main(void){
	int menuSwitch = 1;
	int imovCount = 0;
	int corretorCount = 0;
	Imovel imovel;
	Imovel imoveis[IMOV_TAM];
	Corretor corretor;
	Corretor corretores[CORR_TAM];

	while(menuSwitch == 1){
		int menu = showMenu();
		switch (menu){
			case 1:{
				printf("1 - Cadastrar um imóvel\n");
				printf("Cadastrar %dº aluno\n\n", imovCount + 1);
				cadastrarImovel(&imovel);
				imoveis[imovCount] = imovel;
				imovCount++;
				break;
			}
			case 2:{

				break;
			}
			case 3:{

				break;
			}
			case 4:{

				break;
			}
			case 5:{

				break;
			}
			case 6:{
				system("cls || clear");
				menuSwitch = 0;
				break;
			}
		}
	}
	return 0;
}

int showMenu(){
	int menuNumber;
	system("clear || cls");
	printf("1 - Cadastrar imóvel\n");
	printf("2 - Cadastral corretor\n");
	printf("3 - Lista de imóveis\n");
	printf("4 - Lista de corretores\n");
	printf("5 - Pesquisar se há aluno\n");
	printf("6 - Sair\n");
	printf("––> Escolha um número: ");
	scanf("%d", &menuNumber);
	fflush(stdin);
	system("clear || cls");
	return menuNumber;
}
//Cria imovel e liga ao corretor
void cadastrarImovel(Imovel *imovel){
	printf("Digite o nome do imóvel:\n-> ");
	scanf("%[^\n]s", imovel -> nome);
	printf("Digite o CEP do imóvel:\n-> ");
	scanf("%ld", &imovel -> cep);
	printf("Digite o preço do imóvel:\n-> R$ ");
	scanf("%2f", &imovel -> preco);
	printf("Digite o endereço do imóvel:\n-> ");
	scanf("%[^\n]s", imovel -> endereco);
}

void cadastrarCorretor(Corretor *corretor){
	printf("Digite o nome do corretor:\n-> ");
	scanf("%[^\n]s", corretor -> nome);
}