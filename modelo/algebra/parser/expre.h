#ifndef EXPRE_H
#define EXPRE_H

#include <cmath>

namespace expre {
    class expre {
    public:
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
        inline float calcular (const float &x);
    };

/**************************************************************************************************************************
--------------------------------------------------------- Funções ---------------------------------------------------------
**************************************************************************************************************************/

    /*! Inicializa as operações binárias
    ** Parâmetros: As duas operações filhas
    ** Retornos: void
    */
    binario::binario (expre *dir, expre *esq) : filhoDir(dir), filhoEsq(esq) {}

    /*! Inicializa as operações binárias com valores nulos
    ** Parâmetros: void
    ** Retornos: void
    */
    binario::binario () : filhoDir(NULL), filhoEsq(NULL) {}

    /*! Insere filho direito
    ** Parâmetros: A operação filha direita
    ** Retornos: void
    */
    void binario::inserirDir (expre *dir) {
        filhoDir = dir;
    }

    /*! Insere filho esquerdo
    ** Parâmetros: A operação filha esquerda
    ** Retornos: void
    */
    void binario::inserirEsq (expre *esq) {
        filhoEsq = esq;
    }

    /*! Inicializa as operações unárias
    ** Parâmetros: A operação filha
    ** Retornos: void
    */
    unario::unario (expre *novo) : filho(novo) {}

    /*! Inicializa as operações unárias com valores nulos
    ** Parâmetros: void
    ** Retornos: void
    */
    unario::unario () : filho(NULL) {}

    /*! Insere filho
    ** Parâmetros: A operação filha
    ** Retornos: void
    */
    void unario::inserirFilho (expre *novo) {
        filho = novo;
    }

    /*! Inicializa a constante
    ** Parâmetros: O valor da constante
    ** Retornos: void
    */
    constante::constante (float novo) : valor(novo) {}

    /*! Insere um novo valor como constante
    ** Parâmetros: O valor da constante
    ** Retornos: void
    */
    void constante::inserirConstante (float novo) {
        valor = novo;
    }

    /*! Retorna o valor da constante
    ** Parâmetros: O valor da variável
    ** Retornos: O valor da constante
    */
    float constante::calcular (const float &x) {
        return valor;
    }

    /*! Retorna o valor da variável
    ** Parâmetros: O valor da variável
    ** Retornos: O valor da variável
    */
    float variavel::calcular (const float &x) {
        return x;
    }
}

#endif //EXPRE_H