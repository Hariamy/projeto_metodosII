#include "NewtonCotes.h"

NewtonCotes::NewtonCotes(){
	filosofia = 1;
	grau = 1;
}

void NewtonCotes::setFilosofia(int filosofia){
	this->filosofia = filosofia;
}

void NewtonCotes::setGrau(int grau){
	this->grau = grau;
}


float NewtonCotes::calcular(Funcao *funcao, float Xi, float Xf){
	float resultado;
	if (filosofia) { //1 PARA A FILOSOFIA FECHADA 
		switch(grau) {
			case 1: // GRAU 1
				resultado = ((Xf - Xi)/2)*(funcao->calcular(Xi) + funcao->calcular(Xf));
			break;

		case 2: // GRAU 2
				resultado = ((Xf - Xi)/9)*(funcao->calcular(Xi) + 4*funcao->calcular((Xi+Xf)/2) + funcao->calcular(Xf));
			break;

			case 3: // GRAU 3
				resultado = 0;
			break;

			case 4: // GRAU 4
				resultado = 0;
			break;
		}
	} else { //0 PARA FILOSOFIA ABERTA
		switch(grau) {
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