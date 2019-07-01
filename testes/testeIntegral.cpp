#include <iostream>
/*#include "integralNewtonCotes.h"
#include "integralGaussLegendre.h"
#include "integralGaussLaguerre.h"
#include "integralGaussHermite.h"*/
#include "../controlador/integrais/integralGaussChebyshev.h"

#define PI 3.14159

int main(){
    float intervalo[2] = {0, (PI / 2)};
    std::string tt = "(4+senx)";
    //if(analisador(tt)){
        expre::expre *calc = parser(tt);

    /*    std::cout << "Integral com Newton Cotes: " << newtonCotes(2, ABERTA, 1, intervalo, calc) << '\n';
        std::cout << "Integral com Gauss Legendre: " << gaussLegendre(2, 1, intervalo, calc) << '\n';
    //}else{
    //    std::cout << "Não foi\n";
    //}*/
    
    /*std::cout << "Integral com Gauss Laguerre: " << gaussLaguerre(4, calc) << '\n';
    std::cout << "Integral com Gauss Hermite: " << gaussHermite(4, calc) << '\n';*/
    std::cout << "Integral com Gauss Chebyshev: " << gaussChebyshev(10000, calc) << '\n';
}