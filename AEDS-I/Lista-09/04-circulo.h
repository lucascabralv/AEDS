#include <iostream>

using namespace std;

class Circulo{
	private:
        float raio;
        float x;
        float y;
        float distancia(float x2, float y2);
        float area();
        float circunferencia();

    public:
        Circulo();
        void setRaio(float raio);
        void setPosition(float x, float y);
        void aumentaRaio(float percent);
        void printRaio();
        void printDistancia(float x2, float y2);
        void printArea();
        void printCentro();
        float getX();
        float getY();
};
