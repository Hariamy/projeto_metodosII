package Modelo.Matriz.utils

import Modelo.Matriz.Matriz
import org.scalatest.{BeforeAndAfterEach, FunSuite}

class ResolverSistemaTest extends FunSuite with  BeforeAndAfterEach{

  var m: Matriz = new Matriz
  var b: Matriz = new Matriz()

  override protected def beforeEach() ={
    m = LeitorDeArquivo("/home/joao/Documentos/projeto_metodosII/Integrais/src/main/resources/matriz.txt")
    b = new Matriz(4)
    b.setValor(0,0,14.308)
    b.setValor(1,0,19.606)
    b.setValor(2,0,-8.524)
    b.setValor(3,0,53.848)
  }

  test("teste resolucao de sistema"){
    println(m)
    println(b)
    println(ResolverSistema(m,b))
  }
}
