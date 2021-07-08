//g++ -c figura.cpp // -> gera figura.o
#include "figura.h"
#include <math.h>

Figura::Figura(){
    this->cor = "";
    this->preenchida = false;
}
Figura::Figura(string cor, bool preenchida){
    this->cor = cor;
    this->preenchida = preenchida;
}

Circulo::Circulo():Figura(){
    this->raio = 0;
}
Circulo::Circulo(float raio, string cor, bool preenchida):Figura(cor, preenchida){
    this->raio = raio;
}
void Circulo::setRaio(float raio){
    this->raio = raio;
}
float Circulo::getRaio(){
    return this->raio;
}
float Circulo::getArea(){
    float area = M_PI * pow(this->raio,2);
    return area;
}
float Circulo::getPerimetro(){
    float perimetro = 2 * M_PI * this->raio;
    return perimetro;
}

//QUADRADO

Quadrado::Quadrado():Figura(){
    this->lado = 0;
}
Quadrado::Quadrado(float lado, string cor, bool preenchida):Figura(cor, preenchida){
    this->lado = lado;
}
void Quadrado::setlado(float lado){
    this->lado = lado;
}
float Quadrado::getLado(){
    return this->lado;
}
float Quadrado::getArea(){
    return pow(this->lado, 2);
}
float Quadrado::getPerimetro(){
    return this->lado * 4;
}

//RETANGULO

Retangulo::Retangulo():Figura(){
    this->base = 0;
    this->altura = 0;
}
Retangulo::Retangulo(float base, float altura, string cor, bool preenchida):Figura(cor, preenchida){
    this->base = base;
    this->altura = altura;
}
void Retangulo::setBase(float base){
    this->base = base;
}
void Retangulo::setAltura(float altura){
    this->altura = altura;
}
float Retangulo::getBase(){
    return this->base;
}
float Retangulo::getAltura(){
    return this->altura;
}
float Retangulo::getArea(){
    return this->base * this->altura;
}
float Retangulo::getPerimetro(){
    return this->base * 2 + this->altura * 2; 
}
