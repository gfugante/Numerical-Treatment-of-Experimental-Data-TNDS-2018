#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main(){

	int x=1;
	cout<<scientific;
	cout<<0.3-0.2-0.1<<endl;
	cout<<0.3-(0.2+0.1)<<endl;
	cout<<0.4-(0.3-0.1)<<endl;
	cout<<0.4-(0.3+0.1)<<endl;
	cout<<(1E15+1)-1E15<<endl;
	cout<<(1E16+1)-1E16<<endl;

	for(int i=0; i<=18; i++){
		
		double f=sqrt(x+1)-sqrt(x);
		double f2=1/(sqrt(x+1)+sqrt(x));
		cout<<scientific;
		cout<<"fconerrore"<<f<<setw(100)<<"fmigliore"<<f2<<endl;
		x=x*10;
	};
	
	return 0;

}
