#include "unario.h"

namespace expre{
    /*! Calcula o seno da expressão
    ** Parâmetros: O valor da variável
    ** Retornos: O seno da expressão
    */
    float sen::calcular (const float &x) {
        return std::sin(filho->calcular(x));
    }

    /*! Calcula o cosseno da expressão
    ** Parâmetros: O valor da variável
    ** Retornos: O cosseno da expressão
    */
    float cos::calcular (const float &x) {
        return std::cos(filho->calcular(x));
    }

    /*! Calcula a tangente da expressão
    ** Parâmetros: O valor da variável
    ** Retornos: A tangente da expressão
    */
    float tan::calcular (const float &x) {
        return std::tan(filho->calcular(x));
    }

    /*! Calcula o logarítmo da expressão
    ** Parâmetros: O valor da variável
    ** Retornos: O logarítmo da expressão
    */
    float log::calcular (const float &x) {
        return std::log(filho->calcular(x));
    }
}