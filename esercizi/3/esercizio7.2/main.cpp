#include <iostream>
#include <math.h>
#include "integrale.hpp"
#include "funzionebase.h"
#include "trigonometric.hpp"
#include <cmath>

using namespace std;

int main() {
    double a=0;
    double b=M_PI;
	FunzioneBase *seno=new Seno();
    	Integral *integrale=new Integral(a,b,seno);
	double prec;
	cout<<"Inserire la precisione: "<<endl;
	cin>>prec;
	double trapezoidifixed=integrale->TrapezoidiFixed(prec);
	cout<<trapezoidifixed<<endl;
    return 0;
}

 
	
