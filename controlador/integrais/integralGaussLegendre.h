#ifndef INTEGRAL_GAUSS_LEGENDRE_H
#define INTEGRAL_GAUSS_LEGENDRE_H

#include <iostream>
#include <cmath>
#include "../parser/parser.h"

double gaussLegendre (const int &qtdPontos, const int &qtdDivisoes, const double intervalo[2], expre::expre *equacao);

double* dividir (const int &qtdDivisoes, const double intervalo[2]);
double mudarVariavelGL (const double &inicio, const double &fim, const int &valor);

double gaussLegendreN1 (const double &inicio, const double &fim, expre::expre *equacao);
double gaussLegendreN2 (const double &inicio, const double &fim, expre::expre *equacao);
double gaussLegendreN3 (const double &inicio, const double &fim, expre::expre *equacao);
double gaussLegendreN4 (const double &inicio, const double &fim, expre::expre *equacao);

#endif //INTEGRAL_GAUSS_LEGENDRE_H