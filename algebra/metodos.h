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
	
	inline autoValVet exponencial (alg::matriz mat, float erro);
	inline matrizLU construirLU (alg::matriz mat);
	inline alg::vetor substituicaoProgressiva (alg::matriz mat, alg::vetor vet);
	inline alg::vetor substituicaoRetroativa (alg::matriz mat, alg::vetor vet);
	inline alg::matriz inversaLU (matrizLU matLU);

/*************************************************************************************************************************
---------------------------------------------------- Implementações ------------------------------------------------------
*************************************************************************************************************************/
	
	void matrizLU::operator = (matrizLU LU) {
		L = (LU.L);
		U = (LU.U);
	}
	
	autoValVet exponencial (alg::matriz mat, float erro){
		unsigned int tam = mat.tam;
		float *vet = (float*)malloc(sizeof(float) * mat.tam),
		      respoVal = INFINITY, anterior, *anteriorVet;
		
		vet[0] = 1;
		
		for(unsigned int i = 1; i < tam; i++){
			vet[i] = 0;
		}
		
		alg::vetor respoVet(mat.tam, vet), aux(mat.tam);
		
		do{
			anterior = respoVal;
			anteriorVet = respoVet.valores;
			
			aux = mat * respoVet;
			respoVal = respoVet * aux;
			
			respoVet = aux;
			respoVet.unitario();
			
			free(anteriorVet);
		}while((std::abs((respoVal - anterior) / respoVal)) > erro);
		
		autoValVet respo{respoVal, respoVet};
		
		return respo;
	}

	matrizLU construirLU (alg::matriz mat) {
		unsigned int tam = mat.tam;
		alg::matriz L(tam, alg::identidade(mat.tam)), U(tam, alg::copiarMatriz(mat));
		float subtrair;
		
		for(unsigned int i = 0; i < tam; i++){
			for(unsigned int j = i + 1; j < tam; j++){
				subtrair = L[j][i] = (U[j][i] / U[i][i]);
				
				for(unsigned int k = i; k < tam; k++){
					U[j][k] -= subtrair * U[i][k];
				}

			}
		}
		
		matrizLU LU{L, U};
		
		return LU;
	}
	
	alg::vetor substituicaoProgressiva (alg::matriz mat, alg::vetor vet){
		if(mat.tam == vet.tam){
			int tam = vet.tam;
			alg::vetor resul(tam);
			
			for(int i = 0; i < tam; i++){
				
				for(int j = 0; j < i; j++){
					resul.valores[i] -= mat[i][j] * resul[j];
				}
				
				resul.valores[i] /= mat[i][i];
			
			}
			
			return resul;
		}
	}
	
	alg::vetor substituicaoRetroativa (alg::matriz mat, alg::vetor vet){
		if(mat.tam == vet.tam){
			int tam = vet.tam;
			alg::vetor resul(tam);
			
			for(int i = tam-1; i >= 0; i++){
				
				for(int j = tam-1; j > i; j++){
					resul.valores[i] -= mat[i][j] * resul[j];
				}
				
				resul.valores[i] /= mat[i][i];
			
			}
			
			return resul;
		}
	}
	
	alg::matriz inversaLU (matrizLU matLU){
		int tam = matLU.L.tam;
		alg::vetor aux(tam);
	}
}

#endif //METODOS_H
