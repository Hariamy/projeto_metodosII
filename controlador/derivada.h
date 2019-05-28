#ifndef DERIVADA_H
#define DERIVADA_h

#include <iostream>
#include <cmath>
#include "parser/expre.h"

namespace deri{

    #define FORWARD  0
    #define BACKWARD 1
    #define CENTRAL  2

    float derivada (int grau, int filosofia);

}

#endif //DERIVADA_H