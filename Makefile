#
# Cross Platform Makefile
# Compatible with MSYS2/MINGW, Ubuntu 14.04.1 and Mac OS X
#
# Linux:
#   apt-get install freeglut3-dev
#

#CXX = g++
#CXX = clang++

EXE = main
SOURCES = main.cpp
SOURCES += $(wildcard visao/im_gui_openGL/*.cpp)
OBJ = Objects/
OBJS = $(addprefix $(OBJ), $(addsuffix .o, $(basename $(notdir $(SOURCES)))))
UNAME_S := $(shell uname -s)

CXXFLAGS = -I im_gui_openGL/
CXXFLAGS += -g -Wall -Wformat
LIBS =

##---------------------------------------------------------------------
## BUILD FLAGS PER PLATFORM
##---------------------------------------------------------------------

ifeq ($(UNAME_S), Linux) #LINUX
	ECHO_MESSAGE = "Linux"
	LIBS += -lGL -lGLU -lglut -lm
	CFLAGS = $(CXXFLAGS)
endif

ifeq ($(UNAME_S), Darwin) #APPLE
	ECHO_MESSAGE = "Mac OS X"
	LIBS += -framework OpenGL -framework GLUT
	LIBS += -L/usr/local/lib -L/opt/local/lib

	CXXFLAGS += -I/usr/local/include -I/opt/local/include
	CFLAGS = $(CXXFLAGS)
endif

ifeq ($(findstring MINGW,$(UNAME_S)),MINGW)
	ECHO_MESSAGE = "MinGW"
	LIBS += -lgdi32 -lopengl32 -limm32 -lglut
	CFLAGS = $(CXXFLAGS)
endif

##---------------------------------------------------------------------
## BUILD RULES
##---------------------------------------------------------------------

all: teste $(EXE)
	@echo Build complete for $(ECHO_MESSAGE)
	
teste:
	if test ! -d Objects; then mkdir Objects; fi

$(OBJ)%.o:%.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(OBJ)%.o:visao/im_gui_openGL/%.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(EXE): $(OBJS)
	$(CXX) -o $@ $^ $(CXXFLAGS) $(LIBS)

clean:
	rm -f $(EXE) $(OBJS)
