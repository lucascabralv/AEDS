#include <iostream>
#include "02-elevador.h"

using namespace std;

void showMenu(Elevador *el){
	system("cls || clear");
	cout << "Andar: ";
	el->getAndarAtual() == 0? cout << "Térreo" : cout << el->getAndarAtual();
	cout << "/"<< el->getTotalAndares();
	cout << "\t Pessoas: " << el->getNumPessoas() << "/" << el->getCapacidade() << endl;
	cout << "1 - Adicionar pessoa" << endl;
	cout << "2 - Retirar pessoa" << endl;
	cout << "3 - Subir andar" << endl;
	cout << "4 - Descer andar" << endl;
	cout << "5 - Sair do prédio" << endl;
	cout << "Escolha um número: "; 
}

int main(){
	int opcao = 0;
	int capacidade;
	int totalAndares;
	cout << "Digite a capacidade do elevador (max de pessoas)" << endl;
	cin >> capacidade;
	cout << "Digite quantos andares o prédio possui" << endl;
	cin >> totalAndares;
	Elevador *el = new Elevador(totalAndares, capacidade);
	while(opcao != 5){
		showMenu(el);
		cin >> opcao;
		switch(opcao){
			case 1:{
				el->adicionaPessoa();
				break;
			}
			case 2:{
				el->retiraPessoa();
				break;
			}
			case 3:{
				el->sobe();
				break;
			}
			case 4:{
				el->desce();
				break;
			}
			case 5:{
				system("clear || cls");
				break;
			}
		}
	}
	return 0;
}
