#include "pvi.hpp"
#include <iostream>
#include <cmath>

using namespace std;
using namespace Eigen;

MN_amb_pvi::MN_amb_pvi(int n, double t, Eigen::VectorXd S, VectorXd (*F)(double t, VectorXd S)){
	dim = n;
	t0 = t;
	S0 = S;
	f = F;
}


VectorXd MN_amb_pvi::euler(double t, int npassos){
	double dt = (t - t0)/npassos;
	VectorXd Sn(dim);
	Sn = S0;

	for(int i=0; i<npassos; i++){
		Sn = Sn + dt*f(t0 + i*dt, Sn);
	}
	
	return Sn;
}


VectorXd MN_amb_pvi::rungeKutta(double t, int npassos){
	double dt = (t-t0)/npassos;
	VectorXd Sn(dim), k0(dim), k1(dim), k2(dim), k3(dim);
	Sn = S0;

	for(int i=0; i<npassos; i++){
		k0 = f(t0 + i*dt, Sn);
		k1 = f(t0 + i*dt + 0.5*dt, Sn + 0.5*dt*k0);
		k2 = f(t0 + i*dt + 0.5*dt, Sn + 0.5*dt*k1);
		k3 = f(t0 + i*dt + dt, Sn + dt*k2);

		if(npassos == 4){
			cout << "k" << i << endl;
			cout << k0(0) << "\t" << k1(0) << "\t" << k2(0) << "\t" << k3(0) << endl;
			cout << k0(1) << "\t" << k1(1) << "\t" << k2(1) << "\t" << k3(1) << endl;
			cout << "S" << i << endl << Sn << "\n\n";
		}
		Sn = Sn + (dt/6)*(k0 + 2*k1 + 2*k2 + k3);
	}

	return Sn;
}

