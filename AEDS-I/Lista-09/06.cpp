#include <iostream>
#include "06-ac.h"

using namespace std;

int main(){
	ArCondicionado *ac1 = new ArCondicionado(10, 25);
	ArCondicionado *ac2 = new ArCondicionado(5, 31);
	cout << "• AC 1:\n-> Potência: " << ac1->getPotencia() << endl;
	cout << "-> Temperatura Externa: " << ac1->getTempExterna()<<endl;
	cout << "-> Temperatura Resultante: " << ac1->getTempResultante() << endl;
	cout << "------------------------" << endl;
	cout << "• AC 2:\n-> Potência: " << ac2->getPotencia() << endl;
	cout << "-> Temperatura Externa: " << ac2->getTempExterna() << endl;
	cout << "-> Temperatura Resultante: " << ac2->getTempResultante() << endl;
	return 0;
}
