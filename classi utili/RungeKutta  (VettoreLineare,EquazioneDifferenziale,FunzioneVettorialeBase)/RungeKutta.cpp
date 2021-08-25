#include "EquazioneDifferenziale.h"
#include "RungeKutta.h"
#include "VettoreLineare.h"

RungeKutta::RungeKutta() 
{ }

RungeKutta::~RungeKutta() 
{ }

VettoreLineare RungeKutta::Passo(double t, const VettoreLineare& inizio, double h, FunzioneVettorialeBase *f) const
{
	unsigned int n = inizio.GetN();
	VettoreLineare rk( n );
	VettoreLineare k1( n );
	VettoreLineare k2( n );
	VettoreLineare k3( n );
	VettoreLineare k4( n );

	k1 = f->Eval(t, inizio);
	k2 = f->Eval(t + h/2., inizio + k1 * h/2.);
	k3 = f->Eval(t + h/2., inizio + k2 * h/2.);
	k4 = f->Eval(t + h/2., inizio + k3 * h/2.);

	rk = inizio + (k1/2. + k2 + k3 + k4/2.) * h/3.;

	return rk;
}
