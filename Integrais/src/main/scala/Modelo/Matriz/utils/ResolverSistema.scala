package Modelo.Matriz.utils

import Modelo.Matriz.Matriz
import org.slf4j.LoggerFactory

/**
  * Classe para resolver sistemas lineares
  * Considera que a matriz ou eh triangular superior ou inferior
  */
object ResolverSistema {
  private val logger = LoggerFactory.getLogger(this.getClass)

  /**
    * Substituicao propriamente dita
    * @param A Matriz triangular
    * @param b vetor de constantes
    * @param triangular_superior informa qual tipo de matriz tringular A eh
    * @return O vetor coluna de valores dos x's
    */
  def apply(A: Matriz , b:Matriz,triangular_superior: Boolean = true): Matriz = {

    if(A.isVetor || !b.isVetor){
      logger.error("Parametros invalidos:\n"+A.toString+"\n"+b.toString)
      return  null

    }

    val resposta: Matriz = new Matriz(b.getLinhas)

    if(triangular_superior){
      val n: Int = A.getLinhas-1
      resposta.setValor(n,0,b(n,0)/A(n,n))

      for(i <- n to 0 by -1){
        var soma = 0.0

        for(j <- i+1 to n){
          soma += A(i,j)* resposta(j,0)
        }

        resposta.setValor(i,0,(b(i,0)-soma)/A(i,i))
      }
    }else{
      val n: Int = A.getLinhas-1
      resposta.setValor(0,0,b(0,0)/A(0,0))

      for(i <- 0 to n){
        var soma = 0.0

        for(j <- 0 until i){
          soma += A(i,j)* resposta(j,0)
        }

        resposta.setValor(i,0,(b(i,0)-soma)/A(i,i))
      }
    }

    resposta

  }

}
