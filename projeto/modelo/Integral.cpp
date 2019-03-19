#include "Integral.h"

Integral::Integral(){}

Integral::Integral(int filosofia, int grau){
	this->filosofia = filosofia;
	this->grau = grau;
}
	
void Integral::setFilosofia(int filosofia){
	this->filosofia = filosofia;
}

void Integral::setGrau(int valor){
	this->grau = grau;
}

float Integral::calcular(Funcao *funcao, float Xi, float Xf){
	return -1;
}

int Integral::getFilosofia(){
	return filosofia;
}
int Integral::getGrau(){
	return grau;
}