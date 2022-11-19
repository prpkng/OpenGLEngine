#include "Sprite.h"



void Sprite::Init(GLFWwindow* window) {
    UnitTexture();
    this->window = window;
    InitComponents();
}

void Sprite::UnitTexture() {
    if (texture.has_value()) {
        texture->texUnit(shaderProgram, "tex0", 0);
    }
}

void Sprite::Update(double dt) {
    UpdateComponents(dt);
    double cx, cy;

    glfwGetCursorPos(window, &cx, &cy);

    bounds->offsetX += dt;
}

void Sprite::Render(vec2i* screen) {
    RenderComponents();
    vao.Bind();
    Rect rect(pos, size);

    vec2 tl = rect.topLeft();
    vec2 bl = rect.bottomLeft();
    vec2 tr = rect.topRight();
    vec2 br = rect.bottomRight();

    Rect brect(bounds->offsetX, bounds->offsetY, bounds->width, bounds->height);

    float hW = screen->x / 2;
    float hH = screen->y / 2;

    GLfloat verts[] ={
        //COORDINATES                                  / COLORS
        (bl.x - hW) / hW, (bl.y - hH) / hH, 0.0f,       clr->r, clr->g, clr->b, clr->a,  //Bottom left
        brect.bottomLeft().x / (float)texture->width, brect.bottomLeft().y / (float)texture->height,                                      //

        (tl.x - hW) / hW, (tl.y - hH) / hH, 0.0f,       clr->r, clr->g, clr->b, clr->a,  //Top Left
        brect.topLeft().x / (float)texture->width, brect.topLeft().y / (float)texture->height,                                            //

        (tr.x - hW) / hW, (tr.y - hH) / hH, 0.0f,       clr->r, clr->g, clr->b, clr->a,  //Top right
        brect.topRight().x / (float)texture->width, brect.topRight().y / (float)texture->height,                                          //

        (br.x - hW) / hW, (br.y - hH) / hH, 0.0f,       clr->r, clr->g, clr->b, clr->a,  //Bottom right
        brect.bottomRight().x / (float)texture->width, brect.bottomRight().y / (float)texture->height,                                    //
    };

    VBO vbo(verts, sizeof(verts));
    EBO ebo(indices, sizeof(indices));

    vao.LinkAttrib(vbo, 0, 3, GL_FLOAT, 9 * sizeof(float), (void *) 0);
    vao.LinkAttrib(vbo, 1, 4, GL_FLOAT, 9 * sizeof(float), (void *) (3 * sizeof(float)));
    vao.LinkAttrib(vbo, 2, 2, GL_FLOAT, 9 * sizeof(float), (void *) (7 * sizeof(float)));

    vao.Unbind();
    vbo.Unbind();
    ebo.Unbind();

    shaderProgram.Activate();
    texture->Bind();
    vao.Bind();
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

Sprite::~Sprite() = default;
