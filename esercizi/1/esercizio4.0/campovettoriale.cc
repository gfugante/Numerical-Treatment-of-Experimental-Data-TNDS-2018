#include "campovettoriale.hh"
#include <cmath>
using namespace std;

campoVettoriale::campoVettoriale():posizione(){
	for (int i=0;i<3;i++){
		_F[i]=0.;
		}
	}

campoVettoriale::campoVettoriale(const posizione&a){
	_p=a;
	for (int i=0;i<3;i++){
		_F[i]=0.;
		}
	}

campoVettoriale::~campoVettoriale(){
	
	}

double campoVettoriale::modulo() const{
	return sqrt(pow(getFx(),2)+pow(getFy(),2)+pow(getFz(),2));
	}

void campoVettoriale::somma (const campoVettoriale&a){
		setFx(getFx()+a.getFx());
		setFy(getFy()+a.getFy());
		setFz(getFz()+a.getFz());
		}
	



