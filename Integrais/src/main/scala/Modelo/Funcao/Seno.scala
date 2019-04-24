package Modelo.Funcao

import scala.math.sin

class Seno(expressao : Funcao) extends Funcao {
  override def apply(valorX: Double): Double = {
    sin(expressao(valorX))
  }
}
