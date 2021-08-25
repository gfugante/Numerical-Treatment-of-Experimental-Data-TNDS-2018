#include <iostream>
using namespace std;


void scambiabyvalue (double a, double b){
	
	double c;
	c=a;
	a=b;
	b=c;
	
	return;
}
void scambiabyreference (double &a, double &b){

	double c;
	c=a;
	a=b;
	b=c;
	
	return;
}

void scambiabypointer (double *a , double *b){

	double c;
	c= *a;
	*a=*b;
	*b=c;
	return;
}


