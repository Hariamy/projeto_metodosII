#include "imgui.h"
#include "im_gui_openGL/imgui_impl_glut.h"
#include "im_gui_openGL/imgui_impl_opengl2.h"


#include <iostream>
#include <cstdio>
#include <GL/freeglut.h>

#define MENU     0
#define DERIVADA 1
#define INTEGRAL 2
#define AUTO     3

static ImVec4 clear_color = ImVec4(0.095f, 0.095f, 0.095f, 1.00f);
int tipo = MENU;
bool mostrarSobreMenu = false;

void pintar ();
void menus ();
void menuPrincipal ();
void sobreMenu ();

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
	
	glutDisplayFunc(pintar);
	
	ImGui::CreateContext();
   ImGuiIO& io = ImGui::GetIO(); (void)io; //Provavelmente, entrada e saída
  
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
	glFrustum(-10, 10, -10, 10, 1.0, 20000.0);
	glMatrixMode(GL_MODELVIEW);
	
	menus();
	
	//Renderiza
	ImGui::Render();
	ImGuiIO& io = ImGui::GetIO();
	glViewport(0, 0, (GLsizei)io.DisplaySize.x, (GLsizei)io.DisplaySize.y);
	
	ImGui_ImplOpenGL2_RenderDrawData(ImGui::GetDrawData());

	glutSwapBuffers();
	glutPostRedisplay();
}

void menus () {
   ImGui::GetStyle().WindowRounding = 0.0f;
   
   switch (tipo){
   case MENU:
      menuPrincipal();
   break;
   case DERIVADA:
      
   break;
   case INTEGRAL:
      
   break;
   case AUTO:
      
   break;
   }
   
   if(mostrarSobreMenu){
      sobreMenu();
   }
}

void menuPrincipal () {
   ImGui::BeginMainMenuBar();
		if(ImGui::BeginMenu("Arquivo")){
			if(ImGui::MenuItem("Derivada"))                  { tipo = DERIVADA; }
			if(ImGui::MenuItem("Integral"))                  { tipo = INTEGRAL; }
			if(ImGui::MenuItem("Autovetores e autovalores")) { tipo = AUTO; }
			ImGui::MenuItem("Sair");
			
			ImGui::EndMenu();
		}
		
		if(ImGui::BeginMenu("Ajuda")){
			ImGui::MenuItem("Sobre", NULL, &mostrarSobreMenu);
			
			ImGui::EndMenu();
		}
	ImGui::EndMainMenuBar();
}

void sobreMenu () {
   ImGui::Begin("Sobre", &mostrarSobreMenu);
   
      ImGui::Text("Métodos Numéricos 2");
		ImGui::Text("Programa de métodos numéricos");

   
   ImGui::End();
}
