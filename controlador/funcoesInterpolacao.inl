#include "interpolacao.h"

void funcaoInterpNewton (std::vector <interp> &pontosInterp, std::vector <interp> &pontosFuncao, int grau, expre::expre *funcao, float inter[2], int filosofia, int particoes) {
    pontosInterp.clear();
    pontosFuncao.clear();

    switch (grau){
    case 1:
        interpNewtonG1(pontosInterp, pontosFuncao, funcao, inter, filosofia, particoes);
    break;
    case 2:
        interpNewtonG2(pontosInterp, pontosFuncao, funcao, inter, filosofia, particoes);
    break;
    case 3:
        interpNewtonG3(pontosInterp, pontosFuncao, funcao, inter, filosofia, particoes);
    break;
    case 4:
        interpNewtonG4(pontosInterp, pontosFuncao, funcao, inter, filosofia, particoes);
    break;
    
    default:
    break;
    }
}

void interpNewtonG1 (std::vector <interp> &pontosInterp, std::vector <interp> &pontosFuncao, expre::expre *funcao, float inter[2], int filosofia, int particoes) {
    float pos, s, dist;
    int qtdPontos, divisaoVetor, i, j;

    pontosFuncao.resize((inter[1] - inter[0]) / (QTD_DIST_UM * particoes));
    divisaoVetor = pontosFuncao.size() / particoes;

    qtdPontos = pontosInterp.size();

    if(filosofia == FECHADA){
        pontosInterp.resize((2*particoes) - (particoes-1));
        dist = (inter[1] - inter[0]) / particoes;
        
        pontosInterp[0].x = inter[0];
    }else{
        pontosInterp.resize(2*particoes);
        dist = (inter[1] - inter[0]) / (3.0 * particoes);

        pontosInterp[0].x = inter[0] + dist;
    }

    pontosInterp[0].y = funcao->calcular(pontosInterp[0].x);
    for(i = 1; i < qtdPontos; i++){
        pontosInterp[i].x = pontosInterp[i].x + dist;
        pontosInterp[i].y = funcao->calcular(pontosInterp[i].x);
    }

    i = 0;
    j = 0;
    
    for(pos = inter[0]; pos <= inter[1]; pos += QTD_DIST_UM){
        s = (pos - inter[0]) / dist;

        pontosFuncao[i].x = pos;
        pontosFuncao[i].y = pontosInterp[j].y + s * (pontosInterp[j+1].y - pontosInterp[j].y);

        i++;
        if(i%divisaoVetor == 0){
            j++;
        }
    }
}

void interpNewtonG2 (std::vector <interp> &pontosInterp, std::vector <interp> &pontosFuncao, expre::expre *funcao, float inter[2], int filosofia, int particoes) {
    float pos, s, s2, dist;
    int qtdPontos, i, j;

    pontosFuncao.resize((inter[1] - inter[0]) / QTD_DIST_UM);

    qtdPontos = pontosInterp.size();

    if(filosofia == FECHADA){
            pontosInterp.resize((3*particoes) - (particoes-1));
        dist = (inter[1] - inter[0]) / (2.0 * particoes);

        pontosInterp[0].x = inter[0];
    }else{
            pontosInterp.resize(3*particoes);
        dist = (inter[1] - inter[0]) / (4.0 * particoes);

        pontosInterp[0].x = inter[0] + dist;
    }

    pontosInterp[0].y = funcao->calcular(pontosInterp[0].x);
    for(i = 1; i < qtdPontos; i++){
        pontosInterp[i].x = pontosInterp[i].x + dist;
        pontosInterp[i].y = funcao->calcular(pontosInterp[i].x);
    }

    i = 0;
    j = 0;

    for(pos = inter[0]; pos <= inter[1]; pos += QTD_DIST_UM){
        s = (pos - inter[0]) / dist;
        s2 = s * s;

        pontosFuncao[i].x = pos;
        pontosFuncao[i].y = pontosInterp[j].y + s * (pontosInterp[j+1].y - pontosInterp[j].y)
              + (1.0/2.0)*(s2 - s)*(pontosInterp[j+2].y - 2.0*pontosInterp[j+1].y + pontosInterp[j].y);

        i++;

        if(i % 3 == 0){
            j += 3;
        }           
    }
}

void interpNewtonG3 (std::vector <interp> &pontosInterp, std::vector <interp> &pontosFuncao, expre::expre *funcao, float inter[2], int filosofia, int particoes) {
    float pos, s, s2, s3, dist;
    int qtdPontos, i, j;

    pontosFuncao.resize((inter[1] - inter[0]) / QTD_DIST_UM);

    qtdPontos = pontosInterp.size();

    if(filosofia == FECHADA){
        pontosInterp.resize((4*particoes) - (particoes-1));
        dist = (inter[1] - inter[0]) / (3.0 * particoes);

        pontosInterp[0].x = inter[0];
    }else{
        pontosInterp.resize(4*particoes);
        dist = (inter[1] - inter[0]) / (5.0 * particoes);

        pontosInterp[0].x = inter[0] + dist;
    }

    pontosInterp[0].y = funcao->calcular(pontosInterp[0].x);
    for(i = 1; i < qtdPontos; i++){
        pontosInterp[i].x = pontosInterp[i].x + dist;
        pontosInterp[i].y = funcao->calcular(pontosInterp[i].x);
    }

    i = 0;
    j = 0;

    for(pos = inter[0]; pos <= inter[1]; pos += QTD_DIST_UM){
        s = (pos - inter[0]) / dist;
        s2 = s * s;
        s3 = s2 * s;

        pontosFuncao[i].x = pos;
        pontosFuncao[i].y = pontosInterp[j].y + s * (pontosInterp[j+1].y - pontosInterp[j].y)
              + (1/2.0)*(s2 - s)*(pontosInterp[j+2].y - 2.0*pontosInterp[j+1].y + pontosInterp[j].y)
              + (1/6.0)*(s3 - 3.0*s2 + 2.0*s)*(pontosInterp[j+3].y - 3.0*pontosInterp[j+2].y + 3.0*pontosInterp[j+1].y - pontosInterp[j].y);            

        i++;

        if(i % 4 == 0){
            j += 4;
        }     
    }
}

void interpNewtonG4 (std::vector <interp> &pontosInterp, std::vector <interp> &pontosFuncao, expre::expre *funcao, float inter[2], int filosofia, int particoes) {
    float pos, s, s2, s3, s4, dist;
    int qtdPontos, i, j;

    pontosFuncao.resize((inter[1] - inter[0]) / QTD_DIST_UM);

    qtdPontos = pontosInterp.size();

    if(filosofia == FECHADA){
        pontosInterp.resize((5*particoes) - (particoes-1));
        dist = (inter[1] - inter[0]) / (4.0 * particoes);

        pontosInterp[0].x = inter[0];
    }else{
        pontosInterp.resize(5*particoes);
        dist = (inter[1] - inter[0]) / (6.0 * particoes);

        pontosInterp[0].x = inter[0] + dist;
    }

    pontosInterp[0].y = funcao->calcular(pontosInterp[0].x);
    for(i = 1; i < qtdPontos; i++){
        pontosInterp[i].x = pontosInterp[i].x + dist;
        pontosInterp[i].y = funcao->calcular(pontosInterp[i].x);
    }

    i = 0;
    j = 0;

    for(pos = inter[0]; pos <= inter[1]; pos += QTD_DIST_UM){
        s = (pos - inter[0]) / dist;
        s2 = s * s;
        s3 = s2 * s;
        s4 = s3 * s;

        pontosFuncao[i].x = pos;
        pontosFuncao[i].y = pontosInterp[j].y + s * (pontosInterp[j+1].y - pontosInterp[j].y)
              + (1.0/2.0)*(s2 - s)*(pontosInterp[j+2].y - 2.0*pontosInterp[j+1].y + pontosInterp[j].y)
              + (1.0/6.0)*(s3 - 3.0*s2 + 2.0*s)*(pontosInterp[j+3].y - 3.0*pontosInterp[j+2].y + 3.0*pontosInterp[j+1].y - pontosInterp[j].y);
              + (1.0/24.0)*(s4 - 6.0*s3 + 11.0*s2 - 6.0*s)*(pontosInterp[j+4].y - 4.0*pontosInterp[j+3].y + 6.0*pontosInterp[j+2].y - 4.0*pontosInterp[j+1].y + pontosInterp[j].y);

        i++;

        if(i % 5 == 0){
            j += 5;
        } 
    }
}