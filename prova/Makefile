OBJ = Objects/
MOD = ../modelo/
AUTO = ../controlador/autoVetorValor/
EXE = prova2
CXX = g++

all: obj $(OBJ)algebra $(OBJ)matriz $(OBJ)vetor $(OBJ)funcoesMetodos $(OBJ)similaridade prova2
	@echo completo!!!!
obj:
	if test ! -d Objects; then mkdir Objects; fi

$(OBJ)algebra: $(MOD)algebra.cpp $(MOD)algebra.h
	$(CXX) -c $< -o $@

$(OBJ)matriz: $(MOD)matriz.cpp $(MOD)matriz.h
	$(CXX) -c $< -o $@

$(OBJ)vetor: $(MOD)vetor.cpp $(MOD)vetor.h
	$(CXX) -c $< -o $@

$(OBJ)funcoesMetodos: $(AUTO)funcoesMetodos.cpp $(AUTO)metodos.h
	$(CXX) -c $< -o $@

$(OBJ)similaridade: $(AUTO)similaridade.cpp $(AUTO)similaridade.h -lm 
	$(CXX) -c $< -o $@ -I eigen

$(EXE): prova2.cpp $(OBJ)algebra $(OBJ)matriz $(OBJ)vetor $(OBJ)funcoesMetodos $(OBJ)similaridade -lm 
	$(CXX) $^ -o $@

clean:
	rm -f $(EXE) $(OBJ)*
