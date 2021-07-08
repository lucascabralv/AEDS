#include "item.h"
#include <cmath>

Item::Item(){
    this->nome = "";
    this->preco = 0;
}
Item::Item(string nome, float preco){
    this->nome = nome;
    this->preco = preco;
}
string Item::getNome(){
    return this->nome;
}
float Item::getPreco(){
    return this->preco;
}
void Item::setNome(string nome){
    this->nome = nome;
}
void Item::setPreco(float preco){
    this->preco = preco;
}

//LIVRO
Livro::Livro():Item(){
    this->autor = "";
}
Livro::Livro(string nome, float preco, string autor):Item(nome, preco){
    this->autor = autor;
}
string Livro::getAutor(){
    return this->autor;
}
void Livro::setAutor(string autor){
    this->autor = autor;
}
string Livro::toString(){
    string resp = "";
    resp += "Nome: " + nome + " | ";
    resp += "Preço: R$" + to_string(preco) + " | ";
    resp += "Autor: " + autor;
    return resp;
}

//CD
CD::CD():Item(){
    this->numfaixas = 0;
}
CD::CD(string nome, float preco, int numfaixas):Item(nome, preco){
    this->numfaixas = numfaixas;
}
int CD::getNumFaixas(){
    return this->numfaixas;
}
void CD::setAutor(int numfaixas){
    this->numfaixas = numfaixas;
}
string CD::toString(){
    string resp = "";
    resp += "Nome: " + nome + " | ";
    resp += "Preço: R$" + to_string(preco) + " | ";
    resp += "Faixas: " + to_string(numfaixas);
    return resp;
}

//DVD
DVD::DVD():Item(){
    this-> duracao = 0;
}
DVD::DVD(string nome, float preco, float duracao):Item(nome, preco){
    this->duracao = duracao;
}
float DVD::getDuracao(){
    return this->duracao;
}
void DVD::setDuracao(float duracao){
    this->duracao = duracao;
}
string DVD::toString(){
    string resp = "";
    resp += "Nome: " + nome + " | ";
    resp += "Preço: R$" + to_string(preco) + " | ";
    resp += "Duração: " + to_string(duracao);
    return resp;
}