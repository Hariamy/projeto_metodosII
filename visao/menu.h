#ifndef MENU_H
#define MENU_H

#include "im_gui_openGL/imgui.h"
#include "im_gui_openGL/imgui_impl_glut.h"
#include "im_gui_openGL/imgui_impl_opengl2.h"

#include <string>
#include "grafico.h"
#include "../controlador/parser/parser.h"
#include "../controlador/interpolacao/interpolacao.h"
#include "../controlador/integrais/integrais.h"

#define QTD_DIST_UM 0.1

#define MENU     0
#define DERIVADA 1
#define INTEGRAL 2
#define AUTO     3

void menus (int &tipo, double inter[2]);
void menuPrincipal (int &tipo);
void sobreMenu ();
void menuIntegral (double inter[2]);

void botaoCalcular (double inter[2]);

#endif //MENU_H