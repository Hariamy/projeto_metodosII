package Modelo.Matriz

import scala.math.sqrt

class Matriz(linhas: Int , colunas: Int) {

  def getColunas: Int = colunas
  def getLinhas: Int = linhas

  def this(dimensao: Int , vetorColuna: Boolean = true) = this( if(vetorColuna) dimensao else 1,
    if(vetorColuna) 1 else dimensao)

  def this() = this(0,0)

  private val matriz = Array.ofDim[Double](getLinhas , getColunas)

  def apply(linha: Int, coluna: Int) = matriz(linha)(coluna)

  def setValor(linha : Int , coluna : Int , valor: Double) = matriz(linha)(coluna) = valor

  override def toString: String = {
    val sb = new StringBuilder
    matriz foreach(sb append _.mkString(" ") append "\n")
    sb.toString
  }
  def isVetor:Boolean = {
    if(getColunas == 1 || getLinhas == 1){
      return true
    }
    false
  }
  def transposta: Matriz= {

    val resposta: Matriz = new Matriz(getColunas , getLinhas)

    for{
      i <- 0 until getLinhas
      j <- 0 until getColunas

    }{
      resposta.setValor(j , i , this(i,j))
    }
    resposta
  }

  def -(valor : Matriz):Matriz = {
    if( getLinhas != valor.getLinhas || getColunas != valor.getColunas){

      println("operacao invalid entre:\n" + this.toString + "\ne\n" + valor.toString)

      return null
    }

    val resposta : Matriz = new Matriz(getColunas,getLinhas)

    for{
      i <- 0 until getLinhas
      j <- 0 until getColunas
    }{
      resposta.setValor(i,j, this(i,j) - valor(i,j) )
    }

    resposta
  }

  def +(valor : Matriz) : Matriz = {
    if( getLinhas != valor.getLinhas || getColunas != valor.getColunas){

      println("operacao invalid entre: \n" + this.toString + "\ne\n" + valor.toString)
      return null
    }

    val resposta : Matriz = new Matriz(getColunas,getLinhas)

    for{
      i <- 0 until getLinhas
      j <- 0 until getColunas
    }{
      resposta.setValor(i,j, this(i,j) + valor(i,j) )
    }


    resposta
  }

  def *(valor : Matriz) : Matriz = {
    if(getColunas != valor.getLinhas){
      println("operacao invalid entre:\n" + this.toString + "\ne\n" + valor.toString)
      return  null
    }


    val resposta : Matriz = new Matriz(getLinhas , valor.getColunas)
    for{
      i <- 0 until getLinhas
      j <- 0 until valor.getColunas
      x <- 0 until valor.getLinhas
    }{
      resposta.setValor(i,j , resposta(i,j) + (this(i,x) * valor(x,j)) )
    }



    resposta

  }

  def *(valor: Double) : Matriz = {
    val resposta: Matriz = new Matriz(getLinhas , getColunas)

    for{
      i <- 0 until getLinhas
      j <- 0 until getColunas
    }{
      resposta.setValor(i,j,this(i,j) * valor)
    }



    resposta

  }

  def **(valor: Matriz): Double ={
    if( !this.isVetor || !valor.isVetor || (getLinhas != valor.getLinhas) || (getColunas != valor.getColunas) ){

      println("operacao invalid entre:\n" + this.toString + "\n e \n" + valor.toString)
      return Double.MaxValue
    }

    var somatorio: Double = 0

    if(getLinhas == 1){

      for(i <- 0 until getColunas){
        somatorio += this(0,i) * valor(0,i)
      }

    }else{

      for(i <- 0 until getLinhas){
        somatorio += this(i,0) * valor(i,0)
      }

    }

    somatorio
  }

  def norma : Double ={

    if(!this.isVetor){
      println("operacao invalida\n"+this.toString)
    }
    var somatorio: Double = 0

    if(getLinhas==1){

      for(i <- 0 until getColunas){
        somatorio += this(0,i)*this(0,i)
      }

    }else{

      for(i <- 0 until getLinhas){
        somatorio += this(i,0)*this(i,0)
      }

    }


    sqrt(somatorio)

  }
}
