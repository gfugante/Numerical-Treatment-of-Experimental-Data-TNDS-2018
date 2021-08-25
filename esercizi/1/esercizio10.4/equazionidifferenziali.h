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

class pendolo: public funzioneVettorialeBase{
	
	public:
	pendolo(double l){m_l=l, m_g=9.81;} //sono metri al secondo quadrato
	~pendolo(){;}
	double getL()const{return m_l;}
	double getG()const{return m_g;}
	void setL(double l){m_l=l;}
	void setG(double g){m_g=g;}
	virtual vettoreLineare Eval (double t, const vettoreLineare& x)const;
	
	private:
	double m_l, m_g;
};

class oscillatoreForzato: public funzioneVettorialeBase{
	
	public:
	oscillatoreForzato(double w0,double alpha,double w){m_w0=w0, m_alpha=alpha, m_w=w;} //alpha e' il coeff di attrito
	~oscillatoreForzato(){;}
	double getW0()const{return m_w0;}
	double getW()const{return m_w;}
	double getAlpha()const{return m_alpha;}
	void setW0(double w0){m_w0=w0;}
	void setW(double w){m_w=w;}
	void setAlpha(double alpha){m_alpha=alpha;}
	virtual vettoreLineare Eval (double t, const vettoreLineare& x)const;
	
	private:
	double m_w0, m_w, m_alpha;
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



