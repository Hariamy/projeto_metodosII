#ifndef INTEGRAL_GAUSS_LAGURERRE_H
#define INTEGRAL_GAUSS_LAGURERRE_H

#include <iostream>
#include <cmath>
#include "../parser/parser.h"

double gaussLaguerre (const int &qtdPontos, expre::expre *equacao);

double gaussLaguerreN2 (expre::expre *equacao);
double gaussLaguerreN3 (expre::expre *equacao);
double gaussLaguerreN4 (expre::expre *equacao);

#endif //INTEGRAL_GAUSS_LAGURERRE_H