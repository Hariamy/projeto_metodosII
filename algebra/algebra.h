#ifndef ALGEBRA_H
#define ALGEBRA_H

#include <iostream>
#include <vector>

#define IDENTIDADE 0
#define ZEROS      1
#define UMS        2

namespace alg{
	
	struct vetor{
		int tam;
		float *valores;
		
		inline vetor (int novoTam, float *novosValores = NULL);
		
		inline float& operator [] (int pos);
		inline void operator = (vetor novosValores);
		inline void operator + (vetor vet2);
		inline void operator - (vetor vet2);
		inline void operator *  (float constante);
		inline float operator * (vetor vet2);
		inline float tamanho ();
		inline void unitario ();
		
		inline ~vetor ();
	};
	
	struct matriz{
		int     tam;
		float **valores;
		
		inline matriz (int novoTam, float **novosValores = NULL);
		inline matriz (int novoTam, int tipo);
		
		inline float* operator [] (int pos);
		inline void operator = (matriz &mat2);
		inline void operator + (float constante);
		inline void operator + (matriz mat2);
		inline void operator - (float constante);
		inline void operator - (matriz mat2);
		inline void operator *  (float constante);
		inline matriz operator * (matriz mat2);
		inline vetor operator * (vetor vet2);

		inline ~matriz();
	};
	
	inline float** identidade (int tam);
	inline float** zeros (int tam);
	inline float** ums (int tam);
	inline float** copiarMatriz (matriz &mat2);

/**************************************************************************************************************************
--------------------------------------------------------- Funções ---------------------------------------------------------
**************************************************************************************************************************/
	
	//Cria uma matriz identidade
	float** identidade (int tam){
		int posLinha = 0, posColuna;
		float **id = (float**)malloc(sizeof(float*) * tam);
		
		for(unsigned int i = 0; i < tam; i++){
			id[i] = (float*)malloc(sizeof(float) * tam);
			
			for(unsigned int j = 0; j < tam; j++){
				if(i == j){
					id[i][j] = 1;
				}else{
					id[i][j] = 0;
				}
			}
		}
		
		return id;
	}
	
	//Cria uma matriz preenchida por zero
	float** zeros (int tam){
		float **id = (float**)malloc(sizeof(float*) * tam);
		
		for(unsigned int i = 0; i < tam; i++){
			id[i] = (float*)malloc(sizeof(float) * tam);
			
			for(unsigned int j = 0; j < tam; j++){
					id[i][j] = 0;
			}
		}
		
		return id;
	}
	
	//Cria uma matriz preenchida por um
	float** ums (int tam){
		float **id = (float**)malloc(sizeof(float*) * tam);
		
		for(unsigned int i = 0; i < tam; i++){
			id[i] = (float*)malloc(sizeof(float) * tam);
			
			for(unsigned int j = 0; j < tam; j++){
				id[i][j] = 1;
			}		
			
		}
		
		return id;
	}
	
	//Faz a cópia da matriz passada
	float** copiarMatriz (matriz &mat) {
		int tam = mat.tam;
		float **copia = (float**)malloc(sizeof(float) * mat.tam);
		
		for(unsigned int i = 0; i < tam; i++){
			copia[i] = (float*)malloc(sizeof(float) * mat.tam);
			
			for(unsigned int j = 0; j < tam; j++){
				copia[i][j] = mat[i][j];
			}
			
		}
		
		return copia;
	}

/*************************************************************************************************************************
---------------------------------------------------- Funções do vetor ----------------------------------------------------
*************************************************************************************************************************/

	//Construtor do vetor
	vetor::vetor (int novoTam, float *novosValores) {
		tam = novoTam;
		
		if(novosValores != NULL){
			valores = novosValores;
		}else{
			valores = (float*)malloc(sizeof(float) * tam);
			
			for(int i = 0; i < tam; i++){
				valores[i] = 0;
			}
		}
	}

	//Acessa uma posição do vetor
	float& vetor::operator [] (int pos) {
		return valores[pos];
	}
	
	//Faz a copia dos valores de um vetor
	void vetor::operator = (vetor novosValores) {
		tam = novosValores.tam;

		free(valores);
		valores = (float*)malloc(sizeof(float) * tam);
		
		for(unsigned int i = 0; i < tam; i++){
			valores[i] = novosValores[i];
		}
	}

