#ifndef BINARIO_H
#define BINARIO_H

#include "expre.h"

namespace expre{
    class soma: public binario {
    public:
        inline soma (expre *esq, expre *dir) : binario (esq, dir) { precedencia = 0; nome = new char[1]; nome[0] = '+'; }
        inline soma () : binario () { nome = new char[1]; nome[0] = '+'; }

        inline float calcular (const float &x);
    };

    class subtracao: public binario {
    public:
        inline subtracao (expre *esq, expre *dir) : binario (esq, dir) { precedencia = 0; nome = new char[1]; nome[0] = '-'; }
        inline subtracao () : binario () { nome = new char[1]; nome[0] = '-'; }

        inline float calcular (const float &x);
    };

    class multiplicacao: public binario {
    public:
        inline multiplicacao (expre *esq, expre *dir) : binario (esq, dir) { precedencia = 1; nome = new char[1]; nome[0] = '*'; }
        inline multiplicacao () : binario () { nome = new char[1]; nome[0] = '*'; }

        inline float calcular (const float &x);
    };

    class divisao: public binario {
    public:
        inline divisao (expre *esq, expre *dir) : binario (esq, dir) { precedencia = 1; nome = new char[1]; nome[0] = '*'; }
        inline divisao () : binario () { nome = new char[1]; nome[0] = '*'; }

        inline float calcular (const float &x);
    };

    class potencia: public binario {
    public:
        inline potencia (expre *esq, expre *dir) : binario (esq, dir) { precedencia = 1; nome = new char[1]; nome[0] = '^'; }
        inline potencia () : binario () { nome = new char[1]; nome[0] = '^'; }

        inline float calcular (const float &x);
    };
}

#include "binario.inl"

#endif //BINARIO_H