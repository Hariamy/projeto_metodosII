#include "../../controlador/valorInicial/valorInicial.h"
using namespace std;

// MATRÍCULA - INÍCIO
#define A 3
#define B 9
#define C 7
#define D 6
#define E 1
#define F1 3
// MATRÍCULA - FIM

#define X0 1
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
	
	double erro = 0.0001;
  
	
	RESPOSTA = rungeKutta4Erro(ti, tf, S0, erro, F);
	
	cout << "\nMÉTODO RUNGE KUTTA DE 4ª ORDEM:" << endl;
	cout << "No tempo t = " << tf << " temos:" << endl;
	cout << "  v(t) = " << RESPOSTA[0] << endl;
	cout << "  x(t) = " << RESPOSTA[1] << endl;

	RESPOSTA = corretor4OrdemErro(ti, tf, S0, erro, F);

	cout << "\nMÉTODO PREDITOR CORRETOR DE 4ª ORDEM:" << endl;
	cout << "No tempo t = " << tf << " temos:" << endl;
	cout << "  v(t) = " << RESPOSTA[0] << endl;
	cout << "  x(t) = " << RESPOSTA[1] << endl;
		
	RESPOSTA = eulerFWErro(ti, tf, S0, erro, F);
	
	cout << "\nMÉTODO FORWARD EULER:" << endl;
	cout << "No tempo t = " << tf << " temos:" << endl;
	cout << "  v(t) = " << RESPOSTA[0] << endl;
	cout << "  x(t) = " << RESPOSTA[1] << endl;

	RESPOSTA = eulerBWErro(ti, tf, S0, erro, F);
	
	cout << "\nMÉTODO BACKWARD EULER:" << endl;
	cout << "No tempo t = " << tf << " temos:" << endl;
	cout << "  v(t) = " << RESPOSTA[0] << endl;
	cout << "  x(t) = " << RESPOSTA[1] << endl;


	return 0; 
	
} 
