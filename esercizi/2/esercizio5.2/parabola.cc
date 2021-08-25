#include <iostream>
#include "funzioneBase.h"
#include "parabola.h"

using namespace std;

parabola:: parabola(double a, double b, double c){
	_a=a;
	_b=b;
	_c=c;
}

double parabola::eval(double x) const{
	return _a*(x*x)+_b*x+_c;
}

void parabola::setA(double a){
	_a=a;
}

double parabola::getA(){
	return _a;
}

void parabola::setB(double b){
	_b=b;
}

double parabola::getB(){
	return _b;
}

void parabola::setC(double c){
	_c=c;
}

double parabola::getC(){
	return _c;
}

parabola::~parabola(){};
