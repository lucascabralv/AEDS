#ifndef GUIA_H
#define GUIA_H
#include<iostream>

using namespace std;

class Guia{
    private:
        string id;
        string titulo;
        string url;

    public:
        Guia();
        Guia(string titulo, string url);
        void setId(string id);
        void setTitulo(string titulo);
        void setUrl(string url);
        string getId();
        string getTitulo();
        string getUrl();
};

#endif // !GUIA_H