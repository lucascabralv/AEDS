#include <iostream>
#include "navegador.h"
using namespace std;

Navegador::Navegador(){
    this-> count = 0;
}
void Navegador::abrirGuia(string titulo, string url){
    if(count < MAXTAM){
        this->guias[count] = new Guia(titulo, url);
        count++;
        cout << "Guia criada com sucesso" << endl;
    } else {
        cout << "Limite de guias alcançado!" << endl;
    }
}
void Navegador::fecharGuia(int n){
    string resp;
    cout << "Tem certeza que fechará essa guia? [s/n]" << endl;
    cin >> resp;
    if(resp == "s" || resp == "S"){
        if(guias[n] != NULL){
            delete guias[n];
            count --;
            for(int i = n; i < count; i++){
                guias[i] = guias[i+1];
            }
            cout << "Guia fechada com sucesso" << endl;
        }
    }
}
void Navegador::listarGuias(){
    for(int i = 0; i < count; i ++){
        cout << "["<< i << "]" << guias[i]->getTitulo() << endl;
    }
}