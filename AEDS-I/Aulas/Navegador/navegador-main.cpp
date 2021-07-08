//g++ navegador-main.cpp -o navegador-main navegador.o guia.o
#include <iostream>
#include "guia.h"
#include "navegador.h"

using namespace std;

void menu(){
    system("clear || cls");
    cout << "1 - Para abrir uma guia" << endl;
    cout << "2 - Para fechar uma guia" << endl;
    cout << "3 - Para visualizar guias abertas" << endl;
    cout << "4 - Para sair" << endl;
    cout << "Escolha um número: ";
}
int main(){
    Navegador *nav = new Navegador();
    int opcao = 0;
    int num;
    string titulo, url;
    while(opcao != 4){
        menu();
        cin >> opcao;
        cin.ignore();
        system("clear || cls");
        switch(opcao){
            case 1:{
                cout << "Entre com url: ";
                cin >> url;
                cin.ignore();
                cout << "Entre com nome: ";
                getline(cin, titulo);
                nav->abrirGuia(titulo, url);
                cout << "Aperte enter para continuar..." << endl;
                cin.ignore();
                break;
            }
            case 2:{
                nav->listarGuias();
                cout << "-----------------------------------" << endl;
                cout << "Entre com o número da guia para fechar" << endl;
                cin >> num;
                cin.ignore();
                nav->fecharGuia(num);
                cout << "Aperte enter para continuar..." << endl;
                cin.ignore();
                break;
            }
            case 3:{
                nav->listarGuias();
                cout << "Aperte enter para continuar..." << endl;
                cin.ignore();
                break;
            }
            case 4:{
                break;
            }
        }
    }
    return 1;
}