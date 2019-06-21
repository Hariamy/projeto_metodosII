#ifndef EXPRE_H
#define EXPRE_H

#include <cmath>

namespace expre {

  enum {BINARIA, UNARIA, PARENTESES, CONSTANTE, VARIAVEL};

  class expre {
  public:
    int tipo, precedencia;
    virtual float calcular (const float &x) = 0;
  };

  class binario: public expre {
  protected:
    expre *filhoDir, *filhoEsq;
  public:
    binario (expre *dir, expre *esq);
    binario ();

    void inserirDir (expre *dir);
    void inserirEsq (expre *esq);

    virtual float calcular (const float &x) = 0;

    ~binario() {delete(filhoDir); delete(filhoEsq);}
  };

  class unario: public expre {
  protected:
    expre *filho;
  public:
    unario (expre *novo);
    unario ();

    void inserirFilho (expre *novo);

    virtual float calcular (const float &x) = 0;

    ~unario () {delete(filho);}
  };

  class constante: public expre {
    float valor;
  public:
    constante (float novo);

    void inserirConstante (float novo);

    float calcular (const float &x);
  };

  class variavel: public expre {
  public:
    variavel ();
    float calcular (const float &x);
  };
}

#include "expre.inl"

#endif //EXPRE_H