package Modelo.Matriz

import org.scalatest.{BeforeAndAfterEach, FunSuite}

class MatrizTest extends FunSuite with  BeforeAndAfterEach{

  var matriz: Matriz = new Matriz(0,0)

  override def beforeEach(): Unit ={
    matriz = new Matriz(1,3)
  }

  test("to string teste"){
    println(matriz)
  }


}
