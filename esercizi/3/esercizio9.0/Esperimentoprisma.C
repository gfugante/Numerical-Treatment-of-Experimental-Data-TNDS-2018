#include "gaussiana.h"
#include "random.hpp"
#include "Esperimentoprisma.h"
#include "math.h"
#include <cmath>

EsperimentoPrisma::EsperimentoPrisma() :
	_generatore(1),
	_lambda1(579.1E-9),
	_lambda2(404.7E-9),
	_alpha(60.*M_PI/180.),
	_sigmat(0.3E-3),
	_A_input(2.7),
	_B_input(60000E-18)
	{
		_n1_input = sqrt(_A_input+_B_input/ (_lambda1*_lambda1));
		_n2_input = sqrt(_A_input+_B_input/ (_lambda2*_lambda2));
		_t0_input = M_PI/2.;
		double dm;
		dm= 2.*asin(_n1_input*sin(0.5*_alpha))-_alpha;
		_t1_input=_t0_input+dm;
		dm= 2.*asin(_n2_input*sin(0.5*_alpha))-_alpha;
		_t2_input=_t0_input+dm;
	}

void EsperimentoPrisma::Esegui() {
	SetT0mis(_generatore.BMGauss(_t0_input, _sigmat));
	SetT1mis(_generatore.BMGauss(_t1_input, _sigmat));
	SetT2mis(_generatore.BMGauss(_t2_input, _sigmat));
	}

void EsperimentoPrisma::Analizza() {
	double dm1=GetT1mis()-GetT0mis();
	double dm2=GetT2mis()-GetT0mis();
	SetN1mis(((sin((dm1+GetAlpha())/2)/sin(GetAlpha()/2))));
	SetN2mis(((sin((dm2+GetAlpha())/2)/sin(GetAlpha()/2))));
	SetAmis((pow(GetLambda2()*GetN2mis(),2)-pow(GetLambda1()*GetN1mis(),2))/(pow(GetLambda2(),2)-pow(GetLambda1(),2)));
	SetBmis((pow(GetN2mis(),2)-pow(GetN1mis(),2))/(pow(GetLambda2(),-2)-pow(GetLambda1(),-2)));
	}
