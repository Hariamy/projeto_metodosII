#ifndef INTEGRAIS_H
#define INTEGRAIS_H

#include <iostream>
#include <cmath>
#include "../parser/parser.h"


// ------- \\ INÍCIO - NEWTON COTES // ------- \\

#define FECHADA  0
#define ABERTA   1

double newtonCotes(const int &grau, const int &filosofia, const int &qtdDivisoes, const double intervalo[2], expre::expre *equacao);
double newtonCotesErro(const int &grau, const int &filosofia, const double erro, const double intervalo[2], expre::expre *equacao);


// ------- \\ FIM - NEWTON COTES // ------- \\

// ------- \\ INÍCIO - GAUSS LEGENDRE // ------- \\

double gaussLegendre (const int &qtdPontos, const int &qtdDivisoes, const double intervalo[2], expre::expre *equacao);

double* dividir (const int &qtdDivisoes, const double intervalo[2]);
double mudarVariavelGL (const double &inicio, const double &fim, const int &valor);

double gaussLegendreN1 (const double &inicio, const double &fim, expre::expre *equacao);
double gaussLegendreN2 (const double &inicio, const double &fim, expre::expre *equacao);
double gaussLegendreN3 (const double &inicio, const double &fim, expre::expre *equacao);
double gaussLegendreN4 (const double &inicio, const double &fim, expre::expre *equacao);

// ------- \\ FIM - GAUSS LEGENDRE // ------- \\

// ------- \\ INÍCIO - GAUSS LAGUERRE // ------- \\

double gaussLaguerre (const int &qtdPontos, expre::expre *equacao);

double gaussLaguerreN2 (expre::expre *equacao);
double gaussLaguerreN3 (expre::expre *equacao);
double gaussLaguerreN4 (expre::expre *equacao);

// ------- \\ FIM - GAUSS LAGUERRE // ------- \\

// ------- \\ INÍCIO - GAUSS HERMITE // ------- \\

double gaussHermite (const int &qtdPontos, expre::expre *equacao);

double gaussHermiteN2 (expre::expre *equacao);
double gaussHermiteN3 (expre::expre *equacao);
double gaussHermiteN4 (expre::expre *equacao);

// ------- \\ FIM - GAUSS HERMITE // ------- \\

// ------- \\ INÍCIO - GAUSS CHEBYSHEV // ------- \\

double gaussChebyshev (int qtdPontos, expre::expre *equacao);


// ------- \\ FIM - GAUSS CHEBYSHEV // ------- \\




#endif//INTEGRAIS_H