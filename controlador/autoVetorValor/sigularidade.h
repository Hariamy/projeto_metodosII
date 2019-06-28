#ifndef SINGULARIDADE_H
#define SINGULARIDADE_H

#include <iostream>
#include <cmath>
#include "../../modelo/algebra.h"

struct retornoHouseHolder {
	matriz* A;
	matriz* H;
};

typedef struct retornoHouseHolder retornoHH;

retornoHH householder (matriz &A);


#endif //SINGULARIDADE_H
