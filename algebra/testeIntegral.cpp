#include <iostream>
#include "integral.h"

#define PI 3.14159

int main(){
    float intervalo[2] = {0, (PI / 2)};
    std::cout << intervalo[0] << "   " << intervalo[1] << '\n';
    std::cout << ((intervalo[1] - intervalo[0]) / 2) * (sin(intervalo[0]) + sin(intervalo[1])) << '\n';
    std::cout << inte::newtonCotes(2, ABERTA, 10, intervalo) << '\n';
}
