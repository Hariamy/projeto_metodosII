#include <iostream>
#include "integral.h"
#include "parser/parser.h"

#define PI 3.14159

int main(){
    float intervalo[2] = {0, (PI / 2)};
    
    std::string tt = "1-3.2-senx";
    if(parser::analisador(tt)){
        expre::expre *calc = parser::parser(tt, 0, tt.size());

        std::cout << inte::newtonCotes(2, ABERTA, 1, intervalo, calc) << '\n';
        std::cout << calc->calcular(2) << '\n';
    }else{
        std::cout << "Não foi\n";
    }
}
