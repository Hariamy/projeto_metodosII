#include "exponenciacao.h"
#include "integralGaussLegendre.h"



double exponenciacaoSimples (expre::expre *equacao, double a, double b, double erro) {
	int qtdPontos = 3, qtdDivisoes = 10000;

	double intAnterior = INFINITY;
	double intAtual = 1;
	double c = 0.1;
	double intervalo[] = {-c,c};
	double integral = 0;


	tranformExpSimples *g = new tranformExpSimples(equacao, a, b);

	while (fabs( (intAnterior - intAtual) / intAtual ) > erro) {
		intAnterior = intAtual;
	
		integral = gaussLegendre (qtdPontos, qtdDivisoes, intervalo, g);

		intAtual = integral*(b - a)*0.5; 
		c += 0.1;

		intervalo[0] = -c;
		intervalo[1] = c;

	}

	delete g;
	return intAtual;
}

double exponenciacaoSimplesNewton (const int &grau, const int &filosofia, const int &qtdDivisoes, const double intervalo[2], expre::expre *equacao, double erro) {

	double intAnterior = INFINITY;
	double intAtual = 1;
	double c = 0.1;
	double intC[] = {-c,c};
	double integral = 0;
	double a, b;

	a = intervalo[0];
	b = intervalo[1];

	tranformExpSimples *g = new tranformExpSimples(equacao, a, b);

	while (fabs( (intAnterior - intAtual) / intAtual ) > erro) {
		intAnterior = intAtual;

		integral = newtonCotes(grau, filosofia, qtdDivisoes, intC, g);
		
		intAtual = integral*(b - a)*0.5; 
		
		c += 0.1;

		intC[0] = -c;
		intC[1] = c;

	}

	delete g;
	return intAtual;
}

double exponenciacaoSimplesGauss (expre::expre *equacao, double a, double b, double erro) {
	int qtdPontos = 3, qtdDivisoes = 10000;

	double intAnterior = INFINITY;
	double intAtual = 1;
	double c = 0.1;
	double intervalo[] = {-c,c};
	double integral = 0;

	tranformExpSimples *g = new tranformExpSimples(equacao, a, b);

	while (fabs( (intAnterior - intAtual) / intAtual ) > erro) {
		intAnterior = intAtual;
	
		integral = gaussLegendre (qtdPontos, qtdDivisoes, intervalo, g);

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
	
	double intAnterior = INFINITY;
	double intAtual = 1;
	double c = 0.05;
	double intervalo[] = {-c,c};
	double integral = 0;

	tranformExpDupla *g = new tranformExpDupla(equacao, a, b);

	while (fabs( (intAnterior - intAtual) / intAtual ) > erro) {
		intAnterior = intAtual;
	
		integral = gaussLegendre (qtdPontos, qtdDivisoes, intervalo, g);

		intAtual = integral*(b - a)*0.25*M_PI; 
		c += 0.1;

		intervalo[0] = -c;
		intervalo[1] = c;

	}

	delete g;
	return intAtual;
}


// -------- \\ INÍCIO - FUNÇÕES PARA A EXPONENCIAÇÃO // -------- \\ 
double tranformExpSimples::calcular(const double &s){
    double x = 0.5*( (a+b) + (b-a)*tanh(s));
    return filho->calcular( x )*(1.0/(cosh(s)*cosh(s)));
}
double tranformExpDupla::calcular(const double &s){
    double x = 0.5*( (a+b) + (b-a)*tanh(M_PI*0.5*sinh(s)));
    return filho->calcular( x )*(cosh(s)/(cosh(M_PI*0.5*sinh(s))*cosh(M_PI*0.5*sinh(s))));
}
// -------- \\ INÍCIO - FUNÇÕES PARA A EXPONENCIAÇÃO // -------- \\ 
