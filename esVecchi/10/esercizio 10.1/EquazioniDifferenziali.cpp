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
 
	osc.SetComponent(0, x.GetComponent(1) ); 
	osc.SetComponent( 1, ( -x.GetComponent(0) * pow(_omega0,2) ) ); 
	
	return osc; 
} 

VettoreLineare Eulero::passo(double t, const VettoreLineare& inizio, double h, FunzioneVettorialeBase *f) const
{ 
	VettoreLineare eul( inizio.GetN() ); 
	
	eul = inizio + f->eval(t, inizio) * h; 
	
	return eul; 
}

VettoreLineare RungeKutta::passo(double t, const VettoreLineare& inizio, double h, FunzioneVettorialeBase *f) const
{
	VettoreLineare rk( inizio.GetN() );
	VettoreLineare k1( inizio.GetN() );
	VettoreLineare k2( inizio.GetN() );
	VettoreLineare k3( inizio.GetN() );
	VettoreLineare k4( inizio.GetN() );

	k1 = f->eval(t, inizio);
	k2 = f->eval(t + h/2, inizio + h/2 * k1);
	k3 = f->eval(t + h/2, inizio + h/2 * k2);
	k4 = f->eval(t + h/2, inizio + h/2 * k3);

	rk = inizio + h/3 * (k1/2 + k2 + k3 + k4/2);

	return rk;
}
