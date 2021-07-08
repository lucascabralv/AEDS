#ifndef CARRO_H
#define CARRO_H

#include <iostream>

using namespace std;

class Carro{
	private:
		float tanque;
		int distancia;

	public:
		Carro();
		Carro(float, int);
		void abastecer(float litros);
		void mover(int quilometros);
		void getStatus();
};

#endif