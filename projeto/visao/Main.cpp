#include "../controlador/Controlador.h"

#include <iostream>
#include <cstdio>

using namespace std;

int main(int argc, char const *argv[]) {
	Controlador *cont = new Controlador();

	cout << cont->integralNewtonGatesErro(1, 1, 4, 1, 1, 1) << endl;
	cout << cont->integralNewtonGatesPartes(1, 1, 4, 1, 1, 1) << endl;
	return 0;
}