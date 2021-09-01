#include <iostream>
using namespace std;

#define ARRAY_MAX 10

bool teste_numero(int arrayNum[]){
    int num;
    bool resp = false;

    cout << "Digite um número: ";
    cin >> num;
    
    for(int i = 0; i < ARRAY_MAX; i++){
        if(arrayNum[i] == num){
            resp = true;
            i = ARRAY_MAX;
        }
    }
    return resp;
}

int main(){
    int arrayNum[ARRAY_MAX] = {12,34,45,22,35,11,9,4,2,7};
    if(teste_numero(arrayNum)){
        cout << "\n -> O número está no array" << endl;
    } else {
        cout << "\n -> O número não está no array" << endl;
    }
    cout << "\n";
    return 0;
}