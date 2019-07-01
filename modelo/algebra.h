#ifndef ALGEBRA_H
#define ALGEBRA_H

#include "matriz.h"

#define IDENTIDADE 0
#define ZEROS      1
#define UMS        2

class matrizLU{
public:
	matriz *L, *U;
	
	matrizLU (matriz *novoL, matriz *novoU) : L(novoL), U(novoU) {}
	void operator = (matrizLU &LU);
};
	
class autoValVet{
public:
	double autoValor;
	vetor *autoVetor;

	void operator = (autoValVet &copia);
	bool operator == (autoValVet &valVet2);
};

matriz* prodExtern (vetor &vet1, vetor &vet2);

#endif //ALGEBRA_H
