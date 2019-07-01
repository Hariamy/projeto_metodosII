#ifndef VETOR_H
#define VETOR_H

#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>

class vetor{
public:
	int tam;
	std::vector <double> *valores;
		
	vetor (int novoTam, double valIncial = 0);
		
	double& operator [] (int pos);
	void   operator =  (vetor novosValores);
	void   operator =  (vetor* novosValores);
	vetor* operator +  (vetor vet2);
	vetor* operator -  (vetor vet2);
	void   operator *  (double constante);
	double  operator *  (vetor vet2);
	double  tamanho     ();
	void   unitario    ();

	void mostrar_debug ();
};

#endif //VETOR_H