#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <vector>
#include <stack>
#include <queue>
#include "unario.h"
#include "binario.h"

bool analisador (std::string &expressao);

float lerConstante (std::string &expressao, int &percorrer); 
std::queue <expre::expre*>* construirFila (std::string &expressao);
expre::expre* construirArvore (std::queue <expre::expre*> *expressaoPoIn);
expre::expre* parser (std::string &expressao);

#endif //PARSER_H