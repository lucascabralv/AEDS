#ifndef NAVEGADOR_H
#define NAVEGADOR_H

#include <iostream>
#include "guia.h"

using namespace std;

#define MAXTAM 100

class Navegador{
    private:
        Guia *guias[MAXTAM];
        int count;

    public:
        Navegador();
        void abrirGuia(string titulo, string url);
        void fecharGuia(int n);
        void listarGuias();

};

#endif