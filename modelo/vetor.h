#ifndef VETOR_H
#define VETOR_H

#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>

class vetor{
public:
	int tam;
	std::vector <float> *valores;
		
	vetor (int novoTam, float valIncial = 0);
		
	float& operator [] (int pos);
	void   operator =  (vetor novosValores);
	void   operator =  (vetor* novosValores);
	vetor* operator +  (vetor vet2);
	vetor* operator -  (vetor vet2);
	void   operator *  (float constante);
	float  operator *  (vetor vet2);
	float  tamanho     ();
	void   unitario    ();

	void mostrar_debug ();
};

#endif //VETOR_H