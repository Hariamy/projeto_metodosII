package Modelo.Metodos_Matrizes

import Modelo.Matriz.Matriz
import Modelo.Matriz.utils.Leitor_de_Arquivo
import org.scalatest.{BeforeAndAfterEach, FunSuite}

class GerarLowerUpperTest extends FunSuite with BeforeAndAfterEach {

  var A: Matriz = new Matriz

  override def beforeEach(): Unit = {
    A = Leitor_de_Arquivo("/home/joao/Documentos/projeto_metodosII/Integrais/src/main/resources/matriz.txt")
  }

  test("Fatoracao identidade"){
    println(GerarLowerUpper(A))
  }




}
