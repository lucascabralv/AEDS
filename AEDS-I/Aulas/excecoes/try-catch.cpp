#include <iostream>

using namespace std;

string pega_sub_string(string str, int k){
    return str.substr(k);
}

string le_entrada(){
    string texto;
    while(1){
        try {
            getline(cin, texto);
            return pega_sub_string(texto, 10);
        } catch(out_of_range &e) {
            cerr << "Entrada invalida!\n -> Digite novamente:";
        }
    }
}

int main(){
    cout << "Digite algo: ";
    cout << le_entrada() << endl;
    return 0;
}