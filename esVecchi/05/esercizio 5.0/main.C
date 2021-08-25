#include <iostream>
#include "Particella.h"
using namespace std;

int main(){
Particella *a=new Particella (1. ,2.);
Particella *b=new Elettrone ();
Particella *c=new CorpoCeleste ("Terra", 1. ,2.);

a->print();
b->print();
c->print();

delete a;
delete b;
delete c;

return 0;
}
