#include <iostream>
#include "06-ac.h"
using namespace std;

ArCondicionado::ArCondicionado(){
	this->potencia = 0;
	this->tempExtenrna = 0;
	this->tempResultante = 0;
}
ArCondicionado::ArCondicionado(int potencia, float tempExterna){
	this->potencia = potencia;
	this->tempExtenrna = tempExterna;
	this->tempResultante = 0;
}
float ArCondicionado::getTempResultante(){
	return this->tempResultante = this->tempExtenrna - (this->potencia * 1.8);
}
int ArCondicionado::getPotencia(){
	return this->potencia;
}
float ArCondicionado::getTempExterna(){
	return this->tempExtenrna;
}
