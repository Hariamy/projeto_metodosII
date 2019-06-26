#include "menu.h"

void menus (int &tipo) {
   ImGui::GetStyle().WindowRounding = 0.0f;
   
    switch (tipo){
    case MENU:
    	menuPrincipal(tipo);
    break;
    case DERIVADA:
    break;
    case INTEGRAL:
      menuIntegral();
    break;
    case AUTO:
      
    break;
    }
   
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
		float distancia = (tamanho.x/2) - (tamBotoes.x/2);

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

void menuIntegral () {
	
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
		ImGui::InputFloat2("Intervalo", inter);
		ImGui::InputInt("Partições", &part);
		ImGui::Combo("Método", &qtd, item, IM_ARRAYSIZE(item));

		switch (qtd){
			case 0:
				ImGui::InputInt("Grau", &grau);
				ImGui::Combo("Filosofia", &filo, filosofia, IM_ARRAYSIZE(filosofia));
				if(grau > 4){
					grau = 4;
				}else if(grau < 1){
					grau = 1;
				}
			break;
			case 1:
				ImGui::InputInt("Nº pontos", &val);
			break;
			case 2:

			break;
		}

		if(ImGui::Button("Calcular")){
			botaoCalcular();
		}
		ImGui::SameLine();
		ImGui::Text(resposta.data());

	ImGui::End();
}

void botaoCalcular () {
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

		funcaoInterpNewton(pontosInterpol, interpol, grauCalculado, expressao, interCalculado, filo, partCalculada);
		resul = newtonCotes(grauCalculado, filoCalculada, partCalculada, interCalculado, expressao);
		resposta = std::to_string(resul);
	}
}