#include"vettoreDati.h"
#include <cmath>


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
		
void vettoreDati::sort(){
	quicksort(0,getN()-1);
}

void vettoreDati::quicksort(unsigned int primo, unsigned int ultimo){
	if (primo>ultimo || ultimo>=getN()) {
		cout<<"I valori degli indiic primo-ultimo non hanno senso...esco"<<endl;
		return;
	}
	if (ultimo-primo<=1){
		if (getComponent(primo)>getComponent(ultimo)){
			switchComponent(primo,ultimo);
			}
	return; 
	}
	double pivot=getComponent((primo+ultimo)/2);
	unsigned int basso=primo;
	unsigned int alto=ultimo;
	while (basso<alto){
		while (getComponent(basso)<pivot){basso ++;}
		while (getComponent(alto)>pivot){alto --;}
		if (basso<alto){switchComponent(basso, alto);
			basso ++;}
	}
	quicksort(primo, basso-1);
	quicksort(basso, ultimo);
}
		
void vettoreDati::calcolaMedia(){
		
	double sum=0.;
		for(int i=0;i<getN();i++)
			sum += getComponent(i);
		_media=sum/getN();

}

void vettoreDati::varianza(){
	float sum2=0.;
	for(int i=0;i<getN();i++)
		sum2 += pow((getComponent(i)-getMedia()),2);
	_varianza= sum2/(getN()-1);
	return;
	}
	
void vettoreDati::devSt(){
	_devSt=sqrt(getVarianza());
	return;
	}

	
double vettoreDati::mediana(){
	sort();
	int index;
	if(getN()%2==0){
		int i=getN()/2;
		int i2= i-1;
		return (getComponent(i)+getComponent(i2))/2;
	} else{
		int i=getN()/2;
	return getComponent(i);
	}
}

double vettoreDati::coeffCorrelazione(vettoreDati& v){
	double cov=0.;
	for(int i=0; i<getN();i++){
		cov+=(getComponent(i)-getMedia())*(v.getComponent(i)-v.getMedia());
	}

	cov=cov/getN(); //controllare se la foruma e giusta
	return cov/(getDevSt()*v.getDevSt());
}
		


		
