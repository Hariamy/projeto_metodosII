#include "integralGaussLegendre.h"

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