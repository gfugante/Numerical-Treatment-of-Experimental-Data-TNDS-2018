#include "particella.hh"
#include "posizione.hh"
#include <iostream>

using namespace std;

int main(){
	corpoceleste*t=new corpoceleste ("Terra", 5.973E24, 6.371E3,3.844E5,0,0 );//si è considerato come origine del sistema di riferimento cartesiano il centro della luna e si è calcolato il potenziale ipotizzando che Terra, Sole e Luna giacciano tutti allineati sull'asse x
	corpoceleste*s=new corpoceleste ("Sole", 1.989E30, 6.957E5,150E9,0,0);
	posizione l (0, 0, 0);
	cout<<"Caratteristiche Terra:"<<endl;
	t->printCorpoceleste();	
	cout<<"Caratteristiche Sole: "<<endl;
	s->printCorpoceleste();
	cout<<endl;
	cout<<"Potenziale esercitato dalla terra sulla luna (p): "<<endl;
	cout<</*"r="<<t->p.distanza(l)<<*/" p="<<t->potenziale(l)<<" J/Kg"<<endl;
	cout<<"Potenziale eserciato dal sole sulla luna (p):"<<endl;
	cout<</*"r="<<s->p.distanza(l)<<*/" p="<<s->potenziale(l)<<" J/Kg"<<endl;
	
	
	return 0;
}
