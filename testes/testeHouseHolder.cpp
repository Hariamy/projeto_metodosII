#include <iostream>
#include "../controlador/autoVetorValor/sigularidade.h"

int main (){
	matriz A(3);

	std::cout << "Insira os valores:\n";

	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			std::cout << "M[ " << i << ", " << j << " ] = ";
			std::cin >> A.posicao(i, j);
		}
	}

	retornoHH *r = householder(A);

	A.mostrar_debug();
	r->A->mostrar_debug();
	r->H->mostrar_debug();

	return 0;
}