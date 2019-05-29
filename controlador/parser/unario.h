#ifndef UNARIO_H
#define UNARIO_H

#include "expre.h"

namespace expre {
    class sen: public unario {
    public:
        inline sen (expre *novo) : unario (novo) {}
        inline sen () : unario () {}

        inline float calcular (const float &x);
    };

    class cos: public unario {
    public:
        inline cos (expre *novo) : unario (novo) {}
        inline cos () : unario () {}

        inline float calcular (const float &x);
    };

    class tan: public unario {
    public:
        inline tan (expre *novo) : unario (novo) {}
        inline tan () : unario () {}

        inline float calcular (const float &x);
    };

    class log: public unario {
    public:
        inline log (expre *novo) : unario (novo) {}
        inline log () : unario () {}

        inline float calcular (const float &x);
    };
}

#include "unario.inl"

#endif //UNARIO_H