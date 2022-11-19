//
// Created by guiej on 19/11/2022.
//

#ifndef CURSOR_COMPONENT_H
#define CURSOR_COMPONENT_H

#include "../Objects/Sprite.h"
#include "../../OGL/Texture.h"
#include "Component.h"

class CursorComponent : public Component {
public:
    CursorComponent(Sprite* owner);

    Sprite* owner;

    void Init(GLFWwindow *window) override;
    void Update(float dt) override;
    void Render() override {}
     operator string() override{
        return "CursorComponent";
    }
};


#endif //CURSOR_COMPONENT_H
