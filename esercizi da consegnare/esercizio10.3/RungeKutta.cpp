#include "EquazioneDifferenziale.h"
#include "RungeKutta.h"
#include "VettoreLineare.h"

RungeKutta::RungeKutta() 
{ }

RungeKutta::~RungeKutta() 
{ }

VettoreLineare RungeKutta::Passo(double t, const VettoreLineare& inizio, double h, FunzioneVettorialeBase *f) const
{
	VettoreLineare rk( inizio.GetN() );
	VettoreLineare k1( inizio.GetN() );
	VettoreLineare k2( inizio.GetN() );
	VettoreLineare k3( inizio.GetN() );
	VettoreLineare k4( inizio.GetN() );

	k1 = f->Eval(t, inizio);
	k2 = f->Eval(t + h/2., inizio + k1 * h/2.);
	k3 = f->Eval(t + h/2., inizio + k2 * h/2.);
	k4 = f->Eval(t + h/2., inizio + k3 * h/2.);

	rk = inizio + (k1/2. + k2 + k3 + k4/2.) * h/3.;

	return rk;
}
