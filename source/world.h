#include <GL/glu.h>
#include <GL/gl.h>
#include <SDL2/SDL.h>

// #include "cube.h"
#include "block/block.h"
#include "player.h"

const unsigned int w = 10;
const unsigned int h = 10;
const unsigned int d = 10;
int WorldData[w][h][d];

Block blocks[]{
    Block("grass")
};

class World{
public:
    World(Player p){
        for(int x = 0; x < w;x++){
            for(int z = 0; z < d; z++){
                for(int y = 0; y < h; y++){
                    WorldData[x][y][z] = -1;
                }
                WorldData[x][0][z] = 1;
            }
        }
        WorldData[5][2][5] = 1;
    }

    void draw(Player player){
        glLoadIdentity();
        glRotatef(player.angle[0],0.0,1.0,0.0);
        glRotatef(player.angle[1],1.0,0.0,0.0);
        glTranslatef(player.x, player.y, player.z);

        for(float x = 0; x < w; x++){
            for(float z = 0; z < d; z++){
                for(float y = 0; y < h; y++){
                    int type = WorldData[(int)x][(int)y][(int)z];
                    if (type != -1){
                        Block block = blocks[type-1];
                        block.draw(x, y, z);
                    }
                }
            }
        }
    }
};