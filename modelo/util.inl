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
	int tam = autoVetor->tam;
	bool vetIgual = true;
	for(int i = 0; i < tam; i++){
		if((*autoVetor)[i] != (*valVet2.autoVetor)[i]){
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
**  Parâmetros: Tamanho da matriz e o vetor de posições
**  Retorno: Void
*/
void identidade (int tam, std::vector <float> &valores){
	int indice = 0, passo = 0;   //Indice que irá indicar a posição atual da matriz, e o passo para indicar em qual posição colocar o valor 1

	valores.resize(tam*tam);

	for(float &i:valores){
		if(indice == passo){
			i = 1;
		}else{
			i = 0;
		}
		indice++;

		if(indice == tam){
			indice = 0;
			passo++;
		}
	}
}
	
/*! Cria uma matriz preenchida por zero
**  Parâmetros: Tamanho da matriz e o vetor de posições
**  Retorno: Void
*/
void zeros (int tam, std::vector <float> &valores){
	valores.resize(tam*tam);

	for(float &i:valores){
		i = 0;
	}	
}
	
/*! Cria uma matriz preenchida por um
** Parâmetros: Tamanho da matriz e o vetor de posições
** Retorno: Void
*/
void ums (int tam, std::vector <float> &valores){
	valores.resize(tam*tam);

	for(float &i:valores){
		i = 1;
	}	
}
	
/*! Faz a cópia da matriz passada
**  Parâmetros: A matriz que se deseja copiar e a que obterá a cópia
**  Retorno: Void
*/
void copiarMatriz (std::vector <float> &copiada, std::vector <float> &copiadora) {
	unsigned int indice = 0;
	
	copiadora.resize(copiada.size());

	for(float &i:copiadora){
		i = copiada[indice++];
	}
}