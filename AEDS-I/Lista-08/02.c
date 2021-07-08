/*
2. Crie uma struct para controlar ações de uma bolsa de valores com as seuigntes informações:
• Nome da compania
• Área de atuação da compania
• Valor atual da ação (em reais)
• Valor anterior
• Variação da ação em porcentagem (double), ou seja, quanto a ação cresceu ou caiu desde a abertura da bolsa no dia.
*/

#include <stdio.h>
#include <stdlib.h>

#define TAM 2

typedef struct{
	char nome[30];
	char area[30];
	float valor_atual;
	float valor_anterior;
	double variacao;
} Acao;

void cadastrarAcao(Acao acoes[]){
	for(int i = 0; i < TAM; i++){
		printf("--> %dª Ação\n", i+1);
		printf("• Digite o nome da compania:\n -> ");
		scanf(" %[^\n]s", acoes[i].nome);
		printf("• Digite a área de atuação:\n -> ");
		scanf(" %[^\n]s", acoes[i].area);
		printf("• Digite o valor anterior da ação:\n -> ");
		scanf("%f", &acoes[i].valor_anterior);
		printf("• Digite o valor atual da ação:\n -> ");
		scanf("%f", &acoes[i].valor_atual);
		printf("• Digite o valor da variação da ação:\n -> ");
		scanf("%lf", &acoes[i].variacao);
		printf("\nAperte enter para continuar...");
		getchar();
		system("clear || cls");
		fflush(stdin);
		}
}

void mostrarAcao(Acao acoes[]){
	for(int i = 0; i < TAM; i++){
		printf("->Ação %d\n", i+1);
		printf(" • Nome: %s\n", acoes[i].nome);
		printf(" • Área: %s\n", acoes[i].area);
		printf(" • Valor anterior: %g\n", acoes[i].valor_anterior);
		printf(" • Valor atual: %g\n", acoes[i].valor_atual);
		printf(" • Variação: %g%% \n", acoes[i].variacao);
		printf("------------------------\n");
	}
}

int main(void){
	Acao acoes[TAM];
	printf("-> Cadastre %d ações\n", TAM);
	printf("Aperte enter para começar...\n");
	getchar();
	system("clear || cls");
	cadastrarAcao(acoes);
	mostrarAcao(acoes);
	return 0;
}
