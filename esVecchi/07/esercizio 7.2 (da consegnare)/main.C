#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include "FunzioneBase.h"
#include "Integrale.h"



using namespace std;


int main(int argc, char **argv){
	if(argc!=4){
		cout<<"Usage: "<<argv[0]<<" <a> <b> <epsilon> "<<endl;
		return -1;
	}	


	FunzioneBase* seno = new Seno();

	Integral* integrale = new Integral(atof(argv[1]),atof(argv[2]),atof(argv[3]),seno);

	cout<<"Il valore dell'integrale approssimato con un errore di "<<atof(argv[3])<<" é: "<<integrale->trapezi()<<endl;


	



}
