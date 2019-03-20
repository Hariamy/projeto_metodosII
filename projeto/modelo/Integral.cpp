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

void Integral::setXiXf(float Xi, float Xf){
	this->Xi = Xi;
	this->Xf = Xf;
}

void Integral::setXi(float Xi){
	this->Xi = Xi;
}

void Integral::setXf(float Xf){
	this->Xf = Xf;
}

float Integral::getXi(){
	return Xi;
}

float Integral::getXf(){
	return Xf;
}

int Integral::getFilosofia(){
	return filosofia;
}

int Integral::getGrau(){
	return grau;
}


float Integral::calcularErro(Funcao *funcao, float erro){
	return -1;
}

float Integral::calcularPartes(Funcao *funcao, int partes){
	return -1;
}