package Modelo.Metodos_Matrizes
import Modelo.Matriz.Matriz

object Potenciacao extends Metodo {
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
