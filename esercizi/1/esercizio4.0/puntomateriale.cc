#include "puntomateriale.hh"
#include <cmath>

puntoMateriale::puntoMateriale ():particella(),posizione(){
	}

puntoMateriale::puntoMateriale (double m,double q,double x, double y,double z):particella(m,q),posizione(x,y,z){
	}

puntoMateriale::~puntoMateriale(){
	} 

double puntoMateriale::moduloElettrico(const posizione& r)const{
	double k=1/(4*M_PI*8.8544E-12);
	double d=distanza(r);
	return k*getCarica()/(pow(d,2));
	}

double puntoMateriale::moduloGravitazionale(const posizione& r)const{
	double g=6.67E-11;
	double d=distanza(r);
	return getMassa()*g/pow(d,2);
	}

campoVettoriale puntoMateriale::campoElettrico(const posizione& r)const{
	campoVettoriale F(r);
	double fx,fy,fz;
	double k=1/(4*M_PI*8.8544E-12);
	fx=k*getCarica()*(r.x()-x())/(pow(distanza(r),3));
	fy=k*getCarica()*(r.y()-y())/(pow(distanza(r),3));
	fz=k*getCarica()*(r.z()-z())/(pow(distanza(r),3));
	F.setFx(fx);
	F.setFy(fy);
	F.setFz(fz);
	return F;
}

campoVettoriale puntoMateriale::campoGravitazionale(const posizione& r)const{
	campoVettoriale F(r);
	double fx,fy,fz;
	double k=6.67E-11;
	fx=k*getMassa()*(r.x()-x())/(pow(distanza(r),3));
	fy=k*getMassa()*(r.y()-y())/(pow(distanza(r),3));
	fz=k*getMassa()*(r.z()-z())/(pow(distanza(r),3));
	F.setFx(fx);
	F.setFy(fy);
	F.setFz(fz);
	return F;
}
	 
	
	

	
	


