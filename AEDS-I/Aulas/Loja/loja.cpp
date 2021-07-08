#include "loja.h"
#include "item.h"

using namespace std;

Loja::Loja(){
    this->count = 0;
}
void Loja::addItem(){
    int opcao;
    cout << "Qual item será adicionado?" << endl;
    cout << "1 - Livro" << endl;
    cout << "2 - CD" << endl;
    cout << "3 - DVD" << endl;
    cin >> opcao;
    cin.ignore();
    string nome;
    float preco;
    system("clear || cls");
    cout << "Entre com o nome: ";
    getline(cin, nome);
    cout << "Entre com o preço: ";
    cin >> preco;
    cin.ignore();

    switch(opcao){
        case 1:{
            string autor;
            cout << "Entre com o nome do autor: ";
            getline(cin, autor);
            cin.ignore();
            this->itens[count] = new Livro(nome, preco, autor);
            break;
        }
        case 2:{
            int numfaixas;
            cout << "Entre com o número de faixas: ";
            cin >> numfaixas;
            cin.ignore();
            this->itens[count] = new CD(nome, preco, numfaixas);
            break;
        }
        case 3:{
            float duracao;
            cout << "Entre com a duração: ";
            cin >> duracao;
            cin.ignore();
            this->itens[count] = new DVD(nome, preco, duracao);
            break;
        }

    }

    this->count++;
}
void Loja::showItens(){
    for(int i = 0; i < count; i++){
        cout << itens[i]->toString() << endl;
    }
}
int Loja::getCount(){
    return this->count;
}