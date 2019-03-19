#ifndef NEWTON_GATES_H
#define NEWTON_GATES_H

#include <cmath>

#include "funcoes/Funcao.h"
#include "Integral.h"

class NewtonGates : public Integral{
	
public:
	NewtonGates();
	NewtonGates(int filosofia, int grau);
	
	float calcular(Funcao *funcao, float Xi, float Xf);

private:
	float calcularValor(Funcao *funcao, float Xi, float Xf);

};

#endif //NEWTON_GATES_H