#include <cmath>

#include "VettoreLineare.h" 
#include "EquazioniDifferenziali.h" 


using namespace std;

oscillatoreArmonico::oscillatoreArmonico(double omega0)
{ 
	_omega0 = omega0; 
} 

VettoreLineare oscillatoreArmonico::eval(double t, const VettoreLineare& x) const
{ 
	VettoreLineare osc(2);
 
	osc.setComponent(0, x.getComponent(1) ); 
	osc.setComponent( 1, ( -x.getComponent(0) * pow(_omega0,2) ) ); 
	
	return osc; 
} 

VettoreLineare Eulero::passo(double t, const VettoreLineare& inizio, double h, FunzioneVettorialeBase *f) const
{ 
	VettoreLineare eul( inizio.getN() ); 
	
	eul = inizio + f->eval(t, inizio) * h; 
	
	return eul; 
}

VettoreLineare RungeKutta::passo(double t, const VettoreLineare& inizio, double h, FunzioneVettorialeBase *f) const
{
	int n = inizio.getN();
	VettoreLineare rk(n);
	VettoreLineare k1(n);
	VettoreLineare k2(n);
	VettoreLineare k3(n);
	VettoreLineare k4(n);

	k1 = f->eval(t, inizio);
	k2 = f->eval(t + h/2, inizio + k1 * h/2);
	k3 = f->eval(t + h/2, inizio + k2 * h/2);
	k4 = f->eval(t + h/2, inizio + k3 * h/2);

	rk = inizio + ((k1/2 + k2 + k3 + k4/2) * h/3);

	return rk;
}
