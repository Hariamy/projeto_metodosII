#include "expre.h"

namespace expre{
  /*! Inicializa as operações binárias
  ** Parâmetros: As duas operações filhas
  ** Retornos: void
  */
  binario::binario (expre *dir, expre *esq) : filhoDir(dir), filhoEsq(esq) {
    tipo = BINARIA;
  }

  /*! Inicializa as operações binárias com valores nulos
  ** Parâmetros: void
  ** Retornos: void
  */
  binario::binario () : filhoDir(NULL), filhoEsq(NULL) {
    tipo = BINARIA;
  }

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
  unario::unario (expre *novo) : filho(novo) {
    tipo = UNARIA;
    precedencia = 3;
  }

  /*! Inicializa as operações unárias com valores nulos
  ** Parâmetros: void
  ** Retornos: void
  */
  unario::unario () {
    tipo = UNARIA;
    precedencia = 3;
  }

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
  constante::constante (float novo) : valor(novo) {
    tipo = CONSTANTE;
    precedencia = 0;
  }

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

  /*! Inicializa a variável
  ** Parâmetros: void
  ** Retornos: void
  */
  variavel::variavel () {
    tipo = VARIAVEL;
    precedencia = 0;
  }

  /*! Retorna o valor da variável
  ** Parâmetros: O valor da variável
  ** Retornos: O valor da variável
  */
  float variavel::calcular (const float &x) {
    return x;
  }
}