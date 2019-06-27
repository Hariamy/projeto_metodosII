#ifndef INTEGRAL_NEWTON_COTES_H
#define INTEGRAL_NEWTON_COTES_H

#include <iostream>
#include <cmath>
#include "../parser/parser.h"

#define FECHADA  0
#define ABERTA   1

float newtonCotes(const int &grau, const int &filosofia, const int &qtdDivisoes, const float intervalo[2], expre::expre *equacao);

float* initNcG1 (const int &filosofia, const int &qtdDivisoes, const float intervalo[2], float &h);
float* initNcG2 (const int &filosofia, const int &qtdDivisoes, const float intervalo[2], float &h);
float* initNcG3 (const int &filosofia, const int &qtdDivisoes, const float intervalo[2], float &h);
float* initNcG4 (const int &filosofia, const int &qtdDivisoes, const float intervalo[2], float &h);

float newtonCotesG1 (const int &filosofia, const float &inicio, const float &fim, const float &h, expre::expre *equacao);
float newtonCotesG2 (const int &filosofia, const float &inicio, const float &fim, const float &h, expre::expre *equacao);
float newtonCotesG3 (const int &filosofia, const float &inicio, const float &fim, const float &h, expre::expre *equacao);
float newtonCotesG4 (const int &filosofia, const float &inicio, const float &fim, const float &h, expre::expre *equacao);


#endif //INTEGRAL_NEWTON_COTES_H