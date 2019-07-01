#include "parser.h"

/*! Analiza se a expressão está corretamente estruturada
** Parâmetros: A expressão em string
** Retornos: true se estiver corretamente estruturada e false se não
*/
/*bool analisador (std::string &expressao) {
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
}*/

/*! Função que lê um número que está em uma string e retorna seu valor numérico
** Parâmetros: A string e a primeira posição do número na string
** Retornos: O número lido
*/
double lerConstante (std::string &expressao, int &percorrer) {
  int quant = 0, inicio = percorrer, tam = expressao.size();
        
  while(((percorrer < tam) && ((expressao[percorrer] >= '0') && (expressao[percorrer] <= '9')))
        || (expressao[percorrer] == '.')){
    quant++;
    percorrer++;
  }

  return atof(expressao.substr(inicio, quant).data());
}

/*! Função que lê uma expressão matemática e transforma para sua versão polonesa inversa
** Parâmetros: A expressão matemática
** Retornos: Sua versão polonesa inversa
*/
std::queue <expre::expre*>* construirFila (std::string &expressao) {
  std::stack <expre::expre*> pilhaTemp;
  std::queue <expre::expre*> *filaFinal = new std::queue <expre::expre*>;
  expre::expre *ope;
  int percorrer = 0, tam = expressao.size();
        
  while(percorrer < tam){
    if(expressao[percorrer] >= '0' && expressao[percorrer] <= '9'){
      filaFinal->push( new expre::constante( lerConstante (expressao, percorrer) ) );
      ope = NULL;
      continue;
    }else{
      switch (expressao[percorrer]){
        case ' ':
          percorrer++;
          continue;
        break;
        case '+':
          ope = new expre::soma();
          percorrer++;
        break;
        case '-':
          /*if((pilhaTemp.empty()) && (pilhaTemp.top() != NULL)){
            filaFinal->push( new expre::constante(0.0) );
          }*/

          ope = new expre::subtracao();
          percorrer++;
        break;
        case '*':
          ope = new expre::multiplicacao();
          percorrer++;
        break;
        case '/':
          ope =new expre::divisao();
          percorrer++;
        break;
        case '^':
          ope = new expre::potencia();
          percorrer++;
        break;
        case 'e':
          ope = new expre::exp();
          percorrer++;
        break;
        case 'x':
          filaFinal->push(new expre::variavel());
          ope = NULL;
          percorrer++;
          continue;
        break;
        case '(':
          ope = NULL;
          percorrer++;
        break;
        case ')':
          while(pilhaTemp.top() != NULL){
            filaFinal->push(pilhaTemp.top());
            pilhaTemp.pop();
          }
          pilhaTemp.pop();

          percorrer++;
          ope = NULL;
          continue;
        break;
        default:
          if(!expressao.compare(percorrer, 3, "sen")){
            ope = new expre::sen();
            percorrer += 3;
          }else if(!expressao.compare(percorrer, 3, "cos")){
            ope = new expre::cos();
            percorrer += 3;
          }else if(!expressao.compare(percorrer, 3, "tan")){
            ope = new expre::tan();
            percorrer += 3;
          }else if(!expressao.compare(percorrer, 3, "log")){
            ope = new expre::log();
            percorrer += 3;
          }
        break;
      }
    }
            
    if(ope != NULL){
      while(!(pilhaTemp.empty()) && (pilhaTemp.top() != NULL) && (pilhaTemp.top()->precedencia > ope->precedencia)){
        filaFinal->push(pilhaTemp.top());
        pilhaTemp.pop();
      }
    }
      
    pilhaTemp.push(ope);
  }

  while(!(pilhaTemp.empty())){
    filaFinal->push(pilhaTemp.top());
    pilhaTemp.pop();
  }

  return filaFinal;
}

/*! Recebe uma expressão matemática na polonesa inversa e retorna sua expressão normal
** Parâmetros: A expressão na polonesa inversa
** Retornos: A expressão normal
*/
expre::expre* construirArvore (std::queue <expre::expre*> *expressaoPoIn) {
  expre::expre *lido;
  std::stack<expre::expre*> nosLidos;
  
  while(!(expressaoPoIn->empty())){
    lido = expressaoPoIn->front();
    
    switch(lido->tipo){
      case expre::BINARIA:
        ((expre::binario*)lido)->inserirEsq(nosLidos.top());
        nosLidos.pop();

        ((expre::binario*)lido)->inserirDir(nosLidos.top());
        nosLidos.pop();

        nosLidos.push(lido);
      break;
      case expre::UNARIA:
        ((expre::unario*)lido)->inserirFilho(nosLidos.top());
        nosLidos.pop();

        nosLidos.push(lido);
      break;
      default:
        
        nosLidos.push(lido);
        
      break;
    }
    
    expressaoPoIn->pop();
    
  }
  
  return nosLidos.top();
}

/*! Controi uma árvore a partir de uma expressão matemática
** Parâmetros: A expressão matemática
** Retornos: A árvore da expressão
*/
expre::expre* parser (std::string &expressao) {
  std::queue <expre::expre*> *fila;
  expre::expre *arvore;

  fila = construirFila(expressao);
  arvore = construirArvore(fila);

  delete(fila);
  
  return arvore;
}