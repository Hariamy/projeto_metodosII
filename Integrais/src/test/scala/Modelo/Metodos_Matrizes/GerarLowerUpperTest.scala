package Modelo.Metodos_Matrizes

import Modelo.Matriz.Matriz
import Modelo.Matriz.utils.{GerarLowerUpper, LeitorDeArquivo}
import org.scalatest.{BeforeAndAfterEach, FunSuite}

class GerarLowerUpperTest extends FunSuite with BeforeAndAfterEach {

  var A: Matriz = new Matriz

  override def beforeEach(): Unit = {
    A = LeitorDeArquivo("/home/joao/Documentos/projeto_metodosII/Integrais/src/main/resources/matriz.txt")
  }

  test("Fatoracao identidade"){
    var LU =GerarLowerUpper(A)
    println(LU._1)
    println(LU._2)
  }




}
