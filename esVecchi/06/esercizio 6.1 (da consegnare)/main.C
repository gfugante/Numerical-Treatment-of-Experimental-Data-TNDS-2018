#include <iostream>
#include "Vettore.h"
#include <time.h>
#include <string>
#include <iomanip>
using namespace std;

int main(){

	int n = 100000;
	double a,b,T1,T2,T3;
	clock_t t1,t2,t3;
	const	string c = "/home/comune/labTNDS_aa1112_materiale/lezione2/data.txt";
	//valutazione di a e b

	VettoreDati* v = new VettoreDati(n,c);

	t1 = clock();
	v->sort();
	t1 = clock()-t1;
	v->~Vettore();

	
	VettoreDati* w = new VettoreDati((2*n),c);

	t2 = clock();
	w->sort();
	t2 = clock()-t2;
	w->~Vettore();

	T1=double(t1)/CLOCKS_PER_SEC;
	T2=double(t2)/CLOCKS_PER_SEC;

	a = (T2-(2*T1))/(n*n);
	b = ((4*T1)-T2)/n;

	cout<<"La seguente tabella riporta i valori del tempo stimato e effettivo impiegato da un algoritmo di selection sort:"<<endl;
	cout<<endl;
	cout<<"stimato		effettivo		differenza"<<endl;

	int k;
	VettoreDati* x;
	for(unsigned int i=0;i<150; i+3){
 		k=i*1e3;
		x = new VettoreDati(i,c);
		
		t3 = clock();
		x->sort();
		t3 = clock()-t3;
		x->~Vettore();
		T3=double(t3)/CLOCKS_PER_SEC;

		T2 = (a*i*i)+(b*i);
		cout<<scientific<<setprecision(2)<<T2<<"		"<<T3<<"		"<<T2-T3<<endl;
	}

return 0;
}
