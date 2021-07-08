
#include <iostream>
//Para manipular arquivos
#include <fstream>


using namespace std;

int main(){
    /*
    string nome;
    int idade;

    cout << "Digite sua idade" << endl;
    cin >> idade;

    cout << "Digite seu nome" << endl;
    cin.ignore();
    getline(cin, nome);

    cout << "Seu nome é " << nome << " e sua idade é " << idade << endl;

    */
    // ---  ARQUIVOS  ---
    //Cria arquivo e imprime nele

    ofstream teste("teste.txt", ios::trunc); //app faz append e trunc apaga o que existe e coloca o novo

    teste << "Saída no arquivo" << endl;
    teste.close();

    //Abre arquivo e imprime na tela conteúdo

    ifstream input("texto.txt");
    string linha;
    while(getline(input, linha)){
        cout << linha << endl;
    }
    input.close();
    return 0;
}


