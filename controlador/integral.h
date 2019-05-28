#ifndef INTEGRAL_H
#define INTEGRAL_H

#include <iostream>
#include <cmath>
#include "parser/expre.h"

namespace inte {
    
    #define FECHADA  0
    #define ABERTA   1

    #define t11 0.0
    #define t12 (std::sqrt(3.0) / 3.0)
    #define t22 -(std::sqrt(3.0) / 3.0)
    #define t13 0.0
    #define t23 (std::sqrt(3.0 / 5.0))
    #define t33 -(std::sqrt(3.0 / 5.0))
    #define t14 (std::sqrt((3.0 - (2.0 * (std::sqrt(6.0 / 5.0)))) / 7.0))
    #define t24 -(std::sqrt((3.0 - (2.0 * (std::sqrt(6.0 / 5.0)))) / 7.0))
    #define t34 (std::sqrt((3.0 + (2.0 * (std::sqrt(6.0 / 5.0)))) / 7.0))
    #define t44 -(std::sqrt((3.0 + (2.0 * (std::sqrt(6.0 / 5.0)))) / 7.0))

    #define w11 2.0
    #define w12 1.0
    #define w22 1.0
    #define w13 (8.0 / 9.0)
    #define w23 (5.0 / 9.0)
    #define w33 (5.0 / 9.0)
    #define w14 ((18.0 + std::sqrt(30.0)) / 36.0)
    #define w24 ((18.0 + std::sqrt(30.0)) / 36.0)
    #define w34 ((18.0 - std::sqrt(30.0)) / 36.0)
    #define w44 ((18.0 - std::sqrt(30.0)) / 36.0)
    

    inline float newtonCotes(const int &grau, const int &filosofia, const int &qtdDivisoes, const float intervalo[2], expre::expre *equacao);

    inline float* initNcG1 (const int &filosofia, const int &qtdDivisoes, const float intervalo[2], float &h);
    inline float* initNcG2 (const int &filosofia, const int &qtdDivisoes, const float intervalo[2], float &h);
    inline float* initNcG3 (const int &filosofia, const int &qtdDivisoes, const float intervalo[2], float &h);
    inline float* initNcG4 (const int &filosofia, const int &qtdDivisoes, const float intervalo[2], float &h);

    inline float newtonCotesG1 (const int &filosofia, const float &inicio, const float &fim, const float &h, expre::expre *equacao);
    inline float newtonCotesG2 (const int &filosofia, const float &inicio, const float &fim, const float &h, expre::expre *equacao);
    inline float newtonCotesG3 (const int &filosofia, const float &inicio, const float &fim, const float &h, expre::expre *equacao);
    inline float newtonCotesG4 (const int &filosofia, const float &inicio, const float &fim, const float &h, expre::expre *equacao);

    inline float gaussLegendre (const int &qtdPontos, const int &qtdDivisoes, const float intervalo[2], expre::expre *equacao);

    inline float* dividir (const int &qtdDivisoes, const float intervalo[2]);
    inline float mudarVariavelGL (const float &inicio, const float &fim, const int &valor);

    inline float gaussLegendreN1 (const float &inicio, const float &fim, expre::expre *equacao);
    inline float gaussLegendreN2 (const float &inicio, const float &fim, expre::expre *equacao);
    inline float gaussLegendreN3 (const float &inicio, const float &fim, expre::expre *equacao);
    inline float gaussLegendreN4 (const float &inicio, const float &fim, expre::expre *equacao);

    //inline float exponencialSimplesNC (const int &grau, const int &filosofia, const int &qtdDivisoes, const float intervalo[2], expre::expre *equacao);
    //inline float exponencialSimplesGL (const int &qtdPontos, const int &qtdDivisoes, const float intervalo[2], expre::expre *equacao);

/**************************************************************************************************************************
------------------------------------------------------ Newton Cotes -------------------------------------------------------
**************************************************************************************************************************/

    
    /*! Calcula a integral por Newton Cotes
    ** Parâmetros: O grau do polinômio, a filosofia que pode ser ABERTA ou FECHADA, quantas divisões, intervalo e a expressão
    ** Retornos: O valor da integral calculada
    */
    float newtonCotes(const int &grau, const int &filosofia, const int &qtdDivisoes, const float intervalo[2], expre::expre *equacao) {
        float h, resul = 0, *divisoes;

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
    ** Parâmetros: A filosofia que pode ser ABERTA ou FECHADA, o inicio e o fim do intervalo, distância entre pontos e a expressão
    ** Retornos: O valor da integral para o intervalo dado
    */
    inline float newtonCotesG1 (const int &filosofia, const float &inicio, const float &fim, const float &h, expre::expre *equacao) {
        float val1, val2;

        switch (filosofia){
        case ABERTA:
            val1 = inicio + h,
            val2 = val1 + h;

            return ((fim - inicio) / 2) * (equacao->calcular(val1) + equacao->calcular(val2));
        break;
        case FECHADA:

            return ((fim - inicio) / 2) * (equacao->calcular(inicio) + equacao->calcular(fim));
        break;
        }
    }

    /*! Calcula Newton Cotes de grau 2 para o intervalo dado
    ** Parâmetros: A filosofia que pode ser ABERTA ou FECHADA, o inicio e o fim do intervalo, distância entre pontos e a expressão
    ** Retornos: O valor da integral para o intervalo dado
    */
    float newtonCotesG2 (const int &filosofia, const float &inicio, const float &fim, const float &h, expre::expre *equacao) {
        float val1, val2, val3;

        switch (filosofia){
        case ABERTA:
            val1 = inicio + h;
            val2 = val1 + h;
            val3 = val2 + h;

            return (((fim - inicio)) / 3) * ((2 * equacao->calcular(val1)) - equacao->calcular(val2) + (2 * equacao->calcular(val3)));
        break;
        case FECHADA:
            val1 = inicio;
            val2 = val1 + h;
            val3 = fim;

            return (((fim - inicio)) / 6) * (equacao->calcular(val1) + (4 * equacao->calcular(val2)) + equacao->calcular(val3));
        break;
        }
    }

    /*! Calcula Newton Cotes de grau 3 para o intervalo dado
    ** Parâmetros: A filosofia que pode ser ABERTA ou FECHADA, o inicio e o fim do intervalo, distância entre pontos e a expressão
    ** Retornos: O valor da integral para o intervalo dado
    */
    float newtonCotesG3 (const int &filosofia, const float &inicio, const float &fim, const float &h, expre::expre *equacao) {
        float val1, val2, val3, val4;

        switch (filosofia){
        case ABERTA:
            val1 = inicio + h;
            val2 = val1 + h;
            val3 = val2 + h;
            val4 = val3 + h;

            return ((fim - inicio) / 24) * ((11 * equacao->calcular(val1)) + equacao->calcular(val2) + equacao->calcular(val3) + (11 * equacao->calcular(val4)));
        break;
        case FECHADA:
            val1 = inicio;
            val2 = val1 + h;
            val3 = val2 + h;
            val4 = fim;

            return ((fim - inicio) / 8) * (equacao->calcular(val1) + (3 * equacao->calcular(val2)) + (3 * equacao->calcular(val3)) + equacao->calcular(val4));
        break;
        }
    }

    /*! Calcula Newton Cotes de grau 4 para o intervalo dado
    ** Parâmetros: A filosofia que pode ser ABERTA ou FECHADA, o inicio e o fim do intervalo, distância entre pontos e a expressão
    ** Retornos: O valor da integral para o intervalo dado
    */
    float newtonCotesG4 (const int &filosofia, const float &inicio, const float &fim, const float &h, expre::expre *equacao) {
        float val1, val2, val3, val4, val5;

        switch (filosofia){
        case ABERTA:
            val1 = inicio + h;
            val2 = val1 + h;
            val3 = val2 + h;
            val4 = val3 + h;
            val5 = val4 + h;

            return ((fim - inicio) / 70) * ((24 * equacao->calcular(val1)) + (9 * equacao->calcular(val2)) + (4 * equacao->calcular(val3)) + (9 * equacao->calcular(val4)) + (24 * equacao->calcular(val5)));
        break;
        case FECHADA:
            val1 = inicio;
            val2 = val1 + h;
            val3 = val2 + h;
            val4 = val3 + h;
            val5 = fim;

            return (((fim - inicio)) / 90) * ((7 * equacao->calcular(val1)) + (32 * equacao->calcular(val2)) + (12 * equacao->calcular(val3)) + (32 * equacao->calcular(val4)) + (7 * equacao->calcular(val5)));
        break;
        }
    }

/**************************************************************************************************************************
------------------------------------------------------ Newton Cotes -------------------------------------------------------
**************************************************************************************************************************/

    /*! Calcula a integral por Gauss Legendre
    ** Parâmetros: A quantidade de pontos, quantas divisões, o intervalo e a expressão
    ** Retornos: O valor da integral calculada
    */
    float gaussLegendre (const int &qtdPontos, const int &qtdDivisoes, const float intervalo[2], expre::expre *equacao) {
        float resul = 0, *divisoes = dividir(qtdDivisoes, intervalo);

        switch (qtdPontos){
            case 1:
                for(int i = 0; i < qtdDivisoes; i++){
                    resul += gaussLegendreN1(divisoes[i*2], divisoes[(i*2)+1], equacao);
                }
            break;
            case 2:
                for(int i = 0; i < qtdDivisoes; i++){
                    resul += gaussLegendreN2(divisoes[i*2], divisoes[(i*2)+1], equacao);
                }
            break;
            case 3:
                for(int i = 0; i < qtdDivisoes; i++){
                    resul += gaussLegendreN3(divisoes[i*2], divisoes[(i*2)+1], equacao);
                }
            break;
            case 4:
                for(int i = 0; i < qtdDivisoes; i++){
                    resul += gaussLegendreN4(divisoes[i*2], divisoes[(i*2)+1], equacao);
                }
            break;
        }

        return resul;
    }

    /*! Faz as divisões do intervalo
    ** Parâmetros: A quantidade de divisões e o intervalo
    ** Retornos: Os intervalos divididos
    */
    float* dividir (const int &qtdDivisoes, const float intervalo[2]) {
        float *divisoes = (float*)malloc(sizeof(float) * qtdDivisoes * 2),
              tamInt = (intervalo[1] - intervalo[0]) / qtdDivisoes, aux = intervalo[0];

        for(int i = 0; i < qtdDivisoes; i++){
            divisoes[i*2] = aux;
            aux += tamInt;
            divisoes[(i*2)+1] = aux;
        }
        
        return divisoes;
    }

    /*! Faz a mudança de variável para o cálculo de Gauss Legendre
    ** Parâmetros: O início e o fim do intervalo e o valor da variável
    ** Retornos: O resultado da mudança de variável
    */
    float mudarVariavelGL (const float &inicio, const float &fim, const int &valor) {
        return ((fim + inicio) / 2) + (valor * (fim - inicio) / 2);
    }

    /*! Resolve a integral de Gauss Legendre com 1 ponto
    ** Parâmetros: O início e o fim do intervalo e a expressão
    ** Retornos: O resultado da integral
    */
    float gaussLegendreN1 (const float &inicio, const float &fim, expre::expre *equacao) {
        return ((fim - inicio) / 2) * (w11 * equacao->calcular(mudarVariavelGL(inicio, fim, t11)));
    }

    /*! Resolve a integral de Gauss Legendre com 2 ponto
    ** Parâmetros: O início e o fim do intervalo e a expressão
    ** Retornos: O resultado da integral
    */
    float gaussLegendreN2 (const float &inicio, const float &fim, expre::expre *equacao) {
        float resul = 0;

        resul += (w12 * equacao->calcular(mudarVariavelGL(inicio, fim, t12)));
        resul += (w22 * equacao->calcular(mudarVariavelGL(inicio, fim, t22)));

        return ((fim - inicio) / 2) * resul;
    }

    /*! Resolve a integral de Gauss Legendre com 3 ponto
    ** Parâmetros: O início e o fim do intervalo e a expressão
    ** Retornos: O resultado da integral
    */
    float gaussLegendreN3 (const float &inicio, const float &fim, expre::expre *equacao) {
        float resul = 0;

        resul += (w13 * equacao->calcular(mudarVariavelGL(inicio, fim, t13)));
        resul += (w23 * equacao->calcular(mudarVariavelGL(inicio, fim, t23)));
        resul += (w33 * equacao->calcular(mudarVariavelGL(inicio, fim, t33)));

        return ((fim - inicio) / 2) * resul;
    }

    /*! Resolve a integral de Gauss Legendre com 4 ponto
    ** Parâmetros: O início e o fim do intervalo e a expressão
    ** Retornos: O resultado da integral
    */
    float gaussLegendreN4 (const float &inicio, const float &fim, expre::expre *equacao) {
        float resul = 0;

        resul += (w14 * equacao->calcular(mudarVariavelGL(inicio, fim, t14)));
        resul += (w24 * equacao->calcular(mudarVariavelGL(inicio, fim, t24)));
        resul += (w34 * equacao->calcular(mudarVariavelGL(inicio, fim, t34)));
        resul += (w44 * equacao->calcular(mudarVariavelGL(inicio, fim, t44)));

        return ((fim - inicio) / 2) * resul;
    }
}

#endif //INTEGRAL_H