#include "carro.h"

Carro::Carro(){
    this->nome = "";
    this-> anoFab = 0;
    this->cor = "";
    this->consumo = 0;
}
Carro::Carro(string nome, int anoFab, string cor, float consumo){
    this->nome = nome;
    this-> anoFab = anoFab;
    this->cor = cor;
    this->consumo = consumo;
}
void Carro::setNome(string nome){
    this->nome = nome;
}
void Carro::setAnoFab(int anoFab){
    this->anoFab = anoFab;
}
void Carro::setCor(string cor){
    this->cor = cor;
}
void Carro::setConsumo(float consumo){
    this->consumo = consumo;
}
string Carro::getNome(){
    return this->nome;
}
int Carro::getAnoFab(){
    return this->anoFab;
}
string Carro::getCor(){
    return this->cor;
}
float Carro::getConsumo(){
    return this->consumo;
}

void Carro::printaInfoPessoa(){
    string nome;
    int idade;
    cout << "Entre com o seu nome: ";
    getline(cin, nome);
    cout << " Entre com sua idade: ";
    cin >> idade;

    cout << "Nome: " << nome << " | Idade: " << idade << endl;
}