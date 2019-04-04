CONT = controlador/
MODE = modelo/
VISA = visao/
FUNC = modelo/funcoes/

all: Funcao.o Seno.o Cosseno.o Polinomio.o Generica.o Integral.o NewtonCotes.o Controlador.o programa

Funcao.o: $(FUNC)Funcao.cpp $(FUNC)Funcao.h
	g++ -w -g -c $(FUNC)Funcao.cpp

Seno.o: $(FUNC)Seno.cpp $(FUNC)Seno.h 
	g++ -w -g -c $(FUNC)Seno.cpp

Cosseno.o: $(FUNC)Cosseno.cpp $(FUNC)Cosseno.h
	g++ -w -g -c $(FUNC)Cosseno.cpp

Polinomio.o: $(FUNC)Polinomio.cpp $(FUNC)Polinomio.h
	g++ -w -g -c $(FUNC)Polinomio.cpp

Generica.o: $(FUNC)Generica.cpp $(FUNC)Generica.h
	g++ -w -g -c $(FUNC)Generica.cpp

Integral.o: $(MODE)Integral.cpp $(MODE)Integral.h $(FUNC)Funcao.h
	g++ -w -g -c $(MODE)Integral.cpp

NewtonCotes.o: $(MODE)NewtonCotes.cpp $(MODE)NewtonCotes.h $(FUNC)Funcao.h
	g++ -w -g -c $(MODE)NewtonCotes.cpp

Controlador.o: $(CONT)Controlador.cpp $(CONT)Controlador.h $(MODE)NewtonCotes.h $(FUNC)Funcao.h $(FUNC)Seno.h $(FUNC)Cosseno.h $(FUNC)Polinomio.h $(FUNC)Generica.h
	g++ -w -g -c $(CONT)Controlador.cpp

Main.o: $(VISA)Main.cpp $(CONT)Controlador.h
	g++ -w -g -c $(VISA)Main.cpp

programa: Main.o Funcao.o Seno.o Cosseno.o Polinomio.o Generica.o Integral.o NewtonCotes.o Controlador.o
	g++ Funcao.o Seno.o Cosseno.o Polinomio.o Generica.o Integral.o NewtonCotes.o Controlador.o Main.o -o programa

clean: 
	rm *.o
	rm programa