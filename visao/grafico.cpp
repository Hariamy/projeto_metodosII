#include "grafico.h"

void planoCarteziano (double &esquerda, double &direita, double baixo, double cima) {
    double inicioLargura = esquerda - (DISTANCIA - fmod(esquerda, DISTANCIA)) - 1,
          fimLargura = direita + fmod(direita, DISTANCIA) + 1,
          inicioAltura = baixo - (DISTANCIA - fmod(baixo, DISTANCIA)) - 1,
          fimAltura = cima + fmod(cima, DISTANCIA) + 1;

    glPushAttrib(GL_LINE_BIT);
    glColor4f(0.86, 0.86, 0.86, 0.4);

    glEnable(GL_LINE_STIPPLE);

    glLineStipple(3, 0xAAAA);
    glLineWidth(0.5);

    glBegin(GL_LINES);
    for(double i = inicioLargura; i <= fimLargura; i += DISTANCIA){
        glVertex2f(i, inicioAltura);
        glVertex2f(i, fimAltura);
    }

    for(double i = inicioAltura; i <= fimAltura; i += DISTANCIA){
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

void mostrarFuncao (expre::expre *expressao, double inter[2]) {
	double fim = inter[1] + QTD_DIST_UM;
	if(expressao != NULL){
		glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_LINE_STRIP);
		for(double i = inter[0]; i < fim; i += QTD_DIST_UM){
			glVertex2f(i, expressao->calcular(i));
		}
		glEnd();
	}
}

void mostrarArea (std::vector <interp> &interpol) {
	int tam = interpol.size()-1;

	glBegin(GL_TRIANGLES);
		glColor4f(1.0, 0.7, 0.3, 0.85);
		
		for(double i = 0; i < tam; i++){
			if(interpol[i].y > 0){
				glVertex2f(interpol[i].x, 0.0);
				glVertex2f(interpol[i+1].x, 0.0);
				glVertex2d(interpol[i].x, interpol[i].y);

				glVertex2f(interpol[i+1].x, interpol[i+1].y);
				glVertex2f(interpol[i].x, interpol[i].y);
				glVertex2f(interpol[i+1].x, 0.0);
			}else{
				glVertex2f(interpol[i].x, 0.0);
				glVertex2f(interpol[i].x, interpol[i].y);
				glVertex2f(interpol[i+1].x, 0.0);

				glVertex2d(interpol[i+1].x, interpol[i+1].y);
				glVertex2f(interpol[i+1].x, 0.0);
				glVertex2d(interpol[i].x, interpol[i].y);
			}
		}
	glEnd();
}

void mostrarInterpolacao (std::vector <interp> &interpol, std::vector <interp> &pontosInterpol) {
	int tam = interpol.size(), qtdPontos = pontosInterpol.size();

	glBegin(GL_LINE_STRIP);
		glColor3f(1.0, 0.0, 0.0);

		for(int i = 0; i < tam-1; i++){
			glVertex2f(interpol[i].x, interpol[i].y);
			glVertex2f(interpol[i+1].x, interpol[i+1].y);
		}
	glEnd();

	glPointSize(5.0);
	glBegin(GL_POINTS);
		glColor3f(1.0, 1.0, 0.0);
		
        for(int i = 0; i < qtdPontos; i++){
		    glVertex2f(pontosInterpol[i].x, pontosInterpol[i].y);
        }
	glEnd();
}