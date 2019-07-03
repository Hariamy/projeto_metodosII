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

VectorXf EulerIpct(double xi, double xf, VectorXf estadoInicial ,  int particoes, funcao *F);

VectorXd EulerMod(double xi, double xf, VectorXf estadoInicial ,  int particoes, funcao *F); // euler modificado y1 = y0 + h f(   x + 0.5 h  ,   y0 + 0.5 h f(x0, y0)  )

VectorXd EulerApr(double xi, double xf, VectorXf estadoInicial ,  int particoes, funcao *F); // euler aprimorado y1 = y0 + 0.5 h[ f(x , y0) + f(   x+h  ,   y0 + h f(x0, y0)  ) ]



#endif //VALOR_INICIAL_H
