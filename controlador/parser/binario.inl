#include "binario.h"

namespace expre{
    /*! Calcula a soma de duas expressões
    ** Parâmetros: O valor da variável
    ** Retornos: A soma das expressões
    */
    float soma::calcular (const float &x) {
        return filhoDir->calcular(x) + filhoEsq->calcular(x);
    }

    /*! Subtrai a expressão da esquerda pela direita
    ** Parâmetros: O valor da variável
    ** Retornos: A subtração das expressões
    */
    float subtracao::calcular (const float &x) {
        return filhoDir->calcular(x) - filhoEsq->calcular(x);
    }

    /*! Calcula a multiplicação de duas expressões
    ** Parâmetros: O valor da variável
    ** Retornos: A multiplicação das expressões
    */
    float multiplicacao::calcular (const float &x) {
        return filhoDir->calcular(x) * filhoEsq->calcular(x);
    }

    /*! Divide a espressão da esquerda pela direita
    ** Parâmetros: O valor da variável
    ** Retornos: A divisão das expressões
    */
    float divisao::calcular (const float &x) {
        return filhoDir->calcular(x) / filhoEsq->calcular(x);
    }

    /*! Calcula a expressão esquerda em potência da direita
    ** Parâmetros: O valor da variável
    ** Retornos: A potência das expressões
    */
    float potencia::calcular (const float &x) {
        return std::pow(filhoDir->calcular(x), filhoEsq->calcular(x));
    }
}