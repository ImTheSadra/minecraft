#include <SDL2/SDL.h>
#include <GL/glu.h>
#include <GL/gl.h>

#include "world.h"

const int WIDTH = 800;
const int HEIGHT = 600;

// float angle = 0.0;

class App{
private:
    Player player = Player();
    World world = World(player);
public:
    SDL_Window* window;
    SDL_GLContext context;
    bool running = true;
    App(){
        this->window = SDL_CreateWindow(
            "TEST", 
            SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED,
            WIDTH, HEIGHT, SDL_WINDOW_OPENGL
        );
        this->context = SDL_GL_CreateContext(this->window);

        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluPerspective(45,640.0/480,1.0,500.0);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        glMatrixMode(GL_MODELVIEW);
        glEnable(GL_DEPTH_TEST);
    }

    void draw(){
        glClearColor(0.3, 0.0, 0.3, 1.0);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        this->world.draw(this->player);

        SDL_GL_SwapWindow(SDL_GL_GetCurrentWindow());
    }

    void update(){
        SDL_Event event;
        while(SDL_PollEvent(&event)){
            if (event.type == SDL_QUIT){this->running = false;}
            player.checkEvent(event);
        }

        // angle += 0.1;
        // if (angle >= 360){angle = 0;}

        SDL_Delay(5);
    }

    void run(){
        glEnable(GL_DEPTH_TEST);

        while(this->running){
            this->update();
            this->draw();
        }

        SDL_DestroyWindow(this->window);
        SDL_Quit();
    }
};