#ifndef ALGEBRA_H
#define ALGEBRA_H

#include <iostream>

#define IDENTIDADE 0
#define ZEROS      1
#define UMS        2

namespace alg{
	
	inline float** identidade (int tam);
	inline float** zeros (int tam);
	inline float** ums (int tam);
	inline float** copiar (matriz mat2);
	inline matrizLU construirLU(matriz mat);
	
	struct vetor{
		int tam;
		float *valores, *init, *fim;
		
		inline vetor (int novoTam, float *novosValores);
		inline vetor (int novoTam);
		
		inline float operator [] (int pos);
		inline void operator = (float *novosValores);
		inline void operator = (vetor novosValores);
		inline void operator + (vetor vet2);
		inline void operator - (vetor vet2);
		inline void operator *  (float constante);
		inline float operator * (vetor vet2);
		inline float tamanho ();
		inline void unitario ();
	};
	
	struct matriz{
		int     tam;
		float **valores;
		
		inline matriz (int novoTam, float **novosValores);
		inline matriz (int novoTam, int tipo);
		inline matriz (int novoTam);
		
		inline float* operator [] (int pos);
		inline void operator + (float constante);
		inline void operator + (matriz mat2);
		inline void operator - (float constante);
		inline void operator - (matriz mat2);
		inline void operator *  (float constante);
		inline matriz operator * (matriz mat2);
		inline vetor operator * (vetor vet2);
	};

/**************************************************************************************************************************
--------------------------------------------------------- Funções ---------------------------------------------------------
**************************************************************************************************************************/
	
	float** identidade (int tam){
		int posLinha = 1, posColuna;
		float **id = (float**)malloc(sizeof(float*) * tam),
		**percC = id, **fimC = id + tam,
		*percLinha, *fimLinha;
		
		while(percC != fimC){
			*percC = percLinha = (float*)malloc(sizeof(float) * tamanho);
			fimLinha = percLinha + tamanho;
			posColuna = 1;
			
			while(percLinha != fimLinha){
				if(posLinha == posColuna){
					*percLinha = 1;
				}else{
					*percLinha = 0;
				}
				
				posColuna++;
			}
			
			posLinha++;
			perC++;
		}
		
		return id;
	}
	
	float** zeros (int tam){
		float **id = (float**)malloc(sizeof(float*) * tam),
		**percCol = id, **fimCol = id + tam,
		*percLinha, *fimLinha;
		
		while(percC != fimC){
			*percC = percLinha = (float*)malloc(sizeof(float) * tamanho);
			fimLinha = percLinha + tamanho;
			
			while(percLinha != fimLinha){
				*percLinha = 0;
				percLinha++;
			}		
			
			perC++;
		}
		
		return id;
	}
	
	float** ums (int tam){
		float **id = (float**)malloc(sizeof(float*) * tam),
		**percCol = id, **fimCol = id + tam,
		*percLinha, *fimLinha;
		
		while(percC != fimC){
			*percC = percLinha = (float*)malloc(sizeof(float) * tamanho);
			fimLinha = percLinha + tamanho;
			
			while(percLinha != fimLinha){
				*percLinha = 1;
				percLinha++;
			}		
			
			perC++;
		}
		
		return id;
	}
	
	float** copiar (matriz mat) {
		float **copia = (float**)malloc(sizeof(float) * mat.tam);
		      **perCol = valores, **fimCol = perCol + mat.tam, **copiar = copia,
		      *perLin, *fimLin, *perLin2, *fimLin2;
		
		while(perCol != fimCol){
			*perCol = perLin = (float*)malloc(sizeof(float) * mat.tam);
			fimLin = perLin + mat.tam;
			perLin2 = copiar;
			fimLin2 = perLin2 + mat.tam;
			
			while(perLin != fimLin){
				*perLin = *perLin2;
				
				perLin++;
				perLin2++;
			}
			
			perCol++;
			copiar++;
		}
		
		return copia;
	}
	
	/*inline matrizLU construirLU(matriz mat){
		int tam = mat.tam;
		matriz L(tam, identidade(mat.tam)), U(tam, copiar(mat));
		float **perColU = U.valores, **perColL = L.valores,
		      *perL, *perU, fimU, valor;
		for(int i = 0; i < tam; i++){
			for(int j = 0; j < tam; j++){
				perU = *(perColU) + j;
				fimU = *(perColU) + tam;
				
				while(perU != fimU){
					 = ;
				}
				
				perColU++;
			}
		}
		
		return;
	}*/

/*************************************************************************************************************************
---------------------------------------------------- Funções do vetor ----------------------------------------------------
*************************************************************************************************************************/

	vetor::vetor (int novoTam, float *novosValores) {
		tam = novoTam;
		valores = init = novosValores;
		fim = init + tam;
	}

	vetor::vetor (int novoTam) {
		tam = novoTam;
		valores = init = (float*) malloc(sizeof(float) * tam);
		fim = init + tam;
		
		while(init != fim){
			*init = 0; init++;
		}
		
		init = valores;
	}

	float vetor::operator [] (int pos) {
		return valores[pos];
	}

