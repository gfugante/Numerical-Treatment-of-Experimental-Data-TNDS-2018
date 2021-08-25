#ifndef _equazioniDifferenziali_h_
#define _equazioniDifferenziali_h_
#include "VettoreLineare.h"

class funzioneVettorialeBase: public vettore{
	public:
		virtual VettoreLineare eval(double t, const VettoreLineare &x) const =0;
};

class equazioniDifferenzialiBase{
	public:
		virtual VettoreLineare passo(double t, const VettoreLineare& inizio, double h, funzioneVettorialeBase *f) const =0;
};

class oscillatore_armonico: public funzioneVettorialeBase{
	private:
		double _omega0;
	public:
		oscillatore_armonico(double omega0);
		~oscillatore_armonico() {};
		void setfrequenza(double o) {_omega0=o;}
		double get_omega0() const {return _omega0;}
		virtual VettoreLineare eval(double t, const VettoreLineare& x) const;
};

class Eulero: public equazioniDifferenzialiBase{
	public:
		Eulero() {}
		virtual VettoreLineare passo(double t, const VettoreLineare& inizio, double h, funzioneVettorialeBase *f) const;
};

class Runge_Kutta: public equazioniDifferenzialiBase{
	public:
		Runge_Kutta() {}
		virtual VettoreLineare passo(double t, const VettoreLineare& inizio, double h, funzioneVettorialeBase *f) const;
};

#endif
