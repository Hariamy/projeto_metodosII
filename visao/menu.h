#ifndef MENU_H
#define MENU_H

#include "im_gui_openGL/imgui.h"
#include "im_gui_openGL/imgui_impl_glut.h"
#include "im_gui_openGL/imgui_impl_opengl2.h"

#include <string>
#include "grafico.h"
#include "../controlador/parser/expre.h"
#include "../controlador/parser/parser.h"

#define QTD_DIST_UM 0.1

#define MENU     0
#define DERIVADA 1
#define INTEGRAL 2
#define AUTO     3

bool mostrarSobreMenu = false;
static float inter[2] = {-10.0, 10.0};
static std::vector <float> valInterpol, interpol, pontosInterpol, valPontosInterpol;

static std::string textoExpre;
static expre::expre *expressao = NULL;

inline void menus (int &tipo);
inline void menuPrincipal (int &tipo);
inline void sobreMenu ();
inline void menuIntegral ();

inline void funcaoInterpoladoraNewton ();

#include "menu.inl"

#endif //MENU_H