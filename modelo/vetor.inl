#include "algebra.h"

/*! Construtor do vetor
**  Parâmetros: Quantidade de elementos
**  Retorno: 
*/
vetor::vetor (int novoTam, float valIncial) {
	tam = novoTam;
	valores = new std::vector <float> (novoTam);		
	
	for(float &i:(*valores)){
		i = valIncial;
	}
}

/*! Acessa uma posição do vetor
**  Parâmetros: O indice da posição desejada
**  Retorno: O valor presente no indice
*/
float& vetor::operator [] (int pos) {
	return (*valores)[pos];
}
	
/*! Faz a cópia dos valores de um vetor
**  Parâmetros: O vetor que se deseja copiar
**  Retorno: void
*/
void vetor::operator = (vetor novosValores) {
	int posicao = 0;
	tam = novosValores.tam;

	(*valores).resize(tam);
		
	for(float &i:(*valores)){
		i = novosValores[posicao++];
	}
}

void vetor::operator = (vetor* novosValores) {
	*valores = *novosValores->valores;
	tam = valores->size();
	std::cout << tam << '\n';
}

/*! Faz a soma de dois vetores
**  Parâmetros: O vetor para somar
**  Retorno: O vetor somado
*/
vetor* vetor::operator + (vetor soma) {
	vetor* somVetor = new vetor(tam);
	int indice = 0;

	for(float &i:(*somVetor->valores)){
		i = (*valores)[indice] + soma[indice];
		indice++;
	}
		
	return somVetor;
}

/*! Faz a subtração de dois vetores
**  Parâmetros: O vetor para subtrair
**  Retorno: O subtraido somado
*/
vetor* vetor::operator - (vetor subtracao) {
	vetor *subVetor = new vetor(tam);
	int indice = 0;
			
	for(float &i:(*subVetor->valores)){
		i = (*valores)[indice] - subtracao[indice];
		indice++;
	}

	return subVetor;
}

/*! Multiplica o vetor por uma escalar
**  Parâmetros: Escalar para a multiplicação
**  Retorno: void
*/
void vetor::operator *  (float constante) {
	for(float &i:(*valores)){
		i *= constante;
	}
}

/*! Faz o produto escalar entre dois vetores
**  Parâmetros: O vetor para fazer o produto
**  Retorno: O valor do produto escalar
*/
float vetor::operator * (vetor vetMult) {
	float prodEscalar = 0;
		
	for(int i = 0; i < tam; i++){
		prodEscalar += (*valores)[i] * vetMult[i];
	}

	return prodEscalar;
}

/*! Tamanho do vetor
**  Parâmetros: void
**  Retorno: O tamanho do vetor
*/
float vetor::tamanho () {
	float respo = 0;
		
	for(float &i:(*valores)){
		respo += i * i;
	}
		
	return sqrt(respo);
}

/*! Unitariza o vetor
**  Parâmetros: void
**  Retorno: void
*/
void vetor::unitario () {
	float vetTam = tamanho();
		
	for(float &i:(*valores)){
		i /= vetTam;
	}
}

void vetor::mostrar_debug () {
	int pos = 0;

	for(float &i:(*valores)){
		std::cout << "[" << pos << "] = " << i << '\n';
		pos++;
	}
	std::cout << '\n';
}