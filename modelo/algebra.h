#ifndef ALGEBRA_H
#define ALGEBRA_H

#include <iostream>
#include <vector>
#include <cmath>

#define IDENTIDADE 0
#define ZEROS      1
#define UMS        2
	
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
	
class matriz{
public:
	int     tam;
	std::vector <float> *valores;

	matriz      (int novoTam, int tipo = ZEROS);

	void redimensionar(int novoTam);
		
	float&  posicao (int x, int y);
	void    operator =  (matriz &mat2);
	void    operator +  (float constante);
	matriz* operator +  (matriz &mat2);
	void    operator -  (float constante);
	matriz* operator -  (matriz &mat2);
	void    operator *  (float constante);
	matriz* operator *  (matriz &mat2);
	vetor*  operator *  (vetor &vet2);

	void transposta ();

	void mostrar_debug ();
};

class matrizLU{
public:
	matriz *L, *U;
	
	matrizLU (matriz *novoL, matriz *novoU) : L(novoL), U(novoU) {}
	void operator = (matrizLU &LU);
};
	
class autoValVet{
public:
	float autoValor;
	vetor *autoVetor;

	void operator = (autoValVet &copia);
	bool operator == (autoValVet &valVet2);
};
	
void identidade   (int tam, std::vector <float> &valores);
void zeros        (int tam, std::vector <float> &valores);
void ums          (int tam, std::vector <float> &valores);
void copiarMatriz (std::vector <float> &copiada, std::vector <float> &copiadora);

#include "util.inl"
#include "vetor.inl"
#include "matriz.inl"

#endif //ALGEBRA_H
