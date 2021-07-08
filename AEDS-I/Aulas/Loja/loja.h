#ifndef LOJA_H
#define LOJA_H

#include "item.h"

class Loja{
    protected:
        Item *itens[5];
        int count;
    public:
        Loja();
        int getCount();
        void addItem();
        void showItens();
};

#endif 