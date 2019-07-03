#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <GL/freeglut.h>

#include "../../../visao/im_gui_openGL/imgui.h"
#include "../../../visao/im_gui_openGL/imgui_impl_glut.h"
#include "../../../visao/im_gui_openGL/imgui_impl_opengl2.h"

#include "../../../controlador/Contorno/Contorno.h"

struct ponto {
    double x, y;
    
    void inserirPosicao (double xNovo, double yNovo) {
        x = xNovo; y = yNovo;
    }
    
    bool emCima(double x, double y){
        double distX = x - this->x,
               distY = y - this->y;
        //std::cout << sqrt((distX*distX) + (distY*distY)) << std::endl;
        return (sqrt((distX*distX) + (distY*distY)) < 0.02);
    }
};

bool mostrarIniciais = true, tooltip = false;
std::vector <ponto> pontosX(6);
ponto pontoEmCima;
//static ImVec4 clear_color = ImVec4(0.095f, 0.095f, 0.095f, 1.00f);
double inter[2] = {-10.0, 10.0}, inicio = 0.2, fim = 0.5, dist = fim - inicio,
       largTela = 500.0, alturaTela = 500.0;
int qtdDiv = 5;

void init();
void resize (int w, int h);
void pintar ();
void desenharPontos ();
void teclado (unsigned char key, int x, int y);
void movimentoMouse (int x, int y);

void conversao (int x, int y, double &respoX, double &respoY);

int main(int argc, char *argv[]) {
	glutInit(&argc, argv);
		
	#ifdef __FREEGLUT_EXT_H__
		glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);
	#endif
	
	glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);

	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_MULTISAMPLE);
	
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("PVC");
    
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    
    ImGui::StyleColorsDark();
    
    ImGui_ImplGLUT_Init();
    ImGui_ImplGLUT_InstallFuncs();
    ImGui_ImplOpenGL2_Init();

	glutDisplayFunc(pintar);
    glutKeyboardFunc(teclado);
    glutPassiveMotionFunc(movimentoMouse);
    glutReshapeFunc(resize);

    /*#ifdef __FREEGLUT_EXT_H__
        glutMouseWheelFunc(ImGui_ImplGLUT_MouseWheelFunc);
    #endif
    glutKeyboardUpFunc(ImGui_ImplGLUT_KeyboardUpFunc);
    glutSpecialFunc(ImGui_ImplGLUT_SpecialFunc);
    glutSpecialUpFunc(ImGui_ImplGLUT_SpecialUpFunc);*/

    init();

	glutMainLoop();

    ImGui_ImplOpenGL2_Shutdown();
	ImGui_ImplGLUT_Shutdown();
	ImGui::DestroyContext();
	
	return 0;
}

void init() {
    double deltaX = (fim - inicio)/qtdDiv, xi = inicio;
    VectorXf pontos;

    for(ponto &i:pontosX){
        i.x = xi;
        xi += deltaX;
    }

    pontos = Contorno1D(inicio, fim,  qtdDiv);

    pontosX[0].y = 0.0;

    for(int i = 0; i < qtdDiv-1; i++){
        pontosX[i+1].y = pontos[i];
    }

    pontosX[qtdDiv+1].y = 0.0;
    pontoEmCima.inserirPosicao(0.0, 0.0);
}

void resize (int w, int h) {
    ImGui_ImplGLUT_ReshapeFunc(w, h);
	glViewport(0, 0, w, h);
    largTela = w;
    alturaTela = h;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(inicio-0.01, fim+0.01, -dist-0.01, dist+0.01, -1.0, 20000.0);
	
	glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void pintar () {
    ImGui_ImplOpenGL2_NewFrame();
	ImGui_ImplGLUT_NewFrame();

	glClearColor(0.25, 0.25, 0.25, 1.00);

	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(0.0, 0.0, 1.0,   //Posição da câmera
			  0.0, 0.0, 0.0,   //Onde está olhando
			  0.0, 1.0, 0.0);  //Orientação de cima
	
	desenharPontos();
    
    ImGui::SetWindowSize("tooltip", ImVec2(80.0, 48.0));
    if(tooltip){
        ImGui::Begin("tooltip", NULL, ImGuiWindowFlags_Tooltip | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_AlwaysUseWindowPadding);
            ImGui::Text("x: %.4lf", pontoEmCima.x);
            ImGui::Text("y: %.4lf", pontoEmCima.y);
        ImGui::End();
    }

	//Renderiza
	ImGui::Render();
	ImGuiIO& io = ImGui::GetIO();
	glViewport(0, 0, (GLsizei)io.DisplaySize.x, (GLsizei)io.DisplaySize.y);

	ImGui_ImplOpenGL2_RenderDrawData(ImGui::GetDrawData());

	glutSwapBuffers();
	glutPostRedisplay();
}

void desenharPontos () {
    int indice = 0;

    glLineWidth(5.0);
    glPointSize(10.0);

    if(mostrarIniciais){
        glBegin(GL_LINE_STRIP);
            glColor3d(1.0, 1.0, 1.0);
            for(ponto i:pontosX){
                glVertex3d(i.x, 0.0, 0.0);
            }
        glEnd();

        glBegin(GL_POINTS);
            glColor3d(0.0, 1.0, 0.0);
            for(ponto i:pontosX){
                glVertex3d(i.x, 0.0, 0.0);
            }
        glEnd();
    }else{
        glBegin(GL_LINE_STRIP);
            glColor3d(1.0, 1.0, 1.0);
            for(ponto i:pontosX){
                glVertex3d(i.x, -i.y, 0.0);
            }
        glEnd();
        indice = 0;
        glBegin(GL_POINTS);
            glColor3d(0.0, 1.0, 0.0);
            for(ponto i:pontosX){
                glVertex3d(i.x, -i.y, 0.0);
            }
        glEnd();
    }
}

void teclado (unsigned char key, int x, int y) {
	ImGui_ImplGLUT_KeyboardFunc(key, x, y);

    if(key == 'm'){
        mostrarIniciais = !mostrarIniciais;
        glutPostRedisplay();
    }
}

void conversao (int x, int y, double &respoX, double &respoY) {
    respoX = (inicio - 0.01) + (x * (dist+0.02) / largTela);
    respoY = -(dist - 0.01) + (((alturaTela - y) * ((2.0*dist)+0.02)) / alturaTela);
}

void movimentoMouse (int x, int y) {
    ImGui_ImplGLUT_MotionFunc(x, y);
    double posX, posY;

    conversao(x, y, posX, posY);
    
    if(mostrarIniciais){
        for(ponto i:pontosX){
            if(i.emCima(posX, posY-i.y)){
                tooltip = true;
                pontoEmCima.inserirPosicao(i.x, 0.0);
                return;
            }
        }
    }else{
        for(ponto i:pontosX){
            if(i.emCima(posX, posY)){
                tooltip = true;
                pontoEmCima.inserirPosicao(i.x, i.y);
                return;
            }
        }
    }
    tooltip = false;
}
