#include "vetor.h"

/*! Construtor do vetor
**  Parâmetros: Quantidade de elementos
**  Retorno: 
*/
vetor::vetor (int novoTam, double valIncial) {
	tam = novoTam;
	valores = new std::vector <double> (novoTam);		
	
	for(double &i:(*valores)){
		i = valIncial;
	}
}

/*! Acessa uma posição do vetor
**  Parâmetros: O indice da posição desejada
**  Retorno: O valor presente no indice
*/
double& vetor::operator [] (int pos) {
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
		
	for(double &i:(*valores)){
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

	for(double &i:(*somVetor->valores)){
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
			
	for(double &i:(*subVetor->valores)){
		i = (*valores)[indice] - subtracao[indice];
		indice++;
	}

	return subVetor;
}

/*! Multiplica o vetor por uma escalar
**  Parâmetros: Escalar para a multiplicação
**  Retorno: void
*/
void vetor::operator *  (double constante) {
	for(double &i:(*valores)){
		i *= constante;
	}
}

/*! Faz o produto escalar entre dois vetores
**  Parâmetros: O vetor para fazer o produto
**  Retorno: O valor do produto escalar
*/
double vetor::operator * (vetor vetMult) {
	double prodEscalar = 0;
		
	for(int i = 0; i < tam; i++){
		prodEscalar += (*valores)[i] * vetMult[i];
	}

	return prodEscalar;
}

/*! Tamanho do vetor
**  Parâmetros: void
**  Retorno: O tamanho do vetor
*/
double vetor::tamanho () {
	double respo = 0;
		
	for(double &i:(*valores)){
		respo += i * i;
	}
		
	return sqrt(respo);
}

/*! Unitariza o vetor
**  Parâmetros: void
**  Retorno: void
*/
void vetor::unitario () {
	double vetTam = tamanho();
		
	for(double &i:(*valores)){
		i /= vetTam;
	}
}

void vetor::mostrar_debug () {
	int pos = 0;

	for(double &i:(*valores)){
		std::cout << "[" << pos << "] = " << i << '\n';
		pos++;
	}
	std::cout << '\n';
}