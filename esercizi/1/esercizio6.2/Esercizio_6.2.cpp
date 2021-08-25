#include "vettoreDati.h"
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iomanip>
#define nN 4
using namespace std;




int main(int argc, char **argv){
	if(argc!=3){
		cerr<<"Usage: "<<argv[0]<<" <N_Values> <filename>"<<endl;
		return -1; }
	
	unsigned int N=atoi(argv[1]); //contenuta in cstdlib...converte in int atof converte in float
	vettoreDati v1(N, argv[2]);
	vettoreDati v2(2*N, argv[2]);
	
	
	//cout<<"Before sorting.. "<<endl;
	double time1,time2;
//timer v n
	clock_t t1;
	t1=clock(); 
	v1.sort();
	cout<<endl<<endl;
	//cout<<"After sorting.. "<<endl;
	t1=clock()-t1;
	time1=static_cast<float>(t1)/CLOCKS_PER_SEC;

//timer v 2n
	clock_t t2;
	t2=clock(); 
	v2.sort();
	t2=clock()-t2;	
	time2=static_cast<float>(t2)/CLOCKS_PER_SEC;
//stimiamo i parametri a b

	double a,b,t;
	a=(time2-2*time1)/(2*N*N);
	b=(4*time1-time2)/(2*N);
	
	ofstream outfile;
	outfile.open("table_time.dat");

	cout<<endl<<"Sto stampando N, t vero e t stimato e la differenza tvero-tstimato "
		<<" su file table_time.dat:"<<endl;
	outfile<<"N"<<"\t"<<"tv"<<"\t"<<"ts"<<"\t"<<"tv-ts"<<endl<<endl;
	for(int i=0; i<nN;i++){
		vettoreDati v(N, argv[2]);
		float timev,times;
		clock_t tn;
		tn=clock(); 
		v.sort();
		tn=clock()-tn;
		timev=static_cast<float>(tn)/CLOCKS_PER_SEC;
		times=a*N*N+b*N;
	outfile<<setprecision(5);
		//outfile<<N<<"\t"<<timev<<"\t"<<times<<"\t"<<timev-times<<endl;
		N=N*2;
		if(N>=pow(10,6)){ 
			cout<<"N e' maggiore del numero di elementi nel file. Non calcolo pou"<<endl;
			break;
		}
	
	}
		

	return 0;	


}


