#ifndef _EQUAZIONIDIFFERENZIALI_h_
#define _EQUAZIONIDIFFERENZIALI_h_

#include "vettorelineare.h"
#include<cmath>

class funzioneVettorialeBase{
	
	public:
	virtual vettoreLineare Eval (double t, const vettoreLineare&x) const=0;
};

class equazioneDifferenzialeBase{
	public:
	virtual vettoreLineare Passo(double t, const vettoreLineare& inizio, double h, funzioneVettorialeBase *f) const =0;
};

class oscillatoreArmonico: public funzioneVettorialeBase{
	
	public:
	oscillatoreArmonico(double omega0){m_omega0=omega0;}
	~oscillatoreArmonico(){;}
	double getOmega0()const{return m_omega0;}
	void setOmega0(double newomega){m_omega0=newomega;}
	virtual vettoreLineare Eval (double t, const vettoreLineare& x)const;
	
	private:
	double m_omega0;
};

class Eulero: public equazioneDifferenzialeBase{
	public:
	Eulero(){;}
	~Eulero(){;}
	virtual vettoreLineare Passo(double t, const vettoreLineare& x, double h, funzioneVettorialeBase*f) const;
};

class RungeKutta: public equazioneDifferenzialeBase{
	public:
	RungeKutta(){;}
	~RungeKutta(){;}
	virtual vettoreLineare Passo(double t, const vettoreLineare& x, double h, funzioneVettorialeBase*f) const;
};

#endif



