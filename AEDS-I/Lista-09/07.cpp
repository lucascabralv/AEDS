#include <iostream>
#include "07-carro.h"

using namespace std;

int main(){
	Carro *c1 = new Carro();
	Carro *c2 = new Carro();
	c1->abastecer(20);
	c2->abastecer(30);
	c1->mover(200);
	c2->mover(400);
	c1->getStatus();
	c2->getStatus();
	return 0;
}