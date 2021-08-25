#include <iostream>
#include <fstream>
#include <time.h>
#include <iomanip>
#include "vettore.h"
#include "vettoredati.h"

using namespace std;

int main(){
	
	clock_t t;

	int N;
	cout<<"dammi le componenti da stampare"<<endl;
	cin>>N;
	vettoredati* a=new vettoredati(N, "data.txt");
	cout<<"vettore non ordinato"<<endl;
	a->print();
	t=clock();
	a->ordina();
	t=clock()-t;
	cout<<"vettore ordinato"<<endl;
	a->print();
	double p=float(t)/CLOCKS_PER_SEC;
	cout<<p<<endl;

	double x= (1.53-2*0.44)/(2*10000*10000);
	double y=(4*0.44-1.53)/(2*10000);
	double ts=x*N*N+y*N;
	cout<<"il tempo stimato con a="<<x<<", b="<<y<<", N="<<N<<" e': "<<ts<<endl;

	cout<<N<<setw(10)<<p<<setw(10)<<ts<<setw(10)<<p-ts<<endl;
	return 0;
}
	
