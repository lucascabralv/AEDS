#include <iostream>
#include "02-elevador.h"

using namespace std;

Elevador::Elevador(){
	this->andarAtual = 0;
	this->capacidade = 0;
	this->numPessoas = 0;
	this-> totalAndares = 0;
}
Elevador::Elevador(int totalAndares, int capacidade){
	this->andarAtual = 0;
	this->numPessoas = 0;
	this->capacidade = capacidade;
	this->totalAndares = totalAndares;
}
void Elevador::adicionaPessoa(){
	if(this->numPessoas < this->capacidade){
		this->numPessoas++;
	} else {
		cout << "ERRO: Limite de pessoas atingido" << endl;
		cout << "Aperte enter para continuar" << endl;
		cin.ignore();
		getchar();
	}
}
void Elevador::retiraPessoa(){
	if(this->numPessoas > 0){
		this->numPessoas--;
	} else {
		cout << "ERRO: Não há ninguém no elevador para ser retirado" << endl;
		cout << "Aperte enter para continuar" << endl;
		cin.ignore();
		getchar();
	}
}
void Elevador::sobe(){
	if(this->andarAtual < this->totalAndares){
		this->andarAtual++;
	} else {
		cout << "ERRO: Não há andares acima do "<< this->andarAtual << "º andar" << endl;
		cout << "Aperte enter para continuar" << endl;
		cin.ignore();
		getchar();
	}
}
void Elevador::desce(){
	if(this->andarAtual > 0){
		this->andarAtual--;
	} else {
		cout << "ERRO: Não há andares abaixo do térreo" << endl;
		cout << "Aperte enter para continuar" << endl;
		cin.ignore();
		getchar();
	}
}
int Elevador::getTotalAndares(){
	return this->totalAndares;
}
int Elevador::getCapacidade(){
	return this->capacidade;
}
int Elevador::getAndarAtual(){
	return this->andarAtual;
}
int Elevador::getNumPessoas(){
	return this->numPessoas;
}
