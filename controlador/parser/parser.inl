#include "parser.h"

void pilha::init () {
    tam = 0;
    base = NULL;
    topo = NULL;
}

void pilha::inserir (expre::expre *no, int precedencia) {
    noPilha *novo = (noPilha*)malloc(sizeof(noPilha));
        
    novo->val = no;
    novo->precedencia = precedencia;
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
    int quant = 0, inicio = percorrer, tam = expressao.size();
        
    while((percorrer < tam) && (expressao[percorrer] >= '0' && expressao[percorrer] <= '9')
          || expressao[percorrer] == '.'){
        quant++;
        percorrer++;
    }

    return atof(expressao.substr(inicio, quant).data());
}

pilha* construirPilha (std::string &expressao) {
    pilha *pilhaTemporaria = (pilha*)malloc(sizeof(pilha)),
          *pilhaFinal = (pilha*)malloc(sizeof(pilha));
    noPilha *auxTrans = NULL;
    int percorrer = 0, tam = expressao.size();
    expre::expre *ope;

    pilhaTemporaria->init();
    pilhaFinal->init();
        
    while(percorrer < tam){
        if(expressao[percorrer] >= '0' && expressao[percorrer] <= '9'){
            pilhaFinal->inserir( ope = ( new expre::constante( lerConstante (expressao, percorrer) ) ) );
        }else{
            switch (expressao[percorrer]){
            case '+':
                pilhaTemporaria->inserir( ope = ( new expre::soma() ), 0 );
                percorrer++;
            break;
            case '-':
                pilhaTemporaria->inserir( ope = ( new expre::subtracao() ), 0 );
                percorrer++;
            break;
            case '*':
                pilhaTemporaria->inserir( ope = ( new expre::multiplicacao() ), 1 );
                percorrer++;
            break;
            case '/':
                pilhaTemporaria->inserir( ope = ( new expre::divisao() ), 1 );
                percorrer++;
            break;
            case '^':
                pilhaTemporaria->inserir( ope = ( new expre::potencia() ), 1 );
                percorrer++;
            break;
            case 'x':
                pilhaFinal->inserir( ope = ( new expre::variavel() ) );
                percorrer++;
            break;
            case '(':
                pilhaTemporaria->inserir( NULL, -1 );
                percorrer++;
            break;
            case ')':
                while(pilhaTemporaria->topo->precedencia != -1){
                    pilhaFinal->inserir(pilhaTemporaria->retirarTopo());
                }

                free(pilhaTemporaria->retirarTopo());
                percorrer++;
            break;
            default:
                if(!expressao.compare(percorrer, 3, "sen")){
                        pilhaTemporaria->inserir( ope = ( new expre::sen() ), 1 );
                        percorrer += 3;
                    }else if(!expressao.compare(percorrer, 3, "cos")){
                        pilhaTemporaria->inserir( ope = ( new expre::cos() ), 1 );
                        percorrer += 3;
                    }else if(!expressao.compare(percorrer, 3, "tan")){
                        pilhaTemporaria->inserir( ope = ( new expre::tan() ), 1 );
                        percorrer += 3;
                    }else if(!expressao.compare(percorrer, 3, "log")){
                        pilhaTemporaria->inserir( ope = ( new expre::log() ), 1 );
                        percorrer += 3;
                    }
            break;
            }
        }
            
        if(pilhaTemporaria->topo != NULL && pilhaTemporaria->topo->ant != NULL
           && (pilhaTemporaria->topo->precedencia < pilhaTemporaria->topo->ant->precedencia)
           && pilhaTemporaria->topo->precedencia > -1){
            auxTrans = pilhaTemporaria->retirarTopo();
                
            while(pilhaTemporaria->topo != NULL &&
                 (auxTrans->precedencia < pilhaTemporaria->topo->precedencia)){
                pilhaFinal->inserir(pilhaTemporaria->retirarTopo());
            }

            pilhaTemporaria->inserir(auxTrans);
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

expre::expre* parser (std::string &expressao) {
    pilha *novaPilha;
    expre::expre *arvore;

    novaPilha = construirPilha(expressao);
    arvore = construirArvore(novaPilha);

    free(novaPilha);

    return arvore;
}