#ifndef INTEGRAL_H
#define INTEGRAL_H

#include <iostream>
#include <cmath>

namespace inte {

    #define FORWARD  0
    #define BACKWARD 1
    #define CENTRAL  2

    #define FECHADA  0
    #define ABERTA   1

    inline float newtonCotes(const int &grau, const int &filosofia, const int &qtdDivisoes, const float intervalo[2]);//, expre &equacao);

    inline float* initNcG1 (const int &filosofia, const int &qtdDivisoes, const float intervalo[2], float &h);
    inline float* initNcG2 (const int &filosofia, const int &qtdDivisoes, const float intervalo[2], float &h);
    inline float* initNcG3 (const int &filosofia, const int &qtdDivisoes, const float intervalo[2], float &h);
    inline float* initNcG4 (const int &filosofia, const int &qtdDivisoes, const float intervalo[2], float &h);

    inline float newtonCotesG1(const int &filosofia, const float &inicio, const float &fim, const float &h);//, expre &equacao);
    inline float newtonCotesG2(const int &filosofia, const float &inicio, const float &fim, const float &h);//, expre &equacao);
    inline float newtonCotesG3(const int &filosofia, const float &inicio, const float &fim, const float &h);//, expre &equacao);
    inline float newtonCotesG4(const int &filosofia, const float &inicio, const float &fim, const float &h);//, expre &equacao);

/**************************************************************************************************************************
--------------------------------------------------------- Funções ---------------------------------------------------------
**************************************************************************************************************************/

    
    /*! Calcula A integral por Newton Cotes
    ** Parâmetros: O grau do polinômio, a filosofia que pode ser ABERTA ou FECHADA, quantas divisões e o intervalo
    ** Retornos: O valor da integral calculada
    */
    float newtonCotes(const int &grau, const int &filosofia, const int &qtdDivisoes, const float intervalo[2]) {
        float h, resul = 0, *divisoes;

        switch (grau) {
            case 1:
                divisoes = initNcG1(filosofia, qtdDivisoes,intervalo, h);

                for(int i = 0; i < qtdDivisoes; i++){
                    resul += newtonCotesG1(filosofia, divisoes[(i*2)], divisoes[(i*2)+1], h);
                }
            break;
            case 2:
                divisoes = initNcG2(filosofia, qtdDivisoes,intervalo, h);

                for(int i = 0; i < qtdDivisoes; i++){
                    resul += newtonCotesG2(filosofia, divisoes[(i*2)], divisoes[(i*2)+1], h);
                }
            break;
            case 3: 
                divisoes = initNcG3(filosofia, qtdDivisoes,intervalo, h);

                for(int i = 0; i < qtdDivisoes; i++){
                    resul += newtonCotesG3(filosofia, divisoes[(i*2)], divisoes[(i*2)+1], h);
                }
            break;
            case 4:
                divisoes = initNcG4(filosofia, qtdDivisoes,intervalo, h);

                for(int i = 0; i < qtdDivisoes; i++){
                    resul += newtonCotesG4(filosofia, divisoes[(i*2)], divisoes[(i*2)+1], h);
                }
            break;
            default: break;
        }

        return resul;
    }

