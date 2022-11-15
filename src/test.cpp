#include <iostream>
#include <cstdio>
#include <math.h>

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>

#include "OGL/Shaders.h"
#include "OGL/VBO.h"
#include "OGL/VAO.h"
#include "OGL/EBO.h"
#include "OGL/Texture.h"
#include "stb_image.h"

using namespace std;

// Vertices coordinates
GLfloat verts[] =
{       //COORDINATES             / COLORS       / TEX COORDS  //
        -0.5f, -0.5f, 0.0f,       1.0, 0.7f, 0.2f, 0.0f, 0.0f,  //Bottom left
        -0.5f,  0.5f, 0.0f,       0.5, 0.6f, 0.8f, 0.0f, 1.0f,  //Top left
         0.5f,  0.5f, 0.0f,       0.8, 0.5f, 0.2f, 1.0f, 1.0f,  //Top right
         0.5f, -0.5f, 0.0f,       0.2, 0.9f, 0.4f, 1.0f, 0.0f   //Bottom right
};

GLuint indices[] = {
        0, 2, 1, //Upper triangle
        0, 3, 2 //Lower triangle
};

int main() {
    GLFWwindow *window;

    //Initialize the glfw
    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    //Create the window
    window = glfwCreateWindow(900, 900, "TestWindow", NULL, NULL);


    //Check if window is valid
    if (!window) {
        glfwTerminate();
        printf("Window Initialization ran into an error!");
        return -1;
    }

    //Make window's context current
    glfwMakeContextCurrent(window);

    //Load GLAD and if not, terminate
    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        glfwTerminate();
        printf("OpenGL Initialization ran into an error!");
        return -1;
    }


    //Setup Opengl Viewport
    glViewport(0, 0, 900, 900);

    //Set the opengl clear color and clear the viewport
    glClearColor(0.6, 0.6, 0.7f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    //Swap window buffers (idk what this does, but it's important)
    glfwSwapBuffers(window);

    //Triangle vertices


    Shader program("default.vert", "default.frag");

    // Generates Vertex Array Object and binds it
    VAO VAO1;
    VAO1.Bind();

    // Generates Vertex Buffer Object and links it to vertices
    VBO VBO1(verts, sizeof(verts));
    // Generates Element Buffer Object and links it to indices
    EBO EBO1(indices, sizeof(indices));

    // Links VBO attributes such as coordinates and colors to VAO
    VAO1.LinkAttrib(VBO1, 0, 3, GL_FLOAT, 8 * sizeof(float), (void *) 0);
    VAO1.LinkAttrib(VBO1, 1, 3, GL_FLOAT, 8 * sizeof(float), (void *) (3 * sizeof(float)));
    VAO1.LinkAttrib(VBO1, 2, 2, GL_FLOAT, 8 * sizeof(float), (void *) (6 * sizeof(float)));
    // Unbind all to prevent accidentally modifying them
    VAO1.Unbind();
    VBO1.Unbind();
    EBO1.Unbind();

    Texture popCat("pop_cat.png", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGBA, GL_UNSIGNED_BYTE);
    popCat.texUnit(program, "tex0", 0);


    //Main-loop
    while (!glfwWindowShouldClose(window)) {
        //Clear
        glClearColor(0.2f, 0.5f, 0.7f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        program.Activate();
        popCat.Bind();
        VAO1.Bind();
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        //Swap buffers and poll events
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    popCat.Delete();
    VAO1.Delete();
    VBO1.Delete();
    EBO1.Delete();
    program.Delete();
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
