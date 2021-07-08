/*
1.Crie uma classe para representar uma pessoa,com os atributos privados de nome, idade e altura.
Crie os métodos públicos necessários para sets e gets e também um métodos para imprimir os dados de uma pessoa.
*/

#include <iostream>

using namespace std;

class Pessoa {
	private:
	string nome;
	int idade;
	float altura;

	public:
	Pessoa(){
		this-> nome = "";
		this-> idade = 0;
		this-> altura = 0;
	}
	string get_nome(){return nome;}
	int get_idade(){return idade;}
	float get_altura(){return altura;}
	void set_altura(float altura){
    	this -> altura = altura;
  	}
	void set_idade(int idade){
    	this -> idade = idade;
  	}
	void set_nome(string nome){
    	this -> nome = nome;
  	}
};

int main(){
	string nome;
	int idade;
	float altura;
	Pessoa *p1 = new Pessoa();
	cout << "Digite o nome da pessoa:" << endl;
	getline(cin, nome);

	cout << "Digite a idade da pessoa:" << endl;
	cin >> idade;
	
	cout << "Digite a altura da pessoa:" << endl;
	cin >> altura;

	p1->set_nome(nome);
	p1->set_idade(idade);
	p1->set_altura(altura);
	cout << "Nome: " << p1->get_nome() << endl;
	cout << "Idade: " << p1->get_idade() << endl;
	cout << "Altura: " << p1->get_altura() << endl;
	return 0;
}
