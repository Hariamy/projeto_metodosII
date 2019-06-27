#ifndef METODOS_H
#define METODOS_H

#include <iostream>
#include <cmath>
#include "../../modelo/algebra.h"
	
autoValVet* potencia (matriz &mat, float &erro);
autoValVet* potenciaInversa (matriz &mat, float &erro);
std::vector<autoValVet> potenciaDeslocamento (matriz &mat, float &erro);
matrizLU* construirLU (matriz &mat);
vetor* substituicaoProgressiva (matriz &mat, vetor &vet);
vetor* substituicaoRetroativa (matriz &mat, vetor &vet);
matriz* inversaLU (matrizLU &matLU);

#endif //METODOS_H
