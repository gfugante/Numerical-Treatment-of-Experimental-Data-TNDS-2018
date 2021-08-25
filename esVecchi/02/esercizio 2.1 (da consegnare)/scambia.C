#include <iostream>
using namespace std;


int Nscambi = 0;

int numeroscambi(){return Nscambi;}

void scambiaByValue(double a,double b,int d){
	static int Ns = 0;
	double c=a;
	a=b;
	b=c;
	Ns++;
	Nscambi++;
	if(Ns==d/2){cout<<"Numero scambi per valore effettuati: " << Ns <<endl;}

}


void scambiaByRef(double &a,double &b,int d){
	static int Ns = 0;
	double c=a;
	a=b;
	b=c;
	Ns++;
	Nscambi++;
	if(Ns==d/2){cout<<"Numero scambi per referenza effettuati: " << Ns <<endl;}

}


void scambiaByPointer(double *a,double *b, int d){
	static int Ns = 0;
	double c=*a;
	*a=*b;
	*b=c;
	Ns++;
	Nscambi++;
	if(Ns==d/2){cout<<"Numero scambi per puntatore effettuati: " << Ns <<endl;}

}
