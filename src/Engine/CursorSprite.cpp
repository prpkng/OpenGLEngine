#include "CursorSprite.h"

void CursorSprite::Init() {
    Sprite::Init();
}

void CursorSprite::Update(double dt, GLFWwindow *window) {
    Sprite::Update(dt, window);
    double cX, cY;
    glfwGetCursorPos(window, &cX, &cY);

    int wX, wY;
    glfwGetWindowSize(window, &wX, &wY);

    pos->x = (float)cX;
    pos->y = (float)wY - (float)cY - size->y;
}

void CursorSprite::Render(vec2i *screen) {
    Sprite::Render(screen);
}
