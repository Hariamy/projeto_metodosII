#ifndef METODOS_H
#define METODOS_H

#include <iostream>
#include <cmath>
#include "algebra.h"

namespace met{
	struct resposta{
		float autoValor;
		alg::vetor autoVetor;
	};

/*************************************************************************************************************************
-------------------------------------------------------- Funções ---------------------------------------------------------
*************************************************************************************************************************/
	
	inline resposta exponencial(alg::matriz mat, float erro){
		float *vet = (float*)malloc(sizeof(float) * mat.tam),
		respoVal = INFINITY, anterior, *anteriorVet;
		
		vet[0] = 1;
		
		for(int i = 1; i < mat.tam; i++){
			vet[i] = 0;
		}
		
		alg::vetor respoVet(mat.tam, vet), aux(mat.tam, NULL);
		
		do{
			anterior = respoVal;
			anteriorVet = respoVet.valores;
			
			aux = mat * respoVet;
			respoVal = respoVet * aux;
			
			respoVet = aux.valores;
			respoVet.unitario();
			
			free(anteriorVet);
		}while(std::abs(respoVal - anterior) > erro);
		
		resposta respo{respoVal, respoVet};
		
		return respo;
	}
}

#endif //METODOS_H
