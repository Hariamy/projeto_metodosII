#ifndef GRAFICO_H
#define GRAFICO_H

#include <GL/freeglut.h>
#include <cmath>
#include <vector>
#include "../controlador/interpolacao/interpolacao.h"

#define DISTANCIA 1.0
#define QTD_DIST_UM 0.1

void planoCarteziano (double &esquerda, double &direita, double baixo, double cima);
void mostrarFuncao (expre::expre *expressao, double inter[2]);
void mostrarArea (std::vector <interp> &interpol);
void mostrarInterpolacao (std::vector <interp> &interpol, std::vector <interp> &pontosInterpol);

#endif //GRAFICO_H