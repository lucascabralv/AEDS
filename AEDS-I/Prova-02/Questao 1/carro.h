#ifndef CARRO_H
#define CARRO_H
#include <iostream>
using namespace std;

class Carro{
    private:
        string nome;
        int anoFab;
        string cor;
        float consumo;
    public:
        Carro();
        Carro(string nome, int anoFab, string cor, float consumo);
        void setNome(string nome);
        void setAnoFab(int anoFab);
        void setCor(string cor);
        void setConsumo(float consumo);
        string getNome();
        int getAnoFab();
        string getCor();
        float getConsumo();
        void printaInfoPessoa();
};

#endif