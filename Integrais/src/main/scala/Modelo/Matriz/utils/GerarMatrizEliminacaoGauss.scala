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
  def apply(A: Matriz , b: Matriz, com_zeros:Boolean = true): (Matriz,Matriz) = {


    var k = 0
    while(k < A.getLinhas-1){

      var i = k+1
      while(i < A.getLinhas ){

        val m:Double = -A(i,k)/A(k,k)

        var j = k+1
        while(j < A.getLinhas){

          A.setValor(i,j, A(i,j) + (m * A(k,j) ) )

          j +=1
        }
        b.setValor(i,0,b(i,0) + (m * b(k,0) ) )

        i += 1
      }

      k +=1
    }

    if(com_zeros){

      var i = 0
      while(i<A.getLinhas){
        var j = 0
        while(j<A.getColunas){
          if(j<i) A.setValor(i,j,0)
          j += 1
        }
        i += 1
      }
    }


    (A,b)
  }

}
