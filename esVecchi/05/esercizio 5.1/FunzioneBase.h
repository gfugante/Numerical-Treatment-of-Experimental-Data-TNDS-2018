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



#endif
