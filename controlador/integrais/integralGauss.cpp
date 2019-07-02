#include "integrais.h"

// ------- \\ INÍCIO - GAUSS LEGENDRE // ------- \\

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
double gaussLegendre (const int &qtdPontos, const int &qtdDivisoes, const double intervalo[2], expre::expre *equacao) {
    double resul = 0, *divisoes = dividir(qtdDivisoes, intervalo);
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

    free(divisoes);
    return resul;
}

double gaussLegendreErro (const int &qtdPontos, const double &erro, const double intervalo[2], expre::expre *equacao) {

    int MAX_PART = 1000000000000;
    int particoes = 1000;
    double anterior = 0;
    double proximo = INFINITY;
    
    do{
        anterior = proximo;
        proximo = gaussLegendre(qtdPontos, particoes, intervalo, equacao);
        particoes = particoes*2;

    } while(fabs((proximo - anterior) / anterior) > erro and MAX_PART > particoes);

    return proximo;
}

/*! Faz as divisões do intervalo
** Parâmetros: A quantidade de divisões e o intervalo
** Retornos: Os intervalos divididos
*/
double* dividir (const int &qtdDivisoes, const double intervalo[2]) {
    double *divisoes = (double*)malloc(sizeof(double) * qtdDivisoes * 2),
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
double mudarVariavelGL (const double &inicio, const double &fim, const int &valor) {
    return ((fim + inicio) / 2) + (valor * (fim - inicio) / 2);
}

/*! Resolve a integral de Gauss Legendre com 1 ponto
** Parâmetros: O início e o fim do intervalo e a expressão
** Retornos: O resultado da integral
*/
double gaussLegendreN1 (const double &inicio, const double &fim, expre::expre *equacao) {
    return ((fim - inicio) / 2) * (w11 * equacao->calcular(mudarVariavelGL(inicio, fim, t11)));
}

/*! Resolve a integral de Gauss Legendre com 2 ponto
** Parâmetros: O início e o fim do intervalo e a expressão
** Retornos: O resultado da integral
*/
double gaussLegendreN2 (const double &inicio, const double &fim, expre::expre *equacao) {
    double resul = 0;
    resul += (w12 * equacao->calcular(mudarVariavelGL(inicio, fim, t12)));
    resul += (w22 * equacao->calcular(mudarVariavelGL(inicio, fim, t22)));
    return ((fim - inicio) / 2) * resul;
}

/*! Resolve a integral de Gauss Legendre com 3 ponto
** Parâmetros: O início e o fim do intervalo e a expressão
** Retornos: O resultado da integral
*/
double gaussLegendreN3 (const double &inicio, const double &fim, expre::expre *equacao) {
    double resul = 0;
    resul += (w13 * equacao->calcular(mudarVariavelGL(inicio, fim, t13)));
    resul += (w23 * equacao->calcular(mudarVariavelGL(inicio, fim, t23)));
    resul += (w33 * equacao->calcular(mudarVariavelGL(inicio, fim, t33)));
    return ((fim - inicio) / 2) * resul;
}

/*! Resolve a integral de Gauss Legendre com 4 ponto
** Parâmetros: O início e o fim do intervalo e a expressão
** Retornos: O resultado da integral
*/
double gaussLegendreN4 (const double &inicio, const double &fim, expre::expre *equacao) {
    double resul = 0;
    resul += (w14 * equacao->calcular(mudarVariavelGL(inicio, fim, t14)));
    resul += (w24 * equacao->calcular(mudarVariavelGL(inicio, fim, t24)));
    resul += (w34 * equacao->calcular(mudarVariavelGL(inicio, fim, t34)));
    resul += (w44 * equacao->calcular(mudarVariavelGL(inicio, fim, t44)));
    return ((fim - inicio) / 2) * resul;
}

// ------- \\ FIM - GAUSS LEGENDRE // ------- \\

// ------- \\ INÍCIO - GAUSS LAGUERRE // ------- \\

#define x21GLa 0.585786
#define x22GLa 3.41421
#define x31GLa 0.415775
#define x32GLa 2.29428
#define x33GLa 6.28995
#define x41GLa 0.322548
#define x42GLa 1.74576
#define x43GLa 4.53662
#define x44GLa 9.39507

#define w21GLa 0.853553
#define w22GLa 0.146447
#define w31GLa 0.711093
#define w32GLa 0.278518
#define w33GLa 0.0103893
#define w41GLa 0.603154
#define w42GLa 0.357419
#define w43GLa 0.0388879
#define w44GLa 0.000539295


/*! Calcula a integral por Gauss Laguerre
** Parâmetros: A quantidade de pontos e a expressão
** Retornos: O valor da integral calculada
*/
double gaussLaguerre (const int &qtdPontos, expre::expre *equacao) {
    double resul = 0;
    
    switch (qtdPontos){
        case 2:
            resul = gaussLaguerreN2(equacao);
        break;
        case 3:
            resul = gaussLaguerreN3(equacao);
        break;
        case 4:
            resul = gaussLaguerreN4(equacao);
        break;
    }

    return resul;
}

/*! Resolve a integral de Gauss Laguerre com 2 ponto
** Parâmetros: A expressão
** Retornos: O resultado da integral
*/
double gaussLaguerreN2 (expre::expre *equacao) {
    return (equacao->calcular(x21GLa) * w21GLa) + (equacao->calcular(x22GLa) * w22GLa);
}

/*! Resolve a integral de Gauss Laguerre com 3 ponto
** Parâmetros: A expressão
** Retornos: O resultado da integral
*/
double gaussLaguerreN3 (expre::expre *equacao) {
    return (equacao->calcular(x31GLa) * w31GLa) + (equacao->calcular(x32GLa) * w32GLa)
         + (equacao->calcular(x33GLa) * w33GLa);
}

/*! Resolve a integral de Gauss Laguerre com 4 ponto
** Parâmetros: A expressão
** Retornos: O resultado da integral
*/
double gaussLaguerreN4 (expre::expre *equacao) {
    return (equacao->calcular(x41GLa) * w41GLa) + (equacao->calcular(x42GLa) * w42GLa)
         + (equacao->calcular(x43GLa) * w43GLa) + (equacao->calcular(x44GLa) * w44GLa);
}

// ------- \\ FIM - GAUSS LAGUERRE // ------- \\

// ------- \\ INÍCIO - GAUSS HERMITE // ------- \\


#define x21GHe -0.707107
#define x22GHe 0.707107
#define x31GHe -1.22474
#define x32GHe 0.0
#define x33GHe 1.22474
#define x41GHe -1.65068
#define x42GHe -0.524648
#define x43GHe 0.524648
#define x44GHe 1.65068

#define w21GHe 0.886227
#define w22GHe 0.886227
#define w31GHe 0.295409
#define w32GHe 1.18164
#define w33GHe 0.295409
#define w41GHe 0.0813128
#define w42GHe 0.804914
#define w43GHe 0.804914
#define w44GHe 0.0813128

/*! Calcula a integral por Gauss Hermite
** Parâmetros: A quantidade de pontos e a expressão
** Retornos: O valor da integral calculada
*/
double gaussHermite (const int &qtdPontos, expre::expre *equacao) {
    double resul = 0;
    
    switch (qtdPontos){
        case 2:
            resul = gaussHermiteN2(equacao);
        break;
        case 3:
            resul = gaussHermiteN3(equacao);
        break;
        case 4:
            resul = gaussHermiteN4(equacao);
        break;
    }

    return resul;
}

/*! Resolve a integral de Gauss Hermite com 2 ponto
** Parâmetros: A expressão
** Retornos: O resultado da integral
*/
double gaussHermiteN2 (expre::expre *equacao) {
    return (equacao->calcular(x21GHe) * w21GHe) + (equacao->calcular(x22GHe) * w22GHe);
}

/*! Resolve a integral de Gauss Hermite com 3 ponto
** Parâmetros: A expressão
** Retornos: O resultado da integral
*/
double gaussHermiteN3 (expre::expre *equacao) {
    return (equacao->calcular(x31GHe) * w31GHe) + (equacao->calcular(x32GHe) * w32GHe)
         + (equacao->calcular(x33GHe) * w33GHe);
}

/*! Resolve a integral de Gauss Hermite com 4 ponto
** Parâmetros: A expressão
** Retornos: O resultado da integral
*/
double gaussHermiteN4 (expre::expre *equacao) {
    return (equacao->calcular(x41GHe) * w41GHe) + (equacao->calcular(x42GHe) * w42GHe)
         + (equacao->calcular(x43GHe) * w43GHe) + (equacao->calcular(x44GHe) * w44GHe);
}

// ------- \\ FIM - GAUSS HERMITE // ------- \\


// ------- \\ INÍCIO - GAUSS CHEBYSHEV // ------- \\


/*! Calcula a integral por Gauss Chebyshev
** Parâmetros: A quantidade de pontos e a expressão
** Retornos: O valor da integral calculada
*/
double gaussChebyshev (int qtdPontos, expre::expre *equacao) {
    double xi = 0.0,
          wi = 0.0,
          resul  = 0,
          n = (double)qtdPontos;
          
    for (int i = 0; i < qtdPontos; i++) {
        xi = std::cos((((i) - 0.5)*M_PI)/(n));
        wi = M_PI/n;
        
        resul += equacao->calcular(xi)*wi;
    }
    
    return resul;
}

// ------- \\ FIM - GAUSS CHEBYSHEV // ------- \\
