package Modelo.Matriz.utils

import Modelo.Matriz.Matriz

/**
  * Classe que realiza eleiminacao Gaussiana
  */
object GerarMatrizEliminacaoGauss {

  /**
    * O metodo faz a eliminacao gaussiana, porem nao ocorre solucao do sistema linear
    * @param A matriz do sistema
    * @param b vetor coluna de constantes
    * @return a tupla( matriz A na forma triangular superior , vetor b alterado)
    */
  def apply(A: Matriz , b: Matriz): (Matriz,Matriz) = {
    for(k <- 0 until A.getLinhas-1){
      for(i <- k+1 until A.getLinhas ){
        val m:Double = -A(i,k)/A(k,k)
        for(j <- k+1 until A.getLinhas){

          A.setValor(i,j, A(i,j) + (m * A(k,j) ) )
        }
        b.setValor(i,0,b(i,0) + (m * b(k,0) ) )
      }
    }

    for{
      i <- 0 until A.getLinhas
      j <- 0 until A.getColunas
      if j<i
    }{
      A.setValor(i,j,0)
    }
    (A,b)
  }

}
