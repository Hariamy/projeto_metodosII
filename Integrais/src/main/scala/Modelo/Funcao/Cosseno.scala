package Modelo.Funcao

import scala.math.cos

/**Implementacao do cosseno
  *
  * @param expressao classe generica que representa uma funcao
  */
class Cosseno(expressao : Funcao) extends Funcao {

  /**Calculo da funcao
    *
    * @param valorX valor da variavel 'x'
    * @return o valor da funcao no 'x' passado
    */
  override def apply(valorX: Double): Double = {
    cos(expressao(valorX))
  }

  override def toString: String = {
    "cos("+expressao.toString+")"
  }
}
