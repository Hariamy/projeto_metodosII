#ifndef METODOS_H
#define METODOS_H

#include <iostream>
#include <cmath>
#include "algebra.h"

namespace met{

/*************************************************************************************************************************
------------------------------------------------------- Retornos ---------------------------------------------------------
*************************************************************************************************************************/
	
	struct matrizLU{
		matriz L, U;
	};
	
	struct autoValVet{
		float autoValor;
		alg::vetor autoVetor;
	};

/*************************************************************************************************************************
-------------------------------------------------------- Funções ---------------------------------------------------------
*************************************************************************************************************************/
	
	inline autoValVet exponencial(alg::matriz mat, float erro);

/*************************************************************************************************************************
---------------------------------------------------- Implementações ------------------------------------------------------
*************************************************************************************************************************/
	
	autoValVet exponencial(alg::matriz mat, float erro){
		float *vet = (float*)malloc(sizeof(float) * mat.tam), *percorrer = vet, *ult = vet + mat.tam,
		respoVal = INFINITY, anterior, *anteriorVet;
		
		*percorrer = 1;
		percorrer++;
		
		while(percorrer < ult){
			*percorrer = 0;
			percorrer++;
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
		
		autoValVet respo{respoVal, respoVet};
		
		return respo;
	}
}

#endif //METODOS_H
