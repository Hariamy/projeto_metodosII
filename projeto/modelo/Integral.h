#ifndef INTEGRAL_H
#define INTEGRAL_H

#include <cmath>

#include "funcoes/Funcao.h"

class Integral{
public:
	Integral();

	virtual float calcular(Funcao *funcao, float Xi, float Xf);
	virtual void setGrau(int grau);
	virtual void setFilosofia(int filosofia);

private:

};

#endif //INTEGRAL_H