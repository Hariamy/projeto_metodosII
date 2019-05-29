#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <iostream>
#include <vector>
#include "expre.h"
#include "unario.h"
#include "binario.h"

struct noPilha {
    expre::expre *val;
    struct noPilha *ant, *prox;
    int precedencia;
};

struct pilha {
    noPilha *base, *topo;
    int tam;

    inline void init ();

    inline void inserir (expre::expre *no, int precedencia = 0);
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
inline pilha* construirPilha (std::string &expressao);
inline expre::expre* construirArvore (pilha *expressaoPoIn);
inline expre::expre* parser (std::string &expressao);

#include "parser.inl"

#endif //PARSER_H