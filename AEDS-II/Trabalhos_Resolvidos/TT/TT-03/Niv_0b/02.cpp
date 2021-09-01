#include <iostream>
using namespace std;

#define ARRAY_MAX 10

bool teste_numero(int arrayNum[]){
    int num;
    bool resp = false;

    cout << "Digite um número: ";
    cin >> num;

    int e = 0, d = ARRAY_MAX -1, meio;

    while(e <= d){
        meio = (e + d) / 2;
        if(arrayNum[meio] == num){
            resp = true;
            break;
        }else if(arrayNum[meio] > num){
            d = meio - 1;
        }else {
            e = meio + 1;
        }
    }
    return resp;
}

int main(){
    int arrayNum[ARRAY_MAX] = {10,11,12,13,14,15,16,17,18,19};
    if(teste_numero(arrayNum)){
        cout << "\n -> O número está no array" << endl;
    } else {
        cout << "\n -> O número não está no array" << endl;
    }
    cout << "\n";
    return 0;
}