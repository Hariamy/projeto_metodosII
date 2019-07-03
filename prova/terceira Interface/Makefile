OBJ = Objects/
MOD = ../../modelo/
CON = ../../controlador/Contorno/
VIS = ../../visao/im_gui_openGL/
EXE = appContorno
CXX = g++

CXXFLAGS = -I im_gui_openGL/ -I eigen
CXXFLAGS += -g -Wall -Wformat -lm -lGL -lGLU -lglut -lm

all: obj $(OBJ)Contorno $(OBJ)imgui_draw $(OBJ)imgui_impl_glut $(OBJ)imgui_impl_opengl2 $(OBJ)imgui_widgets $(OBJ)imgui $(EXE)
	@echo completo!!!!
obj:
	if test ! -d Objects; then mkdir Objects; fi

$(OBJ)Contorno: $(CON)Contorno.cpp $(CON)Contorno.h
	$(CXX) -c $< -o $@

$(OBJ)imgui_draw: $(VIS)imgui_draw.cpp
	$(CXX) -c $< -o $@

$(OBJ)imgui_impl_glut: $(VIS)imgui_impl_glut.cpp
	$(CXX) -c $< -o $@

$(OBJ)imgui_impl_opengl2: $(VIS)imgui_impl_opengl2.cpp
	$(CXX) -c $< -o $@

$(OBJ)imgui_widgets: $(VIS)imgui_widgets.cpp
	$(CXX) -c $< -o $@

$(OBJ)imgui: $(VIS)imgui.cpp
	$(CXX) -c $< -o $@

$(EXE): $(EXE).cpp $(OBJ)Contorno $(OBJ)imgui_draw $(OBJ)imgui_impl_glut $(OBJ)imgui_impl_opengl2 $(OBJ)imgui_widgets $(OBJ)imgui 
	$(CXX) $^ -o $@ $(CXXFLAGS)

clean:
	rm -f $(EXE) $(OBJ)*
