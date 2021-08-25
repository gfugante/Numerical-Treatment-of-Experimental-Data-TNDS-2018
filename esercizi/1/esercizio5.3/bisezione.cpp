#include "bisezione.h"

bisezione::bisezione(){
	_prec=1E-9;}

bisezione::bisezione(double prec, double xmin, double xmax){
		_prec=prec;
		_a=xmin;
		_b=xmax;
		_zero=false;
		}

double bisezione::cercaZeri(double xmin, double xmax, const funzioneBase* f){
		int count=0;
		double xm;
		if (sign(f->Eval(xmin))*sign(f->Eval(xmax))==-1){
			while (count<1000){
				xm=(xmin+xmax)/2;
				if (sign(f->Eval(xm))*sign(f->Eval(xmax))==-1){
					xmin=xm;}

				else if(sign(f->Eval(xmin))*sign(f->Eval(xm))==-1){
					xmax=xm;
					}
				else if(f->Eval(xm)==0)
					{return xm;}

				if(abs(xmin-xmax)<=getPrecision()){
					_zero=true;  //aggiunto
					return (xmin+xmax)/2;
				}
				
				count++;				
			
			}
			if (count==1000){
				cout<<endl<<endl<<"Ho fatto 1000 iterazioni, sono troppe."
				    <<" Fermare il programma"<<endl;
			}
		}

		else { 
			cout<<endl<<endl<<"Non e' stato scelto un intervallo contenente zeri, oppure ne contiene più di uno e l'algoritmo non funziona"<<endl<<endl;
				
			}
}

