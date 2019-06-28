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

/*! Faz o produto externo entre dois vetores
**  Parâmetros: Os dois vetores para fazer o produto
**  Retorno: A matriz resutante
*/
matriz* prodExtern (vetor &vet1, vetor &vet2) {
	int linha = 0, coluna = 0, tam = vet1.tam;
	matriz *resul = new matriz(tam, ZEROS);

	for(float &i:(*vet1.valores)){
		for(float &j:(*vet2.valores)){
			resul->posicao(linha, coluna++) = i * j;

			if(coluna >= tam){
				coluna = 0;
				linha++;
			}
		}
	}

	return resul;
}