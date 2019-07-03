#include <iostream>
#include "../../controlador/autoVetorValor/similaridade.h"
#include "../../controlador/autoVetorValor/metodos.h"

using namespace std;

int A = 3, 
	B = 9, 
	C = 7, 
	D = 6, 
	E = 1, 
	F = 3;

int main (){
	IOFormat formato(4, 0, "  ", "\n", "│", "│");
	
	A = 4;
	B = 0;
	C = 0;
	D = 1;
	E = 1;
	F = 4;

	MatrixXd MA(5, 5);

	MA <<
	 		30 + A + F, 	 A,	   		 B, 	  C, 	   D,
		 		 A,		10 + B + E, 	 E, 	  F, 	 A + B,
		 		 B, 		 E, 	50 + C + D, B + C, 	 C + D,
		 		 C,			 F,		   B + C, 	40 - A,  D + E,
				 D,		   A + B,	   C + D,	D + E, 	 60 - B;


	int n = MA.rows();
	
	// ERROS
	double erro = 0.00001;

	// PARA OS CÁLCULOS DE POTÊNCA
	matriz MA1(n);
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < n; j++) 
			MA1.posicao(i, j) = MA(i, j);
		
	autoValVet *respoMaior;
	autoValVet *respoMenor;
	autoValVet *respoDesloc;
	double chute = 20.0;

	respoMaior = potencia(MA1, erro);
	respoMenor = potenciaInversa(MA1, erro);
	respoDesloc = potenciaDeslocamento(MA1, chute, erro);
	
	MatrixXd MAD(n, n);
	MatrixXd MAH(n, n);
	MatrixXd valorMAJ(n, n);
	MatrixXd vetorMAJ(n, n);
	MatrixXd valorMAQR(n, n);
	MatrixXd vetorMAQR(n, n);

	tie(MAD, MAH) = Householder(MA);
	tie(valorMAJ, vetorMAJ) = Jacobi(MAD, erro, MAH);
	tie(MAD, MAH) = Householder(MA);
	tie(valorMAQR, vetorMAQR) = QR(MAD, erro, MAH);

	around(MA);
	around(valorMAJ);
	around(vetorMAJ);
	around(valorMAQR);
	around(vetorMAQR);
		
	respoMaior->autoVetor->unitario ();
	respoMenor->autoVetor->unitario ();
	respoDesloc->autoVetor->unitario ();

	cout << "MATRIZ A:\n" 			<< MA.format(formato) 	<< "\n\n";
	cout << "MAIOR AUTOVALOR DE A: " << respoMaior->autoValor << "\n";
	cout << "AUTOVETOR ASSOCIADO AO MAIOR AUTOVALOR DE A: "; respoMaior->autoVetor->mostrar_debug(); cout << "\n\n";

	cout << "MENOR AUTOVALOR DE A: " << respoMenor->autoValor << "\n";
	cout << "AUTOVETOR ASSOCIADO AO MENOR AUTOVALOR DE A: "; respoMenor->autoVetor->mostrar_debug(); cout << "\n\n";
	
	cout << "AUTOVALOR DE A COM DESLOCAMENTO " << chute << ": " << respoDesloc->autoValor << "\n";
	cout << "AUTOVETOR ASSOCIADO AO DESLOCAMENTO DE A: "; respoDesloc->autoVetor->mostrar_debug(); cout << "\n\n";
	
	cout << "MATRIZ AUTOVALORES DE A POR JACOBI:\n" << valorMAJ.format(formato) << "\n\n";
	cout << "MATRIZ AUTOVETORES DE A POR JACOBI:\n" << vetorMAJ.format(formato) << "\n\n";
	cout << "MATRIZ AUTOVALORES DE A POR QR:\n" << valorMAQR.format(formato) << "\n\n";
	cout << "MATRIZ AUTOVETORES DE A POR QR:\n" << vetorMAQR.format(formato) << "\n\n";
	
	
	return 0;
}