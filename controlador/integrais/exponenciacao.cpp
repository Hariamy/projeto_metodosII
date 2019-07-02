#include "exponenciacao.h"
#include "integrais.h"



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
	g->inserirFilho(NULL);
	delete g;
	return intAtual;
}

double exponenciacaoSimplesNewton (const int &grau, const int &filosofia, const double erro, const double intervalo[2], expre::expre *equacao){

	double intAnterior = INFINITY;
	double intAtual = 1;
	double c = 0.1;
	double intC[2] = {-c,c};
	double integral = 0;
	double a, b;

	a = intervalo[0];
	b = intervalo[1];

	tranformExpSimples *g = new tranformExpSimples(equacao, a, b);

	while (fabs( (intAnterior - intAtual) / intAtual ) > erro) {
		intAnterior = intAtual;

		integral = newtonCotesErro(grau, filosofia, erro, intC, g);
		
		intAtual = integral*(b - a)*0.5; 
		
		c += 0.1;

		intC[0] = -c;
		intC[1] = c;

	}
	g->inserirFilho(NULL);
	delete g;
	return intAtual;
}

double exponenciacaoSimplesGauss (const int &qtdPontos, double erro, const double intervalo[2], expre::expre *equacao) {
	
	double intAnterior = INFINITY;
	double intAtual = 1;
	double c = 0.1;
	double intC[2] = {-c,c};
	double integral = 0;

	double a, b;

	a = intervalo[0];
	b = intervalo[1];

	tranformExpSimples *g = new tranformExpSimples(equacao, a, b);

	while (fabs( (intAnterior - intAtual) / intAtual ) > erro) {
		intAnterior = intAtual;
		
		integral = gaussLegendreErro (3, erro, intC, g);
		
		intAtual = integral*(b - a)*0.5;
		
		c += 0.1;

		intC[0] = -c;
		intC[1] = c;
		
	}
	g->inserirFilho(NULL);
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
	g->inserirFilho(NULL);
	delete g;
	return intAtual;
}

double exponenciacaoDuplaGauss (const int &qtdPontos, double erro, const double intervalo[2], expre::expre *equacao) {
	
	double intAnterior = INFINITY;
	double intAtual = 1;
	double c = 0.05;
	double intC[2] = {-c,c};
	double integral = 0;

	double a, b;

	a = intervalo[0];
	b = intervalo[1];

	tranformExpDupla *g = new tranformExpDupla(equacao, a, b);

	while (fabs( (intAnterior - intAtual) / intAtual ) > erro) {
		intAnterior = intAtual;
		
		integral = gaussLegendreErro (3, erro, intC, g);
		
		intAtual = integral*(b - a)*0.25*M_PI; 
		
		c += 0.1;

		intC[0] = -c;
		intC[1] = c;
		
	}
	g->inserirFilho(NULL);
	delete g;
	return intAtual;
}

double exponenciacaoDuplaNewton (const int &grau, const int &filosofia, const double erro, const double intervalo[2], expre::expre *equacao){

	double intAnterior = INFINITY;
	double intAtual = 1;
	double c = 0.1;
	double intC[2] = {-c,c};
	double integral = 0;
	double a, b;

	a = intervalo[0];
	b = intervalo[1];

	tranformExpDupla *g = new tranformExpDupla(equacao, a, b);

	while (fabs( (intAnterior - intAtual) / intAtual ) > erro) {
		intAnterior = intAtual;

		integral = newtonCotesErro(grau, filosofia, erro, intC, g);
		
		intAtual = integral*(b - a)*0.25*M_PI;
		
		c += 0.1;

		intC[0] = -c;
		intC[1] = c;

	}
	g->inserirFilho(NULL);
	delete g;
	return intAtual;
}