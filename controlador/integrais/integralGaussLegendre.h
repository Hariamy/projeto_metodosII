#ifndef INTEGRAL_GAUSS_LEGENDRE_H
#define INTEGRAL_GAUSS_LEGENDRE_H

#include <iostream>
#include <cmath>
#include "../parser/parser.h"

float gaussLegendre (const int &qtdPontos, const int &qtdDivisoes, const float intervalo[2], expre::expre *equacao);

float* dividir (const int &qtdDivisoes, const float intervalo[2]);
float mudarVariavelGL (const float &inicio, const float &fim, const int &valor);

float gaussLegendreN1 (const float &inicio, const float &fim, expre::expre *equacao);
float gaussLegendreN2 (const float &inicio, const float &fim, expre::expre *equacao);
float gaussLegendreN3 (const float &inicio, const float &fim, expre::expre *equacao);
float gaussLegendreN4 (const float &inicio, const float &fim, expre::expre *equacao);

#endif //INTEGRAL_GAUSS_LEGENDRE_H