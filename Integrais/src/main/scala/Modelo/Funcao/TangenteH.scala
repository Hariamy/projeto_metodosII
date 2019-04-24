package Modelo.Funcao

import scala.math.tanh

class TangenteH(expressao : Funcao) extends Funcao {


  override def apply(valorX: Double): Double = {
    tanh(expressao(valorX))
  }

}
