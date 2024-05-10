#define GL_GLEXT_LEGACY
#define GL_GLEXT_PROTOTYPES 

#define STB_IMAGE_IMPLEMENTATION

#include <GL/glu.h>
#include <GL/gl.h>
#include <GL/glext.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int bindTexture(SDL_Surface* surf){
    GLuint result;

    int Mode = GL_RGB;

    if(surf->format->BytesPerPixel == 4) {
        Mode = GL_RGBA;
    }

    glGenTextures(1, &result);
    glBindTexture(GL_TEXTURE_2D, result);

    glTexImage2D(GL_TEXTURE_2D, 0, Mode,
        surf->w, surf->h,
        0, Mode, GL_UNSIGNED_BYTE, surf->pixels
    );

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    return (int)result;
}