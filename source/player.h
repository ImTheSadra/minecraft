#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <math.h>

using namespace std;

class Player{
public:
    SDL_MouseMotionEvent last;
    TTF_Font* font = TTF_OpenFont("./assest/fonts/font.fon", 24);
    SDL_Color white{255,255,255};
    float x,y,z;
    float angle[2] = {0,0};
    bool pause = false;

    Player(){
        this->last.x = 0;
        this->last.y = 0;
        this->y = -2.0;
        this->z = -5.0;
    }

    void draw(SDL_Renderer* renderer){
        stringstream txt;
        txt << "cord > ";
        txt << (int)this->x << " - " << (int)this->y << " - " << this->z;
        SDL_Surface* stxt = TTF_RenderText_Solid(this->font, txt.str().c_str(), this->white);
        SDL_Texture* ttxt = SDL_CreateTextureFromSurface(renderer, stxt);
        SDL_Rect rect;
        rect.x = 0;
        rect.y = 0;
        rect.w = stxt->w;
        rect.h = stxt->h;

        SDL_RenderCopy(renderer, ttxt, NULL, &rect);
        SDL_RenderPresent(renderer);
    }

    void checkEvent(SDL_Event event){
        if (event.type == SDL_KEYDOWN){
            if(event.key.keysym.sym == SDLK_ESCAPE){
                if(this->pause){this->pause = false;}
                else {this->pause = true;}
            }
            if (this->pause){return;}
            int dx, dy, dz;
            dx = 0; dz = 0; dy = 0;
            double rangle = this->angle[0]*(M_PI / 180);
            double trangle = (90+this->angle[0])*(M_PI/180);
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
                this->z += cos(trangle)/5;
                this->x -= sin(trangle)/5;
                break;

            case SDLK_a:
            case SDLK_LEFT:
                this->z -= cos(trangle)/5;
                this->x += sin(trangle)/5;
                break;

            case SDLK_SPACE:
                this->y -= 0.1;
                break;

            case SDLK_LSHIFT:
                this->y += 0.1;
                break;

            default:
                break;
            }
            this->z += dz;
            this->x += dx;
        } else if (event.type == SDL_MOUSEMOTION){
            if (this->pause){return;}
            float da = (float)((this->last.x-event.motion.x));
            this->angle[0] += da;
            da = (float)(this->last.y-event.motion.y);
            this->last.x = event.motion.x;
            this->last.y = event.motion.y;
        }
    }
};