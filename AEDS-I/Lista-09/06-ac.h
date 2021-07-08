#include <iostream>

using namespace std;

class ArCondicionado{
	private:
		int potencia;
		float tempExtenrna;
		float tempResultante;

	public:
		ArCondicionado();
		ArCondicionado(int potencia, float tempExterna);
		float getTempResultante();
		int getPotencia();
		float getTempExterna();
};
