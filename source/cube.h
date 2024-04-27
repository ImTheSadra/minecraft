#include <SDL2/SDL.h>
#include <GL/gl.h>

const float size = 1.0;

void drawCube(float x, float y, float z){
    glBegin(GL_QUADS);

    GLfloat pointmap[6][4][3]{
        {
            { size/2, size/2, size/2 },
            {-size/2, size/2, size/2 },
            {-size/2,-size/2, size/2 },
            { size/2,-size/2, size/2 }
        }, {
            {-size/2, size/2, size/2 },
            {-size/2, size/2,-size/2 },
            {-size/2,-size/2,-size/2 },
            {-size/2,-size/2, size/2 }
        }, {
            { size/2, size/2,-size/2 },
            {-size/2, size/2,-size/2 },
            {-size/2,-size/2,-size/2 },
            { size/2,-size/2,-size/2 }
        }, {
            { size/2, size/2,-size/2 },
            { size/2, size/2, size/2 },
            { size/2,-size/2, size/2 },
            { size/2,-size/2,-size/2 }
        }, {
            { size/2, size/2, size/2 },
            {-size/2, size/2, size/2 },
            {-size/2, size/2,-size/2 },
            { size/2, size/2,-size/2 }
        }, {
            { size/2,-size/2, size/2 },
            {-size/2,-size/2, size/2 },
            {-size/2,-size/2,-size/2 },
            { size/2,-size/2,-size/2 }
        }
    };

    glColor3f(0.0,1.0,0.0);
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 4; j++){
            glVertex3f(
                x+pointmap[i][j][0],
                y+pointmap[i][j][1],
                z+pointmap[i][j][2]
            );
        }
    }

    glEnd();
}