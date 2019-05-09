package Modelo.Metodos_Matrizes
import Modelo.Matriz.Matriz
import Modelo.Matriz.utils.GerarMatrizInversa

object PotenciacaoReversa extends AutoValores {

  override def apply(A: Matriz, x0: Matriz, erro: Double): (Double, Matriz) = {
    val inversa: Matriz = GerarMatrizInversa(A)
    Potenciacao(inversa, x0 , erro)
  }

}
