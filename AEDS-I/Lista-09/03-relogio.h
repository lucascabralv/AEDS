#include <iostream>

using namespace std;

class Relogio{
	private:
		int hora;
		int minuto;
		int segundo;
	public:
		Relogio();
		void setHora(int hora, int minuto, int segundo);
		void horaUp();
		void minutoUp();
		void segundoUp();
		string getHora();
};