#ifndef EXPONENCIACAO 
#define EXPONENCIACAO 

#include "../parser/parser.h"
#include "../parser/expre.h"
#include "../parser/unario.h"

class tranformExpSimples : public expre::unario {
	private:
		float a,b;
	public:

    tranformExpSimples (expre *novo, float a, float b) : unario (novo) { 
    	nome = new char[4];
    	strcpy(nome, "tranformExpSimples");
    	this->a = a;
    	this->b = b;
    }
    tranformExpSimples () : unario () { nome = new char[4]; strcpy(nome, "tranformExpSimples"); a = 0; b = 0 ;}

    float calcular (const float &s);	
};
class tranformExpDupla : public expre::unario {
	private:
		float a,b;
	public:

    tranformExpDupla (expre *novo, float a, float b) : unario (novo) { 
    	nome = new char[4];
    	strcpy(nome, "tranformExpDupla");
    	this->a = a;
    	this->b = b;
    }
    tranformExpDupla () : unario () { nome = new char[4]; strcpy(nome, "tranformExpDupla"); a = 0; b = 0 ;}

    float calcular (const float &s);	
};


////////////////////////////////////////

float exponenciacaoSimples (expre::expre *equacao, float a, float b, float erro);

float exponenciacaoDupla (expre::expre *equacao, float a, float b, float erro);

#endif