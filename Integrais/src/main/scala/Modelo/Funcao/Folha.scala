package Modelo.Funcao

/** Classe que sera usada como folha da 'arvore' de resolucao das funcoes criadas pelo usuario
  *
  *
  */
class Folha extends Funcao {

  /**Observar que como 'folha' o proposito dela sera dar inicio a resolucao da arvore. Ela sera o f(x)=x
    *
    * @param valorX valor da variavel 'x'
    * @return o valor da funcao no 'x' passado
    */
  override def apply(valorX: Double): Double = {
    valorX
  }
  override def toString: String = {
    "x"
  }
}
