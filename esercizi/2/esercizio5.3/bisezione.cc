#include "solutore.h"
#include "funzioneBase.h"
#include "meccquant.h"
#include "segno.h"
#include "bisezione.h"

using namespace std;

bisezione::bisezione(){}

double bisezione::cercaZeri(double xmin, double xmax, double prec, const funzioneBase * f){
	while((xmax-xmin)>prec){
		double xM=(xmax+xmin)/2;
		if(f->eval(xM)==0){
			break;
		}else{
			if(sign(f->eval(xM))*sign(f->eval(xmin))<0){
				xmax=xM;
			}else{
				xmin=xM;
			}
		}	
	
	};
	return ((xmax+xmin)/2);
}

bisezione::~bisezione(){};
