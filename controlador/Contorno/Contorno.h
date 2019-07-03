#ifndef INTEGRAL_H
#define INTEGRAL_H

#include <iostream>
#include <cmath>
#include "../../biblioteca/eigen/Eigen/Dense"
#include <vector>

using namespace Eigen;

typedef VectorXf (funcao)(VectorXf estado, double t);

VectorXf Contorno1D(double xi, double xf,  int particoes, double A, double B, double C, double D, double E, double F);

MatrixXf preencherMatriz(double xi, int particoes, double deltaR);

void resolverSistema(MatrixXf &matriz, VectorXf &vetor);

#endif //PVC