	//Soma dois vetores e o resultado final fica no vetor da esquerda
	void vetor::operator + (vetor vetSom) {
		if(tam == vetSom.tam){
			float *som = vetSom.valores;
			
			for(int i = 0; i < tam; i++){
				valores[i] += som[i];
			}
			
		}
	}

	//Subtrai dois vetores e o resultado final fica no vetor da esquerda
	void vetor::operator - (vetor vetSub) {
		if(tam == vetSub.tam){
			float *sub = vetSub.valores;
			
			for(int i = 0; i < tam; i++){
				valores[i] -= sub[i];
			}
		}
	}

	//Multiplica o vetor por uma escalar e o resultado final fica no vetor
	void vetor::operator *  (float constante) {
		for(int i = 0; i < tam; i++){
			valores[i] *= constante;
		}
	}

	//Produto escalar de dois vetores
	float vetor::operator * (vetor vetMult) {
		if(tam == vetMult.tam){
			float *mult = vetMult.valores, respo = 0;
			
			for(unsigned int i = 0; i < tam; i++){
				respo += valores[i] * mult[i];
			}
			
			return respo;
		}
	}

	//Retorna o tamanho do vetor
	float vetor::tamanho () {
		float respo = 0;
		
		for(unsigned int i = 0; i < tam; i++){
			respo += valores[i] * valores[i];
		}
		
		return sqrt(respo);
	}

	//Unitariza o vetor
	void vetor::unitario () {
		float vetTam = tamanho();
		
		for(unsigned int i = 0; i < tam; i++){
			valores[i] /= vetTam;
		}
	}

	//Destrutor do vetor
	vetor::~vetor (){
		free(valores);
	}

/**************************************************************************************************************************
---------------------------------------------------- Funções da matriz ----------------------------------------------------
**************************************************************************************************************************/

	//Contrutor da matriz
	matriz::matriz (int novoTam, float **novosValores) {
		tam = novoTam;
		
		if(novosValores != NULL){
			valores = novosValores;
		}else{
			valores = zeros(tam);
		}
	}
	
	//Contrutor da matriz
	matriz::matriz (int novoTam, int tipo) {
		tam = novoTam;
		
		switch (tipo){
			case IDENTIDADE: valores = identidade(tam); break;
			case ZEROS : valores = zeros(tam);          break;
			case UMS : valores = ums(tam);              break;
			default: valores = zeros(tam);
		}
	}

	//Retorna a linha pedida
	float* matriz::operator [] (int pos) {
		return valores[pos];
	}

	//Copia os valores da matriz
	void matriz::operator = (matriz &mat2) {
		for(int i = 0; i < tam; i++){
			free(valores[i]);
		}
		free(valores);

		tam = mat2.tam;
		valores = (float**)malloc(sizeof(float) * tam);
		
		for(unsigned int i = 0; i < tam; i++){
			valores[i] = (float*)malloc(sizeof(float) * tam);
			
			for(unsigned int j = 0; j < tam; j++){
				valores[i][j] = mat2[i][j];
			}	
		}
	}

	//Soma a matriz por uma matriz identidade multiplicada pela escalar
	void matriz::operator + (float constante) {
		for(int i = 0; i < tam; i++){
			*( *(valores + i) + i) += constante;
		}
	}

	//Soma duas matrizes e o resultado final fica na matriz da esquerda
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

	//Subtrai a matriz por uma matriz identidade multiplicada pela escalar
	void matriz::operator - (float constante) {
		for(int i = 0; i < tam; i++){
			*( *(valores + i) + i) -= constante;
		}
	}

	//Subtrai duas matrizes e o resultado final fica na matriz da esquerda
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

	//Multiplica a matriz por uma escalar
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

	//Produto de duas matrizes
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

	//Produto de uma matriz por um vetor
	vetor matriz::operator * (vetor mult) {
		if(tam == mult.tam){
			float *respoVal = (float*)malloc(sizeof(float) * tam);
			
			for(int i = 0; i < tam; i++){
				respoVal[i] = 0;
				
				for(int j = 0; j < tam; j++){
					respoVal[i] += valores[i][j] * mult.valores[j];
				}
				
			}
			
			vetor resposta(tam, respoVal);
			
			return resposta;
		}
	}

	//Destrutor da matriz
	matriz::~matriz() {
		for(int i = 0; i < tam; i++){
			free(valores[i]);
		}
		free(valores);
	}
}
#endif //ALGEBRA_H
