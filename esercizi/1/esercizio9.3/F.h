#ifndef _F_h_
#define _F_h_

#include "funzionebase.h"
#include <cmath>

class F : public funzioneBase { //funzione caratteristica

	public:

		F()  {;};
		~F() {;};

		double Eval(vettore& x) const ;

};

double VolumeIpersfera(int n, double r); // Dimensioni e raggio

#endif // _F_h_
