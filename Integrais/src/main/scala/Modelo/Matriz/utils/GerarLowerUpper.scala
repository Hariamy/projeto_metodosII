package Modelo.Matriz.utils

import Modelo.Matriz.Matriz

/**
  * Classe singleton para aplicar a fatoracao LU
  */
object GerarLowerUpper {
  /**
    * Fatoracao LU
    * @param A matriz que sera fatorada
    * @return tupla (matriz lower, matriz upper)
    */
  def apply(A: Matriz): (Matriz,Matriz) = {
    val lower: Matriz = GerarIdentidade(A.getColunas)
    val upper: Matriz = A.clone

    var i = 0
    while(i< A.getLinhas){

      var j = 0
      while(j < A.getColunas){

        var k = 0
        while(k <  i){
          upper.setValor(i,j, upper(i,j) - (lower(i,k) * upper(k,j) ) )
          k +=1
        }

        j +=1
      }

      var m = i+1
      while(m < A.getLinhas){
        lower.setValor(m,i,A(m,i))

        var k =0
        while(k < i){
          lower.setValor(m,i, A(m,i) - (lower(m,k) * upper(k,i)) )
          k +=1
        }

        lower.setValor(m,i,lower(m,i)/upper(i,i))

        m+=1
      }
      i+=1
    }

    (lower,upper)

  }
}
