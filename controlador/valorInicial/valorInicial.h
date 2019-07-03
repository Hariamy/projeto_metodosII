#ifndef VALOR_INICIAL_H
#define VALOR_INICIAL_H

#include <iostream>
#include <cmath>
#include "../parser/parser.h"
#include "../../biblioteca/eigen/Eigen/Dense"
#include <vector>

using namespace Eigen;

typedef VectorXf (funcao)(VectorXf estado, double t);

VectorXf corretor4Ordem(double xi, double xf, VectorXf estadoInicial ,  int particoes, funcao *F);
VectorXf corretor4OrdemErro(double xi, double xf, VectorXf estadoInicial ,  double erro, funcao *F);

VectorXf eulerFW(double xi, double xf, VectorXf estadoInicial ,  int particoes, funcao *F);
VectorXf eulerFWErro(double xi, double xf, VectorXf estadoInicial ,  double erro, funcao *F);

VectorXf rungeKutta4(double xi, double xf, VectorXf estadoInicial ,  int particoes, funcao *F);
VectorXf rungeKutta4Erro(double xi, double xf, VectorXf estadoInicial ,  double erro, funcao *F);

VectorXf eulerBW(double xi, double xf, VectorXf estadoInicial ,  int particoes, funcao *F);
VectorXf eulerBWErro(double xi, double xf, VectorXf estadoInicial ,  double erro, funcao *F);



#endif //VALOR_INICIAL_H
