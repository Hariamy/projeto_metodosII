#include <iostream>
#include <cmath>

#include "algebra.h"
#include "metodos.h"

int main(){
	float **valores, erro;
	int tamMatriz;
	
	std::cout << "Insira o tamanho da matriz: ";
	std::cin >> tamMatriz;
	
	valores = (float**)malloc(sizeof(float*) * tamMatriz);
	
	for(int i = 0; i < tamMatriz; i++){
		valores[i] = (float*)malloc(sizeof(float) * tamMatriz);
		for(int j = 0; j < tamMatriz; j++){
			std::cout << "mat[" << i <<", " << j << "] = ";
			std::cin >> valores[i][j];
		}
	}
	
	std::cout << "Insira o valor do erro: ";
	std::cin >> erro;
	
	alg::matriz mt(tamMatriz, valores);
	
	met::autoValVet respo = met::exponencial(mt, erro);
	
	met::matrizLU teste = met::construirLU(mt);
	
	std::cout << "Auto valor: " << respo.autoValor << "\nAuto vetor: ";
	
	for(int i = 0; i < tamMatriz; i++){
		std::cout << respo.autoVetor[i] << ' '; 
	}
	std::cout << '\n';
	
	for(int i = 0; i < tamMatriz; i++){
		for(int j = 0; j < tamMatriz; j++){
			std::cout << teste.L[i][j] << ' ';
		}
		std::cout << '\n';
	}
	
	std::cout << "\n\n";
	
	for(int i = 0; i < tamMatriz; i++){
		for(int j = 0; j < tamMatriz; j++){
			std::cout << teste.U[i][j] << ' ';
		}
		std::cout << '\n';
	}
	
	return 0;
}
