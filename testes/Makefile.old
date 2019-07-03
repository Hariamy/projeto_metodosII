OBJ = Objects/
PAR = ../controlador/parser/
INTE = ../controlador/integrais/
EXE = teste
CXX = g++

all: obj $(OBJ)integralGaussChebyshev $(OBJ)parser $(OBJ)expre $(OBJ)binario $(OBJ)unario teste
	@echo completo!!!!
obj:
	if test ! -d Objects; then mkdir Objects; fi

$(OBJ)integralGaussChebyshev: $(INTE)integralGaussChebyshev.cpp $(INTE)integralGaussChebyshev.h
	$(CXX) -c $< -o $@ -lm

$(OBJ)parser: $(PAR)parser.cpp $(PAR)parser.h
	$(CXX) -c $< -o $@ -lm

$(OBJ)expre: $(PAR)expre.cpp $(PAR)expre.h
	$(CXX) -c $< -o $@ -lm

$(OBJ)binario: $(PAR)binario.cpp $(PAR)binario.h
	$(CXX) -c $< -o $@ -lm

$(OBJ)unario: $(PAR)unario.cpp $(PAR)unario.h
	$(CXX) -c $< -o $@ -lm

$(EXE): testeIntegral.cpp $(OBJ)integralGaussChebyshev $(OBJ)parser $(OBJ)expre $(OBJ)binario $(OBJ)unario
	$(CXX) $^ -o $@ -lm

clean:
	rm -f $(EXE) $(OBJ)*
