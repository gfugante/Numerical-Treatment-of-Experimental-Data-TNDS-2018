#include <iostream>
#include "Vettore.h"

using namespace std;

int main(){
	Vettore* a = new Vettore(10);
	for(unsigned int i=0; i<a->getN();i++) a->setComponente(i,10.*i);
	cout<<"Vettore a iniziale:"<<endl;
	for(unsigned int i=0; i<a->getN();i++) cout<<i<<")"<<a->getComponente(i)<<endl;
	if(a->getN()>0){
		Vettore b=(*a);
		cout<<"Vettore b iniziale:"<<endl;
			for(unsigned int i=0; i<b.getN();i++) cout<<i<<")"<<b.getComponente(i)<<endl;
			for(unsigned int i=0; i<b.getN();i++) b.setComponente(i,9.*i);
		cout<<"Vettore b modificato:"<<endl;
		for(unsigned int i=0; i<b.getN();i++) cout<<i<<")"<<b.getComponente(i)<<endl;
	}
	cout<<"Vettore a:"<<endl;
		for(unsigned int i=0; i<a->getN();i++) cout<<i<<")"<<a->getComponente(i)<<endl;
	delete a;
	return 0;
}
