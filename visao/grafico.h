#ifndef GRAFICO_H
#define GRAFICO_H

#include <GL/freeglut.h>
#include <cmath>
#include <vector>
#include "../controlador/interpolacao/interpolacao.h"

#define DISTANCIA 1.0
#define QTD_DIST_UM 0.1

inline void planoCarteziano (float &esquerda, float &direita, float baixo, float cima);
inline void mostrarFuncao (expre::expre *expressao, float inter[2]);
inline void mostrarArea (std::vector <interp> &interpol);
inline void mostrarInterpolacao (std::vector <interp> &interpol, std::vector <interp> &pontosInterpol);

#include "grafico.inl"

#endif //GRAFICO_H