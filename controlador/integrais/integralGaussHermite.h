#ifndef INTEGRAL_GAUSS_HERMITE_H
#define INTEGRAL_GAUSS_HERMITE_H

#include <iostream>
#include <cmath>
#include "../parser/parser.h"

float gaussHermite (const int &qtdPontos, expre::expre *equacao);

float gaussHermiteN2 (expre::expre *equacao);
float gaussHermiteN3 (expre::expre *equacao);
float gaussHermiteN4 (expre::expre *equacao);

#endif //INTEGRAL_GAUSS_HERMITE_H