package Modelo.Matriz.utils

import Modelo.Matriz.Matriz

object GerarIdentidade {
  def apply(dimensao: Int): Matriz = {
    val identidade: Matriz = new Matriz(dimensao,dimensao)

    var i = 0
    while(i < dimensao){
      identidade.setValor(i,i,1)
      i+=1
    }
    identidade
  }
}
