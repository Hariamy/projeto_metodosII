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

      var i = n
      while(i >=0){
        var soma = 0.0

        var j = i+1
        while(j <= n){
          soma += A(i,j)* resposta(j,0)
          j+=1
        }

        resposta.setValor(i,0,(b(i,0)-soma)/A(i,i))

        i -=1
      }
    }else{

      val n: Int = A.getLinhas-1

      var i = 0
      while(i <= n){
        var soma = 0.0

        var j = 0
        while(j < i){
          soma += A(i,j)* resposta(j,0)
          j+=1
        }

        resposta.setValor(i,0,(b(i,0)-soma)/A(i,i))
        i += 1
      }
    }

    resposta

  }

}
