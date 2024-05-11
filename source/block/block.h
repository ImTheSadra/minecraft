#include <iostream>
#include <string>
#include <SDL2/SDL.h>

#include "../texture.h"

using namespace std;

class Block{
public:
    SDL_Surface* top;
    SDL_Surface* body;
    SDL_Surface* down;
    float size = 1.0;

    float pointmap[6][4][5]{
        {
            { size/2, size/2, size/2, 1, 1},
            {-size/2, size/2, size/2, 1, 0},
            {-size/2,-size/2, size/2, 0, 0},
            { size/2,-size/2, size/2, 0, 1}
        }, {
            {-size/2, size/2, size/2, 1, 1},
            {-size/2, size/2,-size/2, 1, 0},
            {-size/2,-size/2,-size/2, 0, 0},
            {-size/2,-size/2, size/2, 0, 1}
        }, {
            { size/2, size/2,-size/2, 1, 1},
            {-size/2, size/2,-size/2, 1, 0},
            {-size/2,-size/2,-size/2, 0, 0},
            { size/2,-size/2,-size/2, 0, 1}
        }, {
            { size/2, size/2,-size/2, 1, 1},
            { size/2, size/2, size/2, 1, 0},
            { size/2,-size/2, size/2, 0, 0},
            { size/2,-size/2,-size/2, 0, 1}
        }, {
            { size/2, size/2, size/2, 1, 1},
            {-size/2, size/2, size/2, 1, 0},
            {-size/2, size/2,-size/2, 0, 0},
            { size/2, size/2,-size/2, 0, 1}
        }, {
            { size/2,-size/2, size/2, 1, 1},
            {-size/2,-size/2, size/2, 1, 0},
            {-size/2,-size/2,-size/2, 0, 0},
            { size/2,-size/2,-size/2, 0, 1}
        }
    };

    SDL_Surface* textures[6];

    Block(string name){
        stringstream tname;
        tname << "./assest/blocks/";
        tname << name;
        tname << "/top.png";
        this->top = IMG_Load(tname.str().c_str());

        stringstream bname;
        bname << "./assest/blocks/";
        bname << name;
        bname << "/body.png";
        this->body = IMG_Load(bname.str().c_str());

        stringstream dname;
        dname << "./assest/blocks/";
        dname << name;
        dname << "/down.png";
        this->down = IMG_Load(dname.str().c_str());

        this->textures[0] = this->body;
        this->textures[1] = this->body;
        this->textures[2] = this->body;
        this->textures[3] = this->body;
        this->textures[4] = this->top;
        this->textures[5] = this->down;
    }

    void draw(float x, float y, float z){
        
        for(int i = 0; i < 6; i++){
            glBindTexture(GL_TEXTURE_2D, bindTexture(this->textures[i]));
            glBegin(GL_QUADS);

            glVertexPointer(4, GL_FLOAT, 0, pointmap[i][0]);
            
            glTexCoord2f(0, 0);
            glVertex3f(
                x+pointmap[i][0][0],
                y+pointmap[i][0][1],
                z+pointmap[i][0][2]
            );
        
            glTexCoord2f(1, 0);
            glVertex3f(
                x+pointmap[i][1][0],
                y+pointmap[i][1][1],
                z+pointmap[i][1][2]
            );

            glTexCoord2f(1, 1);
            glVertex3f(
                x+pointmap[i][2][0],
                y+pointmap[i][2][1],
                z+pointmap[i][2][2]
            );

            glTexCoord2f(0, 1);
            glVertex3f(
                x+pointmap[i][3][0],
                y+pointmap[i][3][1],
                z+pointmap[i][3][2]
            );

            glEnd();
            glFlush();
        }

        auto err = glGetError();
        if (err != GL_NO_ERROR){
            cout << "[RENDERING ERR]" << err << endl;
        }
    }
};