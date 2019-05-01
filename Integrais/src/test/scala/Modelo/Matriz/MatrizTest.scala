package Modelo.Matriz

import org.scalatest.{BeforeAndAfterEach, FunSuite}

class MatrizTest extends FunSuite with  BeforeAndAfterEach{

  var m1: Matriz = new Matriz(0,0)

  var m2: Matriz = new Matriz(0,0)

  var v1: Vetor = new Vetor(0)
  override def beforeEach(): Unit ={
    m1 = new Matriz(3,3)
    m2 = new Matriz(3,3)
    v1 = new Vetor(3)


  }

  test("soma"){
    println(m1 + m2)
  }

  test("subtracao"){
    println(m1-m2)
  }

  test("multiplicacao"){
    println(m1*m2)
  }

  test("vetor"){
    println(m1*v1)
  }

  test("produto escalar"){
    println(v1**v1)
  }

  test("produto errado"){
    println(v1*m1)
  }




}
