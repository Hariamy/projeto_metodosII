#include "interpolacao.h"

void funcaoInterpNewton (std::vector <interp> &pontosInterp, std::vector <interp> &pontosFuncao, int grau, expre::expre *funcao, float inter[2], int filosofia, int particoes) {
    float dist,//= (inter[1] - inter[0]) / 3,
	      s, s2, s3, fim = inter[1] + QTD_DIST_UM;

    pontosInterp.clear();
    pontosFuncao.clear();

    switch (grau){
    case 1:
        if(filosofia == FECHADA){
            dist = (inter[1] - inter[0]);
        }else{
            dist = (inter[1] - inter[0]) / 3;
        }
    break;
    case 2:
        if(filosofia == FECHADA){
            dist = (inter[1] - inter[0]) / 2;
        }else{
            dist = (inter[1] - inter[0]) / 4;
        }
    break;
    case 3:
        if(filosofia == FECHADA){
            dist = (inter[1] - inter[0]) / 3;
        }else{
            dist = (inter[1] - inter[0]) / 5;
        }
    break;
    case 4:
        if(filosofia == FECHADA){
            dist = (inter[1] - inter[0]) / 4;
        }else{
            dist = (inter[1] - inter[0]) / 6;
        }
    break;
    
    default:
    break;
    }

    if(filosofia == FECHADA){
        pontosInterp.push_back({inter[0], funcao->calcular(inter[0])});

        for(int i = 1; i < grau; i++){
            pontosInterp.push_back({pontosInterp[i-1].x + dist, funcao->calcular(pontosInterp[i-1].x + dist)});
        }

        pontosInterp.push_back({inter[1], funcao->calcular(inter[1])});
    }else{
        pontosInterp.push_back({inter[0] + dist, funcao->calcular(inter[0] + dist)});

        for(int i = 1; i < grau + 1; i++){
            pontosInterp.push_back({pontosInterp[i-1].x + dist, funcao->calcular(pontosInterp[i-1].x + dist)});
        }
    }

	for(float i = inter[0]; i <= fim; i += QTD_DIST_UM){
		s = (i - inter[0]) / dist;
		s2 = s * s;
		s3 = s2 * s;

		valInterpol.push_back(i);
		interpol.push_back(valPontosInterpol[0] +
		                  (s * (valPontosInterpol[1] - valPontosInterpol[0])) +
						  (((s2 - s) / 2.0) * (valPontosInterpol[2] - (2.0 * valPontosInterpol[1]) + valPontosInterpol[0])) +
						  (((s3 - (3.0 * s2) + (2.0 * s)) / 6.0) * (valPontosInterpol[3] - (3.0 * valPontosInterpol[2]) + (3.0 * valPontosInterpol[1]) - valPontosInterpol[0])));
	}
}