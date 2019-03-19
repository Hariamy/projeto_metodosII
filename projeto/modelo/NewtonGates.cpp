#include "NewtonGates.h"

NewtonGates::NewtonGates(){}

NewtonGates::NewtonGates(int filosofia, int grau) : Integral(filosofia, grau){}
	
float NewtonGates::calcular(Funcao *funcao, float Xi, float Xf){
	/*ESCREVA SEU CÓDIGO AQUI*/
}

float NewtonGates::calcularValor(Funcao *funcao, float Xi, float Xf){
	float resultado;
	if (getFilosofia()) { //PARA A FILOSOFIA ABERTA
		switch(getGrau()) {
			case 1: // GRAU 1
				reultado = 
			break;

			case 2: // GRAU 2
			break;

			case 3: // GRAU 3
			break;

			case 4: // GRAU 4
			break;
		}
	} else { //PARA FILOSOFIA FECHADA
		switch(getGrau()) {
			case 1: // GRAU 1
			break;

			case 2: // GRAU 2
			break;

			case 3: // GRAU 3
			break;

			case 4: // GRAU 4
			break;
		}
	}
}