package Modelo.Funcao


/**Interface para implementar funcoes
  *
  * @author João Castelo Branco
  */
trait Funcao {

  /** Metodo para calcular o valor da Funcao dado um 'x'
    *
    * @param valorX valor da variavel 'x'
    * @return o valor da funcao no 'x' passado
    */
  def apply(valorX : Double):Double

  def toString: String
}
