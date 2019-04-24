package Modelo.Funcao.Integrais

import Modelo.Funcao.Funcao

trait Integral {
  def apply(expressao : Funcao , valor_inicial : Double , valor_final : Double)
}
