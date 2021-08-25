#ifndef __funz__
#define __funz__


class FunzioneBase{

public:
	virtual double Eval(double x) const=0;
};



class Parabola : public FunzioneBase{
	//f(x) = ax2 + bx + c
private:
	double _a,_b,_c;
	
public:
	Parabola();
	Parabola(double a, double b, double c);
	~Parabola();
	
	virtual double Eval(double x) const;
	void setA(double a)	{_a=a;};
	void setB(double b)	{_b=b;};
	void setC(double c)	{_c=c;};
	double getA() const	{return _a;};
	double getB() const	{return _b;};
	double getC() const	{return _c;};
	
};

class Seno : public FunzioneBase{

private:
	double _A, _omega, _phi;	//in radianti

public:

	Seno();
	Seno(double A, double omega, double phi);	
	~Seno();
	virtual double Eval(double x) const;
	
	
	void setA(double A){_A=A;};
	double getA(){return _A;};	
	void setOmega(double omega){_omega=omega;};
	double getOmega(){return _omega;};
	void setPhi(double phi){_phi=phi;};
	double getPhi(){return _phi;};
	
};

class Gaussiana : public FunzioneBase{

public:

	Gaussiana(double mu, double sigma);
	void setMu(double mu){_mu=mu;};
	void setSigma(double sigma){_sigma=sigma;};
	virtual double Eval(double x) const;
	double getMu(){return _mu;};
	double getSigma(){return _sigma;};

private:
	double _mu;
	double _sigma;

};







#endif
