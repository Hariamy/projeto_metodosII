#include <iostream>
#include <cmath>

#include "../modelo/algebra.h"
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
	
	matriz mt(tamMatriz, valores);
	
	autoValVet respoMaior = potencia(mt, erro), respoMenor = potenciaInversa(mt, erro);
	
	matrizLU teste = construirLU(mt);
	
	std::cout << "\nAuto valor maior: " << respoMaior.autoValor << "\nAuto vetor: ";
	
	for(int i = 0; i < tamMatriz; i++){
		std::cout << respoMaior.autoVetor[i] << ' '; 
	}
	std::cout << "\nAuto valor menor: " << respoMenor.autoValor << "\nAuto vetor: ";
	
	for(int i = 0; i < tamMatriz; i++){
		std::cout << respoMenor.autoVetor[i] << ' '; 
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

	matriz inversa = inversaLU(teste);
	std::cout << "\n\n";

	for(int i = 0; i < tamMatriz; i++){
		for(int j = 0; j < tamMatriz; j++){
			std::cout << inversa[i][j] << ' ';
		}
		std::cout << '\n';
	}
	
	return 0;
}