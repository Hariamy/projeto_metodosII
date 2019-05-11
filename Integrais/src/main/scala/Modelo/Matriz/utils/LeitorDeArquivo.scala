package Modelo.Matriz.utils

import Modelo.Matriz.Matriz

import scala.io.Source
import org.slf4j.LoggerFactory
object LeitorDeArquivo {

  private val logger = LoggerFactory.getLogger(this.getClass)

  def apply(caminho: String , separador: String = " "): Matriz = {

    val linhas = Source.fromFile(caminho).getLines()
    var matriz: List[List[Double]] = List()

    while(linhas.hasNext){

      val linha = linhas.next()

      val linha_matriz: List[Double] = linha.split(separador).flatMap(s => scala.util.Try(s.toDouble).toOption).toList

      matriz = matriz ::: List(linha_matriz)

      if(linha_matriz.length != matriz.head.length){

        logger.warn(s"Má formacao na linha: $linha" + " do arquivo " +caminho)

        matriz=matriz.dropRight(1)

      }
    }

    val resposta: Matriz = new Matriz(matriz.length,matriz.head.length)

    /*
    for{
      i <- 0 until resposta.getLinhas
      j <- 0 until resposta.getColunas
    }{
      resposta.setValor(i,j,matriz(i)(j))
    }

     */
    var i = 0
    while(i< resposta.getLinhas){

      var j = 0
      while(j<resposta.getColunas){
        resposta.setValor(i,j,matriz(i)(j))
        j += 1
      }
      i += 1
    }

resposta

  }



}
