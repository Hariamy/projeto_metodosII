#ifndef SENO_H
#define SENO_H

#include <cmath>

#include "Funcao.h"

class Seno : public Funcao{
public:
	Seno();
	float calcular(float x);
};

#endif //SENO_H