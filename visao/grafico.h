#ifndef GRAFICO_H
#define GRAFICO_H

#include <GL/freeglut.h>
#include <cmath>
#include <vector>

#define DISTANCIA 1.0
#define QTD_DIST_UM 0.1

inline void planoCarteziano (float &esquerda, float &direita, float baixo, float cima);
inline void mostrarFuncao (float inter[2]);
inline void mostrarArea (std::vector <float> &valInterpol, std::vector <float> &interpol);
inline void mostrarInterpolacao (std::vector <float> &valInterpol, std::vector <float> &interpol, std::vector <float> &pontosInterpol, std::vector <float> &valPontosInterpol);

#include "grafico.inl"

#endif //GRAFICO_H