#ifndef EXPRE_H
#define EXPRE_H

#include <cmath>
#include <cstring>

namespace expre {

  enum {BINARIA, UNARIA, PARENTESES, CONSTANTE, VARIAVEL};

  class expre {
  public:
    int tipo, precedencia;
    char *nome;

    virtual double calcular (const double &x) = 0;
  };

  class binario: public expre {
  protected:
    expre *filhoDir, *filhoEsq;
  public:
    binario (expre *dir, expre *esq);
    binario ();

    void inserirDir (expre *dir);
    void inserirEsq (expre *esq);

    virtual double calcular (const double &x) = 0;

    ~binario() {delete(filhoDir); delete(filhoEsq);}
  };

  class unario: public expre {
  protected:
    expre *filho;
  public:
    unario (expre *novo);
    unario ();

    void inserirFilho (expre *novo);

    virtual double calcular (const double &x) = 0;

    ~unario () {delete(filho);}
  };

  class constante: public expre {
    double valor;
  public:
    constante (double novo);

    void inserirConstante (double novo);

    double calcular (const double &x);
  };

  class variavel: public expre {
  public:
    variavel ();
    double calcular (const double &x);
  };
}

#endif //EXPRE_H