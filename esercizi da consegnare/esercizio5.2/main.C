#include <iostream>
#include <cmath>
#include <iomanip>

#include"FunzioneBase.h"
#include "Solutore.h"
using namespace std;

int main(){

	double a,b,c,x,y,e;
	
	cout<<"Inserire i parametri a,b,c della parabola:"<<endl;
	cin>>a>>b>>c;

	FunzioneBase *P = new Parabola(a,b,c);
	
	cout<<"Inserire l'intervallo [a,b] in cui cercare lo zero:"<<endl;
	cin>>x>>y;
	
	cout<<"Inserire una precisione epsilon:"<<endl;
	cin>>e;
	
	int cifreSignificative = -log10(e);	
	Bisezione *B = new Bisezione();
	B->setPrecision(e);
	

	cout<<"L'ascissa dello zero della funzione e':"<<endl;
	cout<<"x = "<<setprecision(cifreSignificative)<<B->CercaZeri(x,y,P)<<endl;






return 0;
}



