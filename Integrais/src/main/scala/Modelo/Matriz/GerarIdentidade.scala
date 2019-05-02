package Modelo.Matriz

object GerarIdentidade {
  def apply(dimensao: Int): Matriz = {
    val identidade: Matriz = new Matriz(dimensao,dimensao)
    for(i <- 0 until dimensao){
      identidade.setValor(i,i,1)
    }
    identidade
  }
}
