#include <cmath>
#include "VettoreLineare.h"
#include "equazioniDifferenziali.h"

using namespace std;

oscillatore_armonico::oscillatore_armonico(double omega0){
	_omega0 = omega0;
}

VettoreLineare oscillatore_armonico::eval(double t, const VettoreLineare& x) const{
	VettoreLineare osc(2);
	osc.setComponenti(0, x.getComponenti(1));
	osc.setComponenti(1, (-x.getComponenti(0)*pow(_omega0, 2)));
	return osc;
}

VettoreLineare Eulero::passo(double t, const VettoreLineare& inizio, double h, funzioneVettorialeBase *f) const{
	VettoreLineare eul(inizio.getN());
	eul=inizio+f->eval(t, inizio)*h;
	return eul;
}

VettoreLineare Runge_Kutta::passo(double t, const VettoreLineare& inizio, double h, funzioneVettorialeBase *f) const{

	VettoreLineare k1(inizio.getN());
	VettoreLineare k2(inizio.getN());
	VettoreLineare k3(inizio.getN());
	VettoreLineare k4(inizio.getN());

	k1=f->eval(t,inizio);
	k2=f->eval(t+h/2, inizio+k1*(h/2));
	k3=f->eval(t+h/2, inizio+k2*(h/2));
	k4=f->eval(t+h, inizio+k3*h);
	
	return inizio+((k1+k2*2+k3*2+k4)*(h/6));
}
