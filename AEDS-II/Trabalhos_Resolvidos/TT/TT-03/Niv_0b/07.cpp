// A diferença entre as funções é que na "m1" ele primeiro retorna i e depois subtrai uma unidade;
// Já na "m2" o i é subtraído em uma unidade e depois retornado.

#include <iostream>
using namespace std;

int m1(int i){
    return i--;
}

int m2(int i){
    return --i;
}

int main(){
    int i;
    cout << "Digite um número: ";
    cin >> i;
    cout << "m1 = " << m1(i) << endl;
    cout << "m2 = " << m2(i) << endl;
    return 0;
}