package Modelo.Funcao

import org.scalatest.{BeforeAndAfterEach, FunSuite}
import math.Pi
class SenoTest extends FunSuite with  BeforeAndAfterEach{
  var sin : Seno = new Seno( null )


  override protected def beforeEach() ={
    sin = new Seno(new Folha)
  }

  test("teste seno de 0"){
    assert(sin(0)==0)
  }
  test("teste seno de Pi/2"){
    assert(sin(Pi/2)==1)
  }
}
