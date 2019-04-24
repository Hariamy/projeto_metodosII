package Modelo.Funcao

import scala.math.cos

class Cosseno(expressao : Funcao) extends Funcao {
  override def apply(valorX: Double): Double = {
    cos(expressao(valorX))
  }
}
