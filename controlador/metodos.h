#ifndef METODOS_H
#define METODOS_H

#include <iostream>
#include <cmath>
#include "../modelo/algebra.h"
	
inline autoValVet potencia (matriz &mat, float erro);
inline autoValVet potenciaInversa (matriz &mat, float erro);
inline std::vector<autoValVet> potenciaDeslocamento (matriz &mat, float erro);
inline matrizLU construirLU (matriz &mat);
inline vetor substituicaoProgressiva (matriz &mat, vetor vet);
inline vetor substituicaoRetroativa (matriz &mat, vetor vet);
inline matriz inversaLU (matrizLU &matLU);

#include "funcoesMetodos.inl"

#endif //METODOS_H
