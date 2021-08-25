#include"vettoreDati.h"


vettoreDati::vettoreDati(unsigned int N, const char* datainfile){
		m_N=N;
		double data;
		int i=0;
		ifstream infile;
		infile.open(datainfile);
		m_v=new double [m_N];
		infile>>data;
		while(infile.good()&& i<m_N){
			setComponent(i, data);
			i++;
			infile>>data;
		}
}

void vettoreDati::print() const{
		cout<<"Dati nel vettore:"<<endl;
		for(int i=0;i<getN();i++){
			cout<<getComponent(i)<<endl;
		}
}

void vettoreDati::print (const char* dataoutfile){
		ofstream outfile;
		outfile.open(dataoutfile);
		outfile<<"Dati nel vettore:"<<endl;
		for(int i=0;i<getN();i++){
			outfile<<getComponent(i)<<endl;
		}
}
		
void vettoreDati::selectionSort() {
		for(unsigned int i=0; i<getN(); i++){
		for(unsigned int j=i+1; j<getN(); j++){

			if( getComponent(i)>getComponent(j)){
				switchComponent(i,j);
			}
		}
	}
	return;
}



		
