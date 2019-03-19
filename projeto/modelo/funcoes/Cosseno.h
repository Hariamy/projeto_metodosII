#ifndef COSSENO_H
#define COSSENO_H

#include <cmath>

#include "Funcao.h"

class Cosseno : public Funcao{
public:
	Cosseno();
	float calcular(float x);
};

#endif //COSSENO_H