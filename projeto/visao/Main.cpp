#include "../controlador/Controlador.h"

#include <iostream>
#include <cstdio>

using namespace std;

int main(int argc, char const *argv[]) {
	Controlador *cont = new Controlador();

	//integralNewtonCotes( filosofia, grau, funcao,  Xi,  Xf,  erro)
	cout << cont->integralNewtonCotes(1, 1, 2, 0, 1.57080, 1) << endl;
	cout << cont->integralNewtonCotes(1, 2, 2, 0, 1.57080, 1) << endl;
	//cout << cont->integralNewtonCotes(1, 1, 2, 0, 1.57080, 1) << endl;
	return 0;
}