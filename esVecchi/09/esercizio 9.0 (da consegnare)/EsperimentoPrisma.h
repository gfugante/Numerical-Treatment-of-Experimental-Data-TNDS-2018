#ifndef __espprisma__
#define __espprisma__

#include "Random.h"
#include "FunzioneBase.h"

class EsperimentoPrisma{

public:
	EsperimentoPrisma();
	~EsperimentoPrisma();
	
	void esegui();
	void analizza();
	
	double getL1(){return _lambda1;};
	double getL2(){return _lambda2;};
	double getAlpha(){return _alpha;};
	double getSigmat(){return _sigmat;};
	double getAin(){return _A_in;};
	double getA(){return _A_mis;};
	double getBin(){return _B_in;};
	double getB(){return _B_mis;};
	double getN1in(){return _n1_in;};
	double getN1(){return _n1_mis;};
	double getN2in(){return _n2_in;};	
	double getN2(){return _n2_mis;};	
	double getT0in(){return _t0_in;};
	double getT0(){return _t0_mis;};	
	double getT1in(){return _t1_in;};	
	double getT1(){return _t1_mis;};	
	double getT2in(){return _t2_in;};	
	double getT2(){return _t2_mis;};
	double getDm1(){return _dm1;};
	double getDm2(){return _dm2;};
	
			
private:
	Random _generatore;
	double _lambda1, _lambda2, _alpha, _sigmat;
	double _A_in, _A_mis;
	double _B_in, _B_mis;
	double _n1_in, _n1_mis;
	double _n2_in, _n2_mis;
	double _t0_in, _t0_mis;
	double _t1_in, _t1_mis;
	double _t2_in, _t2_mis;
	double _dm1, _dm2;

};


#endif
