//g++ televisao-main.cpp -o televisao-main televisao.o
#include <iostream>
#include "televisao.h"

using namespace std;

void menu(Televisao *t1){
    system("clear || cls");
    cout << "• Volume atual: " << t1->getVolume() << endl;
    cout << "• Canal atual: " << t1->getChannel() << endl;
    cout << "1 - Aumentar volume" << endl;
    cout << "2 - Diminuir volume" << endl;
    cout << "3 - Aumentar canal" << endl;
    cout << "4 - Diminuir canal" << endl;
    cout << "5 - Setar canal" << endl;
    cout << "6 - Desligar TV" << endl;
    cout << "Digite um número" << endl;
}

int main(){
    int opcao = 0;
    Televisao *t1 = new Televisao();
    while(opcao != 6){
        menu(t1);
        cin >> opcao;
        switch(opcao){
            case 1:{
                t1->volumeUp();
                break;}
            case 2:{
                t1->volumeDown();
                break;}
            case 3:{
                t1->channelUp();
                break;}
            case 4:{
                t1->channelDown();
                break;}
            case 5:{
                int canal;
                cout << "Digite o número do canal:" << endl;
                cin >> canal;
                t1->setChannel(canal);
                break;}
            case 6:{
                system("clear || cls");
                break;}
        }
    }
    delete t1; // Para liberar memória, caso o programa continuasse a executar outras funções
    return 0;
}