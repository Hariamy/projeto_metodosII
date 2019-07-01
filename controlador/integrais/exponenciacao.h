#ifndef EXPONENCIACAO 
#define EXPONENCIACAO 

#include "../parser/parser.h"
#include "../parser/expre.h"
#include "../parser/unario.h"

class tranformExpSimples : public expre::unario {
	private:
		double a,b;
	public:

    tranformExpSimples (expre *novo, double a, double b) : unario (novo) { 
    	nome = new char[4];
    	strcpy(nome, "tranformExpSimples");
    	this->a = a;
    	this->b = b;
    }
    tranformExpSimples () : unario () { nome = new char[4]; strcpy(nome, "tranformExpSimples"); a = 0; b = 0 ;}

    double calcular (const double &s);	
};
class tranformExpDupla : public expre::unario {
	private:
		double a,b;
	public:

    tranformExpDupla (expre *novo, double a, double b) : unario (novo) { 
    	nome = new char[4];
    	strcpy(nome, "tranformExpDupla");
    	this->a = a;
    	this->b = b;
    }
    tranformExpDupla () : unario () { nome = new char[4]; strcpy(nome, "tranformExpDupla"); a = 0; b = 0 ;}

    double calcular (const double &s);	
};


////////////////////////////////////////

double exponenciacaoSimples (expre::expre *equacao, double a, double b, double erro);

double exponenciacaoDupla (expre::expre *equacao, double a, double b, double erro);

#endif