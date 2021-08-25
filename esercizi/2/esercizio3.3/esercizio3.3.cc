#include <iostream>
#include "particelle.h"
#include "elettrone.h"
#include "corpo_celeste.h"
#include "posizione.h"

using namespace std;

int main(){
	corpo_celeste sole("Sole", 1.9891e30, 6.95475e8);
	corpo_celeste terra("Terra", 5.9742E24, 6.372797E6);
	posizione r;
	double d_luna=384400;

	//terra tra sole e luna
	terra.setposizione(1.496e11,0,0);

	r.setposizione(terra.getx()+d_luna,0,0);

	sole.printposizione();
	terra.printposizione();
	cout<<"distanza tra terra e sole è"<<sole.getdistanza(terra.getposizione())<<"Km"<<endl;
	cout<<"distanza tra terra e luna è"<<sole.getdistanza(r)<<"Km"<<endl;
	
	cout<<"terra posizionata tra sole e luna"<<endl;
	cout<<"potenziale terra su luna"<<terra.getpotenziale(r)<<"J/Kg"<<endl;
	cout<<"potenziale sole su luna"<<sole.getpotenziale(r)<<"J/Kg"<<endl;
	cout<<"rapporto tra potenziale sole e potenziale terra su luna"<<sole.getpotenziale(r)/terra.getpotenziale(r)<<endl;

	//luna tra terra e sole
	r.setposizione(terra.getx()-d_luna,0,0);

	cout<<"luna posizionata tra sole e terra"<<endl;
	cout<<"potenziale terra su luna"<<terra.getpotenziale(r)<<"J/Kg"<<endl;
	cout<<"potenziale sole su luna"<<sole.getpotenziale(r)<<"J/Kg"<<endl;
	cout<<"rapporto tra potenziale sole e potenziale terra su luna"<<sole.getpotenziale(r)/terra.getpotenziale(r)<<endl;

return 0;
}
