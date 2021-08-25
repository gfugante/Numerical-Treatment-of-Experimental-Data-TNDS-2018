#include "parabola.h"

parabola::parabola(){
		_a=1;
		_b=1;
		_c=1;}

parabola::parabola(double a,double b,double c){
		_a=a;
		_b=b;
		_c=c;}
		
parabola::~parabola(){}

double parabola::Eval(double x) const{
		return getA()*x*x+getB()*x+getC();
		}
