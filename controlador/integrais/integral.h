#ifndef INTEGRAL_H
#define INTEGRAL_H

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

float gaussLegendre (const int &qtdPontos, const int &qtdDivisoes, const float intervalo[2], expre::expre *equacao);

float* dividir (const int &qtdDivisoes, const float intervalo[2]);
float mudarVariavelGL (const float &inicio, const float &fim, const int &valor);

float gaussLegendreN1 (const float &inicio, const float &fim, expre::expre *equacao);
float gaussLegendreN2 (const float &inicio, const float &fim, expre::expre *equacao);
float gaussLegendreN3 (const float &inicio, const float &fim, expre::expre *equacao);
float gaussLegendreN4 (const float &inicio, const float &fim, expre::expre *equacao);

float gaussLaguerre (const int &qtdPontos, expre::expre *equacao);

float gaussLaguerreN2 (expre::expre *equacao);
float gaussLaguerreN3 (expre::expre *equacao);
float gaussLaguerreN4 (expre::expre *equacao);

//inline float exponencialSimplesNC (const int &grau, const int &filosofia, const int &qtdDivisoes, const float intervalo[2], expre::expre *equacao);
//inline float exponencialSimplesGL (const int &qtdPontos, const int &qtdDivisoes, const float intervalo[2], expre::expre *equacao);

#include "integralNewtonCotes.inl"
#include "integralGaussLegendre.inl"
#include "integralGaussLaguerre.inl"

#endif //INTEGRAL_H