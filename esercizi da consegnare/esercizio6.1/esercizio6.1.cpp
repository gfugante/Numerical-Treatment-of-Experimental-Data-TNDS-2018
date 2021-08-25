#include <iostream>
#include <fstream>
#include <ctime>
#include <cmath>
#include <cstdlib>

#include  "VettoreDati.h"


using namespace std;

int main (int argc, char **argv)
{
	if (argc < 2)
		{
			cerr << "Stai usando: " << argv[0] << " <nome file>" << endl;
			return -1;
		}

	unsigned int N = 100;
	double a, b, t1, t2, t3;
	clock_t start, end;
	ofstream time;
	ifstream timein, in;

	in.open(argv[1]);
	time.open("data_time.dat");

	in.ignore(100, '\n');

	for (N =100; N <= 100000; N *= 2)
	{
		VettoreDati list(N, in);
		cout << "sto ordinando " << N << " componenti, attendere..." << endl;
		
		start = clock();
		list.selectionSort();
		end = clock();

		time << ( (double)(end-start) )/CLOCKS_PER_SEC << endl;		
	}

	time.close();

	timein.open ("data_time.dat");
	for(int i = 1; i <= 7; i++)
		timein.ignore(100, '\n');
	timein >> t1 >> t2 >> t3;

	a = ( t2 - (2 * t1) ) / ( 2 * pow(12800,2) );
	b = ( (4 * t1) - t2) / ( 2 * 25600 );

	cout << "a = " << a << "; b = " << b << endl;
	cout << "\nDalla relazione t = a*N^2 + b*N è possibile stimare"
		 << " il tempo di esecuzione per qualunque N. " << endl;
	cout << " N = 51 200 ==> t = " << a * pow(51200,2) + b * 51200
		 << " secondi.\nIl tempo misurato corrisponde a " << t3 << " secondi" << endl;

	return 0;
}

