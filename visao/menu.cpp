#include "menu.h"

#define QTD_DIST_UM 0.1

#define MENU     0
#define DERIVADA 1
#define INTEGRAL 2
#define AUTO     3
static float interCalculado[2] = {0.0, 0.0};
static double interCalculadoD[2] = {0.0, 0.0}, resul = 0.0;
static bool mostrarSobreMenu = false;
static char novaExpressao[30], *item[] = {"Newton Cotes", "Gauss Legendre", "Exponencial"},
	        *filosofia[] = {"Fechada", "Aberta"};

static std::string textoExpre, resposta;
static expre::expre *expressao = NULL;

static int grau = 1, grauCalculado = 0, filoCalculada = -1, partCalculada = 0,
           qtd = 0, filo = 0, val = 0, part = 1;
static std::vector <interp> interpol, pontosInterpol;

void menus (int &tipo, double inter[2]) {
   ImGui::GetStyle().WindowRounding = 0.0;
   
   menuIntegral(inter);
       
   if(mostrarSobreMenu){
      sobreMenu();
   }
}

void menuPrincipal (int &tipo) {
	ImVec2 tamanho((ImGui::GetIO().DisplaySize.x*3.0)/4.0, ((ImGui::GetIO().DisplaySize.y)*5.0)/6.0);
	
	ImGui::SetWindowSize("Botoes", tamanho);
	ImGui::SetNextWindowPosCenter();

	ImGui::Begin("Botoes", NULL, ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoTitleBar);
		ImVec2 tamBotoes((tamanho.x*3.0)/4.0, tamanho.y/5.0);
		double distancia = (tamanho.x/2.0) - (tamBotoes.x/2.0);

		ImGui::SameLine(distancia);
		if(ImGui::Button("Derivada", tamBotoes)) { tipo = DERIVADA; }

		ImGui::NewLine();
		ImGui::SameLine(distancia);
		if(ImGui::Button("Integral", tamBotoes)) { tipo = INTEGRAL; }

		ImGui::NewLine();
		ImGui::SameLine(distancia);
		if(ImGui::Button("Autovetor e Autovalor", tamBotoes)) { tipo = AUTO; }

		ImGui::NewLine();
		ImGui::SameLine(distancia);
		if(ImGui::Button("Problema do valor inicial", tamBotoes)) { }

		ImGui::NewLine();
		ImGui::SameLine(distancia);
		if(ImGui::Button("Problema de valor de contorno", tamBotoes)) { }
	ImGui::End();

   ImGui::BeginMainMenuBar();
		if(ImGui::BeginMenu("Arquivo")){
			if(ImGui::MenuItem("Derivada"))                  { tipo = DERIVADA; }
			if(ImGui::MenuItem("Integral"))                  { tipo = INTEGRAL; }
			if(ImGui::MenuItem("Autovetores e autovalores")) { tipo = AUTO; }
			ImGui::MenuItem("Sair");
			
			ImGui::EndMenu();
		}
		
		if(ImGui::BeginMenu("Ajuda")){
			mostrarSobreMenu |= ImGui::MenuItem("Sobre");
			
			ImGui::EndMenu();
		}
	ImGui::EndMainMenuBar();
}

void sobreMenu () {
	ImVec2 tamanho(200, 100), posicao((ImGui::GetWindowWidth()), (ImGui::GetWindowHeight()));
	
	ImGui::SetWindowSize("Sobre", tamanho);
	ImGui::SetNextWindowPosCenter();
    ImGui::Begin("Sobre", &mostrarSobreMenu, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoSavedSettings);
		ImGui::PushTextWrapPos(200);
    	ImGui::Text("Métodos Numéricos 2");
		ImGui::Separator();
		ImGui::AlignFirstTextHeightToWidgets();
		ImGui::Text("Programa de métodos numéricos criado para a cadeira de métodos 2");
		ImGui::PopTextWrapPos();
    ImGui::End();
}

void menuIntegral (double inter[2]) {
	ImVec2 tamanho(250, 220);
	static bool func = false, area = false, interpolacao = false; 

	if(area){
		mostrarArea(interpol);
	}
	if(func){
		mostrarFuncao(expressao, inter);
	}
	if(interpolacao){
		mostrarInterpolacao(interpol, pontosInterpol);
	}

	ImGui::SetWindowSize("Integral", tamanho);
	ImGui::Begin("Integral", NULL, ImGuiWindowFlags_NoResize);
		ImGui::Checkbox("Função", &func);
		ImGui::SameLine();
		ImGui::Checkbox("Área", &area);
		ImGui::SameLine();
		ImGui::Checkbox("Interpolação", &interpolacao);

		ImGui::InputText("Equação", novaExpressao, 30);
		ImGui::InputDouble("Início", &(inter[0]));
		ImGui::InputDouble("Fim", &(inter[1]));
		ImGui::InputInt("Partições", &part);

		ImGui::InputInt("Grau", &grau);
		ImGui::Combo("Filosofia", &filo, filosofia, IM_ARRAYSIZE(filosofia));
		if(grau > 4){
			grau = 4;
		}else if(grau < 1){
			grau = 1;
		}

		if(ImGui::Button("Calcular")){
			botaoCalcular(inter);
		}

		if(resposta.size()){
			ImGui::SameLine();
			ImGui::Text(resposta.data());
		}
	ImGui::End();
}

void botaoCalcular (double inter[2]) {
	if((textoExpre.compare(novaExpressao) != 0)
		|| (interCalculado[0] != inter[0]) || (interCalculado[1] != inter[1])
		|| (grauCalculado != grau) || (filoCalculada != filo) || (partCalculada != part)){
		textoExpre = novaExpressao;

		free(expressao);
		expressao = NULL;
		expressao = parser(textoExpre);

		grauCalculado = grau;
		filoCalculada = filo;
		partCalculada = part;

		interCalculado[0] = inter[0];
		interCalculado[1] = inter[1];

		interCalculadoD[0] = (double)inter[0];
		interCalculadoD[1] = (double)inter[1];

		funcaoInterpNewton(pontosInterpol, interpol, grauCalculado, expressao, interCalculado, filo, partCalculada);
		resul = newtonCotes(grauCalculado, filoCalculada, partCalculada, interCalculadoD, expressao);
		resposta = std::to_string(resul);
	}
}