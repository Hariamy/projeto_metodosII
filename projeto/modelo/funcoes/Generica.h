#ifndef GENERICA_H
#define GENERICA_H

#include <cmath>

#include "Funcao.h"

class Generica : public Funcao{
public:
	Generica();
	float calcular(float x);
};

#endif //GENERICA_H