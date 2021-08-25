#include "funzioni.hpp"
#include <fstream>
#include <iostream>
using namespace std;
ifstream in;
ofstream out;

int Conta(){
    in.open("dati.dat");
    double a;
    int conta=0;
    while(!in.eof()){
        in>>a;
        conta=conta+1;
    }
    in.close();
    return conta;
}

void Carica(double *p, int limite){
    double a;
    in.open("dati.dat");
    for(int i=0; i<limite; i++){
        in>>a;
        p[i]=a;
    }
    in.close();
    return;
}

void ScambioPD(double *p, int limite){
    int t;
    if (limite%2 == 0){
        for (int i=0; i<limite; i++){
            t=p[i];
            p[i]=p[i+1];
            p[i+1]=t;
            i++;
        }
    }
    if (limite%2 != 0){
        for (int i=0; i<limite-1; i++){
            t=p[i];
            p[i]=p[i+1];
            p[i+1]=t;
            i++;
        }
    }
    return;
}

void Stampa(double *p, int limite){
    out.open("output.dat");
    for(int i=0; i<limite; i++){
        out<<p[i]<<endl;
    }
    return;
}
