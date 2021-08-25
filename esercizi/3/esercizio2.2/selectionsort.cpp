#include "funzioni.hpp"
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <fstream>
#include <cmath>

using namespace std;

int main(int argc, char** argv)
{
    if(argc<3){
        cerr<<"Usage: "<<argv[0]<<" <N_points> <filename>"<<endl;
        return -1;}
    
    unsigned int N = atoi(argv[1]);
    struct Vettore v = read(N,argv[2]);
    print(v, "before.dat");
    ordina(v);
    print(v, "after.dat");
    delete[] v.v;
    return 0;
}
