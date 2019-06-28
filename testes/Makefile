OBJ = Objects/
MOD = ../modelo/
AUTO = ../controlador/autoVetorValor/
EXE = teste
CXX = g++

all: obj $(OBJ)algebra $(OBJ)matriz $(OBJ)vetor $(OBJ)funcoesMetodos $(OBJ)sigularidade teste
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

$(OBJ)sigularidade: $(AUTO)sigularidade.cpp $(AUTO)sigularidade.h -lm
	$(CXX) -c $< -o $@

$(EXE): testeHouseHolder.cpp $(OBJ)algebra $(OBJ)matriz $(OBJ)vetor $(OBJ)funcoesMetodos $(OBJ)sigularidade -lm
	$(CXX) $^ -o $@

clean:
	rm -f $(EXE) $(OBJ)*
