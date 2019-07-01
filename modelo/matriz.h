#ifndef MATRIZ_H
#define MATRIZ_H

#include "vetor.h"

#define IDENTIDADE 0
#define ZEROS      1
#define UMS        2
	
class matriz{
public:
	int     tam;
	std::vector <double> *valores;

	matriz      (int novoTam, int tipo = ZEROS);

	void redimensionar(int novoTam);
		
	double&  posicao (int x, int y);
	void    operator =  (matriz &mat2);
	void    operator +  (double constante);
	matriz* operator +  (matriz &mat2);
	void    operator -  (double constante);
	matriz* operator -  (matriz &mat2);
	void    operator *  (double constante);
	matriz* operator *  (matriz &mat2);
	vetor*  operator *  (vetor &vet2);

	void transposta ();

	void mostrar_debug ();
};

void identidade   (int tam, std::vector <double> &valores);
void zeros        (int tam, std::vector <double> &valores);
void ums          (int tam, std::vector <double> &valores);
void copiarMatriz (std::vector <double> &copiada, std::vector <double> &copiadora);

#endif //MATRIZ_H