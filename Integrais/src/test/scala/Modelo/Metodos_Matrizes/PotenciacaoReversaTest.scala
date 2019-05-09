package Modelo.Metodos_Matrizes

import Modelo.Matriz.Matriz
import Modelo.Matriz.utils.{GerarLowerUpper, GerarMatrizInversa, LeitorDeArquivo}
import org.scalatest.{BeforeAndAfterEach, FunSuite}

class PotenciacaoReversaTest extends FunSuite with BeforeAndAfterEach {
  var m: Matriz = new Matriz
  var x0: Matriz = new Matriz

  override def beforeEach(): Unit = {
    m = LeitorDeArquivo("/home/joao/Documentos/projeto_metodosII/Integrais/src/main/resources/matriz.txt")
    x0 = new Matriz(3)
    x0.setValor(0,0,1)
    x0.setValor(1,0,1)
    x0.setValor(2,0,1)
  }

  test("Teste potencia inversa"){
    println(GerarLowerUpper(m)._1)
    println(PotenciacaoReversa(m,x0,0.0001))
  }
}
