#include "integralGaussHermite.h"

#define x21GHe -0.707107
#define x22GHe 0.707107
#define x31GHe -1.22474
#define x32GHe 0.0
#define x33GHe 1.22474
#define x41GHe -1.65068
#define x42GHe -0.524648
#define x43GHe 0.524648
#define x44GHe 1.65068

#define w21GHe 0.886227
#define w22GHe 0.886227
#define w31GHe 0.295409
#define w32GHe 1.18164
#define w33GHe 0.295409
#define w41GHe 0.0813128
#define w42GHe 0.804914
#define w43GHe 0.804914
#define w44GHe 0.0813128

/*! Calcula a integral por Gauss Hermite
** Parâmetros: A quantidade de pontos e a expressão
** Retornos: O valor da integral calculada
*/
float gaussHermite (const int &qtdPontos, expre::expre *equacao) {
    float resul = 0;
    
    switch (qtdPontos){
        case 2:
            resul = gaussHermiteN2(equacao);
        break;
        case 3:
            resul = gaussHermiteN3(equacao);
        break;
        case 4:
            resul = gaussHermiteN4(equacao);
        break;
    }

    return resul;
}

/*! Resolve a integral de Gauss Hermite com 2 ponto
** Parâmetros: A expressão
** Retornos: O resultado da integral
*/
float gaussHermiteN2 (expre::expre *equacao) {
    return (equacao->calcular(x21GHe) * w21GHe) + (equacao->calcular(x22GHe) * w22GHe);
}

/*! Resolve a integral de Gauss Hermite com 3 ponto
** Parâmetros: A expressão
** Retornos: O resultado da integral
*/
float gaussHermiteN3 (expre::expre *equacao) {
    return (equacao->calcular(x31GHe) * w31GHe) + (equacao->calcular(x32GHe) * w32GHe)
         + (equacao->calcular(x33GHe) * w33GHe);
}

/*! Resolve a integral de Gauss Hermite com 4 ponto
** Parâmetros: A expressão
** Retornos: O resultado da integral
*/
float gaussHermiteN4 (expre::expre *equacao) {
    return (equacao->calcular(x41GHe) * w41GHe) + (equacao->calcular(x42GHe) * w42GHe)
         + (equacao->calcular(x43GHe) * w43GHe) + (equacao->calcular(x44GHe) * w44GHe);
}