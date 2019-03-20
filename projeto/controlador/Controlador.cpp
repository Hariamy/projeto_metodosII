
#include "Controlador.h"

Controlador::Controlador(){}

Funcao *getFuncao(int funcao){
	Funcao *func;
	switch(funcao){
		case 1: //SENO
			func = new Seno();
			break;

		case 2: //COSSENO
			func = new Cosseno();
			break;

		case 3: //POLINOMIO
			func = new Polinomio();
			break;

		case 4: //GENERICA
			func = new Generica();
			break;
	}
	return func;
}

float Controlador::integralNewtonGatesErro(int filosofia, int grau, int funcao, float Xi, float Xf, float erro){
	Funcao *func = getFuncao(funcao);

	Integral *integ = new NewtonGates();
	return integ->calcularErro(func, erro);
}

float Controlador::integralNewtonGatesPartes(int filosofia, int grau, int funcao, float Xi, float Xf, int partes){
	Funcao *func = getFuncao(funcao);

	Integral *integ = new NewtonGates();
	return integ->calcularPartes(func, partes);

}