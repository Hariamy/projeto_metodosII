package Modelo.Metodos_Matrizes

import Modelo.Matriz.Matriz
import Modelo.Matriz.utils.GerarIdentidade

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
    val upper: Matriz = A

    for(i<- 0 until A.getLinhas){

      for(j <- 0 until A.getColunas){

        for(k <- 0 until i){
          upper.setValor(i,j, upper(i,j) - (lower(i,k) * upper(k,j) ) )
        }

      }

      for(m <- i+1 until A.getLinhas){
        lower.setValor(m,i,A(m,i))
        for(k <- 0 until i){
          lower.setValor(m,i, A(m,i) - (lower(m,k) * upper(k,i)) )
        }
        lower.setValor(m,i,lower(m,i)/upper(i,i))
      }

    }

    (lower,upper)

  }
}
