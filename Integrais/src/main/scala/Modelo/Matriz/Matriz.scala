package Modelo.Matriz

import org.slf4j.LoggerFactory


import scala.math.sqrt

/** Classe para instanciacao e operacoes com matrizes e vetores
  * Vetores sao matrizes com uma das dimensoes igual a 1
  *
  * @param linhas numero de linhas
  * @param colunas numero de colunas
  */
class Matriz(linhas: Int , colunas: Int) {

  /**
    * variavel de erro para os logs
    */
  private val logger = LoggerFactory.getLogger(this.getClass)

  /**
    * Metodo para acessar o numero de colunas
    * @return o numero de colunas
    */
  def getColunas: Int = colunas

  /**
    * Metodo para acessar o numero de linhas
    * @return o numero de linhas
    */
  def getLinhas: Int = linhas

  /**
    * Construtor auxiliar para vetores
    *
    * @param dimensao O tamanho da dimensao que sera diferente de 1 (para que isso seja um vetor de fato)
    * @param vetorColuna variavel booleana que indica se esse sera um vetor coluna ou, caso contrario, ser um vetor linha
    */
  def this(dimensao: Int , vetorColuna: Boolean = true) = this( if(vetorColuna) dimensao else 1,
    if(vetorColuna) 1 else dimensao)

  /**
    * construtor defalt auxiliar para matrizes
    */
  def this() = this(0,0)

  /**
    * matriz propriamente dita, ela nao pode ser acessada diretamente por fora
    */
  private val matriz = Array.ofDim[Double](getLinhas , getColunas)

  /** Metodo para acessar a matriz externamente. Ex: m1(x,y)
    *
    * @param linha posicao do elemento na linha
    * @param coluna posicao do elemento na coluna
    * @return o elemento na posicao (linha , coluna) da matriz
    */
  def apply(linha: Int, coluna: Int):Double = matriz(linha)(coluna)


  def apply(i: Int): Double = {
    if(!isVetor) return Double.MaxValue
    if(isColuna) return this(i,0)
    this(0,i)

  }
  /** Metodo para colocar valores na matriz
    *
    * @param linha posicao da linha em que o elemento sera inserido
    * @param coluna posicao da linha em que o elemento sera inserido
    * @param valor que sera inserido
    */
  def setValor(linha : Int , coluna : Int , valor: Double) = matriz(linha)(coluna) = valor


  def setValor(i: Int,valor:Double) = {
    if(isColuna) matriz(i)(0)=valor
    if(isLinha)  matriz(0)(i)=valor

  }

  /**
    * metodo sobreescrito para printar matrizes
    * @return uma string que contem os valores da matriz
    */
  override def toString: String = {
    val sb = new StringBuilder
    matriz foreach(sb append _.mkString(" ") append "\n")
    sb.toString
  }


  /** Metodo para saber se a matriz se trata de um vetor
    *
    * @return valor verdade para saber se eh um vetor
    */
  def isVetor:Boolean = {
    if(getColunas == 1 || getLinhas == 1){
      return true
    }
    false
  }

  /**
    * Metodo que identifica uma matriz quadrada
    * @return valor verdade para saber se eh uma matriz quadrada
    */
  def isQuadrado: Boolean = if(getLinhas == getColunas) true else false

  /**
    * metodo que identifica um vetor linha
    * @return valor verdade para saber se eh um vetor linha
    */
  def isLinha: Boolean = if(getLinhas==1 && isVetor) true else false

  /**
    * metodo que identifica um vetor coluna
    * @return valor verdade para saber se eh um vetor coluna
    */
  def isColuna: Boolean = if(getColunas==1 && isVetor) true else false

  /** Metodo para gerar a transposta
    *
    * @return matriz transposta
    */

  def transposta: Matriz= {

    val resposta: Matriz = new Matriz(getColunas , getLinhas)

    var i = 0
    while (i<getLinhas){

      var j=0
      while(j<getColunas){

        resposta.setValor(j , i , this(i,j))

        j +=1
      }

      i +=1
    }
    resposta
  }


  /** Sobreescrita de operador -
    *
    * @param valor matriz que sera subtraida
    * @return matriz resultante da subtracao
    */
  def -(valor : Matriz):Matriz = {
    if( getLinhas != valor.getLinhas || getColunas != valor.getColunas){

      logger.error("operacao invalid entre:\n" + this.toString + "e\n" + valor.toString)
      return null
    }

    val resposta : Matriz = new Matriz(getColunas,getLinhas)

    var i = 0
    while (i<getLinhas){

      var j=0
      while(j<getColunas){

        resposta.setValor(i,j, this(i,j) - valor(i,j) )

        j +=1
      }

      i +=1
    }

    resposta
  }

/** Sobreescrita de operador +
  *
  * @param valor matriz que sera adicionada
  * @return matriz resultante da adicao
  */

  def +(valor : Matriz) : Matriz = {
    if( getLinhas != valor.getLinhas || getColunas != valor.getColunas){

      logger.error("operacao invalid entre: \n" + this.toString + "e\n" + valor.toString)
      return null
    }

    val resposta : Matriz = new Matriz(getColunas,getLinhas)

    var i = 0
    while (i<getLinhas){

      var j=0
      while(j<getColunas){

        resposta.setValor(i,j, this(i,j) + valor(i,j) )

        j +=1
      }

      i +=1
    }


    resposta
  }

  /** Sobreescrita de operador *
    *
    * @param valor matriz que sera multiplicada
    * @return matriz resultante da multiplicacao
    */

  def *(valor : Matriz) : Matriz = {
    if(getColunas != valor.getLinhas){
      logger.error(s"operacao invalid entre:\n" + this.toString + "e\n" + valor.toString)
      return  null
    }


    val resposta : Matriz = new Matriz(getLinhas , valor.getColunas)

    var i =0
    while(i<getLinhas){
      var j =0
      while(j< valor.getColunas){
        var x = 0
        while(x<valor.getLinhas){
          resposta.setValor(i,j , resposta(i,j) + (this(i,x) * valor(x,j)) )
          x +=1
        }

        j +=1
      }
      i +=1
    }

    resposta

  }

  /**Multiplicacao por escalar
    *
    * @param valor escalar que sera multiplicado
    * @return matriz multiplicada pelo escalar
    */
  def *(valor: Double) : Matriz = {
    val resposta: Matriz = new Matriz(getLinhas , getColunas)

    var i = 0
    while(i<getLinhas){

      var j = 0
      while(j<getColunas){
        resposta.setValor(i,j,this(i,j) * valor)
        j +=1
      }

      i +=1
    }

    resposta

  }

  /**operador auxiliar para dividir valores escalares
    *
    * @param valor valor escalar que sera dividido
    * @return matriz dividida pelo escalar
    */
  def /(valor: Double): Matriz = {
    val resposta: Matriz = new Matriz(getLinhas , getColunas)

    var i = 0
    while(i<getLinhas){

      var j = 0
      while(j<getColunas){
        resposta.setValor(i,j,this(i,j) / valor)
        j +=1
      }

      i +=1
    }

    resposta

  }


  /** Operacao para matrizes que sao vetores
    * Esse eh o produto escalar
    *
    * @param valor vetor que sera multiplicado
    * @return valor escalar da operacao
    */
  def **(valor: Matriz): Double ={
    if( !this.isVetor || !valor.isVetor || (getLinhas != valor.getLinhas) || (getColunas != valor.getColunas) ){

      logger.error("operacao invalid entre:\n" + this.toString + "e\n" + valor.toString)
      return Double.MaxValue
    }

    var somatorio: Double = 0

    if(isLinha){

      var i =0
      while(i < getColunas){
        somatorio += this(i) * valor(i)
        i +=1
      }

    }else{

      var i =0
      while(i < getLinhas){
        println("Aqui coluna")
        somatorio += this(i) * valor(i)
        i += 1
      }

    }

    somatorio
  }


  /** Operacao para matrizes que sao vetores
    * Essa eh a norma do vetor
    *
    * @return a norma do vetor
    */
  def norma : Double ={

    if(!this.isVetor){
      logger.error("operacao invalida:\n"+this.toString)
      return Double.MaxValue
    }
    var somatorio: Double = 0

    if(isLinha){

      var i = 0
      while(i < getColunas){
        somatorio += this(i)*this(i)
        i += 1
      }

    }else{

      var i =0
      while(i < getLinhas){
        somatorio += this(i)*this(i)
        i+=1
      }

    }


    sqrt(somatorio)

  }


  /** sobreescrita para determinar igualdade
    *
    * @param valor que sera comparado
    * @return
    */
  def ==(valor: Matriz) :Boolean = {
    if(getColunas != valor.getColunas || getLinhas != valor.getLinhas){
      return false
    }

    var i = 0
    while(i < getLinhas){

      var j =0
      while( j < getColunas){

        if(this(i,j) != valor(i,j)){
          return false
        }

        j += 1
      }

      i +=1
    }

    true
  }


  /** Funcao para troca de linhas
    *
    * @param linha1 index da linha que sera trocada pela linha2
    * @param linha2 index da linha que sera trocada pela linha1
    * @return matriz com as linhas trocadas
    */
  def troca_de_linhas(linha1: Int , linha2: Int ): Matriz ={

    var resposta: Matriz = this.clone

    var j = 0
    while(j<getColunas){
      resposta.setValor(linha1 , j , this(linha2,j))
      resposta.setValor(linha2 , j , this(linha1,j))
      j+=1
    }

    resposta

  }


  /** Funcao para troca de colunas
    *
    * @param coluna1 index da coluna que sera trocada pela coluna2
    * @param coluna2 index da coluna que sera trocada pela coluna2
    * @return matriz com as colunas trocadas
    */
  def troca_de_colunas(coluna1: Int , coluna2: Int ): Matriz ={
    var resposta: Matriz = this.clone

    var j = 0
    while(j<getColunas){
      resposta.setValor(j , coluna1 , this(j,coluna2))
      resposta.setValor(j,coluna2 , this(j,coluna1))
      j+=1
    }
    resposta

  }

  /** Funcao para obter os valores de uma coluna da matriz
    *
    * @param coluna index da coluna desejada
    * @return uma matriz vetor coluna que contem os valores
    */
  def getValoresColuna(coluna: Int): Matriz = {
    val col: Matriz = new Matriz(getLinhas)

    var i = 0
    while(i < getColunas){
      col.setValor(i,0,this(i,coluna))
      i +=1
    }
    col
  }

  /** Funcao para obter os valores de uma linha da matriz
    *
    * @param linha index da linha desejada
    * @return uma matriz vetor linha que contem os valores
    */
  def getValoresLinha(linha: Int): Matriz = {
    val lin: Matriz = new Matriz(getColunas,false)

    var i = 0
    while(i < getColunas){
      lin.setValor(0,i,this(linha,i))
      i +=1
    }
    lin
  }

  /**
    * metodo para fazer copia da classe, ideal antes de manipulacoes em funcoes
    * @return uma copia dessa matriz
    */
  override def clone(): Matriz ={
    val identica: Matriz = new Matriz(getLinhas,getColunas)

    var i = 0
    while(i<getLinhas){

      var j = 0
      while(j<getColunas){
        identica.setValor(i,j,this(i,j))
        j +=1
      }
      i += 1
    }
    identica
  }

}
