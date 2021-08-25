#include "FunzioneBase.h"
#include "Solutore.h"

int sign(double);

Solutore::Solutore(){}
Solutore::~Solutore(){}

double Bisezione::CercaZeri(double a, double b, const FunzioneBase *f){

	if(f->Eval(a)==0){return a;}
	if(f->Eval(b)==0){return b;}

	double t,c,x;
	int i;

	for(i=0;;i++){
		c= a + 0.5*(b-a);
		if(f->Eval(c)==0){x=c;break;}
		if(sign(f->Eval(c))*sign(f->Eval(a))==-1){b=c;}
		else{a=c;}
		t = b-a;
		if(unsigned (t)<getPrecision()){x=0.5*(b-a);break;}
		setInterazioni(i);
	}
	
	return x;

}

Bisezione::~Bisezione(){}
Bisezione::Bisezione() : Solutore::Solutore(){}


int sign(double a){
	if(a>0){return 1;}
	else{return -1;}
}
