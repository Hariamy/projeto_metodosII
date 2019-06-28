#ifndef SINGULARIDADE_H
#define SINGULARIDADE_H

#include <iostream>
#include <cmath>
#include "../../modelo/algebra.h"

class retornoHH {

public:
	retornoHH(matriz * A, matriz * H) {
		this->A = A;
		this->H = H;
	}
	
	retornoHH() {
		this->A = NULL;
		this->H = NULL;
	}


	matriz* A;
	matriz* H;
};

retornoHH * householder (matriz &Ab);


#endif //SINGULARIDADE_H
