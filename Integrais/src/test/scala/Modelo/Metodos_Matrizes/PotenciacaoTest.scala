package Modelo.Metodos_Matrizes

import Modelo.Matriz.Matriz
import org.scalatest.{BeforeAndAfterEach, FunSuite}

class PotenciacaoTest extends FunSuite with BeforeAndAfterEach{

  var A:Matriz = new Matriz
  var x0 : Matriz = new Matriz
  var erro: Double = 0

  override def beforeEach(): Unit = {
    A = new Matriz(3,3)
    x0 = new Matriz(3)
    erro = 0.01

    for(i <- 0 until 3 ){
      A.setValor(i,0,1)
      A.setValor(i,1,2)
      A.setValor(i,2,3)
    }

    x0.setValor(0,0,1)
    x0.setValor(1,0,0)
    x0.setValor(2,0,0)
  }

  test("teste da potenciacao"){

    println( Potenciacao(A,x0,erro) )
  }

}
