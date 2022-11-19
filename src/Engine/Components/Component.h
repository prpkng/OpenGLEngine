#ifndef OPENGLENGINE_COMPONENT_H
#define OPENGLENGINE_COMPONENT_H
#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"

class Component {
public:
    GLFWwindow* window;
    virtual void Init(GLFWwindow *window) {}
    virtual void Update(float dt) {}
    virtual void Render() {}

    virtual operator string() {
        return "Component";
    }
};


#endif //OPENGLENGINE_COMPONENT_H
