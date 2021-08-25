#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>

#include "Modulo.h"


using namespace std;

int main ()
{
    cout << "Punto 1" << endl;
    cout << "Il programma verifica la precisione del calcolatore per eseguire determinate operazioni." << endl;
    
    cout << scientific << setprecision (2) << endl;
    cout << "0.3 - 0.2 - 0.1 = " << 0.3 - 0.2 - 0.1 << endl;
    cout << "0.3 - (0.2 + 0.1) = " << 0.3 - (0.2 + 0.1) << endl << endl;

    cout << "0.4 - 0.3 - 0.1 = " << 0.4 - 0.3 - 0.1 << endl;
    cout << "0.4 - (0.3 - 0.1) = " << 0.4 - (0.3 - 0.1) << endl << endl;

    cout << "(1E15 + 1) - 1E15 = " << (1E15 + 1) - 1E15 <<  endl;
    cout << "(1E16 + 1) - 1E16 = " << (1E15 + 1) - 1E15 <<  endl;
    cout << "__________________________________________________________________________________________" << endl;

    cout << endl << endl << "Punto 2" << endl;

    cout << "--------------------------------------------------" << endl;
    cout << setw(30) << "f(x) con errore" << setw(20) << "f(x) migliorato" << endl;
    cout << "--------------------------------------------------" << endl;

    for (double x = 1; x <= 1E18; x = x * 10)
    {
        cout << "f(" << x << ") = " << setw(15) << sqrt(x+1) - sqrt(x) 
             << setw(20) << 1 / (sqrt(x+1) + sqrt(x)) << endl;
    }
    cout << "--------------------------------------------------" << endl;

    
    cout << "__________________________________________________________________________________________" << endl;

    cout << endl << endl << "Punto 3" << endl;
    double data[4] = {4, 7, 13, 16};
    double x, sum, sum2, V;

    sum = 0;
    sum2 = 0;

    for (int i = 0; i < 4; i++)
    {
        sum = sum + data[i];
        sum2 = sum2 + data[i]*data[i];
    }

    x = sum/4;
    V = (sum2/4 - x*x) *4/3;

    cout << "data: media <x> = " << x << "; varianza V = " << V << endl;

    double hugenumber[4];

    for (int i = 0; i < 4; i++)
        hugenumber[i] = data[i] + 1E9;

    for (int i = 0; i < 4; i++)
    {
        sum = sum + hugenumber[i];
        sum2 = sum2 + hugenumber[i]*hugenumber[i];
    }

    x = sum/4;
    V = (sum2/4 - x*x)*4/3;

    cout << "hugenumber: media <x> = " << x << "; varianza V = " << V << endl;

    return 0;

}
