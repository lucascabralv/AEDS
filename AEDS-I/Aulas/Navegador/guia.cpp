//g++ -c guia.cpp // -> gera guia.o
#include <iostream>
#include "guia.h" 

using namespace std;

Guia::Guia(){
    this->id = to_string(rand()%10) + to_string(rand()%10) + to_string(rand()%10);
    this->titulo = "";
    this->url = "";
}
Guia::Guia(string titulo, string url){
    this->id = to_string(rand()%10) + to_string(rand()%10) + to_string(rand()%10);
    this->titulo = titulo;
    this->url = url;
}
void Guia::setId(string id){
    this->id = id;
}
void Guia::setTitulo(string titulo){
#ifdef DEBUG
    //
    cout << "Guia::setTitulo" << endl; //cpp guia.cpp -D DEBUG > lixo //Ativa a flag e vê o código intermediáio que o compilador recebe
    //                                 //cpp guia.cpp > lixo // tira a flag
#endif // DEBUG
    this->titulo = titulo;
}
void Guia::setUrl(string url){
    this->url = url;
}
string Guia::getId(){
    return this->id;
}
string Guia::getTitulo(){
    return this->titulo;
}
string Guia::getUrl(){
    return this->url;
}