#ifndef BINARIO_H
#define BINARIO_H

#include "expre.h"

namespace expre{
    class soma: public binario {
    public:
        inline soma (expre *dir, expre *esq) : binario (dir, esq) { precedencia = 0; }
        inline soma () : binario () {}

        inline float calcular (const float &x);
    };

    class subtracao: public binario {
    public:
        inline subtracao (expre *dir, expre *esq) : binario (dir, esq) { precedencia = 0; }
        inline subtracao () : binario () {}

        inline float calcular (const float &x);
    };

    class multiplicacao: public binario {
    public:
        inline multiplicacao (expre *dir, expre *esq) : binario (dir, esq) { precedencia = 1; }
        inline multiplicacao () : binario () {}

        inline float calcular (const float &x);
    };

    class divisao: public binario {
    public:
        inline divisao (expre *dir, expre *esq) : binario (dir, esq) { precedencia = 1; }
        inline divisao () : binario () {}

        inline float calcular (const float &x);
    };

    class potencia: public binario {
    public:
        inline potencia (expre *dir, expre *esq) : binario (dir, esq) { precedencia = 1; precedencia = 1; }
        inline potencia () : binario () {}

        inline float calcular (const float &x);
    };
}

#include "binario.inl"

#endif //BINARIO_H