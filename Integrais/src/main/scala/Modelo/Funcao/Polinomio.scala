package Modelo.Funcao

import scala.math.pow
class Polinomio(expressao : Funcao) extends Funcao {
  override def apply(valorX: Double): Double = {
    4*pow(expressao(valorX) , 2) + 3
  }
}
