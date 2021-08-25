#ifndef _equazioniDifferenziali_h_
#define _equazioniDifferenziali_h_

#include "VettoreLineare.h"

class FunzioneVettorialeBase: public Vettore //classe astratta: i metodi non sono implementati
{
	public:
		virtual VettoreLineare eval(double t, const VettoreLineare &x) const =0;
		virtual double getOmega0() const =0;
};

class EquazioneDifferenzialeBase //classe astratta
{
	public:
		virtual VettoreLineare passo(double t, const VettoreLineare& inizio, double h, FunzioneVettorialeBase *f) const =0;
};

class oscillatoreArmonico: public FunzioneVettorialeBase
{
	private:
		double _omega0;
	public:
		oscillatoreArmonico(double omega0);
		~oscillatoreArmonico() { };
		virtual double getOmega0() const {return _omega0;}
		virtual VettoreLineare eval(double t, const VettoreLineare& x) const;
};

class Eulero: public EquazioneDifferenzialeBase
{
	public:
		//Eulero();
		//~Eulero() {};
		virtual VettoreLineare passo(double t, const VettoreLineare& inizio, double h, FunzioneVettorialeBase *f) const;
};

class RungeKutta: public EquazioneDifferenzialeBase
{
	public:
		virtual VettoreLineare passo(double t, const VettoreLineare& inizio, double h, FunzioneVettorialeBase *f) const;
};

#endif
