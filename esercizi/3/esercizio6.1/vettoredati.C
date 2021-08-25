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
	m_N=N;
	m_v=new double [N];
	for(int i=0; i<N; i++)
	{
		m_v[i]=0;
	}
}

Vettoredati::Vettoredati(unsigned int N, const char* Namefile){
	in.open(Namefile);
	m_N=N;
	m_v=new double [N];
	for(int i=0; i<N; i++)
	{
		in>>m_v[i];
	}
	in.close();
}

void Vettoredati::Print(int N){
	for(int i=0; i<N; i++)
	{	
		cout<<"("<<i+1<<")"<<m_v[i]<<endl;
	}
}

void Vettoredati::Print(int N, const char* Namefile){
	out.open(Namefile);
	for(int i=0; i<N; i++)
	{	
		out<<"("<<i+1<<")"<<m_v[i]<<endl;
	}
	out.close();
}

void Vettoredati::Ordina()
{
    for(int i=0; i<m_N -1; i++)
    {
        for(int j=i+1; j<m_N; j++)
        {
            if(m_v[i]>m_v[j])
            {
                double c;
		c=m_v[i];
		m_v[i]=m_v[j];
		m_v[j]=c;
            }
        }
    }
}

double Vettoredati::Media(){
	double somma=0;
	for(int i=0; i<m_N; i++){
		somma=somma+m_v[i];
	}
	return somma/m_N;
}

double Vettoredati::Sigma(){
	double media=Media();
	double scartoquad=0;
	for(int i=0; i<m_N; i++){
		scartoquad=scartoquad+pow(m_v[i]-media,2);
	}	
	return sqrt(scartoquad/m_N);
}

