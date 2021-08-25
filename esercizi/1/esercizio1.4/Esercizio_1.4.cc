#include <iostream>
#include <fstream>
#include <cmath>
#include "funzioni_modulo.hh"

using namespace std;


int main(){
	cout<<"Digitare il numero di cui si vuole calcolare il modulo"<<endl;
	double a, mod;
	cin>>a;
	mod = modulo(a);
	cout<<"il modulo del numero digitato è: "<<mod<<endl;
	cout<<endl;
	
	double mod2;
	int n;
	double vett[2];
	cout<<"Inserire le due componenti del vettore di cui si vuole calcolare il modulo"<<endl;
	for(int i=0;i<2;i++){
		cin>>vett[i];
		}
	mod2=modulo(vett[0], vett[1]);
	cout<<"Il modulo del vettore è "<<mod2<<endl;
	cout<<endl;
	ifstream infile("data.txt");
	int N;
	infile>>N;
	
	double* v=new double [N];
	for (int i=0;i<N; i++){
		infile>>v[i];
		}
	double mod3;
	mod3=modulo(v, N);
	cout<<"Il modulo del vettore caricato dal file data.txt è: "<<mod3<<endl;
	cout<<endl;
	infile.close();
	infile.clear(); 

	return 0;
}



	
	
