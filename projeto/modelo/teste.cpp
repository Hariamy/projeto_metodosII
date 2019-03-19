#include <cmath>

#include "Generica.h"
#include "Seno.h"
#include "Cosseno.h"
#include "Polinomio.h"
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	Funcao *gen = new Generica();
	cout << gen->calcula(1) << endl;
	Funcao *s = new Seno();
	cout << s->calcula(1) << endl;

	Funcao *c = new Cosseno();
	cout << c->calcula(1) << endl;

	Funcao *p = new Polinomio(4);
	cout << p->calcula(1) << endl;
	return 0;
}