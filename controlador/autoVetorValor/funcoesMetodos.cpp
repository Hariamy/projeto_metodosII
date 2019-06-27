#include "metodos.h"

/*! Metodo da potencia
**  Parâmetros: A matriz para se calcular e o erro
**  Retorno: O resultado do autovalor e autovetor na estrutura
*/
autoValVet* potencia (matriz &mat, float &erro) {
	unsigned int tam = mat.tam;
	float respoVal = INFINITY, anterior;
	vetor *respoVet = new vetor(mat.tam, 1), *aux = new vetor(mat.tam);
	
	do{
		anterior = respoVal;
		respoVet->unitario();
		
		aux = mat * (*respoVet);
		respoVal = (*respoVet) * (*aux);

		respoVet = aux;
	}while((std::abs((respoVal - anterior) / respoVal)) > erro);
	
	autoValVet *respo = new autoValVet{respoVal, respoVet};

	return respo;
}

/*! Metodo da potencia inversa
**  Parâmetros: A matriz para se calcular e o erro
**  Retorno: O resultado do autovalor e autovetor na estrutura
*/
autoValVet* potenciaInversa (matriz &mat, float &erro) {
	matrizLU *LU = construirLU(mat);
	matriz *inversa = inversaLU((*LU));
	autoValVet *respo = potencia((*inversa), erro);

	if(respo->autoValor > 0){
		respo->autoValor = 1 / respo->autoValor;
	}

	return respo;
}
/*! Metodo da potencia com deslocamento
**  Parâmetros: A matriz para se calcular e o erro
**  Retorno: O vetor com os resultados dos autovalores e autovetores nas estruturas
*/
/*std::vector<autoValVet> potenciaDeslocamento (matriz &mat, float &erro) {
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
		autoValVet* veri = potenciaInversa(aux, erro);
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
}*/

/*! Constroi as matrizes de decomposição LU
**  Parâmetros: A matriz que se deseja decompor
**  Retorno: A estrutura de matrizes de decomposição LU
*/
matrizLU* construirLU (matriz &mat) {
	unsigned int tam = mat.tam;
	matriz *L = new matriz(tam, IDENTIDADE), *U = new matriz(tam);
	matrizLU *LU;
	float subtrair = 0;
	
	(*U) = mat;
	
	for(unsigned int i = 0; i < tam; i++){
		for(unsigned int j = i + 1; j < tam; j++){
			
			subtrair = L->posicao(j, i) = (U->posicao(j, i) / U->posicao(i, i));
			
			for(unsigned int k = i; k < tam; k++){
				U->posicao(j, k) -= subtrair * U->posicao(i, k);
			}
		}
	}
	
	LU = new matrizLU(L, U);
	
	return LU;
}

/*! Realiza o metodo da substituição seletiva para resolver Ax=b
**  Parâmetros: A matriz A e o vetor b
**  Retorno: O vetor x
*/
vetor* substituicaoProgressiva (matriz &mat, vetor &vet) {
	int tam = mat.tam;
	vetor *resul = new vetor(tam);

	for(int i = 0; i < tam; i++){
		for(int j = 0; j < i; j++){
			(*resul)[i] += mat.posicao(i, j) * (*resul)[j];
		}
		
		(*resul)[i] = (vet[i] - (*resul)[i]) / mat.posicao(i, i);
	}
		
	return resul;
}
	
/*! Realiza o método da substuição retroativa para resolver Ax=b
**  Parâmetros: A matriz A e o vetor b
**  Retorno: O vetor x
*/
vetor* substituicaoRetroativa (matriz &mat, vetor &vet) {
	int tam = vet.tam;
	vetor *resul = new vetor(tam);
		
	for(int i = tam-1; i >= 0; i--){
		for(int j = tam-1; j > i; j--){
			(*resul)[i] += mat.posicao(i, j) * (*resul)[j];
		}
			
		(*resul)[i] = (vet[i] - (*resul)[i])/ mat.posicao(i, i);		
	}
		
	return resul;
}

/*! Acha a matriz inversa utilizando as matrizes de decomposição LU
**  Parâmetros: A estrutura de de matrizes de decomposição LU
**  Retorno: A matriz inversa
*/
matriz* inversaLU (matrizLU &matLU) {
	int tam = matLU.L->tam;
	vetor *subRetro, *subProg, *iden = new vetor(tam);
	matriz *matRespo = new matriz(tam);
	for(int i = 0; i < tam; i++){
		(*iden)[i] = 1;
		if(i-1 >= 0){
			(*iden)[i-1] = 0;
		}

		subProg = substituicaoProgressiva(*(matLU.L), (*iden));
		subRetro = substituicaoRetroativa(*(matLU.U), (*subProg));
		for(int j = 0; j < tam; j++){
			matRespo->posicao(j, i) = (*subRetro)[j];
		}
	}
	return matRespo;
}