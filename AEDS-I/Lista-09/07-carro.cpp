#include <iostream>
#include "07-carro.h"

using namespace std;

Carro::Carro(){
	this->tanque = 0;
	this-> distancia = 0;
}
Carro::Carro(float tanque, int distancia){
	this->tanque = tanque;
	this->distancia = distancia;
}
void Carro::abastecer(float litros){
	if(this->tanque + litros <= 50){
		this->tanque += litros;
	}
}
void Carro::mover(int quilometros){
	float litros = quilometros/15;
	this->distancia += quilometros;
	this->tanque -= litros;
}
void Carro::getStatus(){
	cout << "Distância " << this->distancia << "\tStatus do tanque: " << this->tanque << endl;
}