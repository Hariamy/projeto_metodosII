package Modelo.Funcao


import org.scalatest.{BeforeAndAfterEach, FunSuite}
import math.Pi

class CossenoTest extends FunSuite with BeforeAndAfterEach {
  var cos : Cosseno = new Cosseno(null)

  override def beforeEach(): Unit = {
    cos = new Cosseno(  new Folha )
  }

  test("Teste cosseno de 0") {
    assert(cos(0) == 1)
  }
  test("cosseno valor Pi"){
    assert(cos(Pi) == -1)
  }
  test("teste de Pi/2"){
    println(cos(Pi/2))
    assert(cos(Pi/2) == 6.123233995736766E-17)
  }
}
