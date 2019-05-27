#ifndef BINARIO_H
#define BINARIO_H

#include "expre.h"

namespace expre{
    class soma: public binario {
    public:
        inline soma (expre *dir, expre *esq) : binario (dir, esq) {}
        inline soma () : binario () {}

        inline float calcular (const float &x);
    };

    class subtracao: public binario {
    public:
        inline subtracao (expre *dir, expre *esq) : binario (dir, esq) {}
        inline subtracao () : binario () {}

        inline float calcular (const float &x);
    };

    class multiplicacao: public binario {
    public:
        inline multiplicacao (expre *dir, expre *esq) : binario (dir, esq) {}
        inline multiplicacao () : binario () {}

        inline float calcular (const float &x);
    };

    class divisao: public binario {
    public:
        inline divisao (expre *dir, expre *esq) : binario (dir, esq) {}
        inline divisao () : binario () {}

        inline float calcular (const float &x);
    };

    class potencia: public binario {
    public:
        inline potencia (expre *dir, expre *esq) : binario (dir, esq) {}
        inline potencia () : binario () {}

        inline float calcular (const float &x);
    };

/**************************************************************************************************************************
--------------------------------------------------------- Funções ---------------------------------------------------------
**************************************************************************************************************************/

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

#endif //BINARIO_H