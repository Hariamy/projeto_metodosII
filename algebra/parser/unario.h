#ifndef UNARIO_H
#define UNARIO_H

#include "expre.h"

namespace expre {
    class sen: public unario {
    public:
        inline sen (expre *novo) : unario (novo) {}
        inline sen () : unario () {}

        inline float calcular (const float &x);
    };

    class cos: public unario {
    public:
        inline cos (expre *novo) : unario (novo) {}
        inline cos () : unario () {}

        inline float calcular (const float &x);
    };

    class tan: public unario {
    public:
        inline tan (expre *novo) : unario (novo) {}
        inline tan () : unario () {}

        inline float calcular (const float &x);
    };

    class log: public unario {
    public:
        inline log (expre *novo) : unario (novo) {}
        inline log () : unario () {}

        inline float calcular (const float &x);
    };

/**************************************************************************************************************************
--------------------------------------------------------- Funções ---------------------------------------------------------
**************************************************************************************************************************/

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

#endif //UNARIO_H