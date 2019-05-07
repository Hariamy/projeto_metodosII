package Modelo.Integrais
import Modelo.Funcao.Funcao

/**
  * Implementacao da integral Newton-Cotes
  */
object NewtonCotes extends Integral {

  /** Metodo para calcular a integral usando Newton-Cotes
    *
    * @param expressao funcao generica
    * @param valor_inicial 'x' inicial
    * @param valor_final 'x' final
    * @param grau grau do polinomio de integracao
    * @param filosofia filosofia desejada para o calculo. True = Forward e False = Backward
    * @return o valor da integral
    */
  override def apply(expressao: Funcao, valor_inicial: Double, valor_final: Double , grau:Int = 1 , filosofia: Boolean = true): Double ={
    if(filosofia){

      grau match {

        case 1 => ((valor_final - valor_inicial)/2) * expressao(valor_inicial) + expressao(valor_final)

        case 2 => ((valor_final - valor_inicial)/9) * expressao(valor_inicial) + 4*expressao((valor_inicial+valor_final)/2)

      }
    }else{

      grau match {

        case 1 => 0

      }
    }
  }
}
