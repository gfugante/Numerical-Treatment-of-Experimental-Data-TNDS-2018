#include "esperimentoprisma.h"

esperimentoPrisma::esperimentoPrisma()://Queste sono le caratteristiche proprie del prisma
	_generator(1), 
	_lambda1(579.1E-9),
	_lambda2(404.7E-9),
	_alpha(60.*M_PI/180),
	_sigmat(0.3E-3),
	_A_input(2.7),
	_B_input(60000E-18)
{
	_n1_input=sqrt(_A_input+_B_input/(_lambda1*_lambda1)); //calcolo gli indici di rifrazione attesi
	_n2_input=sqrt(_A_input+_B_input/(_lambda2*_lambda2));
	// calcolo dei valori attesi degli angoli misurati
	_t0_input = M_PI/2.; //theta0 è arbitrario
	double dm;
	dm= 2.*asin(_n1_input*sin(0.5*_alpha))-_alpha;
	_t1_input=_t0_input + dm;
	
	dm= 2.*asin(_n2_input*sin(0.5*_alpha))-_alpha;
	_t2_input=_t0_input + dm;
	
	}

esperimentoPrisma::~esperimentoPrisma(){;}
void esperimentoPrisma::execute(){
	_generator.setMu(_t0_input);
	_generator.setSigma(_sigmat);
	_t0_misurato=_generator.GaussBM();
	_generator.setMu(_t1_input);
	_t1_misurato=_generator.GaussBM();
	_generator.setMu(_t2_input);
	_t2_misurato=_generator.GaussBM();
	}

void esperimentoPrisma::analize(){
	_n1_misurato=sin((_t1_misurato-_t0_misurato+_alpha)/2)/(sin(_alpha/2));
	_n2_misurato=sin((_t2_misurato-_t0_misurato+_alpha)/2)/(sin(_alpha/2));
	_A_misurato=(pow(_lambda2, 2)*pow(_n2_misurato, 2)-pow(_lambda1, 2)*pow(_n1_misurato, 2))/(pow(_lambda2, 2)-pow(_lambda1, 2));
	_B_misurato=(pow(_n2_misurato, 2)-pow(_n1_misurato, 2))/(pow(_lambda2, -2)-pow(_lambda1, -2));
	}
