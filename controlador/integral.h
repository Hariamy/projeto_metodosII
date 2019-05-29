#ifndef INTEGRAL_H
#define INTEGRAL_H

#include <iostream>
#include <cmath>
#include "parser/expre.h"

#define FECHADA  0
#define ABERTA   1

#define t11 0.0
#define t12 (std::sqrt(3.0) / 3.0)
#define t22 -(std::sqrt(3.0) / 3.0)
#define t13 0.0
#define t23 (std::sqrt(3.0 / 5.0))
#define t33 -(std::sqrt(3.0 / 5.0))
#define t14 (std::sqrt((3.0 - (2.0 * (std::sqrt(6.0 / 5.0)))) / 7.0))
#define t24 -(std::sqrt((3.0 - (2.0 * (std::sqrt(6.0 / 5.0)))) / 7.0))
#define t34 (std::sqrt((3.0 + (2.0 * (std::sqrt(6.0 / 5.0)))) / 7.0))
#define t44 -(std::sqrt((3.0 + (2.0 * (std::sqrt(6.0 / 5.0)))) / 7.0))

#define w11 2.0
#define w12 1.0
#define w22 1.0
#define w13 (8.0 / 9.0)
#define w23 (5.0 / 9.0)
#define w33 (5.0 / 9.0)
#define w14 ((18.0 + std::sqrt(30.0)) / 36.0)
#define w24 ((18.0 + std::sqrt(30.0)) / 36.0)
#define w34 ((18.0 - std::sqrt(30.0)) / 36.0)
#define w44 ((18.0 - std::sqrt(30.0)) / 36.0)
    

inline float newtonCotes(const int &grau, const int &filosofia, const int &qtdDivisoes, const float intervalo[2], expre::expre *equacao);

inline float* initNcG1 (const int &filosofia, const int &qtdDivisoes, const float intervalo[2], float &h);
inline float* initNcG2 (const int &filosofia, const int &qtdDivisoes, const float intervalo[2], float &h);
inline float* initNcG3 (const int &filosofia, const int &qtdDivisoes, const float intervalo[2], float &h);
inline float* initNcG4 (const int &filosofia, const int &qtdDivisoes, const float intervalo[2], float &h);

inline float newtonCotesG1 (const int &filosofia, const float &inicio, const float &fim, const float &h, expre::expre *equacao);
inline float newtonCotesG2 (const int &filosofia, const float &inicio, const float &fim, const float &h, expre::expre *equacao);
inline float newtonCotesG3 (const int &filosofia, const float &inicio, const float &fim, const float &h, expre::expre *equacao);
inline float newtonCotesG4 (const int &filosofia, const float &inicio, const float &fim, const float &h, expre::expre *equacao);

inline float gaussLegendre (const int &qtdPontos, const int &qtdDivisoes, const float intervalo[2], expre::expre *equacao);

inline float* dividir (const int &qtdDivisoes, const float intervalo[2]);
inline float mudarVariavelGL (const float &inicio, const float &fim, const int &valor);

inline float gaussLegendreN1 (const float &inicio, const float &fim, expre::expre *equacao);
inline float gaussLegendreN2 (const float &inicio, const float &fim, expre::expre *equacao);
inline float gaussLegendreN3 (const float &inicio, const float &fim, expre::expre *equacao);
inline float gaussLegendreN4 (const float &inicio, const float &fim, expre::expre *equacao);

//inline float exponencialSimplesNC (const int &grau, const int &filosofia, const int &qtdDivisoes, const float intervalo[2], expre::expre *equacao);
//inline float exponencialSimplesGL (const int &qtdPontos, const int &qtdDivisoes, const float intervalo[2], expre::expre *equacao);

#include "integralNewtonCotes.inl"
#include "integralGaussLegendre.inl"

#endif //INTEGRAL_H