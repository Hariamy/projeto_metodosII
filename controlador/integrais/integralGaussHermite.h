#ifndef INTEGRAL_GAUSS_HERMITE_H
#define INTEGRAL_GAUSS_HERMITE_H

#include <iostream>
#include <cmath>
#include "../parser/parser.h"

double gaussHermite (const int &qtdPontos, expre::expre *equacao);

double gaussHermiteN2 (expre::expre *equacao);
double gaussHermiteN3 (expre::expre *equacao);
double gaussHermiteN4 (expre::expre *equacao);

#endif //INTEGRAL_GAUSS_HERMITE_H