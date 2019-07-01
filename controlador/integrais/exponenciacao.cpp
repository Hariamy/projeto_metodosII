#include "exponenciacao.h"
#include "integralGaussLegendre.h"


////////////////////////////////////////// start leon
double tranformExpSimples::calcular(const double &s){
    double x = 0.5*( (a+b) + (b-a)*tanh(s));
    return filho->calcular( x )*(1.0/(cosh(s)*cosh(s)));
}
double tranformExpDupla::calcular(const double &s){
    double x = 0.5*( (a+b) + (b-a)*tanh(M_PI*0.5*sinh(s)));
    return filho->calcular( x )*(cosh(s)/(cosh(M_PI*0.5*sinh(s))*cosh(M_PI*0.5*sinh(s))));
}

//////////////////////////////////////// end leon

double exponenciacaoSimples (expre::expre *equacao, double a, double b, double erro) {
	int qtdPontos = 3, qtdDivisoes = 10000;
	//if(analisador(tt)){

	double intAnterior = INFINITY;
	double intAtual = 1;
	double c = 0.1;
	double intervalo[] = {-c,c};
	double integral = 0;


//////////////////////////////////////////// start leon
	tranformExpSimples *g = new tranformExpSimples(equacao, a, b);
	//////////////////////////////////////////// end leon

	while (fabs( (intAnterior - intAtual) / intAtual ) > erro) {
		intAnterior = intAtual;
	
//////////////////////////////////////////////// start leon
		integral = gaussLegendre (qtdPontos, qtdDivisoes, intervalo, g);
///////////////////////////////////////////////// end leon
		//std::cout << "\nValor de c = " << c << std::endl;
		//std::cout << "\nValor da integral = " << integral << std::endl;
	
		// integral = 0; // calcula integral da forma desejada

		intAtual = integral*(b - a)*0.5; 
		c += 0.1;

		intervalo[0] = -c;
		intervalo[1] = c;

	}

	delete g;
	return intAtual;
}

double exponenciacaoDupla (expre::expre *equacao, double a, double b, double erro) {
	int qtdPontos = 3, qtdDivisoes = 10000;
	//if(analisador(tt)){

	double intAnterior = INFINITY;
	double intAtual = 1;
	double c = 0.05;
	double intervalo[] = {-c,c};
	double integral = 0;


//////////////////////////////////////////// start leon
	tranformExpDupla *g = new tranformExpDupla(equacao, a, b);
	//////////////////////////////////////////// end leon

	while (fabs( (intAnterior - intAtual) / intAtual ) > erro) {
		intAnterior = intAtual;
	
//////////////////////////////////////////////// start leon
		integral = gaussLegendre (qtdPontos, qtdDivisoes, intervalo, g);
		//std::cout << "\nValor de c = " << c << std::endl;
		//std::cout << "\nValor da integral = " << integral << std::endl;
///////////////////////////////////////////////// end leon
	
		// integral = 0; // calcula integral da forma desejada

		intAtual = integral*(b - a)*0.25*M_PI; 
		c += 0.1;

		intervalo[0] = -c;
		intervalo[1] = c;

	}

	delete g;
	return intAtual;
}