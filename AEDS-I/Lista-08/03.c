/*
3. Crie uma struct chamada ponto2d que tenha como atributos os pontos x,y e z. 
Crie duas estruturas do tipo ponto2d chamadas ponto_inicial e ponto_Final. Faça um menu 
com as seguintes opções e implemente-as:

1 Digitar o valor do primeiro ponto
2 Digitar os valores do segundo ponto
3 Mostrar a distância entre os pontos 
4 Sair
*/

#include <stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct{
	float x, y, z;
}Ponto;

void definirPonto(Ponto *ponto){
	printf("-> Digite os valores x y z do ponto\n");
	printf("• x = ");
	scanf("%g", &ponto->x);
	printf("• y = ");
	scanf("%g", &ponto->y);
	printf("• z = ");
	scanf("%g", &ponto->z);
	fflush(stdin);
	printf("\n Aperte enter para voltar...\n");
	getchar();
	system("clear || cls");
}

void distanciaPontos(Ponto p1, Ponto p2){
	float distancia = sqrt(pow((p1.x - p2.x), 2) + pow((p1.y - p2.y), 2));
	printf("\n->A distância dos dois pontos é: %g\n", distancia);
	fflush(stdin);
	printf("\n Aperte enter para voltar...\n");
	getchar();
	system("clear || cls");
}

void showMenu(int *menu){
	printf("1 - Definir ponto 1\n");
	printf("2 - Definir ponto 2\n");
	printf("3 - Calcular distância dos pontos\n");
	printf("4 - Sair\n");
	printf("\nDigite um número:\n -> ");
	scanf(" %d", menu);
	fflush(stdin);
	system("clear || cls");
}

int main(void){
	Ponto p1, p2;
	int menu = 0;
	system("clear || cls");
	while(menu != 4){
		showMenu(&menu);
		switch(menu){
			case 1: {
				printf("1 - Definir ponto 1\n\n");
				definirPonto(&p1);
				break;
			}
			case 2: {
				printf("2 - Definir ponto 2\n\n");
				definirPonto(&p2);
				break;
			}
			case 3: {
				printf("3 - Calcular distância dos pontos\n\n");
				distanciaPontos(p1,p2);
				break;
			}
			case 4: {
				printf("Programa finalizado...\n");
				break;
			}
			default:{
				printf("Digite um número válido(1-4)\n");
			}

		}
	}
	return 0;
}
