package Modelo.Integrais

import Modelo.Funcao.Funcao

/**Interface para calculo de integrais
  *Classes que implementarem essa interface deverao ser singleton
  *
  */
trait Integral {
  /**Calculo propriamente dito
    *
    * @param expressao funcao generica
    * @param valor_inicial 'x' inicial
    * @param valor_final 'x' final
    * @param grau grau do polinomio de integracao
    * @param filosofia filosofia desejada para o calculo. True = Forward e False = Backward
    * @return o valor da integral
    */
  def apply(expressao: Funcao, valor_inicial: Double, valor_final: Double , grau:Int = 1 , filosofia: Boolean = true):Double
}
