package Modelo.Matriz.utils

import Modelo.Matriz.Matriz
import org.scalatest.{BeforeAndAfterEach, FunSuite}

class GerarMatrizEliminacaoGaussTest extends FunSuite with  BeforeAndAfterEach {

  var m: Matriz = new Matriz
  var b: Matriz = new Matriz()

  override protected def beforeEach() ={
    m = LeitorDeArquivo("/home/joao/Documentos/projeto_metodosII/Integrais/src/main/resources/matriz.txt")
    b = new Matriz(4)
    b.setValor(0,0,14.308)
    b.setValor(1,0,25.744)
    b.setValor(2,0,-3.872)
    b.setValor(3,0,36.334)
  }

  test("gauss"){
    println(GerarMatrizEliminacaoGauss(m,b))
  }

}
