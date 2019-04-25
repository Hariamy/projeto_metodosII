package Modelo.Funcao

import org.scalatest.{BeforeAndAfterEach, FunSuite}

class PolinomioTest extends FunSuite with BeforeAndAfterEach{
  var poli : Polinomio = new Polinomio(null)

  override def beforeEach(): Unit = {
    poli = new Polinomio(new Folha)
  }
}
