#ifndef _Random_h
#define _Random_h



#include<cmath>
class Random{
	public:
	//Per generarre numeri uniformi da 0 a 1
	Random (int seed){ _seed=seed; _a=1664525; _c=1013904223; _m=pow(2, 31), _mu=0.; _sigma=1.; _x0=_mu-5*_sigma;  _x1=_mu+5*_sigma; }
	~Random(){ ;}
	void setA(int a){_a=a;}
	void setC(int c){_c=c;}
	void setM(int m){_m=m;}
	void setSeed(int seed){_seed=seed;}
	double Rand();
	
	//Per la gaussiana
	void setMu(double mu){_mu=mu;}
	void setSigma(double sigma){_sigma=sigma;}
	double Gauss();	
	void setX0(int a){_x0=a;}
	void setX1(int c){_x1=c;}
	double getX0()const {return _x0;}
	double getX1() const {return _x1;}
	
	private:
	unsigned int _a;
	unsigned int _c;
	unsigned int _m;
	unsigned int _seed;

	//per la gaussiana
	double _mu; 
	double _sigma;
	double _x0; //estremi intervallo
	double _x1;

};
#endif

