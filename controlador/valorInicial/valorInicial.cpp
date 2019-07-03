#include "valorInicial.h"

using namespace std;

int MAX_ITERATION = 10000;

VectorXf corretor4Ordem(double xi, double xf, VectorXf estadoInicial ,  int particoes, funcao *F){
    
    double deltax = (xf-xi)/(particoes);

    vector <double> x(5);

    double acumulador = xi;
    
    for(int i=0; i<5; i++){
        x[i] = acumulador;
        acumulador = acumulador + deltax;
    }
    
    vector <VectorXf> y(4);

    y[0] = estadoInicial;
    
    VectorXf k1;
        
    VectorXf k2;
        
    VectorXf k3;
        
    VectorXf k4;

    
    for(int i = 1; i<4 ; i++){
        
        k1 = F(y[i-1], x[i-1]);
        
        k2 = F(y[i-1]+ (k1*(deltax/2.0)), x[i-1] + (deltax/2.0));
        
        k3 = F(y[i-1]+(k2*(deltax/2.0)), x[i-1] + (deltax/2.0));
        
        k4 = F(y[i-1]+k3, x[i-1] + deltax);
        
        y[i] =  y[i-1] + ((k1 + 2.0*k2 + 2.0*k3 + k4) * (deltax/6.0));
    }
    
    VectorXf py;
    
    for(int i = 4; i<particoes; i++){
        
        py = (deltax/24.0) * ( (55.0*F(y[3],x[3])) - (59.0*F(y[2],x[2])) + (37.0*F(y[1],x[1])) - (9.0*F(y[0],x[0])) )  + y[3];
        
        y.push_back( (deltax/24.0) * ( (9.0*F(py,x[4])) + (19.0*F(y[3],x[3])) - (5.0*F(y[2],x[2])) + F(y[1],x[1]) ) + y[3] );
        
        x.push_back(x.back() + deltax);
        
        y.erase(y.begin());
        x.erase(x.begin());
    }
    
    return y.back();
}

VectorXf corretor4OrdemErro(double xi, double xf, VectorXf estadoInicial,  double erro, funcao *F){

    VectorXf RESPOSTA(2);
    RESPOSTA[0] = 0.0;
    RESPOSTA[1] = 0.0;
    
    VectorXf erroAnterior(2);
    erroAnterior[0] = 0.0;
    erroAnterior[1] = 0.0;
    
    int iteracoes = 0;
    int particoes = 100;

    do{
        erroAnterior = RESPOSTA;
        
        RESPOSTA = corretor4Ordem(xi, xf, estadoInicial, particoes, F);

        particoes = 2*particoes;

        iteracoes++;
        
    } while( fabs( (erroAnterior[1] - RESPOSTA[1])/RESPOSTA[1] ) > erro and iteracoes < MAX_ITERATION);

    return RESPOSTA;

}


VectorXf eulerFW(double xi, double xf, VectorXf estadoInicial ,  int particoes, funcao *F){
    
    double deltax = (xf-xi)/(particoes);
    
    VectorXf y = estadoInicial;
    
    double x = xi;
    
    for(int i = 1; i<particoes; i++){
        
        y = y + deltax * F(y,x);
        
        x = x + deltax;
        
    }
    return y;
}

VectorXf eulerFWErro(double xi, double xf, VectorXf estadoInicial ,  double erro, funcao *F) {

    VectorXf RESPOSTA(2);
    RESPOSTA[0] = 0.0;
    RESPOSTA[1] = 0.0;
    
    VectorXf erroAnterior(2);
    erroAnterior[0] = 0.0;
    erroAnterior[1] = 0.0;
    
    int iteracoes = 0;
    int particoes = 100;

    do{
        erroAnterior = RESPOSTA;
        
        RESPOSTA = eulerFW(xi, xf, estadoInicial, particoes, F);
        
        particoes = 2*particoes;

        iteracoes++;
        
    } while( fabs( (erroAnterior[1] - RESPOSTA[1])/RESPOSTA[1] ) > erro and iteracoes < MAX_ITERATION);

    return RESPOSTA;

}

VectorXf eulerBW(double xi, double xf, VectorXf estadoInicial ,  int particoes, funcao *F){
    
    double deltax = (xf-xi)/(particoes);
    
    VectorXf y = estadoInicial;
    
    VectorXf py;
    
    double x = xi;
    
    for(int i = 0; i<particoes; i++){

        py = y + deltax * y;
        
        VectorXf anterior;
        
        do{
            anterior = py;
            py = y + (deltax * F(py, x+deltax)); 
        
            
        } while( fabs( (anterior[1] - py[1])/py[1] ) > 0.0000001 );
        y = py;
        x = x + deltax;
        
        
    }
    
    return y;
}

VectorXf eulerBWErro(double xi, double xf, VectorXf estadoInicial ,  double erro, funcao *F) {

    VectorXf RESPOSTA(2);
    RESPOSTA[0] = 0.0;
    RESPOSTA[1] = 0.0;
    
    VectorXf erroAnterior(2);
    erroAnterior[0] = 0.0;
    erroAnterior[1] = 0.0;
    
    int iteracoes = 0;
    int particoes = 100;

    do{
        erroAnterior = RESPOSTA;
        
        RESPOSTA = eulerFW(xi, xf, estadoInicial, particoes, F);
        
        particoes = 2*particoes;

        iteracoes++;
        
    } while( fabs( (erroAnterior[1] - RESPOSTA[1])/RESPOSTA[1] ) > erro and iteracoes < MAX_ITERATION);

    return RESPOSTA;

}

VectorXf rungeKutta4(double xi, double xf, VectorXf estadoInicial ,  int particoes, funcao *F){
    
    double deltax = (xf-xi)/(particoes);

    double x = xi;

    VectorXf y = estadoInicial;
    
    VectorXf k1;
    
    VectorXf k2;
        
    VectorXf k3;
        
    VectorXf k4;

    for(int i = 0; i<particoes ; i++){
        
        k1 = F(y, x);
        
        k2 = F(y+ (k1*(deltax/2.0)), x + (deltax/2.0));
        
        k3 = F(y+(k2*(deltax/2.0)), x + (deltax/2.0));
        
        k4 = F(y+(k3 * deltax), x + deltax);
        
        y =  y + (((k1 + (2.0*k2) + (2.0*k3) + k4) *deltax)/6.0);

        x = x + deltax;
    }
    
    return y;
}


VectorXf EulerIpct(double xi, double xf, VectorXf estadoInicial ,  int particoes, funcao *F){
    double dt = (xf - xi)/particoes;
    int i,j;
    int dim = estadoInicial.rows();
    VectorXf Sn(dim), a(dim), b(dim), c(dim), h(dim),
                    Fa(dim), Fb(dim), Fc(dim);
    MatrixXd J(dim,dim);
    Sn = estadoInicial;

    for(i=0; i<particoes; i++){
        b = Sn;
        h.setConstant(HUGE_VAL);
        while(h.norm() > 0.1*dt){  // metodo de newton para encontrar raizes de funcoes
            Fb = b - Sn - dt*F(b, t0 + (i+1)*dt);
            for (j = 0; j < dim; j++){
                c = a = b;
                a(j) -= 0.5*dt;
                Fa = a - Sn - dt*F(a, t0 + (i+1)*dt);

                c(j) += 0.5*dt;
                Fc = c - Sn - dt*F(c, t0 + (i+1)*dt);

                J.col(j) = (1/dt)*( Fc - Fa );
            }
            // cout << " Jacobiana\n" << J; 
            h = J.inverse()*Fb;
            b = b - h;
            // cout << "\nb " << b.transpose() << "\t\terro "<< Fb.norm() << "\n";
        }

        Sn = b;

    }
    
    return Sn;

}


VectorXf EulerMod(double xi, double xf, VectorXf estadoInicial ,  int particoes, funcao *F){
    double dt = (xf - xi)/particoes;
    VectorXf Sn = estadoInicial;

    for(int i=0; i<particoes; i++){
        Sn = Sn + dt*F(Sn + 0.5*dt*F(t0+i*dt,Sn), t0 + i*dt + 0.5*dt);
    }
    
    return Sn;
}
VectorXf EulerApr(double xi, double xf, VectorXf estadoInicial ,  int particoes, funcao *F){
    double dt = (xf - xi)/particoes;
    VectorXf Sn = estadoInicial;

    for(int i=0; i<particoes; i++){
        Sn = Sn + 0.5*dt*(F(Sn, t0 + i*dt) + F(Sn + dt*F(t0 + i*dt, Sn), t0 + (i+1)*dt));
    }
    
    return Sn;   
}

VectorXf rungeKutta4Erro(double xi, double xf, VectorXf estadoInicial,  double erro, funcao *F) {

    VectorXf RESPOSTA(2);
    RESPOSTA[0] = 0.0;
    RESPOSTA[1] = 0.0;
    
    VectorXf erroAnterior(2);
    erroAnterior[0] = 0.0;
    erroAnterior[1] = 0.0;
    
    int iteracoes = 0;
    int particoes = 100;

    do{
        erroAnterior = RESPOSTA;
        
        RESPOSTA = rungeKutta4(xi, xf, estadoInicial, particoes, F);
        
        particoes = 2*particoes;

        iteracoes++;
        
    } while( fabs( (erroAnterior[1] - RESPOSTA[1])/RESPOSTA[1] ) > erro and iteracoes < MAX_ITERATION);

    return RESPOSTA;

}
