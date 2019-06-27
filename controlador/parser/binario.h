#ifndef BINARIO_H
#define BINARIO_H

#include "expre.h"

namespace expre{
    class soma: public binario {
    public:
        soma (expre *esq, expre *dir) : binario (esq, dir) { precedencia = 0; nome = new char[1]; nome[0] = '+'; }
        soma () : binario () { nome = new char[1]; nome[0] = '+'; }

        float calcular (const float &x);
    };

    class subtracao: public binario {
    public:
        subtracao (expre *esq, expre *dir) : binario (esq, dir) { precedencia = 0; nome = new char[1]; nome[0] = '-'; }
        subtracao () : binario () { nome = new char[1]; nome[0] = '-'; }

        float calcular (const float &x);
    };

    class multiplicacao: public binario {
    public:
        multiplicacao (expre *esq, expre *dir) : binario (esq, dir) { precedencia = 1; nome = new char[1]; nome[0] = '*'; }
        multiplicacao () : binario () { nome = new char[1]; nome[0] = '*'; }

        float calcular (const float &x);
    };

    class divisao: public binario {
    public:
        divisao (expre *esq, expre *dir) : binario (esq, dir) { precedencia = 1; nome = new char[1]; nome[0] = '*'; }
        divisao () : binario () { nome = new char[1]; nome[0] = '*'; }

        float calcular (const float &x);
    };

    class potencia: public binario {
    public:
        potencia (expre *esq, expre *dir) : binario (esq, dir) { precedencia = 1; nome = new char[1]; nome[0] = '^'; }
        potencia () : binario () { nome = new char[1]; nome[0] = '^'; }

        float calcular (const float &x);
    };
}

#endif //BINARIO_H