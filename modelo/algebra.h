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
	float *valores;
		
	inline        vetor       (int novoTam, float *novosValores = NULL);
		
	inline float& operator [] (int pos);
	inline void   operator =  (vetor novosValores);
	inline vetor  operator +  (vetor vet2);
	inline vetor  operator -  (vetor vet2);
	inline void   operator *  (float constante);
	inline float  operator *  (vetor vet2);
	inline float  tamanho     ();
	inline void   unitario    ();
};
	
class matriz{
public:
	int     tam;
	float **valores;
		
	inline        matriz      (int novoTam, float **novosValores = NULL);
	inline        matriz      (int novoTam, int tipo);
		
	inline float* operator [] (int pos);
	inline void   operator =  (matriz &mat2);
	inline void   operator +  (float constante);
	inline matriz operator +  (matriz mat2);
	inline void   operator -  (float constante);
	inline matriz operator -  (matriz mat2);
	inline void   operator *  (float constante);
	inline matriz operator *  (matriz mat2);
	inline vetor  operator *  (vetor vet2);
};

struct matrizLU{
	matriz L, U;
	
	inline void operator = (matrizLU &LU);
};
	
struct autoValVet{
	float autoValor;
	vetor autoVetor;

	inline void operator = (autoValVet &copia);
	inline bool operator == (autoValVet &valVet2);
};
	
inline float** identidade   (int tam);
inline float** zeros        (int tam);
inline float** ums          (int tam);
inline float** copiarMatriz (matriz &mat2);

#include "util.inl"
#include "vetor.inl"
#include "matriz.inl"

#endif //ALGEBRA_H
