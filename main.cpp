#include <iostream>
#include <cstdio>
#include "visao/grafico.h"
#include "visao/menu.h"

static ImVec4 clear_color = ImVec4(0.095f, 0.095f, 0.095f, 1.00f);
int tipoMenu = MENU;
double inter[2] = {-10.0, 10.0};

inline void pintar ();

int main(int argc, char *argv[]) {
	glutInit(&argc, argv);
		
	#ifdef __FREEGLUT_EXT_H__
		glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);
	#endif
	
	glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);

	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_MULTISAMPLE);
	
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Metodos numericos 2");

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glutDisplayFunc(pintar);
	
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io; //Provavelmente, entrada e saída
	
	io.KeyRepeatDelay = 5;
	io.KeyRepeatRate = 2;
  
	ImGui::StyleColorsDark(); //Cores do imgui
  
   //Faz as ligações do imgui com o glut e o opengl
   ImGui_ImplGLUT_Init();
	ImGui_ImplGLUT_InstallFuncs();
	ImGui_ImplOpenGL2_Init();

	glutMainLoop();
	
	ImGui_ImplOpenGL2_Shutdown();
	ImGui_ImplGLUT_Shutdown();
	ImGui::DestroyContext();
	
	return 0;
}

void pintar () {
   //Cria um novo frame do imgui
	ImGui_ImplOpenGL2_NewFrame();
	ImGui_ImplGLUT_NewFrame();
	
	glClearColor(clear_color.x, clear_color.y, clear_color.z, clear_color.w);
	glClear(GL_COLOR_BUFFER_BIT);
	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(inter[0], inter[1], -10, 10, -1.0, 20000.0);
	glMatrixMode(GL_MODELVIEW);
	
	planoCarteziano(inter[0], inter[1], -10, 10);
	menus(tipoMenu, inter);
	
	//Renderiza
	ImGui::Render();
	ImGuiIO& io = ImGui::GetIO();
	glViewport(0, 0, (GLsizei)io.DisplaySize.x, (GLsizei)io.DisplaySize.y);
	
	ImGui_ImplOpenGL2_RenderDrawData(ImGui::GetDrawData());

	glutSwapBuffers();
	glutPostRedisplay();
}
