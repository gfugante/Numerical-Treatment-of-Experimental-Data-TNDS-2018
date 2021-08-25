void esperimentoPrisma::execute{//o usare il set???
	_t0_misurato=_generator.Gauss(_t0_input, _sigmat);
	_t1_misurato=_generator.Gauss(_t1_input, _sigmat);
	_t2_misurato=_generator.Gauss(_t2_input, _sigmat);
	}

void esperimentoPrisma::analize{
	_n1_misurato=sin((_t1_misurato-_t0_misurato+_alpha)/2)/(sin(_alpha/2))
	_n2_misurato=sin((_t2_misurato-_t0_misurato+_alpha)/2)/(sin(_alpha/2))
	_A_misurato=(pow(_lambda2, 2)*pow(_n2_misurato, 2)-pow(_lambda1, 2)*pow(_n1_misurato, 2))/(pow(_lambda2, 2)-pow(_lambda1, 2));
	_B_misurato=(pow(_n2_misurato, 2)-pow(_n1_misurato, 2))/(pow(_lambda2, -2)-pow(_lambda1, -2));
	}
//MAIN
#include "vettoredati.h"
#include "esperimentoprisma.h"
#include <iostream>
//aggiungere cmath nel .cpp di esperimento prisma


double media0, media1, media2, devst0, devst1, devst2;
esperimentoPrisma p;
vettoreDati t0[10000];
vettoreDati t1[10000];
vettoreDati t2[10000];
//vettoreDati n1[10000];		//SERVE???
//vettoreDati n2[10000];
//vettoreDati A[10000];
//vettoreDati B[10000];
vettoreDati diffdm1[10000];
vettoreDati diffdm2[10000];
vettoreDati diffn1[10000];
vettoreDati diffn2[10000];
vettoreDati diffA[10000];
vettoreDati diffB[10000];
//Parte 1
for (int i=0, i<10000; i++){
	execute();
	t0[i]=p.getT0misurato();
	t1[i]=p.getT1misurato();
	t2[i]=p.getT2misurato();
	analize();
	//n1[i]=p.getN1misurato();
	//n2[i]=p.getN2misurato();
	//A[i]=p.getAmisurato();
	//B[i]=p.getAmisurato();
	diffdm1[i]=abs((p.getT1misurato-p.getT0misurato)-(p.getT1input-p.getT0input))
	diffdm2[i]=abs((p.getT2misurato-p.getT0misurato)-(p.getT2input-p.getT0input))
	diffn1[i]=abs(p.getN1misurato()-p.getN1input);
	diffn2[i]=abs(p.getN2misurato()-p.getN2input);
	diffA[i]=abs(p.getAmisurato()-p.getAinput);
	diffB[i]=abs(p.getBmisurato()-p.getBinput);
} //ciclo che fa 10000 volte l'esperimento aggiungere robe istogramma
media0=t0.media();
media1=t1.media();
media2=t2.media();
devst0=t0.devst();
devst1=t1.devst();
devst2=t2.devst();
cout<<"media t0="<<media0<<" "<<"media t1="<<media1<<" "<<"media t2="<<media2<<endl;
cout<<"dev.st t0="<<devst0<<" "<<"dev.st t1="<<devst1<<" "<<"dev.st t2="<<devst2<<endl;



