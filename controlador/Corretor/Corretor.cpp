#include "Corretor.h"

VectorXf Corretor4Ordem(float xi, double xf, VectorXf estadoInicial ,  int particoes, funcao *F){
    
    double deltax = (xf-xi)/(particoes);

    double x[particoes];

    double acumulador = xi
    
    for(int i=0; i<particoes; i++){
        x[i] = acumulador;
        acumulador = acumulador + deltax;
    }
    
    VectorXf y[particoes];

    y[0] = estadoInicial;

    for(int i = 1; i<4 ; i++){
        
        VectorXf k1 = deltax*F(y[i-1], x[i-1]);
        
        VectorXf k2 = deltax*F(y[i-1]+(k1/2), x[i-1] + (deltax/2));
        
        VectorXf k3 = deltax*F(y[i-1]+(k2/2), x[i-1] + (deltax/2));
        
        VectorXf k4 = deltax*F(y[i-1]+k3, x[i-1] + deltax);
        
        y[i] =  y[i-1] + ((k1 + 2*k2 + 2*k3 + k4) * (deltax/6));
    }

    VectorXf py;

    for(int i = 4; i<particoes; i++){
        
        py = (deltax/24) * ( (55*F(y[i-1],x[i-1])) - (59*F(y[i-2],x[i-2])) + (37*F(y[i-3],x[i-3])) - (9*F(y[i-4],x[i-4])) )  + y[i-1];
        
        y[i] = (deltax/24) * ( (9*F(py,x[i])) + (19*F(y[i-1],x[i-1])) - (5*F(y[i-2],x[i-2])) + F(y[i-3],x[i-3]) ) + y[i-1];
    }
    
    return y[particoes - 1];
}

VectorXf EulerFW(float xi, double xf, VectorXf estadoInicial ,  int particoes, funcao *F){
    
    double deltax = (xf-xi)/(particoes);
    
    VectorXf y = estadoInicial;
    
    for(int i = 1; i<particoes; i++){
        
        y = y + deltax * F(y,x);
        
        x = x + deltax;
        
    }
    return y;
}

VectorXf EulerBW(float xi, double xf, VectorXf estadoInicial ,  int particoes, funcao *F){
    
    double deltax = (xf-xi)/(particoes);
    
    VectorXf y = estadoInicial;
    
    VectorXf py;
    
    for(int i = 1; i<particoes; i++){
        
        py = y + deltax * F(y,x);
        
        y = y + deltax * F(py, x+deltax) 
        
        x = x + deltax;
        
    }
    
    return y;
}

VectorXf RungeKutta4(float xi, double xf, VectorXf estadoInicial ,  int particoes, funcao *F){
    
    double deltax = (xf-xi)/(particoes);

    double x = xi;

    VectorXf y = estadoInicial;

    for(int i = 1; i<particoes ; i++){
        
        VectorXf k1 = deltax*F(y, x);
        
        VectorXf k2 = deltax*F(y+(k1/2), x + (deltax/2));
        
        VectorXf k3 = deltax*F(y+(k2/2), x + (deltax/2));
        
        VectorXf k4 = deltax*F(y+k3, x + deltax);
        
        y =  y + ((k1 + 2*k2 + 2*k3 + k4) * (deltax/6));
        
        x = x + deltax;
    }
    
    return y;
}
