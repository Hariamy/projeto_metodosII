#ifndef POLINOMIO_H
#define POLINOMIO_H

#include <cmath>

#include "Funcao.h"

class Polinomio : public Funcao{

public:
	Polinomio();
	Polinomio(int grau);
	float calcular(float x);

private:
	int grau;
	
};

#endif //POLINOMIO_H