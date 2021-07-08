#include <iostream>
#include "03-relogio.h"

using namespace std;

void menu(Relogio *r){
	system("clear || cls");
	cout << "• Horário " << r->getHora() << endl;
	cout << "1 - Definir horário" << endl;
	cout << "2 - Aumentar 1 segundo" << endl;
	cout << "3 - Sair" << endl;
	cout << "Escolha um nº" << endl;
}

int main(){
	int opcao;
	int hora, minuto, segundo;
	Relogio *r = new Relogio();
	while(opcao != 3){
		menu(r);
		cin >> opcao;
		switch(opcao){
			case 1: {
				system("clear || cls");
				cout << "Defina o horário" << endl;
				cout << "Hora: ";
				cin >> hora;
				cout << "Minuto: ";
				cin >> minuto;
				cout << "Segundo: ";
				cin >> segundo;
				r->setHora(hora, minuto, segundo);
				break;
			}
			case 2: {
				r->segundoUp();
				break;
			}
			case 3: {
				system("clear || cls");
				break;
			}
		}
	}
	return 0;
}
