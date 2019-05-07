package Modelo.Funcao

import org.scalatest.{BeforeAndAfterEach, FunSuite}

class PolinomioTest extends FunSuite with BeforeAndAfterEach{
  var poli : Polinomio = new Polinomio(null)
  var poli2: Polinomio = new Polinomio(null)

  override def beforeEach(): Unit = {
    poli = new Polinomio(new Folha)
    poli2 = new Polinomio(new Seno( new Folha ))
  }

  test("to string"){
    println(poli2)
  }
}
