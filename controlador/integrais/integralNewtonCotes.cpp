#include "integrais.h"

double w[48] = {1.0, 1.0, 0.0, 0.0, 0.0, 1.0/2.0,      //Grau 1 Fechada
                1.0, 4.0, 1.0, 0.0, 0.0, 1.0/6.0,      //Grau 2 Fechada
                1.0, 3.0, 3.0, 1.0, 0.0, 1.0/8.0,      //Grau 3 Fechada
                7.0, 32.0, 12.0, 32.0, 7.0, 1.0/90.0,  //Grau 4 Fechada
                1.0, 1.0, 0.0, 0.0, 0.0, 1.0/2.0,      //Grau 1 Aberta
                2.0, 1.0, 2.0, 0.0, 0.0, 1.0/3.0,      //Grau 2 Aberta
                11.0, 1.0, 1.0, 11.0, 0.0, 1.0/24.0,   //Grau 3 Aberta
                24.0, 9.0, 4.0, 9.0, 24.0, 1.0/70.0};  //Grau 4 Aberta

#define QTD_W    6.0
#define QTD_GRAU 4.0
#define POS_DIV  5.0

/*! Calcula a integral por Newton Cotes
** Parâmetros: O grau do polinômio, a filosofia que pode ser ABERTA ou FECHADA, quantas divisões, intervalo e a expressão
** Retornos: O valor da integral calculada
*/
double newtonCotes(const int &grau, const int &filosofia, const int &qtdDivisoes, const double intervalo[2], expre::expre *equacao) {
    double xi = intervalo[0],
           resul = 0,
           resulPart = 0,
           deltaX = (intervalo[1] - intervalo[0]) / (double)((qtdDivisoes * grau) + (filosofia * 2)),
           tamPart = (intervalo[1] - intervalo[0]) / (double)qtdDivisoes,
           linha = QTD_W *((filosofia * QTD_GRAU) + (grau - 1));

    for(int i = 0; i < qtdDivisoes; i++){
        resulPart = 0;

        if(filosofia == ABERTA){
            xi += deltaX;
        }

        for(int j = 0; j <= grau; j++){
            resulPart += w[(int)(j + linha)] * equacao->calcular(xi);

            xi += deltaX;
        }
        
        resul += (tamPart) * w[(int)(linha + POS_DIV)] * resulPart;

        if(filosofia == FECHADA){
            xi -= deltaX;
        }
    }
    
    return resul;
}

double newtonCotesErro(const int &grau, const int &filosofia, const double erro, const double intervalo[2], expre::expre *equacao) {

    int MAX_PART = 10000000000;
    int particoes = 1;
    double anterior = 0;
    double proximo = INFINITY;
    do{
        anterior = proximo;
        proximo = newtonCotes(grau, filosofia, particoes, intervalo, equacao);
        particoes = particoes*2;

    } while(fabs((proximo - anterior) / anterior) > erro and MAX_PART > particoes);

    return proximo;
}

