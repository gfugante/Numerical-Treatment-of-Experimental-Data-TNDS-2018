#include "posizione.hpp"
#include <iostream>
#include <cstdlib>

using namespace std;

int main(int argc, char** argv)
{
    if(argc!=4)
    {
        std::cerr<<"Usage: "<<argv[0]<<" <x> <y> <z>"<<endl;
        return -1;
    }
    
    double x=atof(argv[1]);
    double y=atof(argv[2]);
    double z=atof(argv[3]);
    
    Posizione P(x,y,z);
    cout<<"Coordinate cartesiane: "<<P.X() <<","<<P.Y()<<","<<P.Z()<<endl;
    cout<<"Coordinate cilindriche: "<<P.Rho()<<","<<P.Phi()<<","<<P.Z()<<endl;
    cout<<"Coordinate sferiche: "<<P.R()<<","<<P.Phi()<<","<<P.Theta()<<endl;
    
    return 0;
    
}
