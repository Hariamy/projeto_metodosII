#ifndef UNARIO_H
#define UNARIO_H

#include "expre.h"

namespace expre {
    class sen: public unario {
    public:
        sen (expre *novo) : unario (novo) { nome = new char[4]; strcpy(nome, "sen"); }
        sen () : unario () { nome = new char[4]; strcpy(nome, "sen"); }

        double calcular (const double &x);
    };

    class cos: public unario {
    public:
        cos (expre *novo) : unario (novo) { nome = new char[4]; strcpy(nome, "cos"); }
        cos () : unario () { nome = new char[4]; strcpy(nome, "cos"); }

        double calcular (const double &x);
    };

    class tan: public unario {
    public:
        tan (expre *novo) : unario (novo) { nome = new char[4]; strcpy(nome, "tan"); }
        tan () : unario () { nome = new char[4]; strcpy(nome, "tan"); }

        double calcular (const double &x);
    };

    class log: public unario {
    public:
        log (expre *novo) : unario (novo) { nome = new char[4]; strcpy(nome, "log"); }
        log () : unario () { nome = new char[4]; strcpy(nome, "log"); }

        double calcular (const double &x);
    };

    class exp: public unario {
    public:
        exp (expre *novo) : unario (novo) { nome = new char[4]; strcpy(nome, "exp"); }
        exp () : unario () { nome = new char[4]; strcpy(nome, "exp"); }

        double calcular (const double &x);
    };
}

#endif //UNARIO_H