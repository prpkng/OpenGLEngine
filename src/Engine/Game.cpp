#include "Game.h"


Game::Game(int width, int height, const char *name) : Game(vec2i(width, height), name)
{}
Game::Game(vec2i windSize, const char *name) {
    windowCaption = name;
    windowSize = &windSize;

    std::string file = FileManager::ReadFile("config.json");
    nlohmann::json js = nlohmann::json::parse(file);
    if (js) {
        windowSize->x = js["screen_width"];
        windowSize->y = js["screen_height"];
        //windowCaption = std::string(js["caption"]).c_str();
    }
}

void Game::Initialize() {
    if (!glfwInit()){
        exit(-1);
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(windowSize->x, windowSize->y, windowCaption, NULL, NULL);

    if (!window){
        std::cout << "Error caught on window creation: " << glfwGetError(NULL);
        exit(-1);
    }

    //Make window's context current
    glfwMakeContextCurrent(window);

    //Load GLAD and if not, terminate
    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        glfwTerminate();
        printf("OpenGL Initialization ran into an error!");
        exit(-1);
    }

    //glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);

    //Setup Opengl Viewport
    glViewport(0, 0, 900, 900);

    //Set the opengl clear color and clear the viewport
    glClearColor(0.6, 0.6, 0.7f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    //Swap window buffers (IDK what this does, but it's important)
    glfwSwapBuffers(window);



    Shader defShader("default.vert", "default.frag");
    Texture cursorPng("cursor.png", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGBA, GL_UNSIGNED_BYTE);
    Texture spyral("spyral.png", GL_TEXTURE_2D, GL_TEXTURE1, GL_RGBA, GL_UNSIGNED_BYTE);

    shaders.push_back(&defShader);
    textures.push_back(&cursorPng);
    textures.push_back(&spyral);

    Sprite* spr = new Sprite(0.0f, 0.0f, 200.0f, 200.0f, defShader, spyral);
    //CursorSprite* cursor = new CursorSprite(32.0f, 32.0f, defShader, cursorPng);

    Scene scene;



    //scene.sprites.push_back((Sprite*)cursor);
    scene.sprites.push_back(spr);

    scene.LoadContent();
    scene.InitScene();
    scenes.push_back(scene);

    SetCursor("cursor.png");

    MainLoop();

}

void Game::MainLoop() {
    while(!glfwWindowShouldClose(window)){
        Update();
        Render();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwDestroyWindow(window);
    glfwTerminate();
    for (auto s: scenes){
        s.DeleteScene();
    }

    delete windowSize;

    for (auto tex: textures){
        tex->Delete();
    }
    for (auto shader: shaders){
        shader->Delete();
    }

    exit(0);
}

double curFrame, lastFrame;
void Game::Update() {
    curFrame = glfwGetTime();
    double dt = curFrame - lastFrame;
    lastFrame = curFrame;
    int sizeX, sizeY;
    glfwGetWindowSize(window, &sizeX, &sizeY);

    auto ws = vec2i(sizeX, sizeY);
    windowSize = &ws;

    scenes[curSceneIndex].UpdateScene(dt, window);
}

void Game::Render() {
    glClearColor(0.6, 0.6, 0.7f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glViewport(0, 0, windowSize->x, windowSize->y);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    scenes[curSceneIndex].RenderScene(windowSize);

}


void Game::SetCursor(std::string filename) {
    int widthImg, heightImg, numColCh;
    stbi_set_flip_vertically_on_load(false);
    unsigned char* data = stbi_load(("textures/"+filename).c_str(), &widthImg, &heightImg, &numColCh, 0);
    GLFWimage img;
    img.pixels = data;
    img.width = widthImg;
    img.height = heightImg;

    GLFWcursor* cr = glfwCreateCursor(&img, 0, 0);
    glfwSetCursor(window, cr);
    stbi_image_free(data);
}
