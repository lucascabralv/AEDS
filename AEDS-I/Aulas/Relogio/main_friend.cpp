#include <iostream>
#include "relogio.h"
#include "mensagem.h"

int main(){
    Relogio r(9,20, 0);
    Mensagem m;
    m.imprimir(r);
    return 0;
}