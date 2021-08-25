#include <iostream>
#include <cstdlib>
#include "Posizione.h"
#include "Particella.h"
#include<iomanip>

using namespace std;

int main(){							

	
	CorpoCeleste *terra = new CorpoCeleste("Terra",5.2796e24,6.372797E6);
	CorpoCeleste *sole = new CorpoCeleste("Sole",1.9891e30,6.9547e8);
	CorpoCeleste *luna = new CorpoCeleste("Luna",7.342e22,1.738e3);

	Posizione *S = new Posizione();
	Posizione *T = new Posizione(1.496e8,0.,0.);
	Posizione *L = new Posizione(1.492156e8,0.,0.);

	sole->setPosizione(*S);
	terra->setPosizione(*T);
	luna->setPosizione(*L);


	cout<<endl;
	cout<<"1° caso: la Luna si trova tra il Sole e la Terra"<<endl;
	
	cout<<"Il potenziale generato dal Sole sulla Luna è: "<<setprecision(3)<<sole->potenziale(*L)<<" N/kg"<<endl;

	cout<<"Il potenziale generato dalla Terra sulla Luna è: "<<setprecision(3)<<terra->potenziale(*L)<<" N/kg"<<endl;

	cout<<endl;



	Posizione *L1 = new Posizione(1.499844e8,0.,0.);
	luna->setPosizione(*L1);

	cout<<"2° caso: la Luna si trova alla massima distanza dal Sole"<<endl;
	
	cout<<"Il potenziale generato dal Sole sulla Luna è: "<<setprecision(3)<<sole->potenziale(*L1)<<" N/kg"<<endl;

	cout<<"Il potenziale generato dalla Terra sulla Luna è: "<<setprecision(3)<<terra->potenziale(*L1)<<" N/kg"<<endl;
	cout<<endl;
}
