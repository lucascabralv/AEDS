#include <iostream>

using namespace std;

class Retangulo {
  private:
  int altura;
  int largura;

  public:
  Retangulo(){
    altura = 0;
    largura = 0;
  }
  Retangulo(int altura, int largura){
    this -> altura = altura;
    this -> largura = largura;
  }

  void set_altura(int altura){
    this -> altura = altura;
  }
  void set_largura(int largura){
    this -> largura = largura;
  }
  int get_altura(){ return altura; }
  int get_largura(){ return largura; }

  int area(){
    return altura * largura;
  }
  int perimetro(){
    return 2 * (largura + altura);
  }
};

class Quadrado :public Retangulo{
  private:
  int lado;

  public:
  Quadrado(int lado) : Retangulo(lado, lado){
    this -> lado = lado;
  }

};

int main() {
  //Retangulo r1;
  //r1.set_altura(10); //EXEMPLO

  Retangulo *r1 = new Retangulo();
  r1->set_altura(20);
  r1->set_largura(20);

  cout << "\nÁrea do retângulo " << r1->area() << endl;
  cout << "\nPerímetro do retângulo " << r1->perimetro() << endl;

  Quadrado *q1 = new Quadrado(10);
  cout << "\nÁrea do quadrado " << q1->area() << endl;
  cout << "\nPerímetro do quadrado " << q1->perimetro() << endl;

  return 0;
}
