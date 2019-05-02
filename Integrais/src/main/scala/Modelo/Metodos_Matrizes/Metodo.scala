package Modelo.Metodos_Matrizes

import Modelo.Matriz.Matriz

trait Metodo {

  def apply(A: Matriz , x0: Matriz , erro: Double): (Double,Matriz)

}
