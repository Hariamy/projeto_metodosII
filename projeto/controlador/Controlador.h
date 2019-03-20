#ifndef CONTROLADOR_H
#define CONTROLADOR_H

#include <cmath>

#include "../modelo/Integral.h"
#include "../modelo/NewtonGates.h"
#include "../modelo/funcoes/Funcao.h"
#include "../modelo/funcoes/Seno.h"
#include "../modelo/funcoes/Cosseno.h"
#include "../modelo/funcoes/Polinomio.h"
#include "../modelo/funcoes/Generica.h"


class Controlador {
	
public:
	Controlador();

	float integralNewtonGatesErro(int filosofia, int grau, int funcao, float Xi, float Xf, float erro);
	float integralNewtonGatesPartes(int filosofia, int grau, int funcao, float Xi, float Xf, int partes);


};

#endif //CONTROLADOR_H