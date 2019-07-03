#ifndef INTEGRAL_H
#define INTEGRAL_H

#include <iostream>
#include <cmath>
#include "../../biblioteca/eigen/Eigen/Dense"
#include <vector>

using namespace Eigen;

typedef VectorXf (funcao)(VectorXf estado, double t);
typedef double (funcaoReal2D)(double x, double y);

MatrixXf preencherMatriz(double xi, int particoes, double deltaR);

void resolverSistema(MatrixXf &matriz, VectorXf &vetor);

VectorXf Contorno1D(double xi, double xf,  int particoes);

VectorXf Contorno2D(double xi, double xf, double yi, double yf, double uContorno, double coefLapl,
					funcaoReal2D coefDxDy, funcaoReal2D coefDx, funcaoReal2D coefDy, 
					funcaoReal2D coefU, funcaoReal2D F,  int nparticoesx, int nparticoesy);

#endif //PVC