	void vetor::operator = (float *novosValores) {
		valores = init = novosValores;
		fim = init + tam;
	}
	
	void vetor::operator = (vetor novosValores) {
		valores = init = novosValores.valores;
		tam = novosValores.tam;
		fim = init + tam;
	}

	void vetor::operator + (vetor vet2) {
		if(tam == vet2.tam){
			float *init2 = vet2.init;
			
			while(init != fim){
				*init += *init2;
				init++;
				init2++;
			}
			
			init = valores;
		}
	}

	void vetor::operator - (vetor vet2) {
		if(tam == vet2.tam){
			float *init2 = vet2.init;
			
			while(init != fim){
				*init -= *init2;
				init++;
				init2++;
			}
			
			init = valores;
		}
	}

	void vetor::operator *  (float constante) {
		while(init != fim){
			*init *= constante; init++;
		}
		init = valores;
	}

	float vetor::operator * (vetor vet2) {
		if(tam == vet2.tam){
			float *init2 = vet2.valores, respo = 0;
			
			while(init != fim){
				respo += (*init) * (*init2);
				init++;
				init2++;
			}
			
			init = valores;
			
			return respo;
		}
	}

	float vetor::tamanho () {
		float respo = 0;
		
		while(init != fim){
			respo += (*init) * (*init);
			init++;
		}
		
		init = valores;
		
		return sqrt(respo);
	}

	void vetor::unitario () {
		float vetTam = tamanho();
		
		while(init != fim){
			*init = (*init) / vetTam;
			init++;
		}
		
		init = valores;
	}

/**************************************************************************************************************************
---------------------------------------------------- Funções da matriz ----------------------------------------------------
**************************************************************************************************************************/

	matriz::matriz (int novoTam, float **novosValores) {
		tam = novoTam;
		valores = novosValores;
	}
	
	matriz::matriz (int novoTam, int tipo) {
		tam = novoTam;
		
		switch tipo{
			case IDENTIDADE: valores = identidade(tam); break;
			case ZEROS : valores = zeros(tam); break;
			case UMS : valores = ums(tam); break;
			default: valores = zeros(tam);
		}
	}

	matriz::matriz (int novoTam) {
		float *init, *fim;
		tam = novoTam;
		valores = (float**) malloc(sizeof(float*) * tam);
		
		for(int i = 0; i < tam; i++){
			*(valores + i) = (float*) malloc(sizeof(float) * tam);
			init = *(valores + i), fim = init + tam;
			
			while(init != fim){
				*init = 0;
				init++;
			}
			
		}
	}

	float* matriz::operator [] (int pos) {
		return valores[pos];
	}

	void matriz::operator + (float constante) {
		for(int i = 0; i < tam; i++){
			*( *(valores + i) + i) += constante;
		}
	}

	void matriz::operator + (matriz mat2) {
		if(tam == mat2.tam){
			float *init, *fim, *soma;
			
			for(int i = 0; i < tam; i++){
				init = *(valores + i);
				fim = init + tam;
				soma = *(mat2.valores + i);
				
				while(init != fim){
					(*init) += *soma;
					init++;
					soma++;
				}
			}
		}
	}

	void matriz::operator - (float constante) {
		for(int i = 0; i < tam; i++){
			*( *(valores + i) + i) -= constante;
		}
	}

	void matriz::operator - (matriz mat2) {
		if(tam == mat2.tam){
			float *init, *fim, *soma;
			
			for(int i = 0; i < tam; i++){
				init = *(valores + i);
				fim = init + tam;
				soma = *(mat2.valores + i);
				
				while(init != fim){
					(*init) -= *soma;
					init++;
					soma++;
				}
			}
		}
	}

	void matriz::operator *  (float constante) {
		float *init, *fim;
		
		for(int i = 0; i < tam; i++){
			init = *(valores + i);
			fim = init + tam;
			
			while(init != fim){
				(*init) *= constante;
				init++;
			}
		}
	}

	matriz matriz::operator * (matriz mat2) {
		if(tam == mat2.tam){
			float *init1, *init2;
			matriz respo(tam);
			
			for(int i = 0; i < tam; i++){
				init1 = *(valores + i);
				
				for(int j = 0; j < tam; j++){
					for(int k = 0; k < tam; k++){
						init2 = *(mat2.valores + k) + j;
						*( *(respo.valores + i) + j) += (*init1) * (*init2);
						init1++;
					}
					
					init1 -= tam;
				}
			}
			
			return respo;
		}
	}

	vetor matriz::operator * (vetor vet2) {
		if(tam == vet2.tam){
			float *respoVal = (float*)malloc(sizeof(float) * tam), *aux = respoVal,
			 *initM, *fimM, *initV;
			
			for(int i = 0; i < tam; i++){
				*aux = 0;
				initM = *(valores + i);
				fimM = initM + tam;
				initV = vet2.init;
				
				while(initM != fimM){
					*aux += (*initM) * (*initV);
					initM++;
					initV++;
				}
				
				aux++;
			}
			
			initV = vet2.init;
			
			vetor resposta(tam, respoVal);
			
			return resposta;
		}
	}
}
#endif //ALGEBRA_H
