#include <iostream>

#include "../../controlador/integrais/integrais.h"
#include "../../controlador/integrais/exponenciacao.h"

#define PI 3.14159

using namespace std;

int main(){
    //double intervalo[2] = {0, (PI / 2)};
    double intervalo[2] = {-2, 2};
    double erro = 0.0000001;
    double a = intervalo[0];
    double b = intervalo[1];
    int grau = 4;
    
    string tt = "(4 - (x^2))^(0.5)";
    
    expre::expre *calc = parser(tt);
    
    cout << "Equação: " << tt << endl;
    cout << "Intervalo: a = " << a << " b = " << b << endl;



    //cout << "Integral com Exponenciação Simples: " << exponenciacaoSimples(calc, a, b, erro) << endl;
    //cout << "Integral com exp Gauss Legendre: " << exponenciacaoSimplesGauss(grau, erro, intervalo, calc) << endl;
    //cout << "Integral com exp2 Gauss Legendre: " << exponenciacaoDuplaGauss(grau, erro, intervalo, calc) << endl;

    cout << "Integral com expo Simples Newton: " << exponenciacaoSimplesNewton(grau, FECHADA, erro, intervalo, calc) << endl;
    cout << "Integral com expo Dupla Newton: " << exponenciacaoDuplaNewton(grau, FECHADA, erro, intervalo, calc) << endl;
    //cout << "Integral com expo Simples Gauss: " << exponenciacaoSimplesGauss(grau, erro, intervalo, calc) << endl;

    //cout << "Integral com Exponenciação Dupla: " << exponenciacaoDupla(calc, a, b, erro) << endl;
    //cout << "Integral com Newton Cotes com erro: " << newtonCotesErro(4, ABERTA, erro, intervalo, calc) << endl;
    //cout << "Integral com Newton Cotes fechada: " << newtonCotes(4, FECHADA, 5, intervalo, calc) << endl;
    //cout << "Integral com Gauss Legendre: " << gaussLegendre(grau, 100, intervalo, calc) << endl;
    //cout << "Integral com Gauss Legendre c/ erro: " << gaussLegendreErro(grau, erro, intervalo, calc) << endl;
    //cout << "Integral com Gauss Laguerre: " << gaussLaguerre(4, calc) << endl;
    //cout << "Integral com Gauss Hermite: " << gaussHermite(4, calc) << endl;
    //cout << "Integral com Gauss Chebyshev: " << gaussChebyshev(10000, calc) << endl;
}