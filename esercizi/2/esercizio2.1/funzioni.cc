#include <iostream>
using namespace std;

int Nscambi=0;
int numeroscambi(){
	return Nscambi;
}


void scambiabyvalue (double a, double b){
	static int Ns=0;
	double c;
	c=a;
	a=b;
	b=c;
	Ns++;
	Nscambi++;
	cout<<"scambi effettuati"<<Ns<<endl;
	return;
}
void scambiabyreference (double &a, double &b){
	static int Ns=0;
	double c;
	c=a;
	a=b;
	b=c;
	Ns++;
	Nscambi++;
	cout<<"scambi effettuati"<<Ns<<endl;
	return;
}

void scambiabypointer (double *a , double *b){
	static int Ns=0;
	double c;
	c= *a;
	*a=*b;
	*b=c;
	Ns++;
	Nscambi++;
	cout<<"scambi effettuati"<<Ns<<endl;
	return;
}


