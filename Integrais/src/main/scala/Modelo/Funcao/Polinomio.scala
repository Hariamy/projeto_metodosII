package Modelo.Funcao

import scala.math.pow

/**Classe que implementa um polinomio a nivel de codigo
  *
  * @param expressao classe generica que representa uma funcao
  */
class Polinomio(expressao : Funcao) extends Funcao {

  /** note que o proprio responsavel pela criacao desse polinomio, deve dizer os coeficientes e expoentes
    *
    * @param valorX valor da variavel 'x'
    * @return o valor da funcao no 'x' passado
    */
  override def apply(valorX: Double): Double = {
    4*pow(expressao(valorX) , 2) + 3
  }
  override def toString: String = {
    "4*("+expressao.toString+")^2 + 3"
  }
}
