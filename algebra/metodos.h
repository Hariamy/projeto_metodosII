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
		alg::matriz L, U;
		
		void operator = (matrizLU LU);
	};
	
	struct autoValVet{
		float autoValor;
		alg::vetor autoVetor;
	};

/*************************************************************************************************************************
-------------------------------------------------------- Funções ---------------------------------------------------------
*************************************************************************************************************************/
	
	inline autoValVet exponencial(alg::matriz mat, float erro);
	inline matrizLU construirLU(alg::matriz mat);

/*************************************************************************************************************************
---------------------------------------------------- Implementações ------------------------------------------------------
*************************************************************************************************************************/
	
	void matrizLU::operator = (matrizLU LU) {
		L = (LU.L);
		U = (LU.U);
	}
	
	autoValVet exponencial (alg::matriz mat, float erro){
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

	matrizLU construirLU (alg::matriz mat) {
		int tam = mat.tam, i = 0, j;
		alg::matriz L(tam, alg::identidade(mat.tam)), U(tam, alg::copiarMatriz(mat));
		float **linha = U.valores, **ultimaLinha = linha + tam, **subLinha,
		      **matL = L.valores,
		      *perLinha, *fimLinha, *subPerLinha,
		      subtrair;
		
		while(linha != ultimaLinha){
			subLinha = linha + 1;
			fimLinha = (*linha) + tam;
			j = i + 1;
			
			while(subLinha != ultimaLinha){
				perLinha = (*linha) + i;
				subPerLinha = (*subLinha) + i;
				subtrair = *(*(matL + j) + i) = ((*subPerLinha) / (*perLinha));
				
				while(perLinha != fimLinha){
					*subPerLinha -= subtrair * (*perLinha);
					
					perLinha++;
					subPerLinha++;
				}
				
				j++;
				subLinha++;
			}
			
			linha++;
			i++;
		}
		
		matrizLU LU{L, U};
		
		return LU;
	}
}

#endif //METODOS_H
