#include <iostream>

#include "../../controlador/integrais/integrais.h"
#include "../../controlador/integrais/exponenciacao.h"

#define PI 3.14159

using namespace std;

int main(){
    double intervalo[2] = {0, (PI / 2)};
    double erro = 0.00000000001;
    double a = 0;
    double b = PI/2;
    
    string tt = "(sen(x))";
    
    expre::expre *calc = parser(tt);
    
    cout << "Equação: " << tt << endl;
    cout << "Intervalo: a = " << a << " b = " << b << endl;

    cout << "Integral com Exponenciação Simples: " << exponenciacaoSimples(calc, a, b, erro) << endl;
    cout << "Integral com Exponenciação Dupla: " << exponenciacaoDupla(calc, a, b, erro) << endl;
    cout << "Integral com Newton Cotes com erro: " << newtonCotesErro(4, ABERTA, 0.000000000001, intervalo, calc) << endl;
    cout << "Integral com Newton Cotes fechada: " << newtonCotes(4, FECHADA, 5, intervalo, calc) << endl;
    cout << "Integral com Gauss Legendre: " << gaussLegendre(4, 5, intervalo, calc) << endl;
    cout << "Integral com Gauss Laguerre: " << gaussLaguerre(4, calc) << endl;
    cout << "Integral com Gauss Hermite: " << gaussHermite(4, calc) << endl;
    cout << "Integral com Gauss Chebyshev: " << gaussChebyshev(10000, calc) << endl;
}