#ifndef INTEGRAL_H
#define INTEGRAL_H

#include <iostream>
#include <cmath>
#include "../parser/parser.h"

double gaussChebyshev (int qtdPontos, expre::expre *equacao);

double gaussChebyshevN (int &qtdPontos, expre::expre *equacao);

#endif //INTEGRAL_H