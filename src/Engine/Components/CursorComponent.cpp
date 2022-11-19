//
// Created by guiej on 19/11/2022.
//

#include "CursorComponent.h"

void CursorComponent::Init(GLFWwindow *window) {
    this->window = window;
}

void CursorComponent::Update(float dt) {
    double cX, cY;
    glfwGetCursorPos(window, &cX, &cY);

    int wX, wY;
    glfwGetWindowSize(window, &wX, &wY);

    owner->pos->x = (float)cX;
    owner->pos->y = (float)wY - (float)cY - owner->size->y;
}

CursorComponent::CursorComponent(Sprite *owner) {
    this->owner = owner;
}
