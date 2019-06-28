#include <iostream>
#include "../modelo/algebra.h"

/* resposta esperada
   [ 3 2 1 ]
   [ 6 4 2 ]
   [ 9 6 3 ]
*/

int main(){
    matriz *resul;
    vetor v1(3, 1), v2(3, 1);

    v1[1] = 2;
    v1[2] = 3;

    v2[0] = 3;
    v2[1] = 2;

    resul = prodExtern(v1, v2);
    std::cout << resul->tam << "    " << v1.tam << "    teste\n";
    resul->mostrar_debug();

    return 0;
}