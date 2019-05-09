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
	
	inline autoValVet potencia (alg::matriz mat, float erro);
	inline autoValVet potenciaInversa (alg::matriz mat, float erro);
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
	
	autoValVet potencia (alg::matriz mat, float erro) {
		unsigned int tam = mat.tam;
		float *vet = (float*)malloc(sizeof(float) * mat.tam),
		      respoVal = INFINITY, anterior;
		
		vet[0] = 1;
		
		for(unsigned int i = 1; i < tam; i++){
			vet[i] = 0;
		}
		
		alg::vetor respoVet(mat.tam, vet), aux(mat.tam);
		
		do{
			anterior = respoVal;
			
			aux = mat * respoVet;
			respoVal = respoVet * aux;
			
			respoVet = aux;
			respoVet.unitario();
			
		}while((std::abs((respoVal - anterior) / respoVal)) > erro);
		
		autoValVet respo{respoVal, respoVet};
		
		return respo;
	}

	inline autoValVet potenciaInversa (alg::matriz mat, float erro) {
		matrizLU LU = construirLU(mat);
		alg::matriz inversa = inversaLU(LU);
		autoValVet respo = potencia(inversa, erro);

		respo.autoValor = 1 / respo.autoValor;
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
	
	alg::vetor substituicaoProgressiva (alg::matriz mat, alg::vetor vet) {
		if(mat.tam == vet.tam){
			int tam = vet.tam;
			alg::vetor resul(tam);
			
			for(int i = 0; i < tam; i++){

				for(int j = 0; j < i; j++){
					resul[i] += mat[i][j] * resul[j];
				}
				
				resul[i] = (vet[i] - resul[i])/ mat[i][i];
			
			}
			
			return resul;
		}
	}
	
	alg::vetor substituicaoRetroativa (alg::matriz mat, alg::vetor vet) {
		if(mat.tam == vet.tam){
			int tam = vet.tam;
			alg::vetor resul(tam);
			
			for(int i = tam-1; i >= 0; i--){

				for(int j = tam-1; j > i; j--){
					resul[i] += mat[i][j] * resul[j];
				}
				
				resul[i] = (vet[i] - resul[i])/ mat[i][i];
			
			}
			
			return resul;
		}
	}
	
	//Acha a matriz inversa utilizando a decomposuição LU
	alg::matriz inversaLU (matrizLU matLU) {
		int tam = matLU.L.tam;
		alg::vetor aux(tam), iden(tam);
		alg::matriz matRespo(tam);

		for(int i = 0; i < tam; i++){
			iden[i] = 1;
			if(i-1 >= 0){
				iden[i-1] = 0;
			}
			
			aux = substituicaoRetroativa(matLU.U, substituicaoProgressiva(matLU.L, iden));

			for(int j = 0; j < tam; j++){
				matRespo[j][i] = aux[j];
			}

		}
		return matRespo;
	}
}

#endif //METODOS_H
