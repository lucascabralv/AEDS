/*

Crie três classes Pessoa, Professor e Aluno. A classe Pessoa deve ter o nome e a idade dos membros. 
As classes Professor e Aluno devem herdar da classe Pessoa.

A classe Professor deve ter dois atributos inteiros: publicações e id. Haverá duas funções de membro: 
getData e putData. A função getData deve fazer a leitura dos dados: o nome, idade e publicações do professor. 
A função putData deve imprimir o nome, idade, publicações e o id do professor.

A classe Aluno deve ter dois atributos: notas que é um array de tamanho 6 e id. 
Ele possui duas funções: getData e putData. A função getData deve obter a entrada do usuário: o nome, 
a idade e as notas do aluno nas disciplinas. A função putData deve imprimir o nome, idade, soma das notas, 
a média das notas e o id do aluno.

Para cada objeto sendo criado pelo Professor ou pela classe do Aluno, 
ids sequenciais devem ser atribuídos a eles começando de 1. 

Utilize getData e putData como métodos virtuais da classe Pessoa.

*/

#include <iostream>

using namespace std;

class Pessoa {
    protected:
        string nome;
        int idade;
    public:
        Pessoa(){
            this->nome = "";
            this->idade = 0;
        }
        Pessoa(string nome, int idade){
            this->nome = nome;
            this->idade = idade;
        }
        string getNome(){
            return this->nome;
        }
        int getIdade(){
            return this->idade;
        }
        void setNome(int nome){
            this->nome= nome;
        }
        void setIdade(int idade){
            this->idade = idade;
        }
        virtual void getData(int id)=0;
        virtual void putData()=0;
};

class Professor : public Pessoa{
    private:
        int publicacoes;
        int id;
    public:
        Professor():Pessoa(){
            this->publicacoes = 0;
            this-> id = 0;
        }
        Professor(string nome, int idade, int publicacoes, int id):Pessoa(nome, idade){
            this->publicacoes = publicacoes;
            this-> id = id;
        }
        void getData(int id){
            string nome;
            int idade;

            cout << "Entre com o nome: ";
            getline(cin, nome);
            cout << "Entre com a idade: ";
            cin >> idade;
            cin.ignore();

            int pubs;
            cout << "Digite quantas publicações: " << endl;
            cin >> pubs;

            this->nome = nome;
            this->idade = idade;
            this->publicacoes = pubs;
            this->id = id;
        } 
        void putData(){
            cout << "Nome: " << this->nome << " | ";
            cout << "Idade: " << this->idade << " | ";
            cout << "Publicações: " << this->publicacoes << " | ";
            cout << "ID: " << this->id << endl;
        }   
};

class Aluno : public Pessoa{
    private:
        int notas[6];
        int id;
    public:
        Aluno():Pessoa(){
            for(int i = 0; i < 6; i++){
                this->notas[i] = 0;
            }
            this-> id = 0;
        }
        Aluno(string nome, int idade, int notas[], int id):Pessoa(nome, idade){
            for(int i = 0; i < 6; i++){
                this->notas[i] = notas[i];
            }
            this-> id = id;
        }
        void getData(int id){
            string nome;
            int idade;

            cout << "Entre com o nome: ";
            getline(cin, nome);
            cout << "Entre com a idade: ";
            cin >> idade;
            cin.ignore();
            int notas[6];
            cout << "Digite as notas:" << endl;
            for(int i = 0; i < 6; i++){
                cout << "Nota " << i+1 << ": ";
                cin >> notas[i];
            }
            this->nome = nome;
            this->idade = idade;
            this->id = id;
            for(int i = 0; i < 6; i++){
                this->notas[i] = notas[i];
            }
        } 
        void putData(){
            int soma = 0;
            for(int i = 0; i < 6; i++){
                soma += this->notas[i];
            }
            cout << "Nome: " << this->nome << " | ";
            cout << "Idade: " << this->idade << " | ";
            cout << "Soma das notas: " << soma << " | ";
            cout << "Média das notas: " << soma/6 << " | ";
            cout << "ID: " << this->id << endl;
        }  
};


void menu(){
    system("clear || cls");
    cout << "1 - Adicionar pessoa" << endl;
    cout << "2 - Mostrar pessoas" << endl;
    cout << "3 - Sair" << endl;
    cout << "Digite um número: ";
}

void addPessoa(Pessoa *pessoas[], int *id){
    int opcao;

    cout << "Qual o cargo desta pessoa?" << endl;
    cout << "1 - Estudande" << endl;
    cout << "2 - Professor" << endl;
    cin >> opcao;
    cin.ignore();

    switch(opcao){
        case 1:{
            pessoas[*id] = new Aluno();
            pessoas[*id]->getData(*id+1);
            break;
        }
        case 2:{
            pessoas[*id] = new Professor();
            pessoas[*id]->getData(*id + 1);
            break;
        }
    }
    *id += 1;
}

void showPessoas(Pessoa *pessoas[], int id){
    for(int i = 0; i < id; i++){
        pessoas[i]->putData();
    }
}


int main(){
    Pessoa *pessoas[10];
    int id = 0;
    int opcao = 0;
    while(opcao != 3){
        menu();
        cin >> opcao;
        cin.ignore();
        system("clear || cls");
        switch(opcao){
            case 1: {
                addPessoa(pessoas, &id);
                break;
            }
            case 2: {
                showPessoas(pessoas, id);
                break;
            }
        }
        cout << "Aperte enter para continuar..." << endl;
        getchar();
    }  
    system("clear || cls");
    return 0;
}