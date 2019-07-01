#ifndef INTEGRAL_NEWTON_COTES_H
#define INTEGRAL_NEWTON_COTES_H

#include <iostream>
#include <cmath>
#include "../parser/parser.h"

#define FECHADA  0
#define ABERTA   1

double newtonCotes(const int &grau, const int &filosofia, const int &qtdDivisoes, const double intervalo[2], expre::expre *equacao);

double* initNcG1 (const int &filosofia, const int &qtdDivisoes, const double intervalo[2], double &h);
double* initNcG2 (const int &filosofia, const int &qtdDivisoes, const double intervalo[2], double &h);
double* initNcG3 (const int &filosofia, const int &qtdDivisoes, const double intervalo[2], double &h);
double* initNcG4 (const int &filosofia, const int &qtdDivisoes, const double intervalo[2], double &h);

double newtonCotesG1 (const int &filosofia, const double &inicio, const double &fim, const double &h, expre::expre *equacao);
double newtonCotesG2 (const int &filosofia, const double &inicio, const double &fim, const double &h, expre::expre *equacao);
double newtonCotesG3 (const int &filosofia, const double &inicio, const double &fim, const double &h, expre::expre *equacao);
double newtonCotesG4 (const int &filosofia, const double &inicio, const double &fim, const double &h, expre::expre *equacao);


#endif //INTEGRAL_NEWTON_COTES_H