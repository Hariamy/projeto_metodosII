OBJ = Objects/
PAR = ../../controlador/parser/
INTE = ../../controlador/integrais/
EXE = main
CXX = g++

all: obj $(OBJ)integralGauss  $(OBJ)integralNewtonCotes $(OBJ)parser $(OBJ)expre $(OBJ)binario $(OBJ)exponenciacao $(OBJ)unario main
	@echo completo!!!!
obj:
	if test ! -d Objects; then mkdir Objects; fi

$(OBJ)integralNewtonCotes: $(INTE)integralNewtonCotes.cpp $(INTE)integrais.h
	$(CXX) -c $< -o $@ -lm -w

$(OBJ)integralGauss: $(INTE)integralGauss.cpp $(INTE)integrais.h
	$(CXX) -c $< -o $@ -lm -w

$(OBJ)parser: $(PAR)parser.cpp $(PAR)parser.h
	$(CXX) -c $< -o $@ -lm -w

$(OBJ)expre: $(PAR)expre.cpp $(PAR)expre.h
	$(CXX) -c $< -o $@ -lm -w

$(OBJ)binario: $(PAR)binario.cpp $(PAR)binario.h
	$(CXX) -c $< -o $@ -lm -w

$(OBJ)exponenciacao: $(INTE)exponenciacao.cpp $(INTE)exponenciacao.h
	$(CXX) -c $< -o $@ -lm -w

$(OBJ)unario: $(PAR)unario.cpp $(PAR)unario.h
	$(CXX) -c $< -o $@ -lm -w

$(EXE): main.cpp $(OBJ)integralGauss $(OBJ)integralNewtonCotes $(OBJ)parser $(OBJ)expre $(OBJ)exponenciacao $(OBJ)unario $(OBJ)binario
	$(CXX) $^ -o $@ -lm -w

clean:
	rm -f $(EXE) $(OBJ)*
