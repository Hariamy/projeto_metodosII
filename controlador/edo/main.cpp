#include <iostream>
#include "pvi.hpp"

#define A 3
#define B 9
#define C 7
#define D 6
#define E 1
#define F 3

#define M 1.0 + (A + B + C + D + E + F)%4
#define K 4.0
#define OMEGA  sqrt((K)/(M))
#define ZETA 0.05

#define EPSILON 0.0001

using namespace std;
using namespace Eigen;


VectorXd f(double t, VectorXd S){
	VectorXd Ft(2);
	Ft(0) = S(1);
	if (t>1.0 || t<0.0){
		Ft(1) = -((K)/(M))*S(0) - 2*(ZETA)*(OMEGA)*S(1);
	} else if(t<0.5){
		Ft(1) = -((K)/(M))*S(0) - 2*(ZETA)*(OMEGA)*S(1) + (4*t)/(M);
	} else {
		Ft(1) = -((K)/(M))*S(0) - 2*(ZETA)*(OMEGA)*S(1) + 4*(1-t)/(M);
	}
	
	return Ft;
}

int main(int argc, char ** argv){
	cout << K << M << 4/2 << " OMEGA: " << OMEGA<<endl;
	double x_ant, x_act, erro = INFINITY;
	int n = 4;
	VectorXd S0(2), S(2);
	S0 << (E + F)%3 , 0;
	MN_amb_pvi amb = MN_amb_pvi(2, 0.0, S0, &f);

	cout << "Matricula: " <<A<<B<<C<<D<<E<<F << endl;
	cout << "massa :" << M << endl;
	cout << S0 << endl;
	
	x_ant = S0(0);
	while(erro > EPSILON){
		S = amb.rungeKutta(1.2,n);
		//S = amb.euler_fw(1.2,n);
		x_act = S(0);
		erro = abs((x_act - x_ant)/x_act);
		cout << 1.2/n << "\t\t";
		cout << "s = " << S.transpose();
		cout << "\t erro: "<< erro << endl;

		n *= 2;
		x_ant = x_act;
	}

	// cout << amb.rungeKutta(1.2,4);

	return 0;
}
