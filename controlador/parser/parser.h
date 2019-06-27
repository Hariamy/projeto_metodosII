#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <vector>
#include <stack>
#include <queue>
#include "unario.h"
#include "binario.h"

inline bool analisador (std::string &expressao);

inline float lerConstante (std::string &expressao, int &percorrer); 
inline std::queue <expre::expre*>* construirFila (std::string &expressao);
inline expre::expre* construirArvore (std::queue <expre::expre*> *expressaoPoIn);
inline expre::expre* parser (std::string &expressao);

#include "parser.inl"

#endif //PARSER_H