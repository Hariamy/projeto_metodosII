#include "integralGaussChebyshev.h"

/*! Calcula a integral por Gauss Chebyshev
** Parâmetros: A quantidade de pontos e a expressão
** Retornos: O valor da integral calculada
*/
double gaussChebyshev (int qtdPontos, expre::expre *equacao) {
    double resul = 0;

    resul = gaussChebyshevN(qtdPontos, equacao);

    return resul;
}

/*! Resolve a integral de Gauss Chebyshev com N ponto
** Parâmetros: A expressão
** Retornos: O resultado da integral
*/
double gaussChebyshevN (int &qtdPontos, expre::expre *equacao) {
    double xi = 0.0,
          wi = 0.0,
          resul  = 0,
          n = (double)qtdPontos;

    for (int i = 0; i < qtdPontos; i++) {
        xi = std::cos((((i) - 0.5)*M_PI)/(n));
        wi = M_PI/n;

        resul += equacao->calcular(xi)*wi;
    }
    
    return resul;
}