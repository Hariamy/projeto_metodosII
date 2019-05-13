#include <iostream>
#include "integral.h"

#define PI 3.14159

int main(){
    float intervalo[2] = {0, (PI / 2)};
    
    std::cout << inte::newtonCotes(4, ABERTA, 1, intervalo) << '\n';
}
