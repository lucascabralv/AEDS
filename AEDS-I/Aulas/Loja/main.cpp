#include "loja.h"
#include "item.h"
#include <iostream>

using namespace std;

void menu(){
    system("clear || cls");
    cout << "1 - Adicionar Item" << endl;
    cout << "2 - Mostrar itens" << endl;
    cout << "3 - Sair" << endl;
    cout << "Digite um número: ";
}


int main(){
    Loja *loja = new Loja();
    int opcao = 0;
    while(opcao != 3){
        menu();
        cin >> opcao;
        cin.ignore();
        system("clear || cls");
        switch(opcao){
            case 1: {
                if(loja->getCount() < 5){
                    loja->addItem();
                }
                break;
            }
            case 2: {
                loja->showItens();
                cout << "Aperte enter para continuar..." << endl;
                getchar();
                break;
            }
        }
    }  

    return 0;
}