#ifndef INTEGRAL_H
#define INTEGRAL_H

#include <iostream>
#include <cmath>
#include "../parser/parser.h"

float gaussChebyshev (const int &qtdPontos, expre::expre *equacao);

float gaussChebyshevN2 (expre::expre *equacao);
float gaussChebyshevN3 (expre::expre *equacao);
float gaussChebyshevN4 (expre::expre *equacao);

#endif //INTEGRAL_H