#ifndef ALGEBRA_H
#define ALGEBRA_H

#include <iostream>
#include <vector>

#define IDENTIDADE 0
#define ZEROS      1
#define UMS        2
	
class vetor{
public:
	int tam;
	float *valores;
		
	inline        vetor       (int novoTam, float *novosValores = NULL);
		
	inline float& operator [] (int pos);
	inline void   operator =  (vetor novosValores);
	inline vetor  operator +  (vetor vet2);
	inline vetor  operator -  (vetor vet2);
	inline void   operator *  (float constante);
	inline float  operator *  (vetor vet2);
	inline float  tamanho     ();
	inline void   unitario    ();
};
	
class matriz{
public:
	int     tam;
	float **valores;
		
	inline        matriz      (int novoTam, float **novosValores = NULL);
	inline        matriz      (int novoTam, int tipo);
		
	inline float* operator [] (int pos);
	inline void   operator =  (matriz &mat2);
	inline void   operator +  (float constante);
	inline matriz operator +  (matriz mat2);
	inline void   operator -  (float constante);
	inline matriz operator -  (matriz mat2);
	inline void   operator *  (float constante);
	inline matriz operator *  (matriz mat2);
	inline vetor  operator *  (vetor vet2);
};
	
inline float** identidade   (int tam);
inline float** zeros        (int tam);
inline float** ums          (int tam);
inline float** copiarMatriz (matriz &mat2);

/**************************************************************************************************************************
--------------------------------------------------------- Funções ---------------------------------------------------------
**************************************************************************************************************************/
	
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

/*************************************************************************************************************************
---------------------------------------------------- Funções do vetor ----------------------------------------------------
*************************************************************************************************************************/

/*! Construtor do vetor
**  Parâmetros: Quantidade de elementos e (opcional) os valores
**  Retorno: 
*/
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

/*! Acessa uma posição do vetor
**  Parâmetros: O indice da posição desejada
**  Retorno: O valor presente no indice
*/
float& vetor::operator [] (int pos) {
	return valores[pos];
}
	
/*! Faz a cópia dos valores de um vetor
**  Parâmetros: O vetor que se deseja copiar
**  Retorno: void
*/
void vetor::operator = (vetor novosValores) {
	tam = novosValores.tam;

	free(valores);
	valores = (float*)malloc(sizeof(float) * tam);
		
	for(int i = 0; i < tam; i++){
		valores[i] = novosValores[i];
	}
}

/*! Faz a soma de dois vetores
**  Parâmetros: O vetor para somar
**  Retorno: O vetor somado
*/
vetor vetor::operator + (vetor vetSom) {
	if(tam == vetSom.tam){
		float *som = vetSom.valores;
		vetor resul(tam);
			
		for(int i = 0; i < tam; i++){
			resul[i] = valores[i] + som[i];
		}
			
		return resul;
	}
}

/*! Faz a subtração de dois vetores
**  Parâmetros: O vetor para subtrair
**  Retorno: O subtraido somado
*/
vetor vetor::operator - (vetor vetSub) {
	if(tam == vetSub.tam){
		float *sub = vetSub.valores;
		vetor resul(tam);
			
		for(int i = 0; i < tam; i++){
			resul[i] = valores[i] - sub[i];
		}
	}
}

/*! Multiplica o vetor por uma escalar
**  Parâmetros: Escalar para a multiplicação
**  Retorno: void
*/
void vetor::operator *  (float constante) {
	for(int i = 0; i < tam; i++){
		valores[i] *= constante;
	}
}

/*! Faz o produto escalar entre dois vetores
**  Parâmetros: O vetor para fazer o produto
**  Retorno: O valor do produto escalar
*/
float vetor::operator * (vetor vetMult) {
	if(tam == vetMult.tam){
		float *mult = vetMult.valores, respo = 0;
			
		for(int i = 0; i < tam; i++){
			respo += valores[i] * mult[i];
		}
			
		return respo;
	}
}

/*! Tamanho do vetor
**  Parâmetros: void
**  Retorno: O tamanho do vetor
*/
float vetor::tamanho () {
	float respo = 0;
		
	for(int i = 0; i < tam; i++){
		respo += valores[i] * valores[i];
	}
		
	return sqrt(respo);
}

/*! Unitariza o vetor
**  Parâmetros: void
**  Retorno: void
*/
void vetor::unitario () {
	float vetTam = tamanho();
		
	for(int i = 0; i < tam; i++){
		valores[i] /= vetTam;
	}
}

/**************************************************************************************************************************
---------------------------------------------------- Funções da matriz ----------------------------------------------------
**************************************************************************************************************************/

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

#endif //ALGEBRA_H
