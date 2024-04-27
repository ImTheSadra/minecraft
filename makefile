CC = g++

FLAGS = -w -Wl,-subsystem,windows -lOpenGL32 -lglu32 -lfreeGLUT -lSDL2main -lmingw32 -lSDL2

INCLUDE = -I./includes

LIBS = -L./libs

OUTPUT = build/app
INPUT = source/main.cpp

all: compile run

compile:
	$(CC) $(INPUT) -o $(OUTPUT) $(FLAGS) $(INCLUDE) $(LIBS)

run:
	@cd build/ && app.exe