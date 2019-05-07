package Modelo.Funcao

import scala.math.tanh

/**Implementacao da tangente hiperbolica
  *
  * @param expressao classe generica que representa uma funcao
  */
class TangenteH(expressao : Funcao) extends Funcao {


  override def apply(valorX: Double): Double = {
    tanh(expressao(valorX))
  }

  override def toString: String = {
    "tanh("+expressao.toString+")"
  }

}
