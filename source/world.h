#include <GL/gl.h>
#include <SDL2/SDL.h>

#include "cube.h"
#include "player.h"

class World{
public:
    const int w = 10;
    const int h = 10;
    const int d = 10;
    int data[10][10][10];
    World(Player p){
        for(int x = 0; x < this->w;x++){
            for(int z = 0; z < this->d; z++){
                for(int y = 0; y < this->h; y++){
                    this->data[x][y][z] = 0;
                }
                this->data[x][0][z] = 1;
            }
        }
        this->data[5][2][5] = 1;
    }

    void draw(Player player){
        glLoadIdentity();
        glRotatef(player.angle,0.0,1.0,0.0);
        glTranslatef(player.x, player.y, player.z);

        for(float x = 0; x < this->w;x++){
            for(float z = 0; z < this->d; z++){
                for(float y = 0; y < this->h; y++){
                    if (this->data[(int)x][(int)y][(int)z] == 0){continue;}
                    drawCube(x, y, z);
                }
            }
        }
    }


};