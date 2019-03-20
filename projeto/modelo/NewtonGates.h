#ifndef NEWTON_GATES_H
#define NEWTON_GATES_H

#include <cmath>

#include "funcoes/Funcao.h"
#include "Integral.h"

class NewtonGates : public Integral{
	
public:
	NewtonGates();
	NewtonGates(int filosofia, int grau);
	
	float calcularErro(Funcao *funcao, float erro);
	float calcularPartes(Funcao *funcao, int partes);

private:
	float calcularValor(Funcao *funcao);

};

#endif //NEWTON_GATES_H