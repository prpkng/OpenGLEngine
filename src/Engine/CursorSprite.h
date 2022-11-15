#ifndef OPENGLENGINE_CURSORSPRITE_H
#define OPENGLENGINE_CURSORSPRITE_H

#include "Sprite.h"
#include "Utilities.h"

class CursorSprite: public Sprite {
public:
    CursorSprite(float sizeX, float sizeY, Shader program, Texture tex) :
        CursorSprite(new vec2(sizeX, sizeY), program, tex) {}
    CursorSprite(vec2* size, Shader program, Texture tex) : Sprite(const_cast<vec2*>(vec2::zero()), size, program, tex, 1e3){

    }

    void Update(double dt, GLFWwindow *window) override;
    void Render(vec2i *screen) override;
    void Init() override;
};


#endif //OPENGLENGINE_CURSORSPRITE_H
