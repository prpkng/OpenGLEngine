#pragma once

#ifndef SCENE_HEADER
#define SCENE_HEADER
#include <vector>

#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"

#include <array>
#include "Utilities.h"
#include "Objects/Sprite.h"
#include <algorithm>


class Scene {
public:
    Scene() = default;

    std::vector<Sprite*> sprites;


    void InitScene(GLFWwindow* window);
    void UpdateScene(double dt);
    void RenderScene(vec2i* windSize);
    void LoadContent();
    void DeleteScene();
};


#endif //SCENE_HEADER
