#include "exponenciacao.h"
#include "integralGaussLegendre.h"


////////////////////////////////////////// start leon
float tranformExpSimples::calcular(const float &s){
    float x = 0.5*( (a+b) + (b-a)*tanh(s));
    return filho->calcular( x )*(1.0/(cosh(s)*cosh(s)));
}
float tranformExpDupla::calcular(const float &s){
    float x = 0.5*( (a+b) + (b-a)*tanh(M_PI*0.5*sinh(s)));
    return filho->calcular( x )*(cosh(s)/(cosh(M_PI*0.5*sinh(s))*cosh(M_PI*0.5*sinh(s))));
}

//////////////////////////////////////// end leon

float exponenciacaoSimples (expre::expre *equacao, float a, float b, float erro) {
	int qtdPontos = 3, qtdDivisoes = 100000;
	//if(analisador(tt)){

	float intAnterior = INFINITY;
	float intAtual = 1;
	float c = 0.1;
	float intervalo[] = {-c,c};
	float integral = 0;


//////////////////////////////////////////// start leon
	tranformExpSimples *g = new tranformExpSimples(equacao, a, b);
	//////////////////////////////////////////// end leon

	while (fabs( (intAnterior - intAtual) / intAtual ) > erro) {
		intAnterior = intAtual;
	
//////////////////////////////////////////////// start leon
		integral = gaussLegendre (qtdPontos, qtdDivisoes, intervalo, g);
///////////////////////////////////////////////// end leon
	
		// integral = 0; // calcula integral da forma desejada

		intAtual = integral*(b - a)*0.5; 
		c += 0.1;

		intervalo[0] = -c;
		intervalo[1] = c;

	}

	return intAtual;
}

float exponenciacaoDupla (expre::expre *equacao, float a, float b, float erro) {
	int qtdPontos = 3, qtdDivisoes = 100000;
	//if(analisador(tt)){

	float intAnterior = INFINITY;
	float intAtual = 1;
	float c = 0.05;
	float intervalo[] = {-c,c};
	float integral = 0;


//////////////////////////////////////////// start leon
	tranformExpDupla *g = new tranformExpDupla(equacao, a, b);
	//////////////////////////////////////////// end leon

	while (fabs( (intAnterior - intAtual) / intAtual ) > erro) {
		intAnterior = intAtual;
	
//////////////////////////////////////////////// start leon
		integral = gaussLegendre (qtdPontos, qtdDivisoes, intervalo, g);
///////////////////////////////////////////////// end leon
	
		// integral = 0; // calcula integral da forma desejada

		intAtual = integral*(b - a)*0.25*M_PI; 
		c += 0.1;

		intervalo[0] = -c;
		intervalo[1] = c;

	}

	return intAtual;
}