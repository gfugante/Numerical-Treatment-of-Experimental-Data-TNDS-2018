#include <iostream>
#include <fstream>
#include "scambia.h"

using namespace std;


int main(){

	int a;
	int NsByValue = 20;
	int NsByRef =20;
	int NsByPointer =20;

	ifstream inputFile("/home/comune/labTNDS_aa1011_materiale/lezione1/data.txt");
	inputFile>>a;
	cout<<"Il vettore ha "<<a<<" elementi, che sono i seguenti:"<<endl;

	double *vett = new double[a];



	for(int i=0; i<a; i++){
		inputFile>>vett[i];	
	}
	inputFile.close();


	for(int i=0; i<NsByPointer; i++){
		scambiaByPointer(&vett[i],&vett[i+1],NsByPointer);
		i++;
	}
	
	
	for(int i=0; i<NsByRef; i++){
		scambiaByRef(vett[i],vett[i+1],NsByRef);
		i++;
	}
	
	
	for(int i=0; i<NsByValue; i++){
		scambiaByValue(vett[i],vett[i+1],NsByValue);
		i++;
	}
	
		
	cout<<"Sono stati effettuati "<<numeroscambi()<<" scambi"<<endl;
	delete[] vett;






}
