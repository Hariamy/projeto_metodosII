package Modelo.Matriz

class Matriz(colunas: Int , linhas: Int) {
  def getColunas: Int = colunas
  def getLinhas: Int = linhas

  private val matriz = Array.ofDim[Double](getLinhas , getColunas)

  def apply(linha: Int, coluna: Int) = matriz(linha)(coluna)

  def setValor(linha : Int , coluna : Int , valor: Double) = matriz(linha)(coluna) = valor

  override def toString: String = {
    val sb = new StringBuilder
    matriz foreach(sb append _.mkString(" ") append "\n")
    sb.toString
  }

  def -(valor : Matriz) : Matriz = {
    if( getLinhas != valor.getLinhas || getColunas != valor.getColunas){
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
      return  null
    }

    val resposta : Matriz = new Matriz(getColunas , valor.getLinhas)
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
    val resposta: Matriz = new Matriz(getColunas , getLinhas)

    for{
      i <- 0 until getLinhas
      j <- 0 until getColunas
    }{
      resposta.setValor(i,j,this(i,j) * valor)
    }

    resposta

  }

  


}
