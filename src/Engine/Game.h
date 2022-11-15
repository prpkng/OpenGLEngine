#pragma once

#ifndef GAME_HEADER
#define GAME_HEADER

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>

#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>

#include "../json.hpp"
#include "FileManager.h"
#include "Scene.h"
#include "Utilities.h"
#include "Sprite.h"
#include "CursorSprite.h"




class Game {
public:
    Game(int width, int height, const char *name);
    Game(vec2i windSize, const char* name);

    GLFWwindow* window = nullptr;

    vec2i* windowSize;
    const char* windowCaption;

    std::vector<Scene> scenes;

    int curSceneIndex = 0;

    void Initialize();
    void MainLoop();
    void Update();
    void Render();

    void SetCursor(std::string filename);

    std::vector<Texture*> textures;
    std::vector<Shader*> shaders;

};


#endif //GAME_HEADER
