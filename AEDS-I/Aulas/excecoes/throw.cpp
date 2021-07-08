#include <iostream>
#include <stdexcept>

using namespace std;

int fatorial(int n){
    if(n < 0){
        throw invalid_argument ("Não existe fatorial de n < 0 \n");
    }
    if(n >= 20){
        throw overflow_error ("Não é possível computar fatoriais de números >= 20 \n");
    }
    if(n <= 1){
        return 1;
    }
    return n * fatorial(n-1);
}

int main(){
    int num;
    cout << "Entre com um número para descobrir seu fatorial:" << endl;
    cin >> num;
    try {
        cout << num << "! = " << fatorial(num) << endl;
    } catch (exception &e){
        cout << e.what();
    } 
    return 0;
}
