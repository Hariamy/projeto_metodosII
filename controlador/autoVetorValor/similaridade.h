#ifndef SIMILARIDADE_H
#define SIMILARIDADE_H

#include <iostream>
#include <cmath>
#include <tuple>

#include "../../modelo/algebra.h"
#include "../../biblioteca/eigen/Eigen/Dense"

using namespace Eigen;

std::tuple<MatrixXd, MatrixXd> Householder(Ref<MatrixXd> A);
std::tuple<MatrixXd, MatrixXd> Jacobi(Ref<MatrixXd> A, double e, Ref<MatrixXd> H);
std::tuple<MatrixXd, MatrixXd> QR(Ref<MatrixXd> A, double E, Ref<MatrixXd> H);


// FUNÇÕES AUXILIARES
double error(Ref<MatrixXd> A); 

void around(Ref<MatrixXd> Matriz);

void ordenar(Ref<MatrixXd> Matriz_Valor, Ref<MatrixXd> Matriz_Vetor);

void sqrt_diagonal(Ref<MatrixXd> M);

void igualarSinal(Ref<MatrixXd> MatrizA, Ref<MatrixXd> MatrizB);

void inverteSinal(Ref<MatrixXd> MatrizA, int coluna);

void consertaSinal(Ref<MatrixXd> A, Ref<MatrixXd> V, Ref<MatrixXd> U, Ref<MatrixXd> S);

void clunasUnitarias(Ref<MatrixXd> MatrizA);

void criarSigma(Ref<MatrixXd> Sigma, Ref<MatrixXd> autovetores);
VectorXd zeros(int size);

#endif //SIMILARIDADE_H
