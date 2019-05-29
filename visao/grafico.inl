#include "grafico.h"

void planoCarteziano (float &esquerda, float &direita, float baixo, float cima) {
    float inicioLargura = esquerda - (DISTANCIA - fmod(esquerda, DISTANCIA)) - 1,
          fimLargura = direita + fmod(direita, DISTANCIA) + 1,
          inicioAltura = baixo - (DISTANCIA - fmod(baixo, DISTANCIA)) - 1,
          fimAltura = cima + fmod(cima, DISTANCIA) + 1;

    glPushAttrib(GL_LINE_BIT);
    glColor4f(0.86, 0.86, 0.86, 0.4);

    glEnable(GL_LINE_STIPPLE);

    glLineStipple(3, 0xAAAA);
    glLineWidth(0.5);

    glBegin(GL_LINES);
    for(float i = inicioLargura; i <= fimLargura; i += DISTANCIA){
        glVertex2f(i, inicioAltura);
        glVertex2f(i, fimAltura);
    }

    for(float i = inicioAltura; i <= fimAltura; i += DISTANCIA){
        glVertex2f(inicioLargura, i);
        glVertex2f(fimLargura, i);
    }
    glEnd();

    glDisable(GL_LINE_STIPPLE);
    glLineWidth(2.5);
    glColor4f(0.86, 0.86, 0.86, 1.0);

    glBegin(GL_LINES);

    glVertex2f(0.0, inicioAltura);
    glVertex2f(0.0, fimAltura);

    glVertex2f(inicioLargura, 0.0);
    glVertex2f(fimLargura, 0.0);

    glEnd();

    glPopAttrib();
}

void mostrarFuncao (float inter[2]) {
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_LINE_STRIP);
	for(float i = inter[0]; i < inter[1]; i += QTD_DIST_UM){
		glVertex2f(i, std::sin(i));
	}
	glEnd();
}

void mostrarArea (std::vector <float> &valInterpol, std::vector <float> &interpol) {
	int tam = valInterpol.size()-1;

	glBegin(GL_TRIANGLES);
		glColor4f(1.0, 0.7, 0.3, 0.85);
		
		for(float i = 0; i < tam; i++){
			if(interpol[i] > 0){
				glVertex2f(valInterpol[i], 0.0);
				glVertex2f(valInterpol[i+1], 0.0);
				glVertex2d(valInterpol[i], interpol[i]);

				glVertex2f(valInterpol[i+1], interpol[i+1]);
				glVertex2f(valInterpol[i], interpol[i]);
				glVertex2f(valInterpol[i+1], 0.0);
			}else{
				glVertex2f(valInterpol[i], 0.0);
				glVertex2f(valInterpol[i], interpol[i]);
				glVertex2f(valInterpol[i+1], 0.0);

				glVertex2d(valInterpol[i+1], interpol[i+1]);
				glVertex2f(valInterpol[i+1], 0.0);
				glVertex2d(valInterpol[i], interpol[i]);
			}
		}
	glEnd();
}

void mostrarInterpolacao (std::vector <float> &valInterpol, std::vector <float> &interpol, std::vector <float> &pontosInterpol, std::vector <float> &valPontosInterpol) {
	int tam = interpol.size(), qtdPontos = pontosInterpol.size();

	glBegin(GL_LINE_STRIP);
		glColor3f(1.0, 0.0, 0.0);
		for(int i = 0; i < tam; i++){
			glVertex2f(valInterpol[i], interpol[i]);
		}
	glEnd();

	glPointSize(5.0);
	glBegin(GL_POINTS);
		glColor3f(1.0, 1.0, 0.0);
		
        for(int i = 0; i < qtdPontos; i++){
		    glVertex2f(pontosInterpol[i], valPontosInterpol[i]);
        }
	glEnd();
}