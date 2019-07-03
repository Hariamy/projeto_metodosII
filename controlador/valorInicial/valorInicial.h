#ifndef VALOR_INICIAL_H
#define VALOR_INICIAL_H

#include <iostream>
#include <cmath>
#include "../parser/parser.h"
#include "../../biblioteca/eigen/Eigen/Dense"
#include <vector>

using namespace Eigen;

typedef VectorXf (funcao)(VectorXf estado, double t);

VectorXf Corretor4Ordem(double xi, double xf, VectorXf estadoInicial ,  int particoes, funcao *F);

VectorXf EulerFW(double xi, double xf, VectorXf estadoInicial ,  int particoes, funcao *F);

VectorXf RungeKutta4(double xi, double xf, VectorXf estadoInicial ,  int particoes, funcao *F);

VectorXf EulerBW(double xi, double xf, VectorXf estadoInicial ,  int particoes, funcao *F);



#endif //VALOR_INICIAL_H
