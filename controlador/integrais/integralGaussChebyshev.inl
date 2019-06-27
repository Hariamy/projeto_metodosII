#include "integral.h"

#define x21GCh -0.707107
#define x22GCh 0.707107
#define x31GCh -0.866025
#define x32GCh 0.0
#define x33GCh 0.866025
#define x41GCh -0.92388
#define x42GCh -0.382683
#define x43GCh 0.382683
#define x44GCh 0.92388

#define w21GCh 1.5708
#define w22GCh 1.5708
#define w31GCh 1.0472
#define w32GCh 1.0472
#define w33GCh 1.0472
#define w41GCh 0.785398
#define w42GCh 0.785398
#define w43GCh 0.785398
#define w44GCh 0.785398

/*! Calcula a integral por Gauss Chebyshev
** Parâmetros: A quantidade de pontos e a expressão
** Retornos: O valor da integral calculada
*/
float gaussChebyshev (const int &qtdPontos, expre::expre *equacao) {
    float resul = 0;
    
    switch (qtdPontos){
        case 2:
            resul = gaussChebyshevN2(equacao);
        break;
        case 3:
            resul = gaussChebyshevN3(equacao);
        break;
        case 4:
            resul = gaussChebyshevN4(equacao);
        break;
    }

    return resul;
}

/*! Resolve a integral de Gauss Chebyshev com 2 ponto
** Parâmetros: A expressão
** Retornos: O resultado da integral
*/
float gaussChebyshevN2 (expre::expre *equacao) {
    return (equacao->calcular(x21GCh) * w21GCh) + (equacao->calcular(x22GCh) * w22GCh);
}

/*! Resolve a integral de Gauss Chebyshev com 3 ponto
** Parâmetros: A expressão
** Retornos: O resultado da integral
*/
float gaussChebyshevN3 (expre::expre *equacao) {
    return (equacao->calcular(x31GCh) * w31GCh) + (equacao->calcular(x32GCh) * w32GCh)
         + (equacao->calcular(x33GCh) * w33GCh);
}

/*! Resolve a integral de Gauss Chebyshev com 4 ponto
** Parâmetros: A expressão
** Retornos: O resultado da integral
*/
float gaussChebyshevN4 (expre::expre *equacao) {
    return (equacao->calcular(x41GCh) * w41GCh) + (equacao->calcular(x42GCh) * w42GCh)
         + (equacao->calcular(x43GCh) * w43GCh) + (equacao->calcular(x44GCh) * w44GCh);
}