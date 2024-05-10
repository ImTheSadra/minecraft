CC = g++
 
FLAGS = -lOpenGL32 -lglu32 -lSDL2 -lmingw32 -lSDL2_ttf -lSDL2_image

INCLUDE = -I./includes

LIBS = -L./libs

OUTPUT = build/app
INPUT = source/main.cpp

all: compile run

compile:
	@$(CC) $(INPUT) -o $(OUTPUT) $(FLAGS) $(INCLUDE) $(LIBS)

run:
	@cd build/ && app.exe