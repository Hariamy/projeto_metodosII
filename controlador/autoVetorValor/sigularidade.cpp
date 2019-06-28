#include "sigularidade.h"

int sinal(float &x) {
	if (x >= 0) return 1;
	else return -1;
}

matriz * montagemHH(matriz &Ab, int i) {
	int n = Ab.tam;
	vetor *v = new vetor(n), *N;
	for (int j = i + 1; j < n; ++j) {
		v[j] = Ab.posicao(j, i);
	}

	float lv = v->tamanho();
	vetor *vl = new vetor(n);

	vl[i+1] = lv * sinal((*v)[i+1]);

	N = (*v) - (*vl);

	N->unitario();
	matriz *I = new matriz(n, IDENTIDADE);

	matriz *NN = prodExtern(*N, *N), * Hc;
	*NN * 2;
	Hc = *I - *NN;

	return Hc;
}


retornoHH * householder (matriz &A){
	retornoHH * retorno;

	int n = A.tam;
	
	matriz * H = new matriz(n, IDENTIDADE);
	matriz * Ab = new matriz(n);
	
	*Ab = A;

	matriz * Hc;
	for (int i = 0; i < n-2; ++i) {
		Hc = montagemHH((*Ab), i);
		Ab = (*Ab) * (*Hc);
		Ab = (*Hc) * (*Ab);
		H = (*H) * (*Hc);
	}

	retorno = new retornoHH(Ab, H);
}

