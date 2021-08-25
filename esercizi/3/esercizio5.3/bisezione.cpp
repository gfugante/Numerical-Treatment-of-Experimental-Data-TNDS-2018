#include "bisezione.hpp"
#include "solutore.h"
#include "funzionebase.h"
Bisezione::Bisezione(double a, double b, double eps, FunzioneBase *f){
    m_xmin=a;
    m_xmax=b;
    m_prec=eps;
    f=f;
}

int Bisezione::Sign(double x){
    if (x>0) return 1;
    else return -1;
}

double Bisezione::Cercazeri(){
    double xmed;
    double a=m_xmin, b=m_xmax;
//if(f->Eval(a)==0) {return a;}
  //  if(f->Eval(b)==0) {return b;}
//else{
        while(a-b>m_prec){
            xmed=a+(b-a)/2;
            if(f->Eval(xmed)==0) break;
            if(Sign(f->Eval(xmed))*Sign(f->Eval(a))<0) a=xmed;
            if(Sign(f->Eval(xmed))*Sign(f->Eval(b))<0) b=xmed;
        }
        return a+(b-a)/2;
    //}
}

bool Bisezione::Check(){
    if((f->Eval(m_xmin))*(f->Eval(m_xmax))<=0)
        return true;
    else return false;
}
