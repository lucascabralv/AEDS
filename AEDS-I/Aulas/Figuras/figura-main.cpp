#include "figura.h"

int main(){
    Figura *figs[3];

    figs[0] = new Circulo(3, "Verde", true);
    figs[1] = new Quadrado(5, "Azul", false);
    figs[2] = new Retangulo(3, 5, "Cinza", true);

    for(int i = 0; i < 3; i++){
        cout << "A área da figura " << i << " é: " << figs[i]->getArea() << endl;
        cout << "O perímetro da figura " << i << " é: " << figs[i]->getPerimetro() << endl;
        cout << "-------------" << endl;
    }

    return 0;
}