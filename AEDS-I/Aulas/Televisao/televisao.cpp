//g++ -c televisao.cpp
#include <iostream>
#include "televisao.h"

using namespace std;

Televisao::Televisao(){
    this -> channel = 0;
    this -> volume = 0;
}
Televisao::Televisao(int channel, int volume){
    this -> channel = channel;
    this -> volume = volume;
}
void Televisao::volumeUp(){
    if(this->volume < 100){
        this->volume++;
    }
}
void Televisao::volumeDown(){
    if(this->volume > 0){
        this->volume--;
    }
}
void Televisao::channelUp(){
    if(this->channel < 100){
        this->channel++;
    }
}
void Televisao::channelDown(){
    if(this->channel > 0){
        this->channel--;
    }
}
void Televisao::setVolume(int volume){
    if(volume > 0 && volume < 100){
        this->volume = volume;
    } else {
        cout << "Valor não permitido" << endl;
        cout << "Aperte enter para continuar..." << endl;
        getchar();
    }
}
void Televisao::setChannel(int channel){
    if(channel > 0 && channel < 100){
        this->channel = channel;
    } else {
        cout << "Valor não permitido" << endl;
        cout << "Aperte enter para continuar..." << endl;
        cin.ignore();
        getchar();
    }
}
int Televisao::getChannel(){
    return this->channel;
}
int Televisao::getVolume(){
    return this->volume;
}