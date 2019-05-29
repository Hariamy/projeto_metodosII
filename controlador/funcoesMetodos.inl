#include "metodos.h"

/*! Metodo da potencia
**  Parâmetros: A matriz para se calcular e o erro
**  Retorno: O resultado do autovalor e autovetor na estrutura
*/
autoValVet potencia (matriz &mat, float erro) {
	unsigned int tam = mat.tam;
	float *vet = (float*)malloc(sizeof(float) * mat.tam),
	      respoVal = INFINITY, anterior;
	
	vet[0] = 1;
	
	for(unsigned int i = 1; i < tam; i++){
		vet[i] = 0;
	}
		
	vetor respoVet(mat.tam, vet), aux(mat.tam);
		
	do{
		anterior = respoVal;
		
		aux = mat * respoVet;
		respoVal = respoVet * aux;
		
		respoVet = aux;
		respoVet.unitario();
		
	}while((std::abs((respoVal - anterior) / respoVal)) > erro);
	
	autoValVet respo{respoVal, respoVet};
	
	return respo;
}

/*! Metodo da potencia inversa
**  Parâmetros: A matriz para se calcular e o erro
**  Retorno: O resultado do autovalor e autovetor na estrutura
*/
autoValVet potenciaInversa (matriz &mat, float erro) {
	matrizLU LU = construirLU(mat);
	matriz inversa = inversaLU(LU);
	autoValVet respo = potencia(inversa, erro);

	if(respo.autoValor > 0){
		respo.autoValor = 1 / respo.autoValor;
	}

	return respo;
}
/*! Metodo da potencia com deslocamento
**  Parâmetros: A matriz para se calcular e o erro
**  Retorno: O vetor com os resultados dos autovalores e autovetores nas estruturas
*/
std::vector<autoValVet> potenciaDeslocamento (matriz &mat, float erro) {
	int tam = mat.tam;
	float intervalo;
	bool diferente;
	matriz aux = mat;
	std::vector<autoValVet> respo;
	respo.push_back(potencia(mat, erro));
	respo.push_back(potenciaInversa(mat, erro));
	intervalo = (respo[0].autoValor - respo[1].autoValor) / tam;
	for(float i = respo[1].autoValor; (i < respo[0].autoValor) && (respo.size()) < tam; i += intervalo){
		aux - intervalo;
		autoValVet veri = potenciaInversa(aux, erro);
		diferente = true;
		for(int j = 0; j < respo.size() && diferente; j++){
			if(veri == respo[i]){
				diferente = false;
			}
		}
		if(diferente){
			respo.push_back(veri);
		}
	}
	return respo;
}
/*! Constroi as matrizes de decomposição LU
**  Parâmetros: A matriz que se deseja decompor
**  Retorno: A estrutura de matrizes de decomposição LU
*/
matrizLU construirLU (matriz &mat) {
	unsigned int tam = mat.tam;
	matriz L(tam, identidade(mat.tam)), U(tam, copiarMatriz(mat));
	float subtrair;
	
	for(unsigned int i = 0; i < tam; i++){
		for(unsigned int j = i + 1; j < tam; j++){
			subtrair = L[j][i] = (U[j][i] / U[i][i]);
			
			for(unsigned int k = i; k < tam; k++){
				U[j][k] -= subtrair * U[i][k];
			}
		}
	}
	
	matrizLU LU{L, U};
	
	return LU;
}

/*! Realiza o metodo da substituição seletiva para resolver Ax=b
**  Parâmetros: A matriz A e o vetor b
**  Retorno: O vetor x
*/
vetor substituicaoProgressiva (matriz &mat, vetor vet) {
	if(mat.tam == vet.tam){
		int tam = vet.tam;
		vetor resul(tam);
		
		for(int i = 0; i < tam; i++){
			for(int j = 0; j < i; j++){
				resul[i] += mat[i][j] * resul[j];
			}
			
			resul[i] = (vet[i] - resul[i])/ mat[i][i];
		
		}
		
		return resul;
	}
}
	
/*! Realiza o método da substuição retroativa para resolver Ax=b
**  Parâmetros: A matriz A e o vetor b
**  Retorno: O vetor x
*/
vetor substituicaoRetroativa (matriz &mat, vetor vet) {
	if(mat.tam == vet.tam){
		int tam = vet.tam;
		vetor resul(tam);
		
		for(int i = tam-1; i >= 0; i--){
			for(int j = tam-1; j > i; j--){
				resul[i] += mat[i][j] * resul[j];
			}
			
			resul[i] = (vet[i] - resul[i])/ mat[i][i];
		
		}
		
		return resul;
	}
}

/*! Acha a matriz inversa utilizando as matrizes de decomposição LU
**  Parâmetros: A estrutura de de matrizes de decomposição LU
**  Retorno: A matriz inversa
*/
matriz inversaLU (matrizLU &matLU) {
	int tam = matLU.L.tam;
	vetor aux(tam), iden(tam);
	matriz matRespo(tam);
	for(int i = 0; i < tam; i++){
		iden[i] = 1;
		if(i-1 >= 0){
			iden[i-1] = 0;
		}
		
		aux = substituicaoRetroativa(matLU.U, substituicaoProgressiva(matLU.L, iden));
		for(int j = 0; j < tam; j++){
			matRespo[j][i] = aux[j];
		}
	}
	return matRespo;
}