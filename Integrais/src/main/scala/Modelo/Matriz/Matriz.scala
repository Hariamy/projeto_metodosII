package Modelo.Matriz

import org.slf4j.LoggerFactory

import scala.math.sqrt

//classe para instanciacao e operacoes com matrizes e vetores (sao matrizes com uma das dimensoes igual a 1)
class Matriz(linhas: Int , colunas: Int) {

  //variavel de erro para os logs
  private val logger = LoggerFactory.getLogger(this.getClass)

  //definicao dos gets
  def getColunas: Int = colunas
  def getLinhas: Int = linhas

  //construtor auxiliar para vetores, a variavel vetorColuna por default eh true.
  def this(dimensao: Int , vetorColuna: Boolean = true) = this( if(vetorColuna) dimensao else 1,
    if(vetorColuna) 1 else dimensao)

  //construtor auxiliar para matrizes default
  def this() = this(0,0)

  //matriz propriamente dita, ela nao pode ser acessada diretamente por fora
  private val matriz = Array.ofDim[Double](getLinhas , getColunas)

  //metodo para acessar a matriz externamente. Ex: m1(x,y)
  def apply(linha: Int, coluna: Int) = matriz(linha)(coluna)

  //metodo para colocar valores na matriz
  def setValor(linha : Int , coluna : Int , valor: Double) = matriz(linha)(coluna) = valor

  //metodo sobreescrito para printar matrizes
  override def toString: String = {
    val sb = new StringBuilder
    matriz foreach(sb append _.mkString(" ") append "\n")
    sb.toString
  }

  //metodo para saber se a matriz se trata de um vetor
  def isVetor:Boolean = {
    if(getColunas == 1 || getLinhas == 1){
      return true
    }
    false
  }

  //metodo para gerar a transposta
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

  //sobreescrita de operador -
  def -(valor : Matriz):Matriz = {
    if( getLinhas != valor.getLinhas || getColunas != valor.getColunas){

      logger.warn("operacao invalid entre:\n" + this.toString + "e\n" + valor.toString)

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

  //sobreescrita de operador +
  def +(valor : Matriz) : Matriz = {
    if( getLinhas != valor.getLinhas || getColunas != valor.getColunas){

      logger.warn("operacao invalid entre: \n" + this.toString + "e\n" + valor.toString)
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

  //sobreescrita do operador *
  def *(valor : Matriz) : Matriz = {
    if(getColunas != valor.getLinhas){
      logger.warn("operacao invalid entre:\n" + this.toString + "e\n" + valor.toString)
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

  //sobreescrita do operador * para doubles
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
  //operador auxiliar para dividir valores
  def /(valor: Double): Matriz = {
    val resposta: Matriz = new Matriz(getLinhas , getColunas)

    for{
      i <- 0 until getLinhas
      j <- 0 until getColunas
    }{
      resposta.setValor(i,j,this(i,j) / valor)
    }



    resposta

  }

  //operacao para matrizes que sao vetores, esse eh o produto escalar
  def **(valor: Matriz): Double ={
    if( !this.isVetor || !valor.isVetor || (getLinhas != valor.getLinhas) || (getColunas != valor.getColunas) ){

      logger.warn("operacao invalid entre:\n" + this.toString + "e\n" + valor.toString)
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

  //operacao para matrizes que sao vetores, essa eh a norma do vetor
  def norma : Double ={

    if(!this.isVetor){
      logger.warn("operacao invalida:\n"+this.toString)
      return Double.MaxValue
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

  //sobreescrita para determinar igualdade
  def ==(valor: Matriz) :Boolean = {
    if(getColunas != valor.getColunas || getLinhas != valor.getLinhas){
      return false
    }

    for{
      i <- 0 until getLinhas
      j <- 0 until getColunas
    }{
      if(this(i,j) != valor(i,j)){
        return false
      }
    }

    true
  }

  //funcao para troca de linhas
  def troca_de_linhas(linha1: Int , linha2: Int ): Matriz ={
    var resposta: Matriz = new Matriz(getLinhas,getColunas)

    for{
      i <- 0 until getLinhas
      j <- 0 until getColunas
    }{
      resposta.setValor(i,j,this(i,j))
    }

    for(j <- 0 until getColunas){
      resposta.setValor(linha1 , j , this(linha2,j))
      resposta.setValor(linha2 , j , this(linha1,j))
    }

    resposta

  }

  //funcao para troca de colunas
  def troca_de_colunas(coluna1: Int , coluna2: Int ): Matriz ={
    var resposta: Matriz = new Matriz(getLinhas,getColunas)

    for{
      i <- 0 until getLinhas
      j <- 0 until getColunas
    }{
      resposta.setValor(i,j,this(i,j))
    }

    for(j <- 0 until getLinhas){
      resposta.setValor(j , coluna1 , this(j,coluna2))
      resposta.setValor(j,coluna2 , this(j,coluna1))
    }

    resposta

  }


}
