package Modelo.Matriz
import math.sqrt
class Vetor(linhas: Int) extends Matriz(linhas ,1) {

  def apply(linha: Int): Double = super.apply(linha, 0)

  def setValor(linha: Int, valor: Double): Unit = super.setValor(linha, 0, valor)

  def **(valor: Vetor): Double ={
    if(getLinhas != valor.getLinhas){
      return Double.MaxValue
    }

    var somatorio: Double = 0
    for(i <- 0 until getLinhas){
      somatorio += this(i) * valor(i)
    }

    somatorio
  }

  def norma : Double ={
    var somatorio: Double = 0

    for(i <- 0 until getLinhas){
      somatorio += this(i)*this(i)
    }

    sqrt(somatorio)

  }

}
