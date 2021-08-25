#include "EsperimentoPrisma.h"
#include "Random.h"
#include "FunzioneBase.h"
#include <cmath>

using namespace std;


EsperimentoPrisma::EsperimentoPrisma() :
	_generatore(1), //qui e' l'unico necessario perche' invoco il costruttore di Random
	_lambda1(579.1E-9),
	_lambda2(404.7E-9),
	_alpha(60.*M_PI/180.),
	_sigmat(0.3E-3),
	_A_in(2.7),
	_B_in(60000E-18)

{

	_n1_in = sqrt(_A_in+_B_in/pow(_lambda1,2));
	_n2_in = sqrt(_A_in+_B_in/pow(_lambda2,2));
	_t0_in = M_PI/2.;

	double dm = 2.*asin(_n1_in*sin(0.5*_alpha))-_alpha;
	_t1_in = _t0_in + dm;

	dm = 2.*asin(_n2_in*sin(0.5*_alpha))-_alpha;
	_t2_in = _t0_in + dm;

}

EsperimentoPrisma::~EsperimentoPrisma(){ }

void EsperimentoPrisma::esegui(){
	
	Gaussiana G(_t0_in, _sigmat);
	_t0_mis = _generatore.AccRej(_t0_in - 3*_sigmat,_t0_in + 3*_sigmat, &G);
	G.SetMi(_t1_in);
	_t1_mis = _generatore.AccRej(_t1_in - 3*_sigmat,_t1_in + 3*_sigmat, &G);
	G.SetMi(_t2_in);
	_t2_mis = _generatore.AccRej(_t2_in - 3*_sigmat,_t2_in + 3*_sigmat, &G);
}

void EsperimentoPrisma::analizza(){

	_dm1 = _t1_mis - _t0_mis;
	_n1_mis = sin((_dm1+_alpha)*0.5)/sin(0.5*_alpha);
	
	_dm2 = _t2_mis - _t2_mis;
	_n2_mis = sin((_dm2+_alpha)*0.5)/sin(0.5*_alpha); 


	_A_mis = (pow(_lambda2,2)*pow(_n2_mis,2)-pow(_lambda1,2)*pow(_n1_mis,2))/(pow(_lambda2,2)-pow(_lambda1,2));
	_B_mis = (pow(_n2_mis,2)-pow(_n1_mis,2))/(pow(_lambda2,-2)-pow(_lambda1,-2));
}



