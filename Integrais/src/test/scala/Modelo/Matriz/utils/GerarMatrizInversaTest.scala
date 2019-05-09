package Modelo.Matriz.utils

import Modelo.Matriz.Matriz
import org.scalatest.{BeforeAndAfterEach, FunSuite}

class GerarMatrizInversaTest extends FunSuite with BeforeAndAfterEach {

  var m: Matriz = new Matriz

  override def beforeEach(): Unit = {
    m = LeitorDeArquivo("/home/joao/Documentos/projeto_metodosII/Integrais/src/main/resources/matriz.txt")
  }

  test("Teste inversa"){
    println(GerarMatrizInversa(m))
  }

}
