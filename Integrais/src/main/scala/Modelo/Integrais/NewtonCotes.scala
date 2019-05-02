package Modelo.Integrais
import Modelo.Funcao.Funcao


object NewtonCotes extends Integral {
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
