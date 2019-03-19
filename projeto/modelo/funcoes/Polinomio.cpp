#include "Polinomio.h"


Polinomio::Polinomio(){};

Polinomio::Polinomio(int grau){
	this->grau = grau;
}

float Polinomio::calcular(float x){
	return pow(x, grau);
}