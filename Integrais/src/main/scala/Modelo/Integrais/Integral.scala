package Modelo.Integrais

import Modelo.Funcao.Funcao

trait Integral {
  def apply(expressao: Funcao, valor_inicial: Double, valor_final: Double , grau:Int = 1 , filosofia: Boolean = true):Double
}
