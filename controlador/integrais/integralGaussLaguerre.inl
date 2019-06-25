#include "integral.h"

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



float gaussLaguerre (const int &qtdPontos, expre::expre *equacao) {
    float resul = 0;
    
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

float gaussLaguerreN2 (expre::expre *equacao) {
    return (equacao->calcular(x21GLa) * w21GLa) + (equacao->calcular(x22GLa) * w22GLa);
}

float gaussLaguerreN3 (expre::expre *equacao) {
    return (equacao->calcular(x31GLa) * w31GLa) + (equacao->calcular(x32GLa) * w32GLa)
         + (equacao->calcular(x33GLa) * w33GLa);
}

float gaussLaguerreN4 (expre::expre *equacao) {
    return (equacao->calcular(x41GLa) * w41GLa) + (equacao->calcular(x42GLa) * w42GLa)
         + (equacao->calcular(x43GLa) * w43GLa) + (equacao->calcular(x44GLa) * w44GLa);
}