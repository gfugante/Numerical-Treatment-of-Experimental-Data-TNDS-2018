#include <iostream>
#include"FunzioneBase.h"

using namespace std;

int main(){

	double a,b,c;
	cin>>a>>b>>c;
	
	Parabola *P = new Parabola(a,b,c);
	
	double v = -b/(2*a);
	
	
	cout<<P->Eval(v)<<endl;
	return 0;
}
