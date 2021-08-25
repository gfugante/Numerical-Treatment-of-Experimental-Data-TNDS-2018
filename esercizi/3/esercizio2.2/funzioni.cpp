#include "funzioni.hpp"
#include <iostream>
#include <fstream>
#include <cmath>
#include "math.h"
#include <iomanip>
using namespace std;
ifstream in;
ofstream out;

struct Vettore read(unsigned int N, const char* filename)
{
    struct Vettore vec;
    vec.N=N;
    vec.v= new double[N];
    ifstream in(filename);
    if(!in) {
        cerr<<"Cannot open "<<endl;
        }
        else {
            for (unsigned int i=0; i<N; i++) {
                in>> vec.v[i];
                if (in.eof() ) {
                    cerr<<"Stop after "<<i<<" entries!"<<endl;
                    break;
                }
            }
        }
        return vec;
        }
        
void print(const struct Vettore vec, const char* filename){
	out.open(filename);
            int width = int(log10(vec.N)+1);
            for(unsigned int i=0; i<vec.N; i++){
                out<<setw(width)<<i<<") "<<vec.v[i]<<endl;
            }
	out.close();
        }
        
void scambia(double &a, double &b)
        {
            double x;
            x = a;
            a = b;
            b = x;
        }
        
void ordina(struct Vettore v)
{
    for(int i=0; i<(v.N -1); i++)
    {
        for(int j=i+1; j<v.N; j++)
        {
            if(v.v[i]>v.v[j])
            {
                scambia(v.v[i], v.v[j]);
            }
        }
    }
}
