#ifndef EXPRE_H
#define EXPRE_H

#include <cmath>

namespace expre {
    #define BINARIA            0
    #define UNARIA             1
    #define PARENTESESABRINDO  2
    #define PARENTESESFECHANDO 3
    #define CONSTANTE          4
    #define VARIAVEL           5

    class expre {
    public:
        int tipo;
        inline virtual float calcular (const float &x) = 0;
    };

    class binario: public expre {
    protected:
        expre *filhoDir, *filhoEsq;
    public:
        inline binario (expre *dir, expre *esq);
        inline binario ();

        inline void inserirDir (expre *dir);
        inline void inserirEsq (expre *esq);

        inline virtual float calcular (const float &x) = 0;

        inline ~binario() {delete(filhoDir); delete(filhoEsq);}
    };

    class unario: public expre {
    protected:
        expre *filho;
    public:
        inline unario (expre *novo);
        inline unario ();

        inline void inserirFilho (expre *novo);

        inline virtual float calcular (const float &x) = 0;

        inline ~unario () {delete(filho);}
    };

    class constante: public expre {
        float valor;
    public:
        constante (float novo);

        void inserirConstante (float novo);

        inline float calcular (const float &x);
    };

    class variavel: public expre {
    public:
        variavel ();
        inline float calcular (const float &x);
    };
}

#include "expre.inl"

#endif //EXPRE_H