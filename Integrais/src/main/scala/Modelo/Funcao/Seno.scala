package Modelo.Funcao

import scala.math.sin

/**Implementacao do seno
  *
  * @param expressao classe generica que representa uma funcao
  */
class Seno(expressao : Funcao) extends Funcao {

  /**Calculo da funcao
    *
    * @param valorX valor da variavel 'x'
    * @return o valor da funcao no 'x' passado
    */
  override def apply(valorX: Double): Double = {
    sin(expressao(valorX))
  }

  override def toString: String = {
    "sen("+expressao.toString+")"
  }
  
}
