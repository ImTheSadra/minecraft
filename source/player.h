#include <GL/gl.h>
#include <GL/glu.h>
#include <SDL2/SDL.h>
#include <iostream>
#include <math.h>

using namespace std;

// #include "cube.h"

class Player{
public:
    SDL_MouseMotionEvent last;
    float x,y,z;
    float angle = 1.0;
    Player(){
        this->last.x = 0;
        this->last.y = 0;
        this->y = -2.0;
        this->z = -5.0;
    }

    void checkEvent(SDL_Event event){
        if (event.type == SDL_KEYDOWN){
            int dx, dy, dz;
            dx = 0; dz = 0; dy = 0;
            double rangle = this->angle*(M_PI / 180);
            double trangle = rangle+(90*(M_PI/180));
            switch (event.key.keysym.sym)
            {
            case SDLK_w:
            case SDLK_UP:
                this->z += cos(rangle)/5;
                this->x -= sin(rangle)/5;
                break;

            case SDLK_s:
            case SDLK_DOWN:
                this->z -= cos(rangle)/5;
                this->x += sin(rangle)/5;
                break;

            case SDLK_d:
            case SDLK_RIGHT:
                this->z -= cos(trangle)/5;
                this->x -= sin(trangle)/5;
                break;

            case SDLK_a:
            case SDLK_LEFT:
                this->z += cos(trangle)/5;
                this->x += sin(trangle)/5;
                break;

            case SDLK_KP_6:
                this->angle += 0.3;
                break;
            case SDLK_KP_4:
                this->angle -= 0.3;
                break;
            
            default:
                break;
            }
            this->z += dz;
            this->x += dx;
            // SDL_SetWindowTitle(SDL_GL_GetCurrentWindow(), (char*)dx);
        } else if (event.type == SDL_MOUSEMOTION){
            float da = (float)((this->last.x-event.motion.x));
            this->angle += da;
            this->last.x = event.motion.x;
            this->last.y = event.motion.y;
        }
    }
};