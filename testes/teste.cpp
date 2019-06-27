#include <iostream>
#include <string>
#include "parser.h"

int main () {
    std::string teste = "3+2+x+x*5";
    expre::expre *arvore;

    arvore = parser(teste);

    std::cout << arvore->calcular(10) << '\n';

    return 0;
}