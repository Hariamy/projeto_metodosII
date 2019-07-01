#include <iostream>
/*#include "integralNewtonCotes.h"
#include "integralGaussLegendre.h"
#include "integralGaussLaguerre.h"
#include "integralGaussHermite.h"*/
#include "../controlador/integrais/exponenciacao.h"

#define PI 3.14159

using namespace std;

int main(){
    double intervalo[2] = {0, (PI / 2)};
    std::string tt = "(log(x))";
    //if(analisador(tt)){
    expre::expre *calc = parser(tt);

    /*    std::cout << "Integral com Newton Cotes: " << newtonCotes(2, ABERTA, 1, intervalo, calc) << '\n';
        std::cout << "Integral com Gauss Legendre: " << gaussLegendre(2, 1, intervalo, calc) << '\n';
    //}else{
    //    std::cout << "Não foi\n";
    //}*/
    
    /*std::cout << "Integral com Gauss Laguerre: " << gaussLaguerre(4, calc) << '\n';
    std::cout << "Integral com Gauss Hermite: " << gaussHermite(4, calc) << '\n';*/
    double a = 0;
    double b = 3;
    double erro = 0.00000000001;
    cout << "Equação: " << tt << endl;
    cout << "Intervalo: a = " << a << " b = " << b << endl;

    std::cout << "Integral com Exponenciação Simples: " << exponenciacaoSimples(calc, a, b, erro) << endl;
    std::cout << "Integral com Exponenciação Dupla: " << exponenciacaoDupla(calc, a, b, erro) << endl;
}