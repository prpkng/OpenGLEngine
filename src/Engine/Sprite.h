#pragma once

#ifndef OPENGLENGINE_SPRITE_H
#define OPENGLENGINE_SPRITE_H

#include "Object.h"

//#define GLFW_INCLUDE_NONE
//#include "GLFW/glfw3.h"
#include <glad/glad.h>
#include <optional>

#include "Rect.h"


#include "../OGL/Shaders.h"
#include "../OGL/Texture.h"
#include "../OGL/VAO.h"
#include "../OGL/VBO.h"
#include "../OGL/EBO.h"

class SpriteTexture{
public:
    explicit SpriteTexture(bool fullSize) : SpriteTexture(0, 0, 0, 0){
        full = fullSize;
    }
    SpriteTexture() : SpriteTexture(0, 0, 0, 0){}
    SpriteTexture(float x, float y, float wid, float hei){
        offsetX = x;
        offsetY = y;
        width = wid;
        height = hei;
        full = false;
    }

    float offsetX, offsetY, width, height;
    bool full;
};

class Sprite : public Object {
public:
    Sprite(float x, float y, float sizeX, float sizeY, Shader program,
            std::optional<Texture> tex = std::nullopt, int z_index = 0, color* color = color::white()) :
                Sprite(new vec2(x, y), new vec2(sizeX, sizeY), program, tex, z_index, color) {}

    Sprite(vec2* pos, vec2* size, Shader program, std::optional<Texture> tex = std::nullopt, int z_index = 0,
           color* color = color::white()) : Object(pos), shaderProgram(program) {
        this->size = size;
        vao = VAO();
        bounds = new SpriteTexture(true);
        if (tex.has_value()){
            texture = tex;
            bounds->width = tex->width;
            bounds->height = tex->height;
        }
        this->clr = color;
        this->z_index = z_index;


    }


    vec2* size;
    color* clr;
    int z_index;

    ~Sprite();

    virtual void Init() override;

    virtual void Render(vec2i* screen) override;

    virtual void Update(double dt, GLFWwindow* window) override;

    void UnitTexture();

    GLenum texSlot = 0;
    Shader shaderProgram;
    std::optional<Texture> texture = std::nullopt;

    SpriteTexture* bounds;
private:
    VAO vao;

    // Vertices coordinates


    GLuint indices[6] = {
            0, 2, 1, //Upper triangle
            0, 3, 2 //Lower triangle
    };


};




#endif //OPENGLENGINE_SPRITE_H
