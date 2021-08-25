#include <iostream>
#include <iomanip>
#include <fstream>
#include "scambia.h"

using namespace std;


int main(){
	
	int a;

	ifstream inputFile("/home/comune/labTNDS_aa1011_materiale/lezione1/data.txt");
	ofstream outputFile("output.txt");
	inputFile>>a;
	outputFile<<"Il vettore ha "<<a<<" elementi, che sono i seguenti:"<<endl;

	double *vett = new double[a];

	for(int i=0; i<a; i++){
		inputFile>>vett[i];	
	}
	inputFile.close();

	for(int i=0; i<a; i++){
		scambia(&vett[i],&vett[i+1]);
		i++;
	}
	for(int i=0; i<a; i++){
		outputFile<<vett[i]<<endl;	
	}
	outputFile.close();
	delete[] vett;

}

