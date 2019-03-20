#include "NewtonGates.h"

NewtonGates::NewtonGates(){}

NewtonGates::NewtonGates(int filosofia, int grau) : Integral(filosofia, grau){}
	
float NewtonGates::calcularErro(Funcao *funcao, float erro){
	/*ESCREVA SEU CÓDIGO AQUI*/
	return 10.4;	
}

float NewtonGates::calcularPartes(Funcao *funcao, int partes){
	/*ESCREVA SEU CÓDIGO AQUI*/
	return -10.4;
}

float NewtonGates::calcularValor(Funcao *funcao){
	float resultado;
	if (getFilosofia()) { //PARA A FILOSOFIA ABERTA 
		switch(getGrau()) {
			case 1: // GRAU 1
				resultado = 0;
			break;

			case 2: // GRAU 2
				resultado = 0;
			break;

			case 3: // GRAU 3
				resultado = 0;
			break;

			case 4: // GRAU 4
				resultado = 0;
			break;
		}
	} else { //PARA FILOSOFIA FECHADA
		switch(getGrau()) {
			case 1: // GRAU 1
				resultado = 0;
			break;

			case 2: // GRAU 2
				resultado = 0;
			break;

			case 3: // GRAU 3
				resultado = 0;
			break;

			case 4: // GRAU 4
				resultado = 0;
			break;
		}
	}
	return resultado;
}