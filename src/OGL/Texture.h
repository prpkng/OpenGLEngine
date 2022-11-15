#ifndef OPENGLENGINE_TEXTURE_H
#define OPENGLENGINE_TEXTURE_H

#include "Shaders.h"
#include "../stb_image.h"
#include <glad/glad.h>

class Texture {
public:
    GLuint ID;
    GLenum type;
    Texture(std::string img, GLenum texType, GLenum slot, GLenum format, GLenum pixelType);

    void texUnit(Shader shader, const char* uniform, GLuint unit);

    int width, height;

    void Bind();
    void Unbind();
    void Delete();

};


#endif //OPENGLENGINE_TEXTURE_H
