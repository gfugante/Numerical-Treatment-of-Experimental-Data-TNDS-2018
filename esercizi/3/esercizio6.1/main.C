#include "vettoredati.h"
#include "vettore.h"
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

int main(){
	cout<<"Inserire il numero di valori da ordinare"<<endl;
	int n;
	cin>>n;
	Vettoredati X(n, "data.txt");
	X.Ordina();
	X.Print(n, "risultati.txt");
	return 0;
}
