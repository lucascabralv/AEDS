#include <iostream>

using namespace std;

class Elevador{
	private:
		int andarAtual; // Andar em que o elevador se encontra
		int numPessoas; // Número de pessoas que estão no elevador
		int totalAndares; // Número total de andares no prédio (sem o térreo)
		int capacidade; // Número de pessoas máximas no elevador
	public:
		Elevador();
		Elevador(int, int);
		void adicionaPessoa();
		void retiraPessoa();
		void sobe();
		void desce();
		int getTotalAndares();
		int getCapacidade();
		int getAndarAtual();
		int getNumPessoas();
};