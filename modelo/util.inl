#include "algebra.h"

/**************************************************************************************************************************
--------------------------------------------------------- Funções ---------------------------------------------------------
**************************************************************************************************************************/

/*! Copia  estrutura de matrizes matrizes LU
**  Parâmetros: A estrutura das matrizes LU que se deseja copiar
**  Retorno: void
*/
void matrizLU::operator = (matrizLU &LU) {
	L = (LU.L);
	U = (LU.U);
}

/*! Copia as estrutura de autovalor e autovetor
**  Parâmetros: A estrutura de autovalor e autovetor que se deseja copiar
**  Retorno: void
*/
void autoValVet::operator = (autoValVet &copia) {
	autoValor = copia.autoValor;
	autoVetor = copia.autoVetor;
}

/*! Compara se duas estruturas de autovalor e autovetor tem os mesmos valores 
**  Parâmetros: A estrutura de autovalor e autovetor que se deseja comparar
**  Retorno: Verdadeiro se forem iguais, falso e forem diferentes
*/
bool autoValVet::operator == (autoValVet &valVet2) {
	int tam = autoVetor.tam;
	bool vetIgual = true;
	for(int i = 0; i < tam; i++){
		if(autoVetor[i] != valVet2.autoVetor[i]){
			vetIgual = false;
		}
	}
	if(vetIgual && autoValor == valVet2.autoValor){
		return true;
	}else{
		return false;
	}
}

/*! Cria uma matriz identidade
**  Parâmetros: Tamanho da matriz
**  Retorno: A matriz identidade
*/
float** identidade (int tam){
	int posLinha = 0, posColuna;
	float **id = (float**)malloc(sizeof(float*) * tam);
		
	for(int i = 0; i < tam; i++){
		id[i] = (float*)malloc(sizeof(float) * tam);
			
		for(int j = 0; j < tam; j++){
			if(i == j){
				id[i][j] = 1;
			}else{
				id[i][j] = 0;
			}
		}
	}
		
	return id;
}
	
/*! Cria uma matriz preenchida por zero
**  Parâmetros: Tamanho da matriz
**  Retorno: A matriz de zeros
*/
float** zeros (int tam){
	float **id = (float**)malloc(sizeof(float*) * tam);
		
	for(int i = 0; i < tam; i++){
		id[i] = (float*)malloc(sizeof(float) * tam);
			
		for(int j = 0; j < tam; j++){
				id[i][j] = 0;
		}
	}
		
	return id;
}
	
/*! Cria uma matriz preenchida por um
** Parâmetros: Tamanho da matriz
** Retorno: A matriz de ums
*/
float** ums (int tam){
	float **id = (float**)malloc(sizeof(float*) * tam);
		
	for(int i = 0; i < tam; i++){
		id[i] = (float*)malloc(sizeof(float) * tam);
			
		for(int j = 0; j < tam; j++){
			id[i][j] = 1;
		}		
			
	}
		
	return id;
}
	
/*! Faz a cópia da matriz passada
**  Parâmetros: A matriz que se deseja copiar
**  Retorno: A copia da matriz passada por parâmetro
*/
float** copiarMatriz (matriz &mat) {
	int tam = mat.tam;
	float **copia = (float**)malloc(sizeof(float) * mat.tam);
		
	for(int i = 0; i < tam; i++){
		copia[i] = (float*)malloc(sizeof(float) * mat.tam);
			
		for(int j = 0; j < tam; j++){
			copia[i][j] = mat[i][j];
		}
			
	}
		
	return copia;
}