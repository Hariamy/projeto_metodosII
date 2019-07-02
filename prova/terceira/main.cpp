#include "../../controlador/valorInicial/valorInicial.h"
using namespace std;

#define X0 1
#define A 3
#define B 9
#define C 7
#define D 6
#define E 1
#define F1 3
#define m (double)(1.0+((A+B+C+D+E+F1)%4))
#define k 4.0
#define w sqrt(k/m)
#define nn 0.05

double f(double t){
    
    if( (t < 0) or (t > 1)) return 0;
    else if (t <= 0.5) return 4*t;
    else if (t <= 1) return 4*(1-t);
    else return 0;
}

VectorXf F(VectorXf estado, double t){
    VectorXf RESPOSTA(2);
    
    RESPOSTA[1] = estado[0];
    
    RESPOSTA[0] = (f(t)/m) - (2*nn*w*estado[0]) - (pow(w,2) * estado[1]) ; 
    
    return RESPOSTA;
    
}

int main(){
   
    //Estado inicial
    VectorXf S0(2);
    
    //v(t)'
    S0[0] = 0.0;
    //x(t)'
    S0[1] = X0;
    
    double ti = 0.0;
    double tf = 1.2;
 
    VectorXf RESPOSTA(2);
    RESPOSTA[0] = 0.0;
    RESPOSTA[1] = 0.0;
    
    VectorXf erroAnterior(2);
    erroAnterior[0] = 0.0;
    erroAnterior[1] = 0.0;
    
    int particoes = 2;
    
    double erro = 0.0001;
    int iteracoes = 0;
    
    do{
        erroAnterior = RESPOSTA;
        
        RESPOSTA = RungeKutta4(ti, tf, S0, particoes, F);
        
        particoes = 2*particoes;

        iteracoes++;
        
    } while( fabs( (erroAnterior[1] - RESPOSTA[1])/RESPOSTA[1] ) > erro && iteracoes < 1000);
    
    cout << "PRIMEIRA QUESTÃO:" << endl;
    cout << "No tempo t = " << tf << " temos:" << endl;
    cout << "  v(t) = " << RESPOSTA[0] << endl;
    cout << "  x(t) = " << RESPOSTA[1] << endl;
    return 0; 
    
} 
