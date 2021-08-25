#include "vettoredati.h"
#include <string>
#include <fstream>
#include <iostream>
#include "vettore.h"
#include <cmath>

using namespace std;

ifstream in;
ofstream out;

Vettoredati::Vettoredati(unsigned int N) {
	_N=N;
	_v=new double [N];
	for(int i=0; i<N; i++)
	{
		_v[i]=0;
	}
}

Vettoredati::Vettoredati(unsigned int N, const char* Namefile){
	in.open(Namefile);
	_N=N;
	_v=new double [N];
	for(int i=0; i<N; i++)
	{
		in>>_v[i];
	}
	in.close();
}

void Vettoredati::Print(int N){
	for(int i=0; i<N; i++)
	{	
		cout<<"("<<i+1<<")"<<_v[i]<<endl;
	}
}

void Vettoredati::Print(int N, const char* Namefile){
	out.open(Namefile);
	for(int i=0; i<N; i++)
	{	
		out<<"("<<i+1<<")"<<_v[i]<<endl;
	}
	out.close();
}

void Vettoredati::Ordina()
{
    for(int i=0; i<_N -1; i++)
    {
        for(int j=i+1; j<_N; j++)
        {
            if(_v[i]>_v[j])
            {
                double c;
								c=_v[i];
								_v[i]=_v[j];
								_v[j]=c;
            }
        }
    }
}

double Vettoredati::Media(){
	double somma=0;
	for(int i=0; i<_N; i++){
		somma+=_v[i];
	}
	return somma/_N;
}

double Vettoredati::Sigma(){
	double media=Media();
	double scartoquad=0.;
	for(int i=0; i<_N; i++){
		scartoquad+=pow(_v[i]-media,2);
	}	
	return sqrt(scartoquad/_N);
}

