#include <iostream>
#include "../controlador/autoVetorValor/sigularidade.h"

int main (){
	matriz A(4);

	A.posicao(0, 0) = 4;
	A.posicao(0, 1) = 1;
	A.posicao(0, 2) = -2;
	A.posicao(0, 3) = 2;
	
	A.posicao(1, 0) = 1;
	A.posicao(1, 1) = 2;
	A.posicao(1, 2) = 0;
	A.posicao(1, 3) = 1;

	A.posicao(2, 0) = -2;
	A.posicao(2, 1) = 0;
	A.posicao(2, 2) = 3;
	A.posicao(2, 3) = -2;

	A.posicao(3, 0) = 2;
	A.posicao(3, 1) = 1;
	A.posicao(3, 2) = -2;
	A.posicao(3, 3) = -1;
	A.mostrar_debug();


	retornoHH *r = householder(A);

	r->A->mostrar_debug();
	r->H->mostrar_debug();

	return 0;
}