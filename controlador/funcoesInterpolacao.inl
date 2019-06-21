#include "interpolacao.h"

void funcaoInterpNewton (std::vector <interp> &pontosInterp, std::vector <interp> &pontosFuncao, int grau, expre::expre *funcao, float inter[2], int filosofia, int particoes) {
    pontosInterp.clear();
    pontosFuncao.clear();

    switch (grau){
    case 1:
        if(filosofia == FECHADA){
            interpNewtonG1Fechada(pontosInterp, pontosFuncao, funcao, inter, particoes);
        }else{
            interpNewtonG1Aberta(pontosInterp, pontosFuncao, funcao, inter, particoes);
        }
    break;
    case 2:
        if(filosofia == FECHADA){
            interpNewtonG2Fechada(pontosInterp, pontosFuncao, funcao, inter, particoes);
        }else{
            interpNewtonG2Aberta(pontosInterp, pontosFuncao, funcao, inter, particoes);
        }
    break;
    case 3:
        if(filosofia == FECHADA){
            interpNewtonG3Fechada(pontosInterp, pontosFuncao, funcao, inter, particoes);
        }else{
            interpNewtonG3Aberta(pontosInterp, pontosFuncao, funcao, inter, particoes);
        }
    break;
    case 4:
        if(filosofia == FECHADA){
            interpNewtonG4Fechada(pontosInterp, pontosFuncao, funcao, inter, particoes);
        }else{
            interpNewtonG4Aberta(pontosInterp, pontosFuncao, funcao, inter, particoes);
        }
    break;
    
    default:
    break;
    }
}

void interpNewtonG1Fechada (std::vector <interp> &pontosInterp, std::vector <interp> &pontosFuncao, expre::expre *funcao, float inter[2], int particoes) {
    float pos, s, dist, passo = QTD_DIST_UM / particoes, fim = inter[1] + QTD_DIST_UM;
    int qtdPontos, tamParticoes, i, j, k;

    tamParticoes = ((fim - inter[0]) / QTD_DIST_UM);
    pontosFuncao.resize(tamParticoes * particoes);

    pontosInterp.resize((2*particoes) - (particoes-1));
    dist = (inter[1] - inter[0]) / particoes;
        
    pontosInterp[0].x = inter[0];
    pontosInterp[0].y = funcao->calcular(pontosInterp[0].x);

    qtdPontos = pontosInterp.size();

    for(i = 1; i < qtdPontos; i++){
        pontosInterp[i].x = pontosInterp[i-1].x + dist;
        pontosInterp[i].y = funcao->calcular(pontosInterp[i].x);
    }

    i = 0;
    j = 0;
    k = 0;
        
    for(pos = inter[0]; pos <= fim; pos += passo){
        s = (pos - pontosInterp[j].x) / dist;

        pontosFuncao[i].x = pos;
        pontosFuncao[i].y = pontosInterp[j].y + s * (pontosInterp[j+1].y - pontosInterp[j].y);

        i++;
        k++;

        if(k >= tamParticoes){
            j++;
            k = 0;
        }
    }
}

void interpNewtonG1Aberta (std::vector <interp> &pontosInterp, std::vector <interp> &pontosFuncao, expre::expre *funcao, float inter[2], int particoes) {
    float pos, s, dist, passo = QTD_DIST_UM / particoes, fim = inter[1] + QTD_DIST_UM;
    int qtdPontos, tamParticoes, i, j, k;

    tamParticoes = ((fim - inter[0]) / QTD_DIST_UM);
    pontosFuncao.resize(tamParticoes * particoes);

    pontosInterp.resize(2*particoes);
    dist = (inter[1] - inter[0]) / (3.0 * particoes);

    pontosInterp[0].x = inter[0] + dist;
    pontosInterp[0].y = funcao->calcular(pontosInterp[0].x);

    qtdPontos = pontosInterp.size();

    j = 0;
    for(i = 1; i < qtdPontos; i++){
        if(j < 1){
            pontosInterp[i].x = pontosInterp[i-1].x + dist;
            j++;
        }else{
            pontosInterp[i].x = pontosInterp[i-1].x + (dist * 2);
            j = 0;
        }
        pontosInterp[i].y = funcao->calcular(pontosInterp[i].x);
    }

    i = 0;
    j = 0;
    k = 0;
        
    for(pos = inter[0]; pos <= fim; pos += passo){
        s = (pos - pontosInterp[j].x) / dist;

        pontosFuncao[i].x = pos;
        pontosFuncao[i].y = pontosInterp[j].y + s * (pontosInterp[j+1].y - pontosInterp[j].y);
        
        i++;
        k++;

        if(k >= tamParticoes){
            j += 2;
            k = 0;
        }
    }
}

void interpNewtonG2Fechada (std::vector <interp> &pontosInterp, std::vector <interp> &pontosFuncao, expre::expre *funcao, float inter[2], int particoes) {
    float pos, s, s2, dist, passo = QTD_DIST_UM / particoes, fim = inter[1] + QTD_DIST_UM;
    int qtdPontos, tamParticoes, i, j, k;

    tamParticoes = ((fim - inter[0]) / QTD_DIST_UM);
    pontosFuncao.resize(tamParticoes * particoes);

    pontosInterp.resize((3*particoes) - (particoes-1));
    dist = (inter[1] - inter[0]) / (2.0 * particoes);

    qtdPontos = pontosInterp.size();

    pontosInterp[0].x = inter[0];
    pontosInterp[0].y = funcao->calcular(pontosInterp[0].x);

    for(i = 1; i < qtdPontos; i++){
        pontosInterp[i].x = pontosInterp[i-1].x + dist;
        pontosInterp[i].y = funcao->calcular(pontosInterp[i].x);
    }

    i = 0;
    j = 0;
    k = 0;

    for(pos = inter[0]; pos <= fim; pos += passo){
        s = (pos - pontosInterp[j].x) / dist;
        s2 = s * s;

        pontosFuncao[i].x = pos;
        pontosFuncao[i].y = pontosInterp[j].y + s * (pontosInterp[j+1].y - pontosInterp[j].y)
              + (1.0/2.0)*(s2 - s)*(pontosInterp[j+2].y - 2.0*pontosInterp[j+1].y + pontosInterp[j].y);
        
        i++;
        k++;

        if(k >= tamParticoes){
            j += 2;
            k = 0;
        }           
    }
}

void interpNewtonG2Aberta (std::vector <interp> &pontosInterp, std::vector <interp> &pontosFuncao, expre::expre *funcao, float inter[2], int particoes) {
    float pos, s, s2, dist, passo = QTD_DIST_UM / particoes, fim = inter[1] + QTD_DIST_UM;
    int qtdPontos, tamParticoes, i, j, k;

    tamParticoes = ((fim - inter[0]) / QTD_DIST_UM);
    pontosFuncao.resize(tamParticoes * particoes);

    pontosInterp.resize(3*particoes);
    dist = (inter[1] - inter[0]) / (4.0 * particoes);

    qtdPontos = pontosInterp.size();

    pontosInterp[0].x = inter[0] + dist;
    pontosInterp[0].y = funcao->calcular(pontosInterp[0].x);
    
    j = 0;
    for(i = 1; i < qtdPontos; i++){
        if(j < 2){
            pontosInterp[i].x = pontosInterp[i-1].x + dist;
            j++;
        }else{
            pontosInterp[i].x = pontosInterp[i-1].x + (dist * 2);
            j = 0;
        }
        
        pontosInterp[i].y = funcao->calcular(pontosInterp[i].x);
    }

    i = 0;
    j = 0;
    k = 0;

    for(pos = inter[0]; pos <= fim; pos += passo){
        s = (pos - pontosInterp[j].x) / dist;
        s2 = s * s;

        pontosFuncao[i].x = pos;
        pontosFuncao[i].y = pontosInterp[j].y + s * (pontosInterp[j+1].y - pontosInterp[j].y)
              + (1.0/2.0)*(s2 - s)*(pontosInterp[j+2].y - 2.0*pontosInterp[j+1].y + pontosInterp[j].y);
        
        i++;
        k++;

        if(k >= tamParticoes){
            j += 3;
            k = 0;
        }
    }
}

void interpNewtonG3Fechada (std::vector <interp> &pontosInterp, std::vector <interp> &pontosFuncao, expre::expre *funcao, float inter[2], int particoes) {
    float pos, s, s2, s3, dist, passo = QTD_DIST_UM / particoes, fim = inter[1] + QTD_DIST_UM;
    int qtdPontos, tamParticoes, i, j, k;

    tamParticoes = ((fim - inter[0]) / QTD_DIST_UM);
    pontosFuncao.resize(tamParticoes * particoes);

    pontosInterp.resize((4*particoes) - (particoes-1));
    dist = (inter[1] - inter[0]) / (3.0 * particoes);
        
    qtdPontos = pontosInterp.size();

    pontosInterp[0].x = inter[0];
    pontosInterp[0].y = funcao->calcular(pontosInterp[0].x);

    for(i = 1; i < qtdPontos; i++){
        pontosInterp[i].x = pontosInterp[i-1].x + dist;
        pontosInterp[i].y = funcao->calcular(pontosInterp[i].x);
    }

    i = 0;
    j = 0;
    k = 0;

    for(pos = inter[0]; pos <= fim; pos += passo){
        s = (pos - pontosInterp[j].x) / dist;
        s2 = s * s;
        s3 = s2 * s;

        pontosFuncao[i].x = pos;
        pontosFuncao[i].y = pontosInterp[j].y + s * (pontosInterp[j+1].y - pontosInterp[j].y)
              + (1/2.0)*(s2 - s)*(pontosInterp[j+2].y - 2.0*pontosInterp[j+1].y + pontosInterp[j].y)
              + (1/6.0)*(s3 - 3.0*s2 + 2.0*s)*(pontosInterp[j+3].y - 3.0*pontosInterp[j+2].y + 3.0*pontosInterp[j+1].y - pontosInterp[j].y);            

        i++;
        k++;

        if(k >= tamParticoes){
            j += 3;
            k = 0;
        }
    }
}

void interpNewtonG3Aberta (std::vector <interp> &pontosInterp, std::vector <interp> &pontosFuncao, expre::expre *funcao, float inter[2], int particoes) {
    float pos, s, s2, s3, dist, passo = QTD_DIST_UM / particoes, fim = inter[1] + QTD_DIST_UM;
    int qtdPontos, tamParticoes, i, j, k;

    tamParticoes = ((fim - inter[0]) / QTD_DIST_UM);
    pontosFuncao.resize(tamParticoes * particoes);

    pontosInterp.resize(4*particoes);
    dist = (inter[1] - inter[0]) / (5.0 * particoes);

    qtdPontos = pontosInterp.size();

    pontosInterp[0].x = inter[0] + dist;
    pontosInterp[0].y = funcao->calcular(pontosInterp[0].x);

    j = 0;
    for(i = 1; i < qtdPontos; i++){
        if(j < 3){
            pontosInterp[i].x = pontosInterp[i-1].x + dist;
            j++;
        }else{
            pontosInterp[i].x = pontosInterp[i-1].x + (dist * 2);
            j = 0;
        }

        pontosInterp[i].y = funcao->calcular(pontosInterp[i].x);
    }

    i = 0;
    j = 0;
    k = 0;

    for(pos = inter[0]; pos <= fim; pos += passo){
        s = (pos - pontosInterp[j].x) / dist;
        s2 = s * s;
        s3 = s2 * s;

        pontosFuncao[i].x = pos;
        pontosFuncao[i].y = pontosInterp[j].y + s * (pontosInterp[j+1].y - pontosInterp[j].y)
              + (1/2.0)*(s2 - s)*(pontosInterp[j+2].y - 2.0*pontosInterp[j+1].y + pontosInterp[j].y)
              + (1/6.0)*(s3 - 3.0*s2 + 2.0*s)*(pontosInterp[j+3].y - 3.0*pontosInterp[j+2].y + 3.0*pontosInterp[j+1].y - pontosInterp[j].y);            

        i++;
        k++;

        if(k >= tamParticoes){
            j += 4;
            k = 0;
        }
    }
}

void interpNewtonG4Fechada (std::vector <interp> &pontosInterp, std::vector <interp> &pontosFuncao, expre::expre *funcao, float inter[2], int particoes) {
    float pos, s, s2, s3, s4, dist, passo = QTD_DIST_UM / particoes, fim = inter[1] + QTD_DIST_UM;
    int qtdPontos, tamParticoes, i, j, k;

    tamParticoes = ((fim - inter[0]) / QTD_DIST_UM);
    pontosFuncao.resize(tamParticoes * particoes);

    pontosInterp.resize((5*particoes) - (particoes-1));
    dist = (inter[1] - inter[0]) / (4.0 * particoes);

    qtdPontos = pontosInterp.size();

    pontosInterp[0].x = inter[0];
    pontosInterp[0].y = funcao->calcular(pontosInterp[0].x);

    for(i = 1; i < qtdPontos; i++){
        pontosInterp[i].x = pontosInterp[i-1].x + dist;
        pontosInterp[i].y = funcao->calcular(pontosInterp[i].x);
    }

    i = 0;
    j = 0;
    k = 0;

    for(pos = inter[0]; pos <= fim; pos += passo){
        s = (pos - pontosInterp[j].x) / dist;
        s2 = s * s;
        s3 = s2 * s;
        s4 = s3 * s;

        pontosFuncao[i].x = pos;
        pontosFuncao[i].y = pontosInterp[j].y + s * (pontosInterp[j+1].y - pontosInterp[j].y)
              + (1.0/2.0)*(s2 - s)*(pontosInterp[j+2].y - 2.0*pontosInterp[j+1].y + pontosInterp[j].y)
              + (1.0/6.0)*(s3 - 3.0*s2 + 2.0*s)*(pontosInterp[j+3].y - 3.0*pontosInterp[j+2].y + 3.0*pontosInterp[j+1].y - pontosInterp[j].y)
              + (1.0/24.0)*(s4 - 6.0*s3 + 11.0*s2 - 6.0*s)*(pontosInterp[j+4].y - 4.0*pontosInterp[j+3].y + 6.0*pontosInterp[j+2].y - 4.0*pontosInterp[j+1].y + pontosInterp[j].y);

        i++;
        k++;

        if(k >= tamParticoes){
            j += 4;
            k = 0;
        }
    }
}

void interpNewtonG4Aberta (std::vector <interp> &pontosInterp, std::vector <interp> &pontosFuncao, expre::expre *funcao, float inter[2], int particoes) {
    float pos, s, s2, s3, s4, dist, passo = QTD_DIST_UM / particoes, fim = inter[1] + QTD_DIST_UM;
    int qtdPontos, tamParticoes, i, j, k;

    tamParticoes = ((fim - inter[0]) / QTD_DIST_UM);
    pontosFuncao.resize(tamParticoes * particoes);

    pontosInterp.resize(5*particoes);
    dist = (inter[1] - inter[0]) / (6.0 * particoes);

    qtdPontos = pontosInterp.size();

    pontosInterp[0].x = inter[0] + dist;
    pontosInterp[0].y = funcao->calcular(pontosInterp[0].x);

    j = 0;
    for(i = 1; i < qtdPontos; i++){
        if(j < 4){
            pontosInterp[i].x = pontosInterp[i-1].x + dist;
            j++;
        }else{
            pontosInterp[i].x = pontosInterp[i-1].x + (dist * 2);
            j = 0;
        }

        pontosInterp[i].y = funcao->calcular(pontosInterp[i].x);
    }

    i = 0;
    j = 0;
    k = 0;

    for(pos = inter[0]; pos <= fim; pos += passo){
        s = (pos - pontosInterp[j].x) / dist;
        s2 = s * s;
        s3 = s2 * s;
        s4 = s3 * s;

        pontosFuncao[i].x = pos;
        pontosFuncao[i].y = pontosInterp[j].y + s * (pontosInterp[j+1].y - pontosInterp[j].y)
              + (1.0/2.0)*(s2 - s)*(pontosInterp[j+2].y - 2.0*pontosInterp[j+1].y + pontosInterp[j].y)
              + (1.0/6.0)*(s3 - 3.0*s2 + 2.0*s)*(pontosInterp[j+3].y - 3.0*pontosInterp[j+2].y + 3.0*pontosInterp[j+1].y - pontosInterp[j].y)
              + (1.0/24.0)*(s4 - 6.0*s3 + 11.0*s2 - 6.0*s)*(pontosInterp[j+4].y - 4.0*pontosInterp[j+3].y + 6.0*pontosInterp[j+2].y - 4.0*pontosInterp[j+1].y + pontosInterp[j].y);

        i++;
        k++;

        if(k >= tamParticoes){
            j += 5;
            k = 0;
        } 
    }
}