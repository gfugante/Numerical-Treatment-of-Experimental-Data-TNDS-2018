#include <iostream>
#include <cmath>
#include <fstream>
#include "funzioni.h"

using namespace std;


int main(){

	double a,b;
	int c;

	cout<<"Inserire un numero: "<<endl;
	cin>>a;
	cout<<"|"<<a<<"| = "<<modulo(a)<<endl;

	cout<<"Inserire inserire le componenti di un vettore a due componenti: "<<endl;
	cin>>a>>b;
	cout<<"Il modulo del vettore è: "<<modulo(a,b)<<endl;

	ifstream inputFile("/home/comune/labTNDS_aa1011_materiale/lezione1/data.txt");
	inputFile>>c;
	double *v = new double[c];
	for(int i=0; i<c; i++){
		inputFile>>v[i];
	}
	inputFile.close();
	cout<<"Il modulo del vettore in 'data.txt' è: "<<modulo(v,c)<<endl;
	delete []v;

}


