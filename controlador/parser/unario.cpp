#include "unario.h"

namespace expre{
    /*! Calcula o seno da expressão
    ** Parâmetros: O valor da variável
    ** Retornos: O seno da expressão
    */
    double sen::calcular (const double &x) {
        return std::sin(filho->calcular(x));
    }

    /*! Calcula o cosseno da expressão
    ** Parâmetros: O valor da variável
    ** Retornos: O cosseno da expressão
    */
    double cos::calcular (const double &x) {
        return std::cos(filho->calcular(x));
    }

    /*! Calcula a tangente da expressão
    ** Parâmetros: O valor da variável
    ** Retornos: A tangente da expressão
    */
    double tan::calcular (const double &x) {
        return std::tan(filho->calcular(x));
    }

    /*! Calcula o logarítmo da expressão
    ** Parâmetros: O valor da variável
    ** Retornos: O logarítmo da expressão
    */
    double log::calcular (const double &x) {
        return std::log(filho->calcular(x));
    }

    /*! Calcula a exponêncial da expressão
    ** Parâmetros: O valor da variável
    ** Retornos: A exponêncial da expressão
    */
    double exp::calcular (const double &x) {
        return std::exp(filho->calcular(x));
    }
}