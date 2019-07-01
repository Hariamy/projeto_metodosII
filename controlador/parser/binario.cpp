#include "binario.h"

namespace expre{
    /*! Calcula a soma de duas expressões
    ** Parâmetros: O valor da variável
    ** Retornos: A soma das expressões
    */
    double soma::calcular (const double &x) {
        return filhoEsq->calcular(x) + filhoDir->calcular(x);
    }

    /*! Subtrai a expressão da esquerda pela direita
    ** Parâmetros: O valor da variável
    ** Retornos: A subtração das expressões
    */
    double subtracao::calcular (const double &x) {
        return filhoEsq->calcular(x) - filhoDir->calcular(x);
    }

    /*! Calcula a multiplicação de duas expressões
    ** Parâmetros: O valor da variável
    ** Retornos: A multiplicação das expressões
    */
    double multiplicacao::calcular (const double &x) {
        return filhoEsq->calcular(x) * filhoDir->calcular(x);
    }

    /*! Divide a espressão da esquerda pela direita
    ** Parâmetros: O valor da variável
    ** Retornos: A divisão das expressões
    */
    double divisao::calcular (const double &x) {
        return filhoEsq->calcular(x) / filhoDir->calcular(x);
    }

    /*! Calcula a expressão esquerda em potência da direita
    ** Parâmetros: O valor da variável
    ** Retornos: A potência das expressões
    */
    double potencia::calcular (const double &x) {
        return std::pow(filhoEsq->calcular(x), filhoDir->calcular(x));
    }
}