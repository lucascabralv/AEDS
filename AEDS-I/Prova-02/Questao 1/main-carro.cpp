#include "carro.h"
#include <iostream>

using namespace std;

void menu(){
    system("clear || cls");
    cout << "1 - Adicionar carro" << endl;
    cout << "2 - Mostrar informações do carro" << endl;
    cout << "3 - Sair" << endl;
    cout << "Digite um número: ";
}

void addCarro(Carro *car){
    string nome;
    int anoFab;
    string cor;
    float consumo;

    cout << "Digite o nome do carro: ";
    getline(cin, nome);
    cin.ignore();
    cout << "Entre com o ano de fabricação: ";
    cin >> anoFab;
    cin.ignore();
    cout << "Digite qual a cor do carro: ";
    getline(cin, cor);
    cin.ignore();
    cout << "Qual o consumo médio do carro? (Entre com apenas números) -> ";
    cin >> consumo;
    cin.ignore();

    car->setNome(nome);
    car->setAnoFab(anoFab);
    car->setCor(cor);
    car->setConsumo(consumo);

    cout << "Carro adicionado com sucesso!" << endl;
}

void showCar(Carro *car){
    cout << "INFOS do Carro:" << endl;
    cout << "• Nome: " << car->getNome() << endl;
    cout << "• Ano de Fabricação: " << car->getAnoFab() << endl;
    cout << "• Cor: " << car->getCor() << endl;
    cout << "• Consumo: " << car->getConsumo() << endl;
}



int main(){
    Carro *car = new Carro();
    int opcao = 0;
    car->printaInfoPessoa();
    while(opcao != 3){
        menu();
        cin >> opcao;
        cin.ignore();
        system("clear || cls");
        switch(opcao){
            case 1: {
                addCarro(car);
                break;
            }
            case 2: {
                showCar(car);
                break;
            }
        }
        cout << "Aperte enter para continuar..." << endl;
        getchar();
    }  
    system("clear || cls");
    return 0;
}