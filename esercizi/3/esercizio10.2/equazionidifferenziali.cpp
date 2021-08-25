#include "equazionidifferenziali.h"

vettoreLineare oscillatoreArmonico::Eval (double t, const vettoreLineare& x)const{
	vettoreLineare d (x.getN()); //vettore derivate
	d.setComponent(0,x.getComponent(1));
	d.setComponent(1,-getOmega0()*getOmega0()*x.getComponent(0));
	return d;
}

vettoreLineare pendolo::Eval (double t, const vettoreLineare& x)const{
	vettoreLineare d (x.getN()); 
	d.setComponent(0,x.getComponent(1));
	d.setComponent(1,-getG()/getL()*sin(x.getComponent(0)));
	return d;
}	
// f mi serve per passare eval
vettoreLineare Eulero::Passo (double t, const vettoreLineare& x, double h, funzioneVettorialeBase*f) const{
	vettoreLineare r(x.getN());
	r=x+(f->Eval(t,x))*h;

	return r;
}


vettoreLineare RungeKutta::Passo (double t, const vettoreLineare& x, double h, funzioneVettorialeBase*f) const{
	vettoreLineare r(x.getN());
	vettoreLineare k1(x.getN());
	vettoreLineare k2(x.getN());
	vettoreLineare k3(x.getN());
	vettoreLineare k4(x.getN());
	k1=(f->Eval(t,x));
	k2=(f->Eval(t+h/2,x+k1*(h/2)));
	k3=(f->Eval(t+h/2,x+k2*(h/2)));
	k4=(f->Eval(t+h,x+k3*h));
	r=x+(k1+k2*2+k3*2+k4)*(h/6);

	return r;
}


	
