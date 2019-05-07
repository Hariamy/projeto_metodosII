package Modelo.Metodos_Matrizes
import Modelo.Matriz.Matriz


/**
  * classe singleton que implementa o metodo da potenciacao
  */
object Potenciacao extends AutoValores {

  /**
    * metodo da potenciacao
    * @param A matriz que sera aplicada
    * @param x0 chute inicial
    * @param erro erro toleravel
    * @return tupla (auto valor dominante, auto vetor correspondente)
    */
  override def apply(A: Matriz, x0: Matriz, erro: Double): (Double,Matriz) = {
    if(A.isVetor || !x0.isVetor){
      return null
    }


    var q : Matriz = x0/x0.norma

    var x: Matriz = A*q

    var lamb : Double = (q.transposta * x)(0,0)

    var lamb0 : Double = 0
    do{
      lamb0 = lamb
      q = x/x.norma
      x = A*q
      lamb = (q.transposta * x)(0,0) / (q.transposta*q)(0,0)

    }while( (lamb - lamb0)/lamb > erro )

    (lamb,x)

  }
}
