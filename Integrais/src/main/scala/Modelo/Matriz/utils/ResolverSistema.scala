package Modelo.Matriz.utils

import Modelo.Matriz.Matriz
import org.slf4j.LoggerFactory

object ResolverSistema {
  private val logger = LoggerFactory.getLogger(this.getClass)
  def apply(A: Matriz , b:Matriz,triangular_superior: Boolean = true): Matriz = {

    if(A.isVetor || !b.isVetor){
      logger.error("Parametros invalidos:\n"+A.toString+"\n"+b.toString)
      return  null

    }

    val resposta: Matriz = new Matriz(b.getLinhas)

    if(triangular_superior){
      for{
        i <- A.getLinhas-1 to 0
      }{
        
      }
    }




  }

}
