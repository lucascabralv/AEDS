#include <iostream>
using namespace std;

#define ARRAY_MAX 10

void maior_menor(int arrayNum[]){
    int maior, menor;
    maior = arrayNum[0];
    menor = arrayNum[0];
    for(int i = 0; i < ARRAY_MAX-1; i++){
        if (maior < arrayNum[i+1]){
            maior = arrayNum[i+1];
        }
        if(menor > arrayNum[i+1]){
            menor = arrayNum[i+1];
        }
    }
    cout << "\n -> O maior número é o: " << maior << endl;
    cout << " -> O menor número é o: " << menor << endl;
}

int main(){
    int arrayNum[ARRAY_MAX] = {12,34,45,-2,35,11,-9,1,2,77};
    maior_menor(arrayNum);
    cout << "\n";
    return 0;
}