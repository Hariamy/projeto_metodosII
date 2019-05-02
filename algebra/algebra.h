#ifndef ALGEBRA_H
#define ALGEBRA_H

#include <iostream>

namespace alg{
	struct vetor{
		int tam;
		float *valores, *init, *fim;
		
		inline vetor (int novoTam, float *novosValores) { tam = novoTam; valores = init = novosValores; fim = init + tam; }
		inline vetor (int novoTam) {
		                             tam = novoTam; valores = init = (float*) malloc(sizeof(float) * tam);
		                             fim = init + tam;
		                             while(init != fim){
		                             	*init = 0; init++;
		                             }
		                             init = valores;
		                           }
		                           
		inline float operator [] (int pos)      { return valores[pos]; }
		inline void operator = (float *novosValores) { free(valores); valores = init = novosValores; fim = init + tam; }
		inline void operator + (vetor vet2) { if(tam == vet2.tam){
		                                        float *init2 = vet2.init;
		                                        while(init != fim){
		                                        	*init += *init2; init++; init2++;
		                                        }
		                                        init = valores;
		                                       }
		                                     }
		inline void operator - (vetor vet2) { if(tam == vet2.tam){
		                                        float *init2 = vet2.init;
		                                        while(init != fim){
		                                        	*init -= *init2; init++; init2++;
		                                        }
		                                        init = valores;
		                                       }
		                                     }
		inline void operator *  (float constante) { while(init != fim){
		                                             *init *= constante; init++;
		                                            }
		                                            init = valores;
		                                          }
		inline float operator * (vetor vet2) { if(tam == vet2.tam){
		                                        float *init2 = vet2.valores, respo = 0;
		                                        while(init != fim){respo += (*init) * (*init2); std::cout << (*init) << " - " << (*init2) << '\n';; init++; init2++;}
		                                        init = valores;
		                                        std::cout << respo << '\n';
		                                        return respo;
		                                       }
		                                      }
		inline float tamanho () { float respo = 0;
		                          while(init != fim){respo += (*init) * (*init); init++;}
		                          init = valores;
		                          return sqrt(respo);
		                        }
		inline void unitario () { float vetTam = tamanho();
		                          while(init != fim){*init = (*init) / vetTam; init++;}
		                          init = valores;
		                        }
	};
	
	struct matriz{
		int     tam;
		float **valores;
		
		inline matriz (int novoTam, float **novosValores) { tam = novoTam; valores = novosValores; }
		inline matriz (int novoTam)                       { float *init, *fim;
		                                                    tam = novoTam; valores = (float**) malloc(sizeof(float*) * tam);
		                                                    for(int i = 0; i < tam; i++){
		                                                     *(valores + i) = (float*) malloc(sizeof(float) * tam);
		                                                     init = *(valores + i), fim = init + tam;
		                                                     while(init != fim){
		                                                      *init = 0;
		                                                      init++;
		                                                     }
		                                                    }
		                                                  }
		
		inline float* operator [] (int pos)      { return valores[pos]; }
		inline void operator + (float constante) { for(int i = 0; i < tam; i++){ *( *(valores + i) + i) += constante; } }
		inline void operator + (matriz mat2) { if(tam == mat2.tam){
		                                        float *init, *fim, *soma;
		                                        for(int i = 0; i < tam; i++){
		                                         init = *(valores + i); fim = init + tam; soma = *(mat2.valores + i);
		                                         while(init != fim){
		                                          (*init) += *soma; init++; soma++;
		                                         }
		                                        }
		                                       }
		                                     }
		inline void operator - (float constante) { for(int i = 0; i < tam; i++){ *( *(valores + i) + i) -= constante; } }
		inline void operator - (matriz mat2) { if(tam == mat2.tam){
		                                        float *init, *fim, *soma;
		                                        for(int i = 0; i < tam; i++){
		                                         init = *(valores + i); fim = init + tam; soma = *(mat2.valores + i);
		                                         while(init != fim){
		                                          (*init) -= *soma; init++; soma++;
		                                         }
		                                        }
		                                       }
		                                     }
		inline void operator *  (float constante)  { float *init, *fim;
		                                             for(int i = 0; i < tam; i++){
		                                              init = *(valores + i); fim = init + tam;
		                                              while(init != fim){
		                                               (*init) *= constante; init++;
		                                              }
		                                             }
		                                           }
		inline matriz operator * (matriz mat2) { if(tam == mat2.tam){
		                                          float *init1, *init2;
		                                          matriz respo(tam);
		                                          for(int i = 0; i < tam; i++){
		                                           init1 = *(valores + i);
		                                           for(int j = 0; j < tam; j++){
		                                            for(int k = 0; k < tam; k++){
		                                             init2 = *(mat2.valores + k) + j;
		                                             *( *(respo.valores + i) + j) += (*init1) * (*init2);
		                                             init1++;
		                                            }
		                                            init1 -= tam;
		                                           }
		                                          }
		                                          return respo;
		                                         }
		                                       }
		inline float* operator * (vetor vet2) { if(tam == vet2.tam){
		                                         float *respo = (float*)malloc(sizeof(float) * tam), *aux = respo,
		                                         *initM, *fimM, *initV = vet2.init, *fimV = vet2.fim;
		                                         for(int i = 0; i < tam; i++){
		                                         	
		                                         	*aux = 0; initM = valores[i]; fimM = initM + tam;
		                                         	while(initM != fimM){
		                                         	 std::cout << *initV << '\n';
		                                         	 *aux += (*initM) * (*initV); initM++; initV++;
		                                         	}
		                                         	aux++;
		                                         	initV = vet2.init;
		                                         }
		                                         return respo;
		                                        }
		                                      }
	};
}

#endif //ALGEBRA_H