    /*! Inicializa os intervalos e as distâncias para Newton Cotes de grau 1
    ** Parâmetros: A filosofia que pode ser ABERTA ou FECHADA, quantas divisões, o intervalo e a distância entre pontos
    ** Retornos: Os intervalos das divisões e atualiza a variável das distâncias
    */
    float* initNcG1 (const int &filosofia, const int &qtdDivisoes, const float intervalo[2], float &h) {
        float *divisoes = (float*)malloc(sizeof(float) * qtdDivisoes * 2), aux;

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
    float* initNcG2 (const int &filosofia, const int &qtdDivisoes, const float intervalo[2], float &h) {
        float *divisoes = (float*)malloc(sizeof(float) * qtdDivisoes * 2), aux;

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
    float* initNcG3 (const int &filosofia, const int &qtdDivisoes, const float intervalo[2], float &h) {
        float *divisoes = (float*)malloc(sizeof(float) * qtdDivisoes * 2), aux;

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
    float* initNcG4 (const int &filosofia, const int &qtdDivisoes, const float intervalo[2], float &h) {
        float *divisoes = (float*)malloc(sizeof(float) * qtdDivisoes * 2), aux;

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
    ** Parâmetros: A filosofia que pode ser ABERTA ou FECHADA, o inicio e o fim do intervalo e a distância entre pontos
    ** Retornos: O valor da integral para o intervalo dado
    */
    inline float newtonCotesG1(const int &filosofia, const float &inicio, const float &fim, const float &h) {
        float val1, val2;

        switch (filosofia){
        case ABERTA:
            val1 = inicio + h,
            val2 = val1 + h;

            return ((fim - inicio) / 2) * (sin(val1) + sin(val2));
        break;
        case FECHADA:

            return ((fim - inicio) / 2) * (sin(inicio) + sin(fim));
        break;
        }
    }

    /*! Calcula Newton Cotes de grau 2 para o intervalo dado
    ** Parâmetros: A filosofia que pode ser ABERTA ou FECHADA, o inicio e o fim do intervalo e a distância entre pontos
    ** Retornos: O valor da integral para o intervalo dado
    */
    float newtonCotesG2(const int &filosofia, const float &inicio, const float &fim, const float &h) {
        float val1, val2, val3;

        switch (filosofia){
        case ABERTA:
            val1 = inicio + h;
            val2 = val1 + h;
            val3 = val2 + h;

            return (((fim - inicio)) / 3) * ((2 * sin(val1)) - sin(val2) + (2 * sin(val3)));
        break;
        case FECHADA:
            val1 = inicio;
            val2 = val1 + h;
            val3 = fim;

            return (((fim - inicio)) / 6) * (sin(val1) + (4 * sin(val2)) + sin(val3));
        break;
        }
    }

    /*! Calcula Newton Cotes de grau 3 para o intervalo dado
    ** Parâmetros: A filosofia que pode ser ABERTA ou FECHADA, o inicio e o fim do intervalo e a distância entre pontos
    ** Retornos: O valor da integral para o intervalo dado
    */
    float newtonCotesG3(const int &filosofia, const float &inicio, const float &fim, const float &h) {
        float val1, val2, val3, val4;

        switch (filosofia){
        case ABERTA:
            val1 = inicio + h;
            val2 = val1 + h;
            val3 = val2 + h;
            val4 = val3 + h;

            return ((fim - inicio) / 24) * ((11 * sin(val1)) + sin(val2) + sin(val3) + (11 * sin(val4)));
        break;
        case FECHADA:
            val1 = inicio;
            val2 = val1 + h;
            val3 = val2 + h;
            val4 = fim;

            return ((fim - inicio) / 8) * (sin(val1) + (3 * sin(val2)) + (3 * sin(val3)) + sin(val4));
        break;
        }
    }

    /*! Calcula Newton Cotes de grau 4 para o intervalo dado
    ** Parâmetros: A filosofia que pode ser ABERTA ou FECHADA, o inicio e o fim do intervalo e a distância entre pontos
    ** Retornos: O valor da integral para o intervalo dado
    */
    float newtonCotesG4(const int &filosofia, const float &inicio, const float &fim, const float &h) {
        float val1, val2, val3, val4, val5;

        switch (filosofia){
        case ABERTA:
            val1 = inicio + h;
            val2 = val1 + h;
            val3 = val2 + h;
            val4 = val3 + h;
            val5 = val4 + h;

            return ((fim - inicio) / 70) * ((24 * sin(val1)) + (9 * sin(val2)) + (4 * sin(val3)) + (9 * sin(val4)) + (24 * sin(val5)));
        break;
        case FECHADA:
            val1 = inicio;
            val2 = val1 + h;
            val3 = val2 + h;
            val4 = val3 + h;
            val5 = fim;

            return (((fim - inicio)) / 90) * ((7 * sin(val1)) + (32 * sin(val2)) + (12 * sin(val3)) + (32 * sin(val4)) + (7 * sin(val5)));
        break;
        }
    }

}

#endif //INTEGRAL_H