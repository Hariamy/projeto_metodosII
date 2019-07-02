#ifndef EXPONENCIACAO 
#define EXPONENCIACAO 

#include "../parser/parser.h"
#include "../parser/expre.h"
#include "../parser/unario.h"

class tranformExpSimples : public expre::unario {
	private:
		double a, b;
	public:

    tranformExpSimples (expre *novo, double a, double b) : unario (novo) { 
    	nome = new char[4];
    	strcpy(nome, "tranformExpSimples");
    	this->a = a;
    	this->b = b;
    }
    tranformExpSimples () : unario () { nome = new char[4]; strcpy(nome, "tranformExpSimples"); a = 0; b = 0 ;}

    double calcular (const double &s) {
        double x = 0.5*( (a+b) + (b-a)*tanh(s));
        return filho->calcular( x )*(1.0/(cosh(s)*cosh(s)));
    }
};
class tranformExpDupla : public expre::unario {
	private:
		double a, b;
	public:

    tranformExpDupla (expre *novo, double a, double b) : unario (novo) { 
    	nome = new char[4];
    	strcpy(nome, "tranformExpDupla");
    	this->a = a;
    	this->b = b;
    }
    tranformExpDupla () : unario () { nome = new char[4]; strcpy(nome, "tranformExpDupla"); a = 0; b = 0 ;}

    double calcular (const double &s) {
        double x = 0.5*( (a+b) + (b-a)*tanh(M_PI*0.5*sinh(s)));
        return filho->calcular( x )*(cosh(s)/(cosh(M_PI*0.5*sinh(s))*cosh(M_PI*0.5*sinh(s))));
    }
};


////////////////////////////////////////

double exponenciacaoSimples (expre::expre *equacao, double a, double b, double erro);
double exponenciacaoSimplesNewton (const int &grau, const int &filosofia, const double erro, const double intervalo[2], expre::expre *equacao);
double exponenciacaoSimplesGauss (const int &qtdPontos, double erro, const double intervalo[2], expre::expre *equacao);


double exponenciacaoDupla (expre::expre *equacao, double a, double b, double erro);
double exponenciacaoDuplaNewton (const int &grau, const int &filosofia, const double erro, const double intervalo[2], expre::expre *equacao);
double exponenciacaoDuplaGauss (const int &qtdPontos, double erro, const double intervalo[2], expre::expre *equacao);


#endif