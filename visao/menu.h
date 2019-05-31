#ifndef MENU_H
#define MENU_H

#include "im_gui_openGL/imgui.h"
#include "im_gui_openGL/imgui_impl_glut.h"
#include "im_gui_openGL/imgui_impl_opengl2.h"

#include <string>
#include "grafico.h"
#include "../controlador/parser/parser.h"
#include "../controlador/interpolacao.h"
#include "../controlador/integral.h"

#define QTD_DIST_UM 0.1

#define MENU     0
#define DERIVADA 1
#define INTEGRAL 2
#define AUTO     3

bool mostrarSobreMenu = false;
static float inter[2] = {-10.0, 10.0}, interCalculado[2] = {0.0, 0.0}, resul = 0.0;
static int grau = 1, grauCalculado = 0, filoCalculada = -1, partCalculada = 0,
           qtd = 0, filo = 0, val = 0, part = 1;
static std::vector <interp> interpol, pontosInterpol;

static char novaExpressao[30], *item[] = {"Newton Cotes", "Gauss Legendre", "Exponencial"},
	        *filosofia[] = {"Fechada", "Aberta"};

static std::string textoExpre, resposta;
static expre::expre *expressao = NULL;

inline void menus (int &tipo);
inline void menuPrincipal (int &tipo);
inline void sobreMenu ();
inline void menuIntegral ();

void botaoCalcular ();

#include "menu.inl"

#endif //MENU_H