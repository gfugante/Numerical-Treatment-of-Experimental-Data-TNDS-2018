#ifndef _ESPERIMENTOPRISMA_H_
#define _ESPERIMENTOPRISMA_H_

#include "random.h"

class esperimentoPrisma {
	public:
		esperimentoPrisma();
		~esperimentoPrisma();
		void execute(); //una misura
		void analize();
		//metodi get per i datamembtri
		double getLambda1() const {return _lambda1;}
		double getLambda2() const {return _lambda2;}
		double getAlpha() const {return _alpha;}
		double getSigmat() const {return _sigmat;}
		Random getGenerator() const {return _generator;} //SERVE????
		
		double getAinput() const {return _A_input;}
		double getBinput() const {return _B_input;}
		double getN1input() const {return _n1_input;}
		double getN2input() const {return _n2_input;}
		double getT0input() const {return _t0_input;}
		double getT1input() const {return _t1_input;}
		double getT2input() const {return _t2_input;}
		
		double getAmisurato() const {return _A_misurato;}
		double getBmisurato() const {return _B_misurato;}
		double getN1misurato() const {return _n1_misurato;}
		double getN2misurato() const {return _n2_misurato;}
		double getT0misurato() const {return _t0_misurato;}
		double getT1misurato() const {return _t1_misurato;}
		double getT2misurato() const {return _t2_misurato;}
		
		//metodi set per i datamenbri (SERVONO????)
		void setLambda1(double a)  { _lambda1=a;}
		void setLambda2(double a)  { _lambda2=a;}
		void setAlpha(double a)  { _alpha=a;}
		void setSigmat(double a) { _sigmat=a;}
		
		
		void setAinput(double a) {_A_input=a;}
		void setBinput(double a) {_B_input=a;}
		void setN1input(double a) {_n1_input=a;}
		void setN2input(double a) {_n2_input=a;}
		void setT0input(double a) {_t0_input=a;}
		void setT1input(double a) {_t1_input=a;}
		void setT2input(double a) {_t2_input=a;}
		
		void setAmisurato(double a){ _A_misurato=a;}
		void setBmisurato(double a){ _B_misurato=a;}
		void setN1misurato(double a){ _n1_misurato=a;}
		void setN2misurato(double a){ _n2_misurato=a;}
		void setT0misurato(double a){ _t0_misurato=a;}
		void setT1misurato(double a){ _t1_misurato=a;}
		void setT2misurato(double a){ _t2_misurato=a;}
		
	
	private:
		//generatore di numeri casuali da usare in execute ()
		Random _generator;
		//parametri dell'apparato sperimentale
		double _lambda1, _lambda2, _alpha, _sigmat;
		// valori delle quantità misurabili:
		// _input:	valore assunto come ipotesi nella simulazione
		// _misurato:	valore misurato, calcolato in execute () e analize();
		double _A_input, _A_misurato;
		double _B_input, _B_misurato;
		double _n1_input, _n1_misurato;
		double _n2_input, _n2_misurato;
		double _t0_input, _t0_misurato;
		double _t1_input, _t1_misurato;
		double _t2_input, _t2_misurato;
		
};

#endif
