#include "particella.hpp"
#include "corpoceleste.hpp"
#include "posizione.hpp"
#include <string>
#include <cmath>

using namespace std;

int main()
{
    CorpoCeleste S("Sole", 1.989E30, 695700E3);
	CorpoCeleste T("Terra",5.92e24,6371e3);
	CorpoCeleste L("Luna",7.34e22 ,1737e3);
    Posizione PS(0,0,0);
	Posizione tsP(147e9,0,0);
	Posizione tsA(152e9,0,0);
	Posizione tl(384400,0,0);
	Posizione slA(384400+152e9, 0, 0);
	Posizione slP(384400+147e9,0,0);
    S.SetPosizione(PS);
	T.SetPosizione(PS);
	cout<<"Il potenziale gravitazionale generato dalla terra sulla luna vale: "<<T.Potenziale(tl)<<" J/kg"<<endl;
	cout<<"Il potenziale gravitazionale generato dal sole sulla luna quando la terra e' in perielio vale: "<<S.Potenziale(slA)<<" J/kg"<<endl;
	cout<<"Il potenziale gravitazionale generato dal sole sulla luna quando la terra e' in afelio vale: "<<S.Potenziale(slP)<<" J/kg"<<endl;
	 cout<<"Il potenziale gravitazionale generato dal sole sulla terra in perielio vale: "<<S.Potenziale(tsP)<<" J/kg"<<endl;
	cout<<"Il potenziale gravitazionale generato dal sole sulla terra in afelio vale: "<<S.Potenziale(tsA)<<" J/kg"<<endl;
	
return 0;
}
