#include <cmath>
#include "algebra.h"

/*! Construtor da matriz
**  Parâmetros: O tamanho da matriz e os valores
**  Retorno: 
*/
matriz::matriz (int novoTam, float **novosValores) {
	tam = novoTam;
		
	if(novosValores != NULL){
		valores = novosValores;
	}else{
		valores = zeros(tam);
	}
}
	
/*! Construtor da matriz de tipos definidos
**     alg::IDENTIDADE: Matriz identidade
**     alg::ZEROS: Matriz com zero em todas as posições
**     alg::UMS: Matriz com um em todas as posições
**  Parâmetros: O tamanho da matriz e o tipo de inicialização
**  Retorno: 
*/
matriz::matriz (int novoTam, int tipo) {
	tam = novoTam;
		
	switch (tipo){
		case IDENTIDADE: valores = identidade(tam); break;
		case ZEROS : valores = zeros(tam);          break;
		case UMS : valores = ums(tam);              break;
		default: valores = zeros(tam);
	}
}

/*! Retorna a linha da matriz
**  Parâmetros: O índice da linha desejada
**  Retorno: A linha desejada
*/
float* matriz::operator [] (int pos) {
	return valores[pos];
}

/*! Copia os valores de uma matriz
**  Parâmetros: A matriz que se deseja copiar
**  Retorno: void
*/
void matriz::operator = (matriz &mat2) {
	for(int i = 0; i < tam; i++){
		free(valores[i]);
	}
	free(valores);

	tam = mat2.tam;
	valores = (float**)malloc(sizeof(float) * tam);
		
	for(int i = 0; i < tam; i++){
		valores[i] = (float*)malloc(sizeof(float) * tam);
		
		for(int j = 0; j < tam; j++){
			valores[i][j] = mat2[i][j];
		}	
	}
}

/*! Soma de uma matriz por pela identidade multiplicada por uma escalar
**  Parâmetros: A escalar que se deseja somar
**  Retorno: void
*/
void matriz::operator + (float constante) {
	for(int i = 0; i < tam; i++){
		valores[i][i] += constante;
	}
}

/*! Soma de duas matrizes
**  Parâmetros: A matriz que se deseja somar
**  Retorno: A matriz somada
*/
matriz matriz::operator + (matriz mat2) {
	if(tam == mat2.tam){
		matriz resul(tam);

		for(int i = 0; i < tam; i++){
			for(int j = 0; j < tam; j++){
				resul[i][j] += valores[i][j] + mat2[i][j];
			}
		}

		return resul;
	}
}

/*! Subtração de uma matriz com a identidade multiplicada por uma escalar
**  Parâmetros: A constante que se deseja subtrair
**  Retorno: void
*/
void matriz::operator - (float constante) {
	for(int i = 0; i < tam; i++){
		valores[i][i] -= constante;
	}
}

/*! Subtração de duas matrizes
**  Parâmetros: A matriz que se deseja subtrair
**  Retorno: A matriz subtraida
*/
matriz matriz::operator - (matriz mat2) {
	if(tam == mat2.tam){
		matriz resul(tam);
			
		for(int i = 0; i < tam; i++){
			for(int j = 0; j < tam; j++){
				resul[i][j] = valores[i][j] - mat2[i][j];
			}
		}
	}
}

/*! Multiplicação de uma matriz por uma escalar
**  Parâmetros: A escalar que se deseja multiplicar
**  Retorno: void
*/
void matriz::operator *  (float constante) {
	for(int i = 0; i < tam; i++){
		for(int j = 0; j < tam; j++){
			valores[i][j] *= constante;
		}
	}
}

/*! Produto de duas matrizes
**  Parâmetros: A matriz que se deseja multiplicar
**  Retorno: A matriz multiplicada
*/
matriz matriz::operator * (matriz mat2) {
	if(tam == mat2.tam){
		matriz respo(tam);
			
		for(int i = 0; i < tam; i++){				
			for(int j = 0; j < tam; j++){
				for(int k = 0; k < tam; k++){;
					respo[i][j] += valores[i][k] * mat2[k][j];
				}
			}
		}
			
		return respo;
	}
}

/*! Produto de uma matriz por um vetor
**  Parâmetros: O vetor que se deseja multiplicar
**  Retorno: O vetor multiplicado
*/
vetor matriz::operator * (vetor mult) {
	if(tam == mult.tam){
		vetor respo(tam);
			
		for(int i = 0; i < tam; i++){
			for(int j = 0; j < tam; j++){
				respo[i] += valores[i][j] * mult[j];
			}
			
		}
			
		return respo;
	}
}