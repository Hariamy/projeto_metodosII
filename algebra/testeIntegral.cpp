#include <iostream>
#include "integral.h"
#include "parser/parser.h"

#define PI 3.14159

int main(){
    float intervalo[2] = {0, (PI / 2)};
    
    std::string tt = "4+senx";
    if(parser::analisador(tt)){
        expre::expre *calc = parser::parser(tt, 0, tt.size());

        std::cout << "Integral com Newton Cotes: " << inte::newtonCotes(2, ABERTA, 1, intervalo, calc) << '\n';
        std::cout << "Integral com Gauss Legendre: " << inte::gaussLegendre(2, 1, intervalo, calc) << '\n';
    }else{
        std::cout << "Não foi\n";
    }
}
