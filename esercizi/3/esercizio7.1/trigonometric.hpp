#ifndef trigonometric_hpp
#define trigonometric_hpp
#include "funzionebase.h"

class Seno: public FunzioneBase{
public:
	Seno();
    Seno(double a, double b);
    virtual double Eval(double x) const;
    double GetA() {return _a;}
    double GetB() {return _b;}
    void SetA(double x) {_a=x;}
    void SetB(double y) {_b=y;}
private:
    double _a, _b;
};

class Coseno: public FunzioneBase{
public:
    Coseno(double a, double b);
    virtual double Eval(double x) const;
    double GetA() {return _a;}
    double GetB() {return _b;}
    void SetA(double x) {_a=x;}
    void SetB(double y) {_b=y;}
private:
    double _a, _b;
};

#endif /* trigonometric_hpp */
//F(X)=ASIN(BX)
//F(X)=ACOS(BX)
