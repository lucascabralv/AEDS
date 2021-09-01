#include <iostream>
using namespace std;

#define ARRAY_MAX 10

void ordena(int arrayNum[]){
    for(int i = 0; i < ARRAY_MAX-1; i++){
        for(int j = 1; j < ARRAY_MAX; j++){
            int aux;
            if(arrayNum[i] > arrayNum[j]){
                aux = arrayNum[j];
                arrayNum[j] = arrayNum[i];
                arrayNum[i] = aux;
            }
        }
    }
}

int main(){
    int arrayNum[ARRAY_MAX] = {12,34,45,-2,35,11,-9,1,2,77};
    ordena(arrayNum);
    cout << "O menor número é o:" << arrayNum[0] << endl;
    cout << "O maior número é o: " << arrayNum[ARRAY_MAX - 1] << endl;
    cout << "\n";
    return 0;
}