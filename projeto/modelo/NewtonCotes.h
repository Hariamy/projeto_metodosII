#ifndef NEWTON_GATES_H
#define NEWTON_GATES_H

#include <cmath>

#include "funcoes/Funcao.h"
#include "Integral.h"

class NewtonCotes : public Integral{
	
public:
	NewtonCotes();

	void setFilosofia(int filosofia);
	void setGrau(int grau);

	float calcular(Funcao *funcao, float Xi, float Xf);

private:
	int grau, filosofia;

};

#endif //NEWTON_GATES_H