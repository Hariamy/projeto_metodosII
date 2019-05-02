package Modelo.Metodos_Matrizes

import Modelo.Matriz.Matriz

object GerarLowerUpper {

  def apply(A: Matriz): (Matriz,Matriz) = {
    var lower: Matriz = new Matriz(A.getLinhas , A.getColunas)
    var upper: Matriz = new Matriz(A.getLinhas , A.getColunas)

    //Lower recebe identidade
    for(i <- 0 until lower.getColunas){
      lower.setValor(i,i,1)
    }

    for(j <- 1 until A.getLinhas){

      for(i<- 1 until j){
        var soma: Double = 0

        for(k <- 1 until i-1){
          soma += lower(i,j) * upper(k,j)
        }
        upper.setValor(i,j, A(i,j) - soma )
      }

      for( i <- j+1 until A.getLinhas){
        var soma: Double = 0
        for(k <- 1 until j-1){
          soma += lower(i,k)*upper(k,j)
        }
        lower.setValor(i,j, (A(i,j)-soma)/upper(j,j) )
      }

    }

    (lower,upper)

  }
}
