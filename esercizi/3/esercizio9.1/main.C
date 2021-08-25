#include "funzionebase.h"
#include "integrale.hpp"
#include "random.hpp"
#include "trigonometric.hpp"
#include "math.h"
#include <iostream>
#include <fstream>
using namespace std;

ifstream input;
ofstream output;
int main(){
	FunzioneBase *F=new Seno(1,1);
	Integral H(0,M_PI, F);
    output<<"Passo  Errore"<<endl;
	output.open("HitOrMiss.txt");
	double x;
	for(int i=100; i<10000; i=i+100){
		x=H.HM1(i, 1,0);
		output<<i<<"  "<<x<<endl;
	}
	output.close();
	output.open("Media.txt");
    output<<"Passo  Errore"<<endl;
	for(int i=100; i<10000; i=i+100){
		x=H.Media1(i);
		output<<i<<"  "<<x<<endl;
	}
	output.close();
	return 0;
}
