#ifndef INTEGRAL_H
#define INTEGRAL_H

#include <iostream>
#include <cmath>
#include "../parser/parser.h"

float gaussChebyshev (int qtdPontos, expre::expre *equacao);

float gaussChebyshevN (int &qtdPontos, expre::expre *equacao);

#endif //INTEGRAL_H