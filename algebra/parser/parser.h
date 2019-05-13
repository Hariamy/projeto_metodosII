#ifndef PARSER_H
#define PARSER_H

#include <string>
#include "expre.h"
#include "binario.h"
#include "unario.h"

namespace parser {
    inline expre::expre* parser (std::string &expressao);

    /*! Constroi a árvore de expressão da respectiva string
    ** Parâmetros: A expressão em string
    ** Retornos: A árvore de expressão construída
    */
    expre::expre* parser (std::string &expressao) {
        expre::expre *resul;
        int tam = expressao.size();

        for(int i = 0; i < tam; i++){
            if(expressao[i] < '0' || expressao[i] > '9'){
                switch (expressao[i]){
                    case '+': break;
                    case '-': break;
                    case '*': break;
                    case '/': break;
                    case '^': break;
                    default: break;
                }
            }
        }

        return resul;
    }
}

#endif //PARSER_H