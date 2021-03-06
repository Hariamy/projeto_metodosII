#ifndef METODOS_H
#define METODOS_H

#include <iostream>
#include <cmath>
#include "../../modelo/algebra.h"
	
autoValVet* potencia (matriz &mat, double &erro);
autoValVet* potenciaInversa (matriz &mat, double &erro);
autoValVet* potenciaDeslocamento (matriz &mat, double &chute, double &erro);

// AUXILIARES
matrizLU* construirLU (matriz &mat);
vetor* substituicaoProgressiva (matriz &mat, vetor &vet);
vetor* substituicaoRetroativa (matriz &mat, vetor &vet);
matriz* inversaLU (matrizLU &matLU);

#endif //METODOS_H
