#ifndef Esperimentoprisma_h
#define Esperimentoprisma_h
#include "random.hpp"

class EsperimentoPrisma {

public:
	EsperimentoPrisma();
	//~EsperimentoPrisma();
	void Esegui();
	void Analizza();
	void SetT0mis(double a) {_t0_misurato=a;}
	void SetT1mis(double a) {_t1_misurato=a;}
	void SetT2mis(double a) {_t2_misurato=a;}
	double GetT0mis() {return _t0_misurato;}
	double GetT1mis() {return _t1_misurato;}
	double GetT2mis() {return _t2_misurato;}
	double GetAlpha() {return _alpha;}
	double GetLambda1() {return _lambda1;}
	double GetLambda2() {return _lambda2;}
	void SetN1mis(double a) {_n1_misurato=a;}
	void SetN2mis(double a) {_n2_misurato=a;}
	double GetN1mis() {return _n1_misurato;}
	double GetN2mis() {return _n2_misurato;}
	void SetAmis(double a) {_A_misurato=a;}
	void SetBmis(double a) {_B_misurato=a;}
	double GetAmis() {return _A_misurato;}
	double GetBmis() {return _B_misurato;}
	double GetT0inp() {return _t0_input;}
	double GetT1inp() {return _t1_input;}
	double GetT2inp() {return _t2_input;}
	double GetSigmaT() {return _sigmat;}
    double GetN1in() {return _n1_input;}
    double GetN2in() {return _n2_input;}
    double GetAin() {return _A_input;}
    double GetBin() {return _B_input;}

private:
	Random _generatore;
	double _lambda1, _lambda2, _alpha, _sigmat;
	double _A_input, _A_misurato;
	double _B_input, _B_misurato;
	double _n1_input, _n1_misurato;
	double _n2_input, _n2_misurato;
	double _t0_input, _t0_misurato;
	double _t1_input, _t1_misurato;
	double _t2_input, _t2_misurato;
	
};
#endif
