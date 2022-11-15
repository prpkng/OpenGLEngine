#pragma once
#ifndef OBJECT_HEADER
#define OBJECT_HEADER
#include "Utilities.h"

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

class Object {
public:
    Object(float x, float y) : Object(new vec2(x, y)) {};

    explicit Object(vec2* _pos) : pos(_pos) {}

    vec2* pos;

    virtual void Init() = 0;
    virtual void Render(vec2i* screen) = 0;
    virtual void Update(double dt, GLFWwindow* window) = 0;

};


#endif //OBJECT_HEADER
