#include <iostream>
#include "Particella.h"



int main(){

	Particella *a = new Particella(1.,1.6E-19);
	Elettrone *e = new Elettrone();
	CorpoCeleste *c = new CorpoCeleste("Terra",5.9742E24,6.372797E6);

	std::cout<< a->getMassa() <<","<< a->getCarica() <<std::endl;
	a->print();

	std::cout<< e->getMassa() <<","<< e->getCarica() <<std::endl;
	e->print();

	std::cout<< c->getMassa() <<","<< c->getCarica() <<std::endl;
	c->print();


	Particella b(*a);
	Particella d(*e);
	//Elettrone f(*d);

	//CorpoCeleste g;
	CorpoCeleste g("Test",0.,0.);

	g=(*c);
	g.print();


}
