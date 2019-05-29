#include "algebra.h"

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