#ifndef PARSER_H
#define PARSER_H

#include <string>
#include "expre.h"
#include "binario.h"
#include "unario.h"

namespace parser {

    struct pilhaExpre {
        expre::expre *val;
        struct pilhaExpre *ant, *prox;
    };

    #define BINARIA            0
    #define UNARIA             1
    #define PARENTESESABRINDO  2
    #define PARENTESESFECHANDO 3
    #define CONSTANTE          4
    #define VARIAVEL           5

    inline bool analisador (std::string &expressao);

    inline expre::expre* parser (std::string &expressao);

    /*! Analiza se a expressão está corretamente estruturada
    ** Parâmetros: A expressão em string
    ** Retornos: true se estiver corretamente estruturada e false se não
    */
    bool analisador (std::string &expressao) {
        int qtdPA = 0, qtdPF = 0,                  //Quantidade de parênteses abrindo e fechando
            tipo = CONSTANTE, antTipo = CONSTANTE, //Os tipos do caracteres lido e anteriormente lido
            tam = expressao.size();

        if((expressao[0] == '*')      || (expressao[0] == '/')       || //Se começar com * ou /
          (((expressao[tam-1] < '0')  || (expressao[tam-1] > '9'))   && //Se não terminar com uma constante
          ((expressao[tam-1] != ')')  && (expressao[tam-1] != 'x')))){  //E se não terminar com um ')' ou uma varável
            return false;
          }


        for(int i = 0; i < tam; i++){
            if(expressao[i] < '0' || expressao[i] > '9'){
                switch (expressao[i]){
                    case '+':
                        tipo = BINARIA;
                    break;
                    case '-':
                        tipo = BINARIA;
                    break;
                    case '*':
                        tipo = BINARIA;
                    break;
                    case '/':
                        tipo = BINARIA;
                    break;
                    case '^':
                        tipo = BINARIA;
                    break;
                    case '(':
                        tipo = PARENTESESABRINDO;
                        qtdPA++;
                    break;
                    case ')':
                        tipo = PARENTESESFECHANDO;
                        qtdPF++;
                    break;
                    case 'x':
                        tipo = VARIAVEL;
                    break;
                    case '.':
                        tipo = CONSTANTE;
                    break;
                    default:
                        if(!expressao.compare(i, 3, "sen")){
                            tipo = UNARIA;
                            i += 2;
                        }else if(!expressao.compare(i, 3, "cos")){
                            tipo = UNARIA;
                            i += 2;
                        }else if(!expressao.compare(i, 3, "tan")){
                            tipo = UNARIA;
                            i += 2;
                        }else if(!expressao.compare(i, 3, "log")){
                            tipo = UNARIA;
                            i += 2;
                        }else{
                            return false;
                        }
                    break;
                }
            }else{
                tipo = CONSTANTE;
            }

            if((tipo == BINARIA && antTipo == BINARIA)                      || //Duas operações binárias seguidas
               (tipo == PARENTESESFECHANDO &&  antTipo == BINARIA)          || //Uma operação binária seguida de ')'
               (tipo == BINARIA && antTipo == PARENTESESABRINDO)            || //Um '(' seguido de operação binária
               (tipo == PARENTESESABRINDO && antTipo == PARENTESESFECHANDO) || // )(
               (tipo == PARENTESESFECHANDO && antTipo == PARENTESESABRINDO) || // ()
               (tipo == PARENTESESABRINDO && antTipo == CONSTANTE)          || // Constante seguida de '('
               (tipo == PARENTESESABRINDO && antTipo == VARIAVEL)           || // Variável seguidade de '('
               (tipo == VARIAVEL && antTipo == VARIAVEL)                    ||
               (expressao[i] == '.' && expressao[i-1] == '.')){
               //(tipo == VARIAVEL && antTipo == VARIAVEL) ||
                return false;
            }
            
            antTipo = tipo;
        }

        if(qtdPA != qtdPF){ //Se a quantidade de '(' for diferente de ')' 
            return false;
        }

            return true;
    }

    /*! Constroi a árvore de expressão da respectiva string
    ** Parâmetros: A expressão em string
    ** Retornos: A árvore de expressão construída
    */
    expre::expre* parser (std::string &expressao, const int &inicio, const int &fim) {
        expre::expre *resul;

        if(inicio == fim){
            return new expre::constante(0);
        }

        for(int i = inicio; i < fim; i++){
            if(expressao[i] < '0' || expressao[i] > '9'){
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
                    case 'x':
                        return new expre::variavel();
                    break;
                    default:
                        if(!expressao.compare(i, 3, "sen")){
                            return new expre::sen(parser(expressao, i+3, fim));
                        }else if(!expressao.compare(i, 3, "cos")){
                            return new expre::cos(parser(expressao, i+3, fim));
                        }else if(!expressao.compare(i, 3, "tan")){
                            return new expre::tan(parser(expressao, i+3, fim));
                        }else if(!expressao.compare(i, 3, "log")){
                            return new expre::log(parser(expressao, i+3, fim));
                        }
                    break;
                }
            }
        }
        
        return new expre::constante(atof((expressao.substr(inicio, fim - inicio)).data()));
    }

    expre::expre* parserAux (std::string &expressao, const int &inicio, const int &fim) {
        pilhaExpre *basePilhaTemporaria = NULL, *topoPilhaTemporaria = NULL,
                   *basePilha = NULL, *topoPilha = NULL;
        int percorrer = inicio, quant = 0;
        
        while(percorrer < fim){
            if(expressao[percorrer] >= '0' && expressao[percorrer] <= '9'){
                //inserirPilha(criarConstante(expressao, percorrer));
                quant++;
            }else{
                switch (expressao[percorrer]){
                case '+':
                    //inserirPilhaTemporaria(criarSoma());
                break;
                case '-':
                    //inserirPilhaTemporaria(criarSubtracao());
                break;
                case '*':
                    //inserirPilhaTemporaria(criarMultiplicacao());
                break;
                case '/':
                    //inserirPilhaTemporaria(criarDivisao());
                break;
                case '^':
                    //inserirPilhaTemporaria(criarPotencia());
                break;
                case 'x':
                    //inserirPilha(criarVariavel();
                    quant++;
                break;
                default:
                    if(!expressao.compare(percorrer, 3, "sen")){
                            //inserirPilhaTemporaria(criarSen());
                        }else if(!expressao.compare(percorrer, 3, "cos")){
                            //inserirPilhaTemporaria(criarCos());
                        }else if(!expressao.compare(percorrer, 3, "tan")){
                            //inserirPilhaTemporaria(criarTan());
                        }else if(!expressao.compare(percorrer, 3, "log")){
                            //inserirPilhaTemporaria(criarLog());
                        }
                break;
                }
            }

            if(topoPilhaTemporaria == NULL && basePilhaTemporaria == NULL){
                basePilhaTemporaria = topoPilhaTemporaria;
            }
            if(topoPilha == NULL && basePilha == NULL){
                basePilha = topoPilha;
            }

            if(quant >= 2){
                //inserirPilha();
            }
        }
    }
}

#endif //PARSER_H