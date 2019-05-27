#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <iostream>
#include <vector>
#include "expre.h"
#include "unario.h"
#include "binario.h"

namespace parser {
    struct noPilha {
        expre::expre *val;
        struct noPilha *ant, *prox;
    };

    struct pilha {
        noPilha *base, *topo;
        int tam;

        inline void init ();

        inline void inserir (expre::expre *no);
        inline void inserir (noPilha *no);
        inline void reInserir (noPilha *no);
        inline noPilha* retirarTopo ();
        inline noPilha* retirarBase ();

        inline bool estaVazio ();
        inline bool naoEstaVazio ();
        inline int tamanho ();

        inline ~pilha();
    };

    inline bool analisador (std::string &expressao);

    inline float lerConstante (std::string &expressao, int &percorrer);
    inline pilha* contruirPilha (std::string &expressao);
    inline expre::expre* construirArvore (pilha *expressaoPoIn);


    void pilha::init () {
        tam = 0;
        base = NULL;
        topo = NULL;
    }

    void pilha::inserir (expre::expre *no) {
        noPilha *novo = (noPilha*)malloc(sizeof(noPilha));
        
        novo->val = no;
        inserir(novo);
    }

    void pilha::inserir (noPilha *no) {
        no->ant = topo;
        no->prox = NULL;
        
        if(base == NULL){
            base = no;
        }else{
            topo->prox = no;
        }

        topo = no;

        tam++;
    }

    void pilha::reInserir (noPilha *no) {
        if(no->ant != NULL){
            no->ant->prox = no->prox;
        }else{
            base = no->prox;
        }


        if(no->prox != NULL){
            no->prox->ant = no->ant;
        }else{
            topo = no->ant;
        }

        tam--;

        inserir(no);
    }

    noPilha* pilha::retirarTopo () {
        noPilha *retorno = topo;

        if(topo != NULL){
            topo = topo->ant;

            if(topo != NULL){
                topo->prox = NULL;
            }else{
                base = NULL;
            }

            tam--;
        }

        return retorno;
    }

    noPilha* pilha::retirarBase () {
        noPilha *retorno = base;

        if(base != NULL){
            base = base->prox;

            if(retorno->prox != NULL){
                retorno->prox->ant = NULL;
            }
        }

        tam--;

        return retorno;
    }

    bool pilha::estaVazio () {
        return (tam == 0);
    }
    
    bool pilha::naoEstaVazio () {
        return (tam > 0);
    }

    int pilha::tamanho () {
        return tam;
    }

    pilha::~pilha() {
        noPilha *liberar = NULL, *percorrer = base;

        while(percorrer != NULL) {
            liberar = percorrer;
            percorrer = percorrer->prox;

            free(liberar);
        }
    }





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

    float lerConstante (std::string &expressao, int &percorrer) {
        int quant = 0, inicio = percorrer;
        
        while((expressao[percorrer] >= '0' && expressao[percorrer] <= '9') || expressao[percorrer] == '.'){
            quant++;
            percorrer++;
        }

        return atof(expressao.substr(inicio, quant).data());
    }

    pilha* contruirPilha (std::string &expressao) {
        pilha *pilhaTemporaria = (pilha*)malloc(sizeof(pilha)),
              *pilhaFinal = (pilha*)malloc(sizeof(pilha));
        noPilha *auxTrans;
        int percorrer = 0, tam = expressao.size(), quant = 0;
        expre::expre *ope;

        pilhaTemporaria->init();
        pilhaFinal->init();
        
        while(percorrer < tam){
            if(expressao[percorrer] >= '0' && expressao[percorrer] <= '9'){
                pilhaFinal->inserir( ope = ( new expre::constante( lerConstante (expressao, percorrer) ) ) );
                quant++;
            }else{
                switch (expressao[percorrer]){
                case '+':
                    pilhaTemporaria->inserir( ope = ( new expre::soma() ) );
                    percorrer++;
                break;
                case '-':
                    pilhaTemporaria->inserir( ope = ( new expre::subtracao() ) );
                    percorrer++;
                break;
                case '*':
                    pilhaTemporaria->inserir( ope = ( new expre::multiplicacao() ) );
                    percorrer++;
                break;
                case '/':
                    pilhaTemporaria->inserir( ope = ( new expre::divisao() ) );
                    percorrer++;
                break;
                case '^':
                    pilhaTemporaria->inserir( ope = ( new expre::potencia() ) );
                    percorrer++;
                break;
                case 'x':
                    pilhaFinal->inserir( ope = ( new expre::variavel() ) );
                    percorrer++;
                    quant++;
                break;
                default:
                    if(!expressao.compare(percorrer, 3, "sen")){
                            pilhaTemporaria->inserir( ope = ( new expre::sen() ) );
                            percorrer += 3;
                        }else if(!expressao.compare(percorrer, 3, "cos")){
                            pilhaTemporaria->inserir( ope = ( new expre::cos() ) );
                            percorrer += 3;
                        }else if(!expressao.compare(percorrer, 3, "tan")){
                            pilhaTemporaria->inserir( ope = ( new expre::tan() ) );
                            percorrer += 3;
                        }else if(!expressao.compare(percorrer, 3, "log")){
                            pilhaTemporaria->inserir( ope = ( new expre::log() ) );
                            percorrer += 3;
                        }
                break;
                }
            }
            
            if(quant >= 2){
                pilhaFinal->inserir(pilhaTemporaria->retirarTopo());
                quant = 1;
            }
        }

        while(pilhaTemporaria->naoEstaVazio()){
            pilhaFinal->inserir(pilhaTemporaria->retirarTopo());
        }

        return pilhaFinal;
    }

    expre::expre* construirArvore (pilha *expressaoPoIn) {
        noPilha *lido = NULL, aux;
        std::vector<expre::expre*> nosLidos;

        while(expressaoPoIn->naoEstaVazio()){
            lido = expressaoPoIn->retirarBase();

            switch(lido->val->tipo){
                case BINARIA:
                    ((expre::binario*)lido->val)->inserirDir(nosLidos.back());
                    nosLidos.pop_back();

                    ((expre::binario*)lido->val)->inserirEsq(nosLidos.back());
                    nosLidos.pop_back();

                    nosLidos.push_back(lido->val);
                break;
                case UNARIA:
                    ((expre::unario*)lido->val)->inserirFilho(nosLidos.back());
                    nosLidos.pop_back();

                    nosLidos.push_back(lido->val);
                break;
                default:
                    nosLidos.push_back(lido->val);
                break;

                free(lido);
            }
        }

        return nosLidos.back();
    }
}

int main () {
    std::string t = "1+2*3+x";
    parser::pilha *p = parser::contruirPilha(t);
    parser::noPilha *aux = p->base;
    expre::expre *arvo = construirArvore(p);

    std::cout << arvo->calcular(1) << '\n';

    return 0;
}

#endif //PARSER_H