#include <iostream>
#include <math.h>
#include "04-circulo.h"
using namespace std;

Circulo::Circulo(){
	this->raio = 0;
	this->x = 0;
	this->y = 0;
}
void Circulo::setRaio(float raio){
	this->raio = raio;
}
void Circulo::aumentaRaio(float percent){
	this->raio += this->raio * (percent/100);
}
void Circulo::setPosition(float x, float y){
	this->x = x;
	this->y = y;
}
void Circulo::printRaio(){
	cout << "Raio: " << this->raio << endl;
}
void Circulo::printDistancia(float x2, float y2){
	cout << "Distância entre os centros dos círculos é: " << this->distancia(x2, y2) << endl;
}
void Circulo::printArea(){
	cout << "Área: " << this->area() << endl;
}
void Circulo::printCentro(){
	cout << "Centro: (" << this->x << ", " << this->y << ")" << endl;
}
float Circulo::getX(){
	return this->x;
}
float Circulo::getY(){
	return this->y;
}

float Circulo::distancia(float x2, float y2){
	return sqrt(pow(x2 - this->x, 2) + pow(y2 - this->y, 2));
}
float Circulo::area(){
	return M_PI * pow(this->raio, 2);
}
float Circulo::circunferencia(){
	return 2 * M_PI * this->raio; 
}