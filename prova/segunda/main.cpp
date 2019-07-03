#include <iostream>
#include "../../controlador/autoVetorValor/similaridade.h"
#include "../../controlador/autoVetorValor/metodos.h"

using namespace std;

int escolha = 0;

void menu() {
	cout << "\nMENU 2ª PROVA" << endl;
	cout << "Digite 1 para a 1ª Questão" << endl;
	cout << "Digite 2 para a 2ª Questão" << endl;
	cout << "Digite 3 para a 3ª Questão" << endl;
	cout << "Digite 0 para sair" << endl;
	cout << "> ";
	cin >> escolha;
}

int main (){
	IOFormat formato(4, 0, "  ", "\n", "│", "│");

	int A = 3, 
		B = 9, 
		C = 7, 
		D = 6, 
		E = 1, 
		F = 3;

	MatrixXd MA(5, 5);
	MA <<
	 		30 + A + F, 	 A,	   		 B, 	  C, 	   D,
		 		 A,		10 + B + E, 	 E, 	  F, 	 A + B,
		 		 B, 		 E, 	50 + C + D, B + C, 	 C + D,
		 		 C,			 F,		   B + C, 	40 - A,  D + E,
				 D,		   A + B,	   C + D,	D + E, 	 60 - B;

	int n = MA.rows();
	
	//Erros
	double erro = 0.0001;
	double erroF = 0.0001;

	// 1ª QUESTÃO
	matriz MA1(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			MA1.posicao(i, j) = MA(i, j);
		}
	}
	autoValVet *respoMaior;
	autoValVet *respoMenor;

	// 2ª QUESTÃO
	MatrixXd AAt(n, n);
	MatrixXd AAtH(n, n);
	MatrixXd AAtTD(n, n);
	MatrixXd valorAAt(n, n);
	MatrixXd vetorAAt(n, n);

	MatrixXd AtA(n, n);
	MatrixXd AtAH(n, n);
	MatrixXd AtATD(n, n);
	MatrixXd valorAtA(n, n);
	MatrixXd vetorAtA(n, n);

	MatrixXd Sigma(n, n);
	MatrixXd aux(n, n);


	// 3ª QUESTÃO
	MatrixXd MA3(3, 5);
	MA3 <<
	 		30 + A + F, 	 A, 		 B,		  C, 	 D,
		 		 A, 	10 + B + E, 	 E,		  F,   A + B,
		 		 B,			 E, 	50 + C + D, B + C, C + D;

	MatrixXd AAt3(3, 3);
	MatrixXd AAtH3(3, 3);
	MatrixXd AAtTD3(3, 3);
	MatrixXd valorAAt3(3, 3);
	MatrixXd vetorAAt3(3, 3);

	MatrixXd AtA3(5, 5);
	MatrixXd AtAH3(5, 5);
	MatrixXd AtATD3(5, 5);
	MatrixXd valorAtA3(5, 5);
	MatrixXd vetorAtA3(5, 5);

	MatrixXd Sigma3(3, 5);
	MatrixXd aux3(5, 5);

	bool JacobiAAt, JacobiAtA;
	menu();
	
	while (escolha != 0) {
		switch (escolha) {
			case 1:
				respoMaior = potencia(MA1, erroF);
				respoMenor = potenciaInversa(MA1, erroF);

				cout <<"\n1ª QUESTÃO\n\n";
				std::cout << "\nMAIOR AUTOVALOR DE A: " << respoMaior->autoValor << endl;
				std::cout << "\nMENOR AUTOVALOR DE A: " << respoMenor->autoValor << endl;
				std::cout << "\nk(A) = " << respoMaior->autoValor/respoMenor->autoValor << "\n\n";

			break;

			case 2:
				// Metodo de Jacobi
				
				AAt = MA*MA.transpose();
				tie(AAtTD, AAtH) = Householder(AAt);
				tie(valorAAt, vetorAAt) = Jacobi(AAtTD, erro, AAtH);

				around(AAtTD);
				around(AAtH);
				around(valorAAt);
				around(vetorAAt);

				ordenar(valorAAt, vetorAAt);

				cout <<"\n2ª QUESTÃO \n\n";
				cout << "MATRIZ M:\n" 			<< MA.format(formato) 	<< "\n\n";
				cout <<"\nDESCOBRINDO U POR JACOBI\n\n";
				cout << "MATRIZ A * At:\n" 		<< AAt.format(formato) 	<< "\n\n";
				cout << "MATRIZ AUTOVALORES:\n" << valorAAt.format(formato) << "\n\n";
				cout << "MATRIZ AUTOVETORES:\n" << vetorAAt.format(formato) << "\n\n";


				// Metodo QR
				
				AtA = MA.transpose()*MA;
				tie(AtATD, AtAH) = Householder(AtA);
				tie(valorAtA, vetorAtA) = QR(AtATD, erro, AtAH);

				around(AtATD);
				around(AtAH);
				around(valorAtA);
				around(vetorAtA);

				ordenar(valorAtA, vetorAtA);

				cout << "\nDESCOBRINDO V POR QR\n\n";
				cout << "MATRIZ At * A:\n"		<< AtA.format(formato) 		<< "\n\n";
				cout << "MATRIZ AUTOVALORES:\n" << valorAtA.format(formato) << "\n\n";
				cout << "MATRIZ AUTOVETORES:\n" << vetorAtA.format(formato) << "\n\n";


				// RESULTADO

				Sigma = valorAAt;
			
				sqrt_diagonal(Sigma);
			
				consertaSinal(MA, vetorAtA, vetorAAt, Sigma);
				
				aux = vetorAAt * Sigma * (vetorAtA.transpose());

				around(aux);

				cout << "\nRESULTADO\n\n";
				cout << "Matriz U:\n"		<< vetorAAt.format(formato)	<< "\n\n";
				cout << "Matriz Σ:\n"		<< Sigma.format(formato) 	<< "\n\n";
				cout << "Matriz V:\n"		<< vetorAtA.format(formato)	<< "\n\n";
				cout << "Matriz A:\n"		<< MA.format(formato)		<< "\n\n";
				cout << "Matriz U*Σ*(Vt):\n"<< aux.format(formato)		<< "\n\n";

			break;

			case 3:
				// Metodo de QR
				
				AAt3 = MA3*MA3.transpose();
				tie(AAtTD3, AAtH3) = Householder(AAt3);
				tie(valorAAt3, vetorAAt3) = QR(AAtTD3, erro, AAtH3);
				JacobiAAt = false;

				around(AAtTD3);
				around(AAtH3);
				around(valorAAt3);
				around(vetorAAt3);

				cout <<"\n3ª QUESTÃO\n\n";
				cout << "MATRIZ M:\n" 			<< MA3.format(formato) 	 << "\n\n";
				cout <<"\nDESCOBRINDO U POR QR\n\n";
				cout << "MATRIZ A * At:\n" 		<< AAt3.format(formato)  << "\n\n";
				cout << "MATRIZ AUTOVALORES:\n" << valorAAt3.format(formato) << "\n\n";
				cout << "MATRIZ AUTOVETORES:\n" << vetorAAt3.format(formato) << "\n\n";	

				// Metodo Jacobi
				
				AtA3 = MA3.transpose()*MA3;

				tie(AtATD3, AtAH3) = Householder(AtA3);
				tie(valorAtA3, vetorAtA3) = Jacobi(AtATD3, erro, AtAH3);
				JacobiAtA = true;

				around(AtATD3);
				around(AtAH3);
				around(valorAtA3);
				around(vetorAtA3);

				cout << "\nDESCOBRINDO V POR JACOBI\n\n";
				cout << "MATRIZ At * A:\n"		<< AtA3.format(formato) 	<< "\n\n";
				cout << "MATRIZ AUTOVALORES:\n" << valorAtA3.format(formato)<< "\n\n";
				cout << "MATRIZ AUTOVETORES:\n" << vetorAtA3.format(formato)<< "\n\n";

				// RESULTADO
				criarSigma(Sigma3, valorAAt3);

				consertaSinal(MA3, vetorAtA3, vetorAAt3, Sigma3);

				aux3 = vetorAAt3 * Sigma3 * (vetorAtA3.transpose());
				around(aux3);

				cout << "\nRESULTADO\n\n";
				cout << "Matriz U:\n"		<< vetorAAt3.format(formato)<< "\n\n";
				cout << "Matriz Σ:\n"		<< Sigma3.format(formato) 	<< "\n\n";
				cout << "Matriz V:\n"		<< vetorAtA3.format(formato)<< "\n\n";
				cout << "Matriz A:\n"		<< MA3.format(formato)		<< "\n\n";
				cout << "Matriz U*Σ*(Vt):\n"<< aux3.format(formato)		<< "\n\n";

			break;

			default: cout << "\nEscolha inválida\n"; break;
		}
		cout << "> ";
		cin >> escolha;
	}
	
	return 0;
}