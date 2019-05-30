#ifndef INTERPOLACAO_H
#define INTERPOLACAO_H

#include <vector>
#include "parser/expre.h"

#define QTD_DIST_UM 0.1
#define FECHADA     0
#define ABERTA      1

struct interp {
    float x, y;
};

inline void funcaoInterpNewton (std::vector <interp> &pontosInterp, std::vector <interp> &pontosFuncao, int grau, expre::expre *funcao, float inter[2], int filosofia, int particoes);
inline void interpNewtonG1Fechada (std::vector <interp> &pontosInterp, std::vector <interp> &pontosFuncao, expre::expre *funcao, float inter[2], int particoes);
inline void interpNewtonG1Aberta (std::vector <interp> &pontosInterp, std::vector <interp> &pontosFuncao, expre::expre *funcao, float inter[2], int particoes);
inline void interpNewtonG2Fechada (std::vector <interp> &pontosInterp, std::vector <interp> &pontosFuncao, expre::expre *funcao, float inter[2], int particoes);
inline void interpNewtonG2Aberta (std::vector <interp> &pontosInterp, std::vector <interp> &pontosFuncao, expre::expre *funcao, float inter[2], int particoes);
inline void interpNewtonG3Fechada (std::vector <interp> &pontosInterp, std::vector <interp> &pontosFuncao, expre::expre *funcao, float inter[2], int particoes);
inline void interpNewtonG3Aberta (std::vector <interp> &pontosInterp, std::vector <interp> &pontosFuncao, expre::expre *funcao, float inter[2], int particoes);
inline void interpNewtonG4Fechada (std::vector <interp> &pontosInterp, std::vector <interp> &pontosFuncao, expre::expre *funcao, float inter[2], int particoes);
inline void interpNewtonG4Aberta (std::vector <interp> &pontosInterp, std::vector <interp> &pontosFuncao, expre::expre *funcao, float inter[2], int particoes);

#include "funcoesInterpolacao.inl"

#endif //INTERPOLACAO_H