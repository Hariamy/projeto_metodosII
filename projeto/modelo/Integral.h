#ifndef INTEGRAL_H
#define INTEGRAL_H

#include <cmath>

#include "funcoes/Funcao.h"

class Integral{
public:
	Integral();
	Integral(int filosofia, int grau);
	
	void setFilosofia(int filosofia);
	void setGrau(int grau);
	void setXiXf(float Xi, float Xf);
	void setXi(float Xi);
	void setXf(float Xf);

	int getFilosofia();
	int getGrau();
	float getXi();
	float getXf();

	virtual float calcularErro(Funcao *funcao, float erro);
	virtual float calcularPartes(Funcao *funcao, int partes);

private:
	int grau, filosofia;
	float Xi, Xf;
};

#endif //INTEGRAL_H