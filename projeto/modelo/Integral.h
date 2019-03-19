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

	int getFilosofia();
	int getGrau();

	virtual float calcular(Funcao *funcao, float Xi, float Xf);

private:
	int grau, filosofia;
};

#endif //INTEGRAL_H