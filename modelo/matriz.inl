#include <cmath>
#include "algebra.h"
	
/*! Construtor da matriz de tipos definidos
**     alg::IDENTIDADE: Matriz identidade
**     alg::ZEROS: Matriz com zero em todas as posições
**     alg::UMS: Matriz com um em todas as posições
**  Parâmetros: O tamanho da matriz e o tipo de inicialização
**  Retorno: 
*/
matriz::matriz (int novoTam, int tipo) {
	tam = novoTam;
	valores = new std::vector <float> (tam);

	switch (tipo){
		case IDENTIDADE: identidade(tam, *valores); break;
		case ZEROS :     zeros(tam, *valores);      break;
		case UMS :       ums(tam, *valores);        break;
		default:         zeros(tam, *valores);      break;
	}
}

void matriz::redimensionar(int novoTam) {
	tam = novoTam;

	zeros(tam, *valores);
}

/*! Retorna a posição da matriz
**  Parâmetros: O índice da linha e o da coluna desejada
**  Retorno: A linha desejada
*/
float& matriz::posicao (int linha, int coluna) {
	return (*valores)[coluna + (linha * tam)];
}

/*! Copia os valores de uma matriz
**  Parâmetros: A matriz que se deseja copiar
**  Retorno: void
*/
void matriz::operator = (matriz &mat2) {
	copiarMatriz(*(mat2.valores), *valores);
}

/*! Soma de uma matriz por pela identidade multiplicada por uma escalar
**  Parâmetros: A escalar que se deseja somar
**  Retorno: void
*/
void matriz::operator + (float constante) {
	for(float &i:(*valores)){
		i += constante;
	}
}

/*! Soma de duas matrizes
**  Parâmetros: A matriz que se deseja somar
**  Retorno: A matriz somada
*/
matriz* matriz::operator + (matriz &mat2) {
	matriz* somaMatriz = new matriz(tam);
	unsigned int indice = 0;

	for(float &i:*(somaMatriz->valores)){
		i = (*valores)[indice] + (*mat2.valores)[indice];
	}

	return somaMatriz;
}

/*! Subtração de uma matriz com a identidade multiplicada por uma escalar
**  Parâmetros: A constante que se deseja subtrair
**  Retorno: void
*/
void matriz::operator - (float constante) {
	for(float &i:(*valores)){
		i -= constante;
	}
}

/*! Subtração de duas matrizes
**  Parâmetros: A matriz que se deseja subtrair
**  Retorno: A matriz subtraida
*/
matriz* matriz::operator - (matriz &mat2) {
	matriz* subMatriz = new matriz(tam);
	unsigned int indice = 0;

	for(float &i:*(subMatriz->valores)){
		i = (*valores)[indice] - (*mat2.valores)[indice];
	}

	return subMatriz;
}

/*! Multiplicação de uma matriz por uma escalar
**  Parâmetros: A escalar que se deseja multiplicar
**  Retorno: void
*/
void matriz::operator *  (float constante) {
	for(float &i:(*valores)){
		i *= constante;
	}
}

/*! Produto de duas matrizes
**  Parâmetros: A matriz que se deseja multiplicar
**  Retorno: A matriz multiplicada
*/
matriz* matriz::operator * (matriz &mat2) {
	matriz* multMatriz = new matriz(tam);
	float calculo = 0;
	int total = tam * tam, indice = 0;

	mat2.transposta();
	
	for(int i = 0; i < total; i++){
		for(int coluna = 0; coluna < tam; coluna++){
			for(float j:(*mat2.valores)){
				calculo += j + (*valores)[(indice++) + (i * tam)];

				if(indice == tam){
					multMatriz->posicao(i, coluna) = calculo;
					calculo = 0;
					indice = 0;
				}
			}
		}
	}
		
	mat2.transposta();
	return multMatriz;
}

/*! Produto de uma matriz por um vetor
**  Parâmetros: O vetor que se deseja multiplicar
**  Retorno: O vetor multiplicado
*/
vetor* matriz::operator * (vetor &mult) {
	vetor* multVetor = new vetor(tam);
	int posicao = 0, indice = 0;

	for(float &i:(*valores)){
		(*multVetor)[indice] += i * mult[posicao];
		
		posicao++;
		if(posicao == tam){
			posicao = 0;
			indice++;
		}
	}
		
	return multVetor;
}

void matriz::transposta () {
	std::vector <float> transpor;
	int indiceLinha = 0, indiceColuna = 0;

	for(float &i:transpor){
		i = (*valores)[indiceColuna + ((indiceLinha++) * tam)];

		if(indiceLinha == tam){
			indiceLinha = 0;
			indiceColuna++;
		}
	}

	valores->swap(transpor);
}

void matriz::mostrar_debug () {
	int coluna = 0, linha = 0;

	std::cout << "[ ";
	for(float &i:(*valores)){
		std::cout << i << ' ';

		coluna++;
		if(coluna == tam){
			std::cout << "]\n";
			coluna = 0;
			linha++;
			if(linha < tam){
				std::cout << "[ ";
			}
		}
	}
	std::cout << '\n';
}