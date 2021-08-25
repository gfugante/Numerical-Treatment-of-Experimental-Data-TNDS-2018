#ifndef _Random_h_
#define _Random_h_

class Random{
	private:
		unsigned int _a;
		unsigned int _c;
		unsigned int _m;
		unsigned int _seme;
		

	public:
		Random(int seme);
		void setA(int a);
		void setC(int c);
		void setM(int m);
		double Rand();
		double Accept_Reject(double, double, double, double);
		double Box_Mull_Gauss(double, double);
		double trasformata_exp(double,double);
		~Random();
};
#endif
