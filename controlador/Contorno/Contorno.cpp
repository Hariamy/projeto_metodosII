#include "Contorno.h"

VectorXf Contorno1D(double xi, double xf,  int particoes) {
    double deltaR = (xf - xi) / (double)particoes;
    VectorXf vetor(particoes-1);
    MatrixXf matriz = preencherMatriz(xi, particoes, deltaR);
    
    for(int i = 0; i < particoes-1; i++){
        vetor[i] = -(19.0/19.0);
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

VectorXf Contorno2D(double xi, double xf, double yi, double yf, double uContorno, double coefLapl,
                    funcaoReal2D coefDxDy, funcaoReal2D coefDx, funcaoReal2D coefDy, 
                    funcaoReal2D coefU, funcaoReal2D F,  int nparticoesx, int nparticoesy){
    int dim = (nparticoesy-1)*(nparticoesx-1), i, j;
    double x, y, dx = (xf - xi)/nparticoesx, dy = (yf - yi)/nparticoesy;
    VectorXf u(dim),
             b(dim);
    MatrixXf A(dim, dim);

    for(i=0; i<dim; i++){
        x = xi + (i%(nparticoesx-1))*dx;
        y = yi + (i/(nparticoesx-1))*dy;
        b(i) = -F(x, y);
        if(i%(nparticoesx-1) == 0){
            // b(i) -= (coefDxDy(x,y)/(4*dx*dy))*uContorno;
            b(i) -= ( coefLapl/(dx*dx) - coefDx(x,y)/(2*dx) )*uContorno;
            // b(i) -= -(coefDxDy(x,y)/(4*dx*dy))*uContorno;
            if (i/(nparticoesx-1) == 0)
                b(i) -= (coefDxDy(x,y)/(4*dx*dy))*uContorno;
        }
        if(i%(nparticoesx-1) == nparticoesx-2){
            // b(i) -= -(coefDxDy(x,y)/(4*dx*dy))*uContorno;
            b(i) -= ( coefLapl/(dx*dx) + coefDx(x,y)/(2*dx) )*uContorno;
            // b(i) -= (coefDxDy(x,y)/(4*dx*dy))*uContorno;
            if (i/(nparticoesx-1) == 0)
                b(i) -= -(coefDxDy(x,y)/(4*dx*dy))*uContorno;
        }
        if(i/(nparticoesx-1) == 0){
            // b(i) -= (coefDxDy(x,y)/(4*dx*dy))*uContorno;
            b(i) -= ( coefLapl/(dy*dy) - coefDy(x,y)/(2*dy) )*uContorno;
            // b(i) -= -(coefDxDy(x,y)/(4*dx*dy))*uContorno;
            if(i%(nparticoesx-1) == 0)
                b(i) -= -(coefDxDy(x,y)/(4*dx*dy))*uContorno;
        }
        if(i/(nparticoesx-1) == nparticoesy-2){
            // b(i) -= -(coefDxDy(x,y)/(4*dx*dy))*uContorno;
            b(i) -= ( coefLapl/(dy*dy) + coefDy(x,y)/(2*dy) )*uContorno;
            // b(i) -= +(coefDxDy(x,y)/(4*dx*dy))*uContorno;
            if(i%(nparticoesx-1) == nparticoesx-2)
                b(i) -= (coefDxDy(x,y)/(4*dx*dy))*uContorno;
        }

        A(i,i) = -2*( 1/(dx*dx) + 1/(dx*dx) );
        if(i-1 >= 0) A(i,i-1) = coefLapl/(dx*dx) - coefDx(x,y)/(2*dx);
        if(i+1 < dim) A(i,i+1) = coefLapl/(dx*dx) + coefDx(x,y)/(2*dx);
        
        if(i - nparticoesx > 0) 
            A(i,i - nparticoesx) = coefDxDy(x,y)/(4*dx*dy);
        if(i - nparticoesx+1 > 0) 
            A(i,i - nparticoesx+1) = coefLapl/(dy*dy) - coefDy(x,y)/(2*dy);
        if(i - nparticoesx+2 > 0) 
            A(i,i - nparticoesx+2) = -coefDxDy(x,y)/(4*dx*dy);

        if(i + nparticoesx-2 < dim)
            A(i,i + nparticoesx-2) = -coefDxDy(x,y)/(4*dx*dy);
        if(i + nparticoesx-1 < dim) 
            A(i,i + nparticoesx-1) = coefLapl/(dy*dy) + coefDy(x,y)/(2*dy);
        if(i + nparticoesx < dim)
            A(i,i + nparticoesx) = coefDxDy(x,y)/(4*dx*dy);

    }

    u = A.inverse() * b;

    return u;
}

double coefDxDy(double x, double y){return 0.0;}
double coefDx(double x, double y){return (x+y);}
double coefDy(double x, double y){return (x-y);}
double coefU(double x, double y){return 0.0;}
double F(double x, double y){return 12.0;}


int main(){
    double xi = 1.0,
            xf = 4.0,
            yi = 1.0,
            yf = 4.0,
            uContorno = 11.0,
            coefLapl = 0.0;
    int nparticoesx = 3, nparticoesy = 4;
    MatrixXf A;

    A = Contorno2D( xi,  xf,  yi, yf,  uContorno,  coefLapl,
                     &coefDxDy,  &coefDx,  &coefDy, 
                     &coefU,  &F,  nparticoesx, nparticoesy);

    VectorXf respo = Contorno1D(0.2, 0.5, 6);
    
    std::cout << respo << std::endl;

    std::cout << A << std::endl;
    
    return 0;
}
