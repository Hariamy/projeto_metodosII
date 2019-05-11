package Modelo.Matriz.utils

import Modelo.Matriz.Matriz

/**
  * Classe para gerar matriz inversa
  */
object GerarMatrizInversa {

  /**
    * Ele usa o metodo de achar a inversa atraves da fatoracao LU
    * @param A matriz que sera invertida
    * @return matriz inversa de A
    */
  def apply(A: Matriz): Matriz = {



    val LU: (Matriz,Matriz) = GerarLowerUpper(A)

    val I: Matriz = GerarIdentidade(A.getColunas)

    var m_inversa: List[Matriz] =  List()
    /*
    for(i <- 0 until A.getColunas){


      //L * xi = ei
      val xi: Matriz = ResolverSistema(LU._1,I.getValoresColuna(i),triangular_superior = false)


      //U * ai = xi
      val coluna_inversa: Matriz = ResolverSistema(LU._2,xi)

      m_inversa = m_inversa ::: List(coluna_inversa)
    }

     */

    var i = 0

    while(i < A.getColunas){

      //L * xi = ei
      val xi: Matriz = ResolverSistema(LU._1,I.getValoresColuna(i),triangular_superior = false)


      //U * ai = xi
      val coluna_inversa: Matriz = ResolverSistema(LU._2,xi)

      m_inversa = m_inversa ::: List(coluna_inversa)
      i +=1
    }

    val Inversa: Matriz = new Matriz(A.getLinhas,A.getColunas)


    /*
    for{

      i <- 0 until A.getLinhas
      j <- 0 until A.getColunas

    }{

      Inversa.setValor(i,j,m_inversa(j)(i,0))
    }

     */

    i =0
    while(i < A.getLinhas){

      var j =0
      while(j<A.getColunas){

        Inversa.setValor(i,j,m_inversa(j)(i,0))

        j += 1
      }


      i +=1
    }

    Inversa
  }


}
