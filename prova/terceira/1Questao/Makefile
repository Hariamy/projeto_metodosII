OBJ = Objects/
PVI = ../../../controlador/valorInicial/
EXE = main
CXX = g++

all: obj $(OBJ)valorInicial main
	@echo COMPILADO COM SUCESSO!
obj:
	if test ! -d Objects; then mkdir Objects; fi

$(OBJ)valorInicial: $(PVI)valorInicial.cpp $(PVI)valorInicial.h
	$(CXX) -c $< -o $@

$(EXE): main.cpp $(OBJ)valorInicial -lm 
	$(CXX) $^ -o $@

clean:
	rm -f $(EXE) $(OBJ)*
