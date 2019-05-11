package Modelo.Matriz

import Modelo.Matriz.utils.GerarIdentidade
import org.scalatest.{BeforeAndAfterEach, FunSuite}

class MatrizTest extends FunSuite with  BeforeAndAfterEach{

  var m1: Matriz = new Matriz

  var m2: Matriz = new Matriz

  var m3: Matriz = new Matriz

  var v1: Matriz = new Matriz
  override def beforeEach(): Unit ={
    m1 = new Matriz(3,3)
    m2 = new Matriz(3,3)
    v1 = new Matriz(3,false)

    m3 = new Matriz(3,true)

    m1.setValor(0,0,1)
    m1.setValor(1,1,1)
    m1.setValor(2,2,1)

    m3.setValor(0,0,1)
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
    println("teste "+v1.apply(2))
    println(v1**v1 )
  }

  test("produto errado"){
    println(v1*m1)
  }

  test("construtor novo"){
    println(m3)
  }

  test("transposta"){
    println(m3.transposta)
  }

  test("norma"){
    println(m3.transposta * m3 )
  }
  test("igualdade"){
    println(m3 == m3 )
  }
  test("diferenca"){
    println(m3 == m1 )
  }

  test("identidade"){
    println(GerarIdentidade(6) )
  }

}
