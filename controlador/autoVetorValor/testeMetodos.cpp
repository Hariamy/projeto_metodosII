#include <iostream>
#include <cmath>
#include <ctime>

#include "../modelo/algebra.h"
#include "metodos.h"

int main(){
	matriz mt(0);
	float erro;
	int tamMatriz;
	time_t inicio, fim;
	
	std::cout << "Insira o tamanho da matriz: ";
	std::cin >> tamMatriz;
	
	mt.redimensionar(tamMatriz);

	for(int i = 0; i < tamMatriz; i++){
		for(int j = 0; j < tamMatriz; j++){
			std::cout << "mat[" << i <<", " << j << "] = ";
			std::cin >> mt.posicao(i, j);
		}
	}
	
	std::cout << "Insira o valor do erro: ";
	std::cin >> erro;
	
	inicio = clock();
	autoValVet *respoMaior = potencia(mt, erro), *respoMenor = potenciaInversa(mt, erro);
	fim = clock();

	matrizLU *teste = construirLU(mt);
	std::cout << "\nAuto valor maior: " << respoMaior->autoValor << "\nAuto vetor:\n";
	
	respoMaior->autoVetor->mostrar_debug();

	std::cout << "\nAuto valor menor: " << respoMenor->autoValor << "\nAuto vetor:\n";
	
	respoMenor->autoVetor->mostrar_debug();

	std::cout << '\n';
	std::cout << "Matriz L:\n";
	teste->L->mostrar_debug();
	std::cout << "\n\n";
	
	std::cout << "Matriz U:\n";
	teste->U->mostrar_debug();

	matriz *inversa = inversaLU((*teste));
	std::cout << "\n\n";

	std::cout << "Matriz Inversa:\n";
	inversa->mostrar_debug();

	std::cout << "\nTempo percorrid: " << difftime(fim, inicio) << " ms.\n";
	
	return 0;
}