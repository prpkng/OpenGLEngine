#pragma once
#ifndef OBJECT_HEADER
#define OBJECT_HEADER

#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"
#include <vector>
#include "../Utilities.h"
#include "../Components/Component.h"

using namespace std;

class Object {
public:
    Object(float x, float y) : Object(new vec2(x, y)) {};

    explicit Object(vec2* _pos) : pos(_pos) {}


    vec2* pos;
    GLFWwindow* window;

    virtual void Init(GLFWwindow* window) = 0;
    virtual void Render(vec2i* screen) = 0;
    virtual void Update(double dt) = 0;

    void AddComponent(Component component){
        components.push_back(&component);
    }
    void RemoveComponent(Component component){
        vector<Component*> temp = {};

        for (int i = 0; i < components.size(); i++){
            if (string(*components[i]) == string(component))
                continue;
            temp.push_back(&component);
        }
        components = temp;

    }
    string ListComponents(){
        string comps = "{ ";
        for (auto c: components){
            comps += string(*c) + ", ";
        }
        comps = comps.substr(0, comps.size() - 2 );
        comps += " } ";
        return comps;
    }

    void UpdateComponents(float dt){
        for (auto c: components){
            c->Update(dt);
        }
    }

    void RenderComponents(){
        for (auto c: components){
            c->Render();
        }
    }

    void InitComponents(){
        for (auto c: components){
            c->Init(window);
        }
    }

private:
    vector<Component*> components;

};


#endif //OBJECT_HEADER
