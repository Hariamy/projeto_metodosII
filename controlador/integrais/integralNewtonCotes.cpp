#include "integralNewtonCotes.h"

/*! Calcula a integral por Newton Cotes
** Parâmetros: O grau do polinômio, a filosofia que pode ser ABERTA ou FECHADA, quantas divisões, intervalo e a expressão
** Retornos: O valor da integral calculada
*/
double newtonCotes(const int &grau, const int &filosofia, const int &qtdDivisoes, const double intervalo[2], expre::expre *equacao) {
    double h, resul = 0, *divisoes;
    switch (grau) {
        case 1:
            divisoes = initNcG1(filosofia, qtdDivisoes,intervalo, h);
            for(int i = 0; i < qtdDivisoes; i++){
                resul += newtonCotesG1(filosofia, divisoes[(i*2)], divisoes[(i*2)+1], h, equacao);
            }
        break;
        case 2:
            divisoes = initNcG2(filosofia, qtdDivisoes,intervalo, h);
            for(int i = 0; i < qtdDivisoes; i++){
                resul += newtonCotesG2(filosofia, divisoes[(i*2)], divisoes[(i*2)+1], h, equacao);
            }
        break;
        case 3: 
            divisoes = initNcG3(filosofia, qtdDivisoes,intervalo, h);
            for(int i = 0; i < qtdDivisoes; i++){
                resul += newtonCotesG3(filosofia, divisoes[(i*2)], divisoes[(i*2)+1], h, equacao);
            }
        break;
        case 4:
            divisoes = initNcG4(filosofia, qtdDivisoes,intervalo, h);
            for(int i = 0; i < qtdDivisoes; i++){
                resul += newtonCotesG4(filosofia, divisoes[(i*2)], divisoes[(i*2)+1], h, equacao);
            }
        break;
        default: break;
    }

    free(divisoes);
    return resul;
}
/*! Inicializa os intervalos e as distâncias para Newton Cotes de grau 1
** Parâmetros: A filosofia que pode ser ABERTA ou FECHADA, quantas divisões, o intervalo e a distância entre pontos
** Retornos: Os intervalos das divisões e atualiza a variável das distâncias
*/
double* initNcG1 (const int &filosofia, const int &qtdDivisoes, const double intervalo[2], double &h) {
    double *divisoes = (double*)malloc(sizeof(double) * qtdDivisoes * 2), aux;
    switch (filosofia){
        case ABERTA:
            h = (intervalo[1] - intervalo[0]) / (3 * qtdDivisoes);
            
            aux = intervalo[0];
            for(int i = 0; i < qtdDivisoes; i++){
                divisoes[i*2] = aux;
                aux += 3 * h;
                divisoes[(i*2)+1] = aux;
            }
        break;
        case FECHADA:
            h = (intervalo[1] - intervalo[0]) / qtdDivisoes;
            
            aux = intervalo[0];
            for(int i = 0; i < qtdDivisoes; i++){
                divisoes[i*2] = aux;
                aux += h;
                divisoes[(i*2)+1] = aux;
            }
        break;
    }
    return divisoes;
}
/*! Inicializa os intervalos e as distâncias para Newton Cotes de grau 2
** Parâmetros: A filosofia que pode ser ABERTA ou FECHADA, quantas divisões, o intervalo e a distância entre pontos
** Retornos: Os intervalos das divisões e atualiza a variável das distâncias
*/
double* initNcG2 (const int &filosofia, const int &qtdDivisoes, const double intervalo[2], double &h) {
    double *divisoes = (double*)malloc(sizeof(double) * qtdDivisoes * 2), aux;
    switch (filosofia){
        case ABERTA:
            h = (intervalo[1] - intervalo[0]) / (4 * qtdDivisoes);
            
            aux = intervalo[0];
            for(int i = 0; i < qtdDivisoes; i++){
                divisoes[i*2] = aux;
                aux += 4 * h;
                divisoes[(i*2)+1] = aux;
            }
        break;
        case FECHADA:
            h = (intervalo[1] - intervalo[0]) / (2 * qtdDivisoes);
            
            aux = intervalo[0];
            for(int i = 0; i < qtdDivisoes; i++){
                divisoes[i*2] = aux;
                aux += 2 * h;
                divisoes[(i*2)+1] = aux;
            }
        break;
    }
    return divisoes;
}
/*! Inicializa os intervalos e as distâncias para Newton Cotes de grau 3
** Parâmetros: A filosofia que pode ser ABERTA ou FECHADA, quantas divisões, o intervalo e a distância entre pontos
** Retornos: Os intervalos das divisões e atualiza a variável das distâncias
*/
double* initNcG3 (const int &filosofia, const int &qtdDivisoes, const double intervalo[2], double &h) {
    double *divisoes = (double*)malloc(sizeof(double) * qtdDivisoes * 2), aux;
    switch (filosofia){
        case ABERTA:
            h = (intervalo[1] - intervalo[0]) / (5 * qtdDivisoes);
            
            aux = intervalo[0];
            for(int i = 0; i < qtdDivisoes; i++){
                divisoes[i*2] = aux;
                aux += 5 * h;
                divisoes[(i*2)+1] = aux;
            }
        break;
        case FECHADA:
            h = (intervalo[1] - intervalo[0]) / (3 * qtdDivisoes);
            
            aux = intervalo[0];
            for(int i = 0; i < qtdDivisoes; i++){
                divisoes[i*2] = aux;
                aux += 3 * h;
                divisoes[(i*2)+1] = aux;
            }
        break;
    }
    return divisoes;
}
/*! Inicializa os intervalos e as distâncias para Newton Cotes de grau 4
** Parâmetros: A filosofia que pode ser ABERTA ou FECHADA, quantas divisões, o intervalo e a distância entre pontos
** Retornos: Os intervalos das divisões e atualiza a variável das distâncias
*/
double* initNcG4 (const int &filosofia, const int &qtdDivisoes, const double intervalo[2], double &h) {
    double *divisoes = (double*)malloc(sizeof(double) * qtdDivisoes * 2), aux;
    switch (filosofia){
        case ABERTA:
            h = (intervalo[1] - intervalo[0]) / (6 * qtdDivisoes);
            
            aux = intervalo[0];
            for(int i = 0; i < qtdDivisoes; i++){
                divisoes[i*2] = aux;
                aux += 6 * h;
                divisoes[(i*2)+1] = aux;
            }
        break;
        case FECHADA:
            h = (intervalo[1] - intervalo[0]) / (4 * qtdDivisoes);
            
            aux = intervalo[0];
            for(int i = 0; i < qtdDivisoes; i++){
                divisoes[i*2] = aux;
                aux += 4 * h;
                divisoes[(i*2)+1] = aux;
            }
        break;
    }
    
    return divisoes;
}
/*! Calcula Newton Cotes de grau 1 para o intervalo dado
** Parâmetros: A filosofia que pode ser ABERTA ou FECHADA, o inicio e o fim do intervalo, distância entre pontos e a expressão
** Retornos: O valor da integral para o intervalo dado
*/
inline double newtonCotesG1 (const int &filosofia, const double &inicio, const double &fim, const double &h, expre::expre *equacao) {
    double val1, val2, resul = 0;
    switch (filosofia){
    case ABERTA:
        val1 = inicio + h,
        val2 = val1 + h;
        resul = ((fim - inicio) / 2) * (equacao->calcular(val1) + equacao->calcular(val2));
    break;
    case FECHADA:
        resul = ((fim - inicio) / 2) * (equacao->calcular(inicio) + equacao->calcular(fim));
    break;
    }

    return resul;
}
/*! Calcula Newton Cotes de grau 2 para o intervalo dado
** Parâmetros: A filosofia que pode ser ABERTA ou FECHADA, o inicio e o fim do intervalo, distância entre pontos e a expressão
** Retornos: O valor da integral para o intervalo dado
*/
double newtonCotesG2 (const int &filosofia, const double &inicio, const double &fim, const double &h, expre::expre *equacao) {
    double val1, val2, val3, resul = 0;
    switch (filosofia){
    case ABERTA:
        val1 = inicio + h;
        val2 = val1 + h;
        val3 = val2 + h;
        resul = (((fim - inicio)) / 3) * ((2 * equacao->calcular(val1)) - equacao->calcular(val2) + (2 * equacao->calcular(val3)));
    break;
    case FECHADA:
        val1 = inicio;
        val2 = val1 + h;
        val3 = fim;
        resul = (((fim - inicio)) / 6) * (equacao->calcular(val1) + (4 * equacao->calcular(val2)) + equacao->calcular(val3));
    break;
    }

    return resul;
}
/*! Calcula Newton Cotes de grau 3 para o intervalo dado
** Parâmetros: A filosofia que pode ser ABERTA ou FECHADA, o inicio e o fim do intervalo, distância entre pontos e a expressão
** Retornos: O valor da integral para o intervalo dado
*/
double newtonCotesG3 (const int &filosofia, const double &inicio, const double &fim, const double &h, expre::expre *equacao) {
    double val1, val2, val3, val4, resul = 0;
    switch (filosofia){
    case ABERTA:
        val1 = inicio + h;
        val2 = val1 + h;
        val3 = val2 + h;
        val4 = val3 + h;
        resul = ((fim - inicio) / 24) * ((11 * equacao->calcular(val1)) + equacao->calcular(val2) + equacao->calcular(val3) + (11 * equacao->calcular(val4)));
    break;
    case FECHADA:
        val1 = inicio;
        val2 = val1 + h;
        val3 = val2 + h;
        val4 = fim;
        resul = ((fim - inicio) / 8) * (equacao->calcular(val1) + (3 * equacao->calcular(val2)) + (3 * equacao->calcular(val3)) + equacao->calcular(val4));
    break;
    }

    return resul;
}
/*! Calcula Newton Cotes de grau 4 para o intervalo dado
** Parâmetros: A filosofia que pode ser ABERTA ou FECHADA, o inicio e o fim do intervalo, distância entre pontos e a expressão
** Retornos: O valor da integral para o intervalo dado
*/
double newtonCotesG4 (const int &filosofia, const double &inicio, const double &fim, const double &h, expre::expre *equacao) {
    double val1, val2, val3, val4, val5, resul = 0;
    switch (filosofia){
    case ABERTA:
        val1 = inicio + h;
        val2 = val1 + h;
        val3 = val2 + h;
        val4 = val3 + h;
        val5 = val4 + h;
        resul = ((fim - inicio) / 70) * ((24 * equacao->calcular(val1)) + (9 * equacao->calcular(val2)) + (4 * equacao->calcular(val3)) + (9 * equacao->calcular(val4)) + (24 * equacao->calcular(val5)));
    break;
    case FECHADA:
        val1 = inicio;
        val2 = val1 + h;
        val3 = val2 + h;
        val4 = val3 + h;
        val5 = fim;
        resul = (((fim - inicio)) / 90) * ((7 * equacao->calcular(val1)) + (32 * equacao->calcular(val2)) + (12 * equacao->calcular(val3)) + (32 * equacao->calcular(val4)) + (7 * equacao->calcular(val5)));
    break;
    }

    return resul;
}