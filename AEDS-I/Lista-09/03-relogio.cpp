#include <iostream>
#include "03-relogio.h"

using namespace std;

Relogio::Relogio(){
	this->hora = 0;
	this->minuto = 0;
	this-> segundo = 0;
}
void Relogio::setHora(int hora, int minuto, int segundo){
	this->hora = hora;
	this->minuto = minuto;
	this->segundo = segundo;
}
void Relogio::horaUp(){
	if(this->hora < 24){
		this->hora++;
	} else {
		this->hora = 0;
	}
}
void Relogio::minutoUp(){
	if(this->minuto < 59){
		this->minuto++;
	} else {
		this->horaUp();
		this->minuto = 0;
	}
}
void Relogio::segundoUp(){
	if(this->segundo < 59){
		this->segundo++;
	} else {
		this->minutoUp();
		this->segundo = 0;
	}
}
string Relogio::getHora(){
	string hora;
	string minuto;
	string segundo;
	this->segundo < 10 ? segundo = "0" + to_string(this->segundo) : segundo = to_string(this->segundo);
	this->minuto < 10 ? minuto = "0" + to_string(this->minuto) : minuto = to_string(this->minuto);
	this->hora < 10 ? hora = "0" + to_string(this->hora) : hora = to_string(this->hora);
	string horario = hora + ":" + minuto + ":" + segundo;
	return horario;
}