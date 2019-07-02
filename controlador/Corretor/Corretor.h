 
#ifndef INTEGRAL_H
#define INTEGRAL_H

#include <iostream>
#include <cmath>
#include "../parser/parser.h"
#include <Eigen/Dense>

using namespace Eigen;

typedef VectorXf (funcao)(VectorXf estado, float t);

VectorXf Corretor4Ordem(float xi, double xf, VectorXf estadoInicial ,  int particoes, funcao *F);

VectorXf EulerFW(float xi, double xf, VectorXf estadoInicial ,  int particoes, funcao *F);

VectorXf RungeKutta4(float xi, double xf, VectorXf estadoInicial ,  int particoes, funcao *F);

VectorXf EulerBW(float xi, double xf, VectorXf estadoInicial ,  int particoes, funcao *F){



#endif //INTEGRAL_H
