#include "Contorno.h"

VectorXf Contorno1D(double xi, double xf,  int particoes, double A, double B, double C, double D, double E, double F) {
    double deltaR = (xf - xi) / (double)particoes,
           T = (A+B+C), P = (D+E+F),
           N = 4.0 + (fmod(A+B+C+D+E+F, 4.0));
    VectorXf vetor(particoes-1);
    MatrixXf matriz = preencherMatriz(xi, particoes, deltaR);
    
    for(int i = 0; i < particoes-1; i++){
        vetor[i] = -(P/T);
    }
    //std::cout << matriz << std::endl << vetor << std::endl;
    
    resolverSistema(matriz, vetor);
    
    return vetor;
}

MatrixXf preencherMatriz(double xi, int particoes, double deltaR) {
    MatrixXf matriz(particoes-1, particoes-1);
    double r = xi;
    
    for(int i = 0; i < (particoes-1); i ++){
        r += deltaR;
        
        if(i > 0){
            matriz(i, i-1) = (1/(deltaR*deltaR)) - (1/(2*r*deltaR));
        }
        
        matriz(i, i) = -(2/(deltaR*deltaR));
        
        if(i < particoes-2){
            matriz(i, i+1) = (1/(deltaR*deltaR)) + (1/(2*r*deltaR));
        }
    }
    
    return matriz;
}

void resolverSistema(MatrixXf &matriz, VectorXf &vetor) {
    double sub = 0.0, valor = 0.0;
    int tam = matriz.rows();
    
    for(int i = 0; i < tam; i++){
        valor = matriz(i, i);
        vetor[i] /= valor;
        
        for(int j = 0; j < tam; j++){
            matriz(i, j) /= valor;
        }
        
        if(i < tam-1){
            sub = -matriz(i+1, i);
            
            for(int j = 0; j < tam; j++){
                matriz(i+1, j) += sub * matriz(i, j);
            }
            
            vetor[i+1] += sub * vetor[i];
        }
    }
    
    for(int i = tam-1; i > 0; i--){
      sub = -matriz(i-1, i);
      
      for(int j = 0; j < tam; j++){
        matriz(i-1, j) += sub * matriz(i, j);
      }
      
      vetor[i-1] += sub * vetor[i];
    }
}

/*int main(){
    VectorXf respo = Contorno1D(0.2, 0.5, 6);
    
    std::cout << respo << std::endl;
    
    return 0;
}*/
