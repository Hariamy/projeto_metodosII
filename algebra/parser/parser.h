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
    expre::expre* parser (std::string &expressao, const int &inicio, const int &fim) {
        expre::expre *resul;

        for(int i = inicio; i < fim; i++){
            if((expressao[i] < '0' || expressao[i] > '9') && expressao[i] != 'x'){
                switch (expressao[i]){
                    case '+':
                        return new expre::soma(parser(expressao, inicio, i), parser(expressao, i+1, fim));
                    break;
                    case '-':
                        return new expre::subtracao(parser(expressao, inicio, i), parser(expressao, i+1, fim));
                    break;
                    case '*':
                        return new expre::multiplicacao(parser(expressao, inicio, i), parser(expressao, i+1, fim));
                    break;
                    case '/':
                        return new expre::divisao(parser(expressao, inicio, i), parser(expressao, i+1, fim));
                    break;
                    case '^':
                        return new expre::potencia(parser(expressao, inicio, i), parser(expressao, i+1, fim));
                    break;
                    default:
                        if(expressao.compare(i, 3, "sen")){
                            return new expre::sen(parser(expressao, i+3, fim));
                        }else if(expressao.compare(i, 3, "cos")){
                            return new expre::cos(parser(expressao, i+3, fim));
                        }else if(expressao.compare(i, 3, "tan")){
                            return new expre::tan(parser(expressao, i+3, fim));
                        }else if(expressao.compare(i, 3, "log")){
                            return new expre::log(parser(expressao, i+3, fim));
                        }
                    break;
                }
            }
        }
        
        if(expressao[inicio] == 'x'){
            return new expre::variavel();
        }else{
            return new expre::constante(atof((expressao.substr(inicio, fim - inicio)).data()));
        }
    }
}

#endif //PARSER_H