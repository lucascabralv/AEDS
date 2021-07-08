#ifndef ITEM_H
#define ITEM_H

#include <iostream>
using namespace std;

class Item{
    protected:
        string nome;
        float preco;
    public:
        Item();
        Item(string nome, float preco);
        string getNome();
        float getPreco();
        void setNome(string nome);
        void setPreco(float preco);
        virtual string toString()=0;
};

class Livro : public Item {
    private:
        string autor;
    public:
        Livro();
        Livro(string nome, float preco, string autor);
        string getAutor();
        void setAutor(string autor);
        string toString();
}; 

class CD : public Item {
    private:
        int numfaixas;
    public:
        CD();
        CD(string nome, float preco, int numfaixas);
        int getNumFaixas();
        void setAutor(int numfaixas);
        string toString();
};

class DVD : public Item {
    private:
        float duracao;
    public:
        DVD();
        DVD(string nome, float preco, float duracao);
        float getDuracao();
        void setDuracao(float duracao);
        string toString();
}; 

#endif