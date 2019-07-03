#include <iostream>

#include "../../controlador/integrais/integrais.h"
#include "../../controlador/integrais/exponenciacao.h"

#define PI 3.14159

using namespace std;

int main(){
    //double intervalo[2] = {0, (PI / 2)};
    double intervalo[2] = {-2, 2};
    double erro = 0.0001;
    double a = intervalo[0];
    double b = intervalo[1];
    int grau = 4;
    int quantParticoes = 100;
    
    string tt = "(4 - (x^2))^(0.5)";
    
    expre::expre *calc = parser(tt);
    
    cout << "Função: " << tt << "\n\n";
    cout << "Intervalo de Intetgração: a = " << a << " b = " << b << "\n\n";


    cout << "Exponenciação Simples com Gauss Legendre: " << exponenciacaoSimplesGauss(grau, erro, intervalo, calc) << "\n\n";
    cout << "Exponenciação Dupla com Gauss Legendre: " << exponenciacaoDuplaGauss(grau, erro, intervalo, calc) << "\n\n";

    cout << "Exponenciação Simples com Newton Cotes: " << exponenciacaoSimplesNewton(grau, FECHADA, erro, intervalo, calc) << "\n\n";
    cout << "Exponenciação Dupla com Newton Cotes: " << exponenciacaoDuplaNewton(grau, FECHADA, erro, intervalo, calc) << "\n\n";

    cout << "Newton Cotes por Erro: " << newtonCotesErro(grau, FECHADA, erro, intervalo, calc) << "\n\n";
    cout << "Newton Cotes por Particao: " << newtonCotes(grau, ABERTA, quantParticoes, intervalo, calc) << "\n\n";
    
    cout << "Gauss Legendre por Erro: " << gaussLegendreErro(grau, erro, intervalo, calc) << "\n\n";
    cout << "Gauss Legendre por Particao: " << gaussLegendre(grau, quantParticoes, intervalo, calc) << "\n\n";

    cout << "Função Gauss Laguerre: " << "e^(-x)" << tt << "\n\n";
    cout << "Intervalo de Intetgração: a = 0 b = +INFINITO" << "\n\n";

    cout << "Gauss Laguerre: " << gaussLaguerre(grau, calc) << "\n\n";

    cout << "Função Gauss Hermite: " << "e^(-x^2)" << tt << "\n\n";
    cout << "Intervalo de Intetgração: a = -INFINITO b = +INFINITO" << "\n\n";

    cout << "Gauss Hermite: " << gaussHermite(grau, calc) << "\n\n";

    cout << "Função: " << tt << " * 1/(1 - x^2)^(0.5)" << "\n\n";
    cout << "Intervalo de Intetgração: a = -1 b = 1" << "\n\n";

    cout << "Gauss Chebyshev: " << gaussChebyshev(10000, calc) << "\n\n";
}