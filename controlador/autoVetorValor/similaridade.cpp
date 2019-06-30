#include "similaridade.h"

// pARA OS PRINTS
#include <iostream>
using namespace std;

int MAX_INTERATION = 2000;

int sinal(float &x) {
	if (x >= 0) return 1;
	else return -1;
}

// -------------- \\ INÍCIO - FUNÇÕES PARA HOUSEHOLDER // -------------- \\

MatrixXd MontagemHH(Ref<MatrixXd> A, int c) {
	
	int n = A.rows();

	VectorXd v(n);
	v = zeros(n);

	for (int i = c+1; i < n; i++) v(i) = A(i,c);
	
	double lv = v.norm();

	if (v(c+1) > 0) lv = -1*lv;

	VectorXd vl(n);
	vl = zeros(n);

	vl(c+1) = lv;

	VectorXd N(n);
	N = v - vl;

  	VectorXd vn(n);
  	vn = N/N.norm();

	MatrixXd I(n, n);
	I = MatrixXd::Identity(n, n);

	MatrixXd H(n, n);
	H = I - 2*vn*vn.transpose();

	return H;
}


tuple<MatrixXd, MatrixXd> Householder(Ref<MatrixXd> A){
	
	int n = A.rows();

	MatrixXd Ab(n, n);
	Ab = A;

	MatrixXd H(n, n);
	H = MatrixXd::Identity(n, n);

	MatrixXd Hc(n, n);

	for (int c = 0; c < n-2; c++) {	
		Hc = MontagemHH(Ab, c);
		Ab = Hc * Ab * Hc;
		H = H * Hc; 
	}

	return make_tuple(Ab, H);
}

// -------------- \\ FIM - FUNÇÕES PARA HOUSEHOLDER // -------------- \\


// -------------- \\ INÍCIO - FUNÇÕES PARA JACOBI // -------------- \\

MatrixXd MontagemJ(Ref<MatrixXd> A, int i, int j){
  	int n  = A.rows();

	MatrixXd Pij(n, n);
	Pij = MatrixXd::Identity(n, n);

	double t_aux = (0.5*atan( 2*A(i,j) / (A(j,j)-A(i,i)) ));
	double teta = (fabs( A(j,j) ) - fabs(A(i,i) ) < 0.000001) ? (M_PI/4) : t_aux;
	
	Pij(i, i) = cos(teta);
	Pij(j, j) = cos(teta);
	Pij(i, j) = sin(teta);
	Pij(j, i) = -sin(teta);
	
	return Pij;

}

tuple<MatrixXd, MatrixXd> Jacobi(Ref<MatrixXd> A, double e, Ref<MatrixXd> H){

	int n = A.rows();

	MatrixXd Pij(n, n);
	MatrixXd J(n, n);
	MatrixXd P(n, n);
	
	J = H;

	int i = 0;

	while(error(A) > e && i < MAX_INTERATION) {
		P = MatrixXd::Identity(n, n);

		for (int j = 0; j < n-1; j++){

			for (int i = j+1; i < n; i++){

				Pij = MontagemJ(A, i, j);
				A = Pij.transpose() * A * Pij;
				P = P * Pij;
			}
		}

		J = J*P;
		i++;
	}

	return make_tuple(A, J);

}

// -------------- \\ FIM - FUNÇÕES PARA JACOBI // -------------- \\


// -------------- \\ INÍCIO - FUNÇÕES PARA QR // -------------- \\

MatrixXd MontagemQR(Ref<MatrixXd> A, int i, int j){
  	int n  = A.rows();

	MatrixXd Pijt(n, n);
	Pijt = MatrixXd::Identity(n, n);

	double t_aux = atan(A(i,j)/A(j,j));
	double teta = (fabs(A(j,j)) < 0.000001) ? (M_PI/4) : t_aux;
	
	Pijt(i, i) = cos(teta);
	Pijt(j, j) = cos(teta);
	Pijt(i, j) = -sin(teta);
	Pijt(j, i) = sin(teta);
	
	return Pijt;
}

tuple<MatrixXd, MatrixXd> DecomporQR(Ref<MatrixXd> A){

	int n = A.rows();

	MatrixXd Pt(n, n);
	MatrixXd Qt(n, n);

	Qt = MatrixXd::Identity(n, n);

	for (int j = 0; j < n-1; j++){
		for (int i = (j+1); i < n; i++){
			
			Pt = MontagemQR(A, i, j);
			
			A  = Pt * A;
			Qt = Pt * Qt;
		}
	}

	return make_tuple(Qt.transpose(), A);
}


tuple<MatrixXd, MatrixXd> QR(Ref<MatrixXd> A, double E, Ref<MatrixXd> H){
	
	int n = A.rows();

	MatrixXd Q(n, n);
	MatrixXd R(n, n);
	MatrixXd P(n, n);

	P = H;
	
	int i = 0;

	while (error(A) > E and i < MAX_INTERATION){
		
		tie(Q, R) = DecomporQR(A);
		
		A = R * Q;
		P = P * Q;
		
		i++;
	}

	return make_tuple(A, P);
}


// -------------- \\ FIM - FUNÇÕES PARA QR // -------------- \\

// -------------- \\ INÍCIO - FUNÇÕES AUXILIARES // -------------- \\

//Verifica o erro
double error(Ref<MatrixXd> A){
	double soma = 0;
	for (int i = 0; i < A.rows(); ++i)
		for (int j = 0; j < A.cols(); ++j)
			if(i!=j) soma += pow(A(i,j),2);
	return sqrt(soma);
}


//Cria Vetor de Zeros
VectorXd zeros(int size){
	VectorXd v(size);
	for (int i = 0; i < size; i++)
	{
		v(i) = 0;
	}
	return v;
}


//Aredonda Valores de uma Matriz 
void around(Ref<MatrixXd> Matriz, bool allElements){

	for (int i = 0; i < Matriz.rows(); i++){
		for(int j = 0; j < Matriz.cols(); j++){
			
			if (fabs(Matriz(i,j)) < 0.000001 or allElements) Matriz(i,j) = round(Matriz(i,j));

			if (Matriz(i, j) == -0) Matriz(i, j) = 0;


		}
	}
}

//Ordena os Autovetores em Relação aos Autovalores em Ordem Decrescente 
void ordenar(Ref<MatrixXd> Matriz_Valor, Ref<MatrixXd> Matriz_Vetor){

	int rows = Matriz_Valor.rows();
	int cols = Matriz_Valor.cols();

	VectorXd vetor_diagonal(rows);
	VectorXd vetor_indice(rows);
	MatrixXd EigenValueMatriz(rows,cols);
	MatrixXd EigenVectorMatriz(rows,cols);
	

	for (int i = 0; i < rows; ++i){
		vetor_diagonal(i) = Matriz_Valor(i,i);
		vetor_indice(i) = i;
	}

	for (int i = 1; i < rows; i++) {
    	for (int j = 0; j < i; j++) {
	        if (vetor_diagonal(i) > vetor_diagonal(j)) {
	            double temp = vetor_diagonal(i);
	            vetor_diagonal(i) = vetor_diagonal(j);
	            vetor_diagonal(j) = temp;

	            int temp2 = vetor_indice(i);
	            vetor_indice(i) = vetor_indice(j);
	            vetor_indice(j) = temp2;

	        }
	    }
	}

	for (int i = 0; i < rows; i++){
		for (int j = 0; j < cols; j++){
			
			EigenVectorMatriz(i,j) =	Matriz_Vetor(i, vetor_indice(j));
			EigenValueMatriz(i,j) =	Matriz_Valor(i, vetor_indice(j));

		}	
	}

	for (int i = 0; i < cols; i++){
		for (int j = 0; j < rows; j++){

			if(EigenValueMatriz(j,i) != 0 and i != j){
				EigenValueMatriz(i,i) = EigenValueMatriz(j,i);
				EigenValueMatriz(j,i) = 0;
			}
		}
	}

	Matriz_Valor = EigenValueMatriz;
	Matriz_Vetor = EigenVectorMatriz;

}

//Calcula raiz quadrada dos elementos da diagonal
void sqrt_diagonal(Ref<MatrixXd> M){
	for (int i = 0; i < M.rows(); i++){
		M(i,i) = sqrt(M(i,i));
	}
}

void igualarSinal(Ref<MatrixXd> MatrizA, Ref<MatrixXd> MatrizB){

	for (int i = 0; i < MatrizA.cols(); i++){
		if ((MatrizA(i,i) < 0 and MatrizB(i,i) > 0) or (MatrizA(i,i) > 0 and MatrizB(i,i) < 0) ){
			for (int j = 0; j < MatrizA.rows(); j++){
				MatrizB(j,i) = -1 * MatrizB(j,i);	
			}
		}
	}

}


void inverteSinal(Ref<MatrixXd> MatrizA, int coluna){
	for (int i = 0; i < MatrizA.cols(); i++){
		if (i == coluna){
			for (int j = 0; j < MatrizA.rows(); j++){
				MatrizA(j,i) = -1 * MatrizA(j,i);	
			}
		}
	}

}

void clunasUnitarias(Ref<MatrixXd> MatrizA) {
	cout << "Tem que ter só um aqui: ";

	for (int i = 0; i < MatrizA.cols(); i++){
		float soma = 0;
		for (int j = 0; j < MatrizA.rows(); j++){
			soma += MatrizA(j,i) * MatrizA(j,i);
		}
		cout << sqrt(soma) << "  ";
		
	}
}


// -------------- \\ FIM - FUNÇÕES AUXILIARES // -------------- \\