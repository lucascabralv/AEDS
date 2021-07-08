#include <iostream>
#include "04-circulo.h"

using namespace std;

void defineCirculos(Circulo *c1, Circulo *c2){
	float raio, x, y;
	cout << "• Círculo 1\n-> Raio: ";
	cin >> raio;
	c1->setRaio(raio);
	raio = 0;
	cout << "-> Centro\nX: ";
	cin >> x;
	cout << "Y: ";
	cin >> y;
	c1->setPosition(x,y);
	x = 0;
	y = 0;
	cout << "• Círculo 2\n-> Raio: ";
	cin >> raio;
	c2->setRaio(raio);
	raio = 0;
	cout << "-> Centro\nX: ";
	cin >> x;
	cout << "Y: ";
	cin >> y;
	c2->setPosition(x, y);
}
void printCirculos(Circulo *c1, Circulo *c2){
	cout << "• Círculo 1:" << endl;
	c1->printArea();
	c1->printRaio();
	c1->printDistancia(c2->getX(), c2->getY());
	cout << "-----------------------" << endl;
	cout << "• Círculo 2:" << endl;
	c2->printArea();
	c2->printRaio();
	c2->printDistancia(c1->getX(), c1->getY());
}

int main(){
	float percent;
	Circulo *c1 = new Circulo();
	Circulo *c2 = new Circulo();
	defineCirculos(c1, c2);
	cout << "Aperte enter para continuar..." << endl;
	cin.ignore();
	getchar();
	system("clear || cls");
	printCirculos(c1, c2);
	cout << "Quantos % deseja aumentar o raio do círculo 1?" << endl;
	cin >> percent;
	c1->aumentaRaio(percent);
	cout << "Quantos % deseja aumentar o raio do círculo 2?" << endl;
	cin >> percent;
	c2->aumentaRaio(percent);
	cout << "Aperte enter para continuar..." << endl;
	cin.ignore();
	getchar();
	system("clear || cls");
	printCirculos(c1, c2);
	return 0;
}
