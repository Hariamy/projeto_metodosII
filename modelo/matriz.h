#ifndef MATRIZ_H
#define MATRIZ_H

#include "vetor.h"

#define IDENTIDADE 0
#define ZEROS      1
#define UMS        2
	
class matriz{
public:
	int     tam;
	std::vector <float> *valores;

	matriz      (int novoTam, int tipo = ZEROS);

	void redimensionar(int novoTam);
		
	float&  posicao (int x, int y);
	void    operator =  (matriz &mat2);
	void    operator +  (float constante);
	matriz* operator +  (matriz &mat2);
	void    operator -  (float constante);
	matriz* operator -  (matriz &mat2);
	void    operator *  (float constante);
	matriz* operator *  (matriz &mat2);
	vetor*  operator *  (vetor &vet2);

	void transposta ();

	void mostrar_debug ();
};

void identidade   (int tam, std::vector <float> &valores);
void zeros        (int tam, std::vector <float> &valores);
void ums          (int tam, std::vector <float> &valores);
void copiarMatriz (std::vector <float> &copiada, std::vector <float> &copiadora);

#endif //MATRIZ_H