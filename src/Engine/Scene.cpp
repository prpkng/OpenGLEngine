#include "Scene.h"

void Scene::LoadContent() {

}

void Scene::InitScene(GLFWwindow* window) {
//    Shader defShader("default.vert", "default.frag");
    for (auto s: sprites){
        s->Init(window);
    }
}

void Scene::UpdateScene(double dt) {
    for (auto s: sprites){
        s->Update(dt);
    }
}

void Scene::RenderScene(vec2i* windSize) {
    std::sort(sprites.begin(), sprites.end(), [](const Sprite* a, const Sprite* b) -> bool{
        return a->z_index < b->z_index;
    });
    for (auto s: sprites){
        s->Render(windSize);
    }
}

void Scene::DeleteScene() {
    //for (auto s: sprites){
      //
    //}

}